/******************************************************************************

 @file main.c

 @brief main entry of the example application

 Group: WCS LPC
 Target Device: cc13xx_cc26xx

 ******************************************************************************
 
 Copyright (c) 2016-2024, Texas Instruments Incorporated
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 *  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

 *  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 *  Neither the name of Texas Instruments Incorporated nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ******************************************************************************
 
 
 *****************************************************************************/

/******************************************************************************
 Includes
 *****************************************************************************/

/* RTOS header files */
#ifndef FREERTOS_SUPPORT
#include <ti/sysbios/BIOS.h>
#else
#include <FreeRTOS.h>
#include <task.h>
#endif

#include <pthread.h>

#include <ioc.h>

#include "sys_ctrl.h"

#include "ti_drivers_config.h"

#include <inc/hw_ccfg.h>
#include <inc/hw_ccfg_simple_struct.h>

/* Header files required for the temporary idle task function */
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/drivers/GPIO.h>
#include <aon_rtc.h>
#include <prcm.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>
#include "Defines.h"
/* Header files required to enable instruction fetch cache */
#include <ti/drivers/dpl/HwiP.h>

#include "cpu.h"
#include "collector.h"

#ifdef NV_RESTORE
#include "macconfig.h"
#include "nvocmp.h"
#endif

#include <string.h>
#include "control_task.h"
#include "console.h"
#include "time_clock.h"
#include "utc_clock.h"

#ifdef OSAL_PORT2TIRTOS
#include "macTask.h"
#include"rom_jt_154.h"
#else
#include "api_mac.h"
#include "icall.h"
#endif

#if defined(RESET_ASSERT)
#include "csf.h"
#endif

#ifndef USE_DEFAULT_USER_CFG

#include "mac_user_config.h"

/* MAC user defined configuration */
macUserCfg_t macUser0Cfg[] = MAC_USER_CFG;

#endif /* USE_DEFAULT_USER_CFG */

#ifndef CUI_DISABLE
#include "cui.h"
#endif

#ifdef USE_ITM_DBG
#include "itm.h"
#endif

/******************************************************************************
 Constants
 *****************************************************************************/

/* Assert Reasons */
#define MAIN_ASSERT_MAC          3
#define MAIN_ASSERT_HWI_TIRTOS   4

#define RFC_MODE_BLE                 PRCM_RFCMODESEL_CURR_MODE1
#define RFC_MODE_IEEE                PRCM_RFCMODESEL_CURR_MODE2
#define RFC_MODE_ANT                 PRCM_RFCMODESEL_CURR_MODE4
#define RFC_MODE_EVERYTHING_BUT_ANT  PRCM_RFCMODESEL_CURR_MODE5
#define RFC_MODE_EVERYTHING          PRCM_RFCMODESEL_CURR_MODE6

/* Extended Address offset in FCFG (LSB..MSB) */
#define EXTADDR_OFFSET 0x2F0
#if defined(DeviceFamily_CC13X2) || defined(DeviceFamily_CC26X2) || \
    defined(DeviceFamily_CC13X2X7) || defined(DeviceFamily_CC26X2X7) || \
    defined(DeviceFamily_CC13X1) || defined(DeviceFamily_CC26X1) || \
    defined(DeviceFamily_CC13X4) || defined(DeviceFamily_CC26X4) || defined(DeviceFamily_CC26X3)
#define APP_TASK_STACK_SIZE 1536
#else
#define APP_TASK_STACK_SIZE 960
#endif

#define APP_TASK_PRIORITY   1

#define SET_RFC_MODE(mode) HWREG( PRCM_BASE + PRCM_O_RFCMODESEL ) = (mode)

/******************************************************************************
 External Variables
 *****************************************************************************/

extern ApiMac_sAddrExt_t ApiMac_extAddr;

/******************************************************************************
 Global Variables
 *****************************************************************************/
pthread_t appThread;

#ifdef OSAL_PORT2TIRTOS
static uint8_t _macTaskId;
#endif

/*
 When assert happens, this field will be filled with the reason:
       MAIN_ASSERT_HWI_TIRTOS or MAIN_ASSERT_MAC
 */
uint8 Main_assertReason = 0;

#ifdef NV_RESTORE
mac_Config_t Main_user1Cfg =
    { 0 };
#endif

/******************************************************************************
 Local Variables
 *****************************************************************************/
/* Used to check for a valid extended address */
static const uint8_t dummyExtAddr[] =
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

extern void Board_init(void);

#ifdef FREERTOS_SUPPORT
extern void startRfCbThread(void);
#endif

/*!
 * @brief       Reads the IEEE extended MAC address from the CCFG
 * @param       addr - Extended address pointer
 */
static inline void CCFGRead_IEEE_MAC(ApiMac_sAddrExt_t addr)
{
    uint32_t macAddr = (( HWREG(
            CCFG_BASE + CCFG_O_IEEE_MAC_0 ) &
            CCFG_IEEE_MAC_0_ADDR_M ) >>
            CCFG_IEEE_MAC_0_ADDR_S );
    memcpy(addr, (uint8_t *)&macAddr, (APIMAC_SADDR_EXT_LEN / 2));

    macAddr = (( HWREG(
            CCFG_BASE + CCFG_O_IEEE_MAC_1 ) &
            CCFG_IEEE_MAC_1_ADDR_M ) >>
            CCFG_IEEE_MAC_1_ADDR_S );
    memcpy(addr + (APIMAC_SADDR_EXT_LEN / 2), (uint8_t *)&macAddr,
           (APIMAC_SADDR_EXT_LEN / 2));
}

/*!
 * @brief       Fill in your own assert function.
 *
 * @param       assertReason - reason: MAIN_ASSERT_HWI_TIRTOS or
 *                                     MAIN_ASSERT_MAC
 */
void Main_assertHandler(uint8_t assertReason)
{
    Main_assertReason = assertReason;

#if defined(RESET_ASSERT)
    Csf_assertInd(assertReason);

    /* Pull the plug and start over */
    SysCtrlSystemReset();
#else
    HwiP_disable();
    while(1)
    {
        /* Put you code here to do something if in assert */
    }
#endif
}
Task_Params collectorTaskParam;
 Task_Struct collectorTask;
uint8_t collectorTaskStack[collectorTaskStackSize];

void collectorTask_(uintptr_t arg1, uintptr_t arg2);
/*!
 * @brief       Main task function
 *
 * @param       a0 -
 * @param       a1 -
 */
void collectorTask_(uintptr_t arg1, uintptr_t arg2)
{
    /* The following code encapsulated in TI_154STACK_FPGA flag is used for
     * internal FPGA evaluation of the 15.4 Stack and should not be used with
     * TI hardware platforms. */
#ifdef TI_154STACK_FPGA
    /* FPGA build disables POWER constraints */
    Power_setConstraint(PowerCC26XX_IDLE_PD_DISALLOW);
    Power_setConstraint(PowerCC26XX_SB_DISALLOW);

    IOCPortConfigureSet(IOID_29, IOC_PORT_RFC_GPO0, IOC_IOMODE_NORMAL);
    IOCPortConfigureSet(IOID_30, IOC_PORT_RFC_GPI0, IOC_INPUT_ENABLE);
    IOCPortConfigureSet(IOID_15, IOC_PORT_RFC_TRC, IOC_IOMODE_NORMAL);
    // configure RF Core SMI Command Link
    IOCPortConfigureSet(IOID_22, IOC_IOCFG0_PORT_ID_RFC_SMI_CL_OUT, IOC_STD_OUTPUT);
    IOCPortConfigureSet(IOID_21, IOC_IOCFG0_PORT_ID_RFC_SMI_CL_IN, IOC_STD_INPUT);
#endif

#ifndef OSAL_PORT2TIRTOS
    /* Initialize ICall module */
    ICall_init();
#endif
    /* Copy the extended address from the CCFG area */
    CCFGRead_IEEE_MAC(ApiMac_extAddr);

    /* Check to see if the CCFG IEEE is valid */
    if(memcmp(ApiMac_extAddr, dummyExtAddr, APIMAC_SADDR_EXT_LEN) == 0)
    {
        /* No, it isn't valid.  Get the Primary IEEE Address */
        memcpy(ApiMac_extAddr, (uint8_t *)(FCFG1_BASE + EXTADDR_OFFSET),
               (APIMAC_SADDR_EXT_LEN));
    }


#ifdef NV_RESTORE
    /* Setup the NV driver */
    NVOCMP_loadApiPtrs(&Main_user1Cfg.nvFps);

    if(Main_user1Cfg.nvFps.initNV)
    {
        Main_user1Cfg.nvFps.initNV( NULL);
    }
#endif

#ifdef OSAL_PORT2TIRTOS
    /* Initialize the application */
    Collector_init(_macTaskId);
#else
    ICall_createRemoteTasks();

    /* Initialize the application */
    Collector_init();
#endif

    /* Kick off application - Forever loop */
    while(1)
    {
        Collector_process();
    }
}

/*!
 * @brief       TIRTOS HWI Handler.  The name of this function is set to
 *              M3Hwi.excHandlerFunc in app.cfg, you can disable this by
 *              setting it to null.
 *
 * @param       excStack - uint32_t variable
 * @param       lr - uint32_t variable
 */
void Main_excHandler(uint32_t *excStack, uint32_t lr)
{
    /* User defined function */
    Main_assertHandler(MAIN_ASSERT_HWI_TIRTOS);
}

/*!
 * @brief       HAL assert handler required by OSAL memory module.
 */
void assertHandler(void)
{
    /* User defined function */
    Main_assertHandler(MAIN_ASSERT_MAC);
}

/*!
 * @brief       "main()" function - starting point
 */
int main(void)
{
    pthread_attr_t      attrs;
    struct sched_param  priParam;
    int                 retc;

#ifndef USE_DEFAULT_USER_CFG
    macUser0Cfg[0].pAssertFP = assertHandler;
#endif
    /*
     Initialization for board related stuff such as LEDs
     following TI-RTOS convention
     */
    Board_init();

#if !defined(POWER_MEAS) && !defined(CUI_DISABLE)
    /* Initialize CUI UART*/
    CUI_params_t cuiParams;
    CUI_paramsInit(&cuiParams);
#ifdef MT_CSF
    cuiParams.manageUart = false;
#endif //MT_CSF

    // One-time initialization of the CUI
    // All later CUI_* functions will be ignored if this isn't called
    CUI_init(&cuiParams);
#endif

#ifdef OSAL_PORT2TIRTOS
    _macTaskId = macTaskInit(macUser0Cfg);
#endif


   Task_Params_init(&collectorTaskParam);
   collectorTaskParam.stack = collectorTaskStack;
   collectorTaskParam.stackSize = collectorTaskStackSize;
   collectorTaskParam.priority = collectorTaskPriority;
   Task_construct(&collectorTask, collectorTask_, &collectorTaskParam, NULL);



  control_taskInit();
   console_taskInit();

   UTC_init();
   UTC_setClock(1722169176);


#ifdef IEEE_COEX_TEST
    GPIO_PinConfig RX_Config;
    GPIO_PinConfig TX_Config;

    GPIO_getConfig(PIN_RX_ACTIVE, &RX_Config);
    GPIO_getConfig(PIN_TX_ACTIVE, &TX_Config);

    GPIO_setConfigAndMux(PIN_RX_ACTIVE, RX_Config, IOC_PORT_RFC_GPO0);
    GPIO_setConfigAndMux(PIN_TX_ACTIVE, TX_Config, IOC_PORT_RFC_GPO3);
#endif // IEEE_COEX_TEST
#ifdef USE_ITM_DBG
    ITM_config itm_config =
    {
      48000000,
      ITM_6000000
    };
    ITM_initModule(itm_config);
    ITM_enableModule();
#endif /* USE_ITM_DBG */

#ifdef FREERTOS_SUPPORT
    startRfCbThread();
    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();
#else
    BIOS_start(); /* enable interrupts and start SYS/BIOS */
#endif

    return (0);
}


//static uint16_t getNumActiveDevices(void)
//{
//    uint16_t activeSensors = 0;
//    int x;
//    for(x = 0; x < CONFIG_MAX_DEVICES; x++)
//        {
//            if((Cllc_associatedDevList[x].shortAddr != CSF_INVALID_SHORT_ADDR)
//               && (Cllc_associatedDevList[x].status & CLLC_ASSOC_STATUS_ALIVE))
//            {
//                activeSensors++;
//            }
//
//
//        }
//    return (activeSensors);
//}
