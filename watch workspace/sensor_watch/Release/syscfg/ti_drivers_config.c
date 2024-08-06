/*
 *  ======== ti_drivers_config.c ========
 *  Configured TI-Drivers module definitions
 *
 *  DO NOT EDIT - This file is generated for the LP_EM_CC1314R10
 *  by the SysConfig tool.
 */

#include <stddef.h>
#include <stdint.h>

#ifndef DeviceFamily_CC13X4
#define DeviceFamily_CC13X4
#endif

#include <ti/devices/DeviceFamily.h>

#include "ti_drivers_config.h"

/*
 *  ============================= Display =============================
 */

#include <ti/display/Display.h>
#include <ti/display/DisplayUart2.h>

#define CONFIG_Display_COUNT 1


#define Display_UART2BUFFERSIZE 1024
static char displayUART2Buffer[Display_UART2BUFFERSIZE];

DisplayUart2_Object displayUart2Object;

const DisplayUart2_HWAttrs displayUart2HWAttrs = {
    .uartIdx      = CONFIG_DISPLAY_UART,
    .baudRate     = 115200,
    .mutexTimeout = (unsigned int)(-1),
    .strBuf       = displayUART2Buffer,
    .strBufLen    = Display_UART2BUFFERSIZE
};

const Display_Config Display_config[CONFIG_Display_COUNT] = {
    /* CONFIG_DISPLAY */
    /* XDS110 UART */
    {
        .fxnTablePtr = &DisplayUart2Min_fxnTable,
        .object      = &displayUart2Object,
        .hwAttrs     = &displayUart2HWAttrs
    },
};

const uint_least8_t Display_count = CONFIG_Display_COUNT;

/*
 *  =============================== AESCCM ===============================
 */

#include <ti/drivers/AESCCM.h>
#include <ti/drivers/aesccm/AESCCMCC26X4.h>

#define CONFIG_AESCCM_COUNT 1


AESCCMCC26X4_Object aesccmCC26X4Objects[CONFIG_AESCCM_COUNT];

/*
 *  ======== aesccmCC26X4HWAttrs ========
 */
const AESCCMCC26X4_HWAttrs aesccmCC26X4HWAttrs[CONFIG_AESCCM_COUNT] = {
    {
        .intPriority = (~0),
    },
};

const AESCCM_Config AESCCM_config[CONFIG_AESCCM_COUNT] = {
    {   /* CONFIG_AESCCM_0 */
        .object  = &aesccmCC26X4Objects[CONFIG_AESCCM_0],
        .hwAttrs = &aesccmCC26X4HWAttrs[CONFIG_AESCCM_0]
    },
};

const uint_least8_t CONFIG_AESCCM_0_CONST = CONFIG_AESCCM_0;
const uint_least8_t AESCCM_count = CONFIG_AESCCM_COUNT;

/*
 *  =============================== DMA ===============================
 */

#include <ti/drivers/dma/UDMACC26XX.h>
#include <ti/devices/cc13x4_cc26x4/driverlib/udma.h>
#include <ti/devices/cc13x4_cc26x4/inc/hw_memmap.h>

UDMACC26XX_Object udmaCC26XXObject;

const UDMACC26XX_HWAttrs udmaCC26XXHWAttrs = {
    .baseAddr        = UDMA0_BASE,
    .powerMngrId     = PowerCC26XX_PERIPH_UDMA,
    .intNum          = INT_DMA_ERR,
    .intPriority     = (~0)
};

const UDMACC26XX_Config UDMACC26XX_config[1] = {
    {
        .object         = &udmaCC26XXObject,
        .hwAttrs        = &udmaCC26XXHWAttrs,
    },
};

/*
 *  =============================== GPIO ===============================
 */

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOCC26XX.h>

/* The range of pins available on this device */
const uint_least8_t GPIO_pinLowerBound = 1;
const uint_least8_t GPIO_pinUpperBound = 47;

/*
 *  ======== gpioPinConfigs ========
 *  Array of Pin configurations
 */
GPIO_PinConfig gpioPinConfigs[48] = {
    0, /* Pin is not available on this device */
    GPIO_CFG_NO_DIR, /* DIO_1 */
    /* Owned by CONFIG_DISPLAY_UART as RX */
    GPIO_CFG_INPUT_INTERNAL | GPIO_CFG_IN_INT_NONE | GPIO_CFG_PULL_DOWN_INTERNAL, /* CONFIG_GPIO_DISPLAY_UART_RX */
    /* Owned by CONFIG_DISPLAY_UART as TX */
    GPIO_CFG_OUTPUT_INTERNAL | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_HIGH, /* CONFIG_GPIO_DISPLAY_UART_TX */
    GPIO_CFG_OUTPUT_INTERNAL | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW, /* CONFIG_GPIO_RST */
    GPIO_CFG_OUTPUT_INTERNAL | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW, /* CONFIG_GPIO_DC */
    /* Owned by CONFIG_LED_RED as LED GPIO */
    GPIO_CFG_OUTPUT_INTERNAL | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW, /* CONFIG_GPIO_RLED */
    /* Owned by CONFIG_LED_GREEN as LED GPIO */
    GPIO_CFG_OUTPUT_INTERNAL | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW, /* CONFIG_GPIO_GLED */
    /* Owned by CONFIG_SPI_LCD as POCI */
    GPIO_CFG_INPUT_INTERNAL | GPIO_CFG_IN_INT_NONE | GPIO_CFG_PULL_NONE_INTERNAL, /* CONFIG_GPIO_SPI_LCD_POCI */
    /* Owned by CONFIG_SPI_LCD as PICO */
    GPIO_CFG_OUTPUT_INTERNAL | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW, /* CONFIG_GPIO_SPI_LCD_PICO */
    /* Owned by CONFIG_SPI_LCD as SCLK */
    GPIO_CFG_OUTPUT_INTERNAL | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW, /* CONFIG_GPIO_SPI_LCD_SCLK */
    GPIO_CFG_NO_DIR, /* DIO_11 */
    GPIO_CFG_NO_DIR, /* DIO_12 */
    GPIO_CFG_NO_DIR, /* DIO_13 */
    /* Owned by BTN_UP as Button GPIO */
    GPIO_CFG_INPUT_INTERNAL | GPIO_CFG_IN_INT_NONE | GPIO_CFG_PULL_NONE_INTERNAL, /* CONFIG_GPIO_BTN_UP_INPUT */
    /* Owned by BTN_DWN as Button GPIO */
    GPIO_CFG_INPUT_INTERNAL | GPIO_CFG_IN_INT_NONE | GPIO_CFG_PULL_NONE_INTERNAL, /* CONFIG_GPIO_BTN_DWN_INPUT */
    /* Owned by BTN_ENTR as Button GPIO */
    GPIO_CFG_INPUT_INTERNAL | GPIO_CFG_IN_INT_NONE | GPIO_CFG_PULL_NONE_INTERNAL, /* CONFIG_GPIO_BTN_ENTR_INPUT */
    /* Owned by BTN_EXIT as Button GPIO */
    GPIO_CFG_INPUT_INTERNAL | GPIO_CFG_IN_INT_NONE | GPIO_CFG_PULL_NONE_INTERNAL, /* CONFIG_GPIO_BTN_EXIT_INPUT */
    GPIO_CFG_NO_DIR, /* DIO_18 */
    GPIO_CFG_NO_DIR, /* DIO_19 */
    GPIO_CFG_NO_DIR, /* DIO_20 */
    GPIO_CFG_NO_DIR, /* DIO_21 */
    GPIO_CFG_NO_DIR, /* DIO_22 */
    GPIO_CFG_NO_DIR, /* DIO_23 */
    GPIO_CFG_NO_DIR, /* DIO_24 */
    GPIO_CFG_NO_DIR, /* DIO_25 */
    GPIO_CFG_NO_DIR, /* DIO_26 */
    GPIO_CFG_NO_DIR, /* DIO_27 */
    GPIO_CFG_NO_DIR, /* DIO_28 */
    GPIO_CFG_NO_DIR, /* DIO_29 */
    GPIO_CFG_NO_DIR, /* DIO_30 */
    GPIO_CFG_NO_DIR, /* DIO_31 */
    GPIO_CFG_NO_DIR, /* DIO_32 */
    GPIO_CFG_NO_DIR, /* DIO_33 */
    GPIO_CFG_NO_DIR, /* DIO_34 */
    GPIO_CFG_NO_DIR, /* DIO_35 */
    GPIO_CFG_NO_DIR, /* DIO_36 */
    GPIO_CFG_NO_DIR, /* DIO_37 */
    GPIO_CFG_NO_DIR, /* DIO_38 */
    GPIO_CFG_NO_DIR, /* DIO_39 */
    GPIO_CFG_NO_DIR, /* DIO_40 */
    GPIO_CFG_NO_DIR, /* DIO_41 */
    GPIO_CFG_NO_DIR, /* DIO_42 */
    GPIO_CFG_NO_DIR, /* DIO_43 */
    GPIO_CFG_NO_DIR, /* DIO_44 */
    GPIO_CFG_NO_DIR, /* DIO_45 */
    GPIO_CFG_NO_DIR, /* DIO_46 */
    GPIO_CFG_NO_DIR, /* DIO_47 */
};

/*
 *  ======== gpioCallbackFunctions ========
 *  Array of callback function pointers
 *  Change at runtime with GPIO_setCallback()
 */
GPIO_CallbackFxn gpioCallbackFunctions[48];

/*
 *  ======== gpioUserArgs ========
 *  Array of user argument pointers
 *  Change at runtime with GPIO_setUserArg()
 *  Get values with GPIO_getUserArg()
 */
void* gpioUserArgs[48];

const uint_least8_t CONFIG_GPIO_RST_CONST = CONFIG_GPIO_RST;
const uint_least8_t CONFIG_GPIO_DC_CONST = CONFIG_GPIO_DC;
const uint_least8_t CONFIG_GPIO_SPI_LCD_SCLK_CONST = CONFIG_GPIO_SPI_LCD_SCLK;
const uint_least8_t CONFIG_GPIO_SPI_LCD_POCI_CONST = CONFIG_GPIO_SPI_LCD_POCI;
const uint_least8_t CONFIG_GPIO_SPI_LCD_PICO_CONST = CONFIG_GPIO_SPI_LCD_PICO;
const uint_least8_t CONFIG_GPIO_DISPLAY_UART_TX_CONST = CONFIG_GPIO_DISPLAY_UART_TX;
const uint_least8_t CONFIG_GPIO_DISPLAY_UART_RX_CONST = CONFIG_GPIO_DISPLAY_UART_RX;
const uint_least8_t CONFIG_GPIO_BTN_DWN_INPUT_CONST = CONFIG_GPIO_BTN_DWN_INPUT;
const uint_least8_t CONFIG_GPIO_BTN_UP_INPUT_CONST = CONFIG_GPIO_BTN_UP_INPUT;
const uint_least8_t CONFIG_GPIO_BTN_ENTR_INPUT_CONST = CONFIG_GPIO_BTN_ENTR_INPUT;
const uint_least8_t CONFIG_GPIO_BTN_EXIT_INPUT_CONST = CONFIG_GPIO_BTN_EXIT_INPUT;
const uint_least8_t CONFIG_GPIO_RLED_CONST = CONFIG_GPIO_RLED;
const uint_least8_t CONFIG_GPIO_GLED_CONST = CONFIG_GPIO_GLED;

/*
 *  ======== GPIO_config ========
 */
const GPIO_Config GPIO_config = {
    .configs = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .userArgs = gpioUserArgs,
    .intPriority = (~0)
};

/*
 *  =============================== NVS ===============================
 */

#include <ti/drivers/NVS.h>
#include <ti/drivers/nvs/NVSCC26XX.h>

/*
 *  NVSCC26XX Internal NVS flash region definitions
 *
 * Place uninitialized char arrays at addresses
 * corresponding to the 'regionBase' addresses defined in
 * the configured NVS regions. These arrays are used as
 * place holders so that the linker will not place other
 * content there.
 *
 * For GCC targets, the char arrays are each placed into
 * the shared ".nvs" section. The user must add content to
 * their GCC linker command file to place the .nvs section
 * at the lowest 'regionBase' address specified in their NVS
 * regions.
 */

#if defined(__TI_COMPILER_VERSION__) || defined(__clang__)

static char flashBuf0[0x4000] __attribute__ ((retain, noinit, location(0x52000)));

#elif defined(__IAR_SYSTEMS_ICC__)

__no_init static char flashBuf0[0x4000] @ 0x52000;

#elif defined(__GNUC__)

__attribute__ ((section (".nvs")))
static char flashBuf0[0x4000];

#endif

NVSCC26XX_Object nvsCC26XXObjects[1];

static const NVSCC26XX_HWAttrs nvsCC26XXHWAttrs[1] = {
    /* CONFIG_NVSINTERNAL */
    {
        .regionBase = (void *) flashBuf0,
        .regionSize = 0x4000
    },
};

#define CONFIG_NVS_COUNT 1

const NVS_Config NVS_config[CONFIG_NVS_COUNT] = {
    /* CONFIG_NVSINTERNAL */
    {
        .fxnTablePtr = &NVSCC26XX_fxnTable,
        .object = &nvsCC26XXObjects[0],
        .hwAttrs = &nvsCC26XXHWAttrs[0],
    },
};

const uint_least8_t CONFIG_NVSINTERNAL_CONST = CONFIG_NVSINTERNAL;
const uint_least8_t NVS_count = CONFIG_NVS_COUNT;

/*
 *  =============================== Power ===============================
 */
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26X2.h>
#include "ti_drivers_config.h"

extern void PowerCC26XX_standbyPolicy(void);
extern bool PowerCC26XX_calibrate(unsigned int);

const PowerCC26X2_Config PowerCC26X2_config = {
    .enablePolicy             = true,
    .policyInitFxn            = NULL,
    .policyFxn                = PowerCC26XX_standbyPolicy,
    .calibrateFxn             = PowerCC26XX_calibrate,
    .calibrateRCOSC_LF        = true,
    .calibrateRCOSC_HF        = true,
    .enableTCXOFxn            = NULL
};



/*
 *  =============================== RF Driver ===============================
 */
#include <ti/drivers/GPIO.h>
#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/ioc.h)
#include <ti/drivers/rf/RF.h>

/*
 * Platform-specific driver configuration
 */
const RFCC26XX_HWAttrsV2 RFCC26XX_hwAttrs = {
    .hwiPriority        = (~0),
    .swiPriority        = (uint8_t)0,
    .xoscHfAlwaysNeeded = true,
    .globalCallback     = NULL,
    .globalEventMask    = 0
};


/*
 *  =============================== SPI DMA ===============================
 */
#include <ti/drivers/SPI.h>
#include <ti/drivers/spi/SPICC26X4DMA.h>
#include <ti/drivers/dma/UDMACC26XX.h>

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/ioc.h)

#define CONFIG_SPI_COUNT 1

/*
 *  ======== spiCC26X4DMAObjects ========
 */
SPICC26X4DMA_Object spiCC26X4DMAObjects[CONFIG_SPI_COUNT];

/*
 * ======== spiCC26X4DMA uDMA Table Entries  ========
 */
ALLOCATE_CONTROL_TABLE_ENTRY(dmaSpi0TxControlTableEntry, UDMA_CHAN_SPI0_TX);
ALLOCATE_CONTROL_TABLE_ENTRY(dmaSpi0RxControlTableEntry, UDMA_CHAN_SPI0_RX);
ALLOCATE_CONTROL_TABLE_ENTRY(dmaSpi0TxAltControlTableEntry, (UDMA_CHAN_SPI0_TX | UDMA_ALT_SELECT));
ALLOCATE_CONTROL_TABLE_ENTRY(dmaSpi0RxAltControlTableEntry, (UDMA_CHAN_SPI0_RX | UDMA_ALT_SELECT));


/*
 *  ======== spiCC26X4DMAHWAttrs ========
 */
const SPICC26X4DMA_HWAttrs spiCC26X4DMAHWAttrs[CONFIG_SPI_COUNT] = {
    /* CONFIG_SPI_LCD */
    /* LaunchPad SPI Bus */
    {
        .baseAddr = SPI0_BASE,
        .intNum = INT_SPI0_COMB,
        .intPriority = (~0),
        .swiPriority = 0,
        .powerMngrId = PowerCC26XX_PERIPH_SSI0,
        .defaultTxBufValue = 0,
        .rxChannelBitMask = 1<<UDMA_CHAN_SPI0_RX,
        .txChannelBitMask = 1<<UDMA_CHAN_SPI0_TX,
        .dmaTxTableEntryPri = &dmaSpi0TxControlTableEntry,
        .dmaRxTableEntryPri = &dmaSpi0RxControlTableEntry,
        .dmaTxTableEntryAlt = &dmaSpi0TxAltControlTableEntry,
        .dmaRxTableEntryAlt = &dmaSpi0RxAltControlTableEntry,
        .minDmaTransferSize = 1,
        .txPinMux    = IOC_PORT_MCU_SPI0_TX,
        .rxPinMux    = IOC_PORT_MCU_SPI0_RX,
        .clkPinMux   = IOC_PORT_MCU_SPI0_CLK,
        .csnPinMux   = IOC_PORT_MCU_SPI0_FSS,
        .picoPin = CONFIG_GPIO_SPI_LCD_PICO,
        .pociPin = CONFIG_GPIO_SPI_LCD_POCI,
        .clkPin  = CONFIG_GPIO_SPI_LCD_SCLK,
        .csnPin  = GPIO_INVALID_INDEX
    },
};

/*
 *  ======== SPI_config ========
 */
const SPI_Config SPI_config[CONFIG_SPI_COUNT] = {
    /* CONFIG_SPI_LCD */
    /* LaunchPad SPI Bus */
    {
        .fxnTablePtr = &SPICC26X4DMA_fxnTable,
        .object = &spiCC26X4DMAObjects[CONFIG_SPI_LCD],
        .hwAttrs = &spiCC26X4DMAHWAttrs[CONFIG_SPI_LCD]
    },
};

const uint_least8_t CONFIG_SPI_LCD_CONST = CONFIG_SPI_LCD;
const uint_least8_t SPI_count = CONFIG_SPI_COUNT;

/*
 *  =============================== Timer ===============================
 */

#include <ti/drivers/Timer.h>
#include <ti/drivers/timer/TimerCC26XX.h>

#define CONFIG_TIMER_COUNT 1

/*
 *  ======== timerCC26XXObjects ========
 */
TimerCC26XX_Object timerCC26XXObjects[CONFIG_TIMER_COUNT];

/*
 *  ======== timerCC26XXHWAttrs ========
 */
const TimerCC26XX_HWAttrs timerCC26XXHWAttrs[CONFIG_TIMER_COUNT] = {
    {
        .gpTimerUnit = CONFIG_TIMER_0_GP,
        .subTimer    = TimerCC26XX_timer32

    },
};

/*
 *  ======== Timer_config ========
 */
const Timer_Config Timer_config[CONFIG_TIMER_COUNT] = {
    /* CONFIG_TIMER_0 */
    {
        .object    = &timerCC26XXObjects[CONFIG_TIMER_0],
        .hwAttrs   = &timerCC26XXHWAttrs[CONFIG_TIMER_0]
    },
};

const uint_least8_t CONFIG_TIMER_0_CONST = CONFIG_TIMER_0;
const uint_least8_t Timer_count = CONFIG_TIMER_COUNT;

/*
 *  =============================== UART2 ===============================
 */

#include <ti/drivers/UART2.h>
#include <ti/drivers/uart2/UART2CC26X2.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/dma/UDMACC26XX.h>
#include <ti/drivers/power/PowerCC26X2.h>
#include <ti/devices/cc13x4_cc26x4/driverlib/ioc.h>
#include <ti/devices/cc13x4_cc26x4/inc/hw_memmap.h>
#include <ti/devices/cc13x4_cc26x4/inc/hw_ints.h>

#define CONFIG_UART2_COUNT 1

UART2CC26X2_Object uart2CC26X2Objects[CONFIG_UART2_COUNT];

static unsigned char uart2RxRingBuffer0[32];
/* TX ring buffer allocated to be used for nonblocking mode */
static unsigned char uart2TxRingBuffer0[32];

ALLOCATE_CONTROL_TABLE_ENTRY(dmaUart1RxControlTableEntry, UDMA_CHAN_UART1_RX);
ALLOCATE_CONTROL_TABLE_ENTRY(dmaUart1TxControlTableEntry, UDMA_CHAN_UART1_TX);

static const UART2CC26X2_HWAttrs uart2CC26X2HWAttrs[CONFIG_UART2_COUNT] = {
  {
    .baseAddr           = UART1_BASE,
    .intNum             = INT_UART1_COMB,
    .intPriority        = (~0),
    .rxPin              = CONFIG_GPIO_DISPLAY_UART_RX,
    .txPin              = CONFIG_GPIO_DISPLAY_UART_TX,
    .ctsPin             = GPIO_INVALID_INDEX,
    .rtsPin             = GPIO_INVALID_INDEX,
    .flowControl        = UART2_FLOWCTRL_NONE,
    .powerId            = PowerCC26XX_PERIPH_UART1,
    .rxBufPtr           = uart2RxRingBuffer0,
    .rxBufSize          = sizeof(uart2RxRingBuffer0),
    .txBufPtr           = uart2TxRingBuffer0,
    .txBufSize          = sizeof(uart2TxRingBuffer0),
    .txPinMux           = IOC_PORT_MCU_UART1_TX,
    .rxPinMux           = IOC_PORT_MCU_UART1_RX,
    .ctsPinMux          = IOC_PORT_MCU_UART1_CTS,
    .rtsPinMux          = IOC_PORT_MCU_UART1_RTS,
    .dmaTxTableEntryPri = &dmaUart1TxControlTableEntry,
    .dmaRxTableEntryPri = &dmaUart1RxControlTableEntry,
    .rxChannelMask      = 1 << UDMA_CHAN_UART1_RX,
    .txChannelMask      = 1 << UDMA_CHAN_UART1_TX,
    .txIntFifoThr       = UART2CC26X2_FIFO_THRESHOLD_1_8,
    .rxIntFifoThr       = UART2CC26X2_FIFO_THRESHOLD_4_8
  },
};

const UART2_Config UART2_config[CONFIG_UART2_COUNT] = {
    {   /* CONFIG_DISPLAY_UART */
        .object      = &uart2CC26X2Objects[CONFIG_DISPLAY_UART],
        .hwAttrs     = &uart2CC26X2HWAttrs[CONFIG_DISPLAY_UART]
    },
};

const uint_least8_t CONFIG_DISPLAY_UART_CONST = CONFIG_DISPLAY_UART;
const uint_least8_t UART2_count = CONFIG_UART2_COUNT;


/*
 *  =============================== Button ===============================
 */
#include <ti/drivers/apps/Button.h>

#define CONFIG_BUTTON_COUNT 4
Button_Object ButtonObjects[CONFIG_BUTTON_COUNT];

static const Button_HWAttrs ButtonHWAttrs[CONFIG_BUTTON_COUNT] = {
    /* BTN_DWN */
    /* LaunchPad Button BTN-1 (Left) */
    {
        .gpioIndex = CONFIG_GPIO_BTN_DWN_INPUT,
        .pullMode = Button_PULL_UP,
        .internalPullEnabled = 1,
    },
    /* BTN_UP */
    /* LaunchPad Button BTN-2 (Right) */
    {
        .gpioIndex = CONFIG_GPIO_BTN_UP_INPUT,
        .pullMode = Button_PULL_UP,
        .internalPullEnabled = 1,
    },
    /* BTN_ENTR */
    {
        .gpioIndex = CONFIG_GPIO_BTN_ENTR_INPUT,
        .pullMode = Button_PULL_UP,
        .internalPullEnabled = 1,
    },
    /* BTN_EXIT */
    {
        .gpioIndex = CONFIG_GPIO_BTN_EXIT_INPUT,
        .pullMode = Button_PULL_UP,
        .internalPullEnabled = 1,
    },
};

const Button_Config Button_config[CONFIG_BUTTON_COUNT] = {
    /* BTN_DWN */
    /* LaunchPad Button BTN-1 (Left) */
    {
        .object = &ButtonObjects[BTN_DWN],
        .hwAttrs = &ButtonHWAttrs[BTN_DWN]
    },
    /* BTN_UP */
    /* LaunchPad Button BTN-2 (Right) */
    {
        .object = &ButtonObjects[BTN_UP],
        .hwAttrs = &ButtonHWAttrs[BTN_UP]
    },
    /* BTN_ENTR */
    {
        .object = &ButtonObjects[BTN_ENTR],
        .hwAttrs = &ButtonHWAttrs[BTN_ENTR]
    },
    /* BTN_EXIT */
    {
        .object = &ButtonObjects[BTN_EXIT],
        .hwAttrs = &ButtonHWAttrs[BTN_EXIT]
    },
};

const uint_least8_t BTN_DWN_CONST = BTN_DWN;
const uint_least8_t BTN_UP_CONST = BTN_UP;
const uint_least8_t BTN_ENTR_CONST = BTN_ENTR;
const uint_least8_t BTN_EXIT_CONST = BTN_EXIT;
const uint_least8_t Button_count = CONFIG_BUTTON_COUNT;

/*
 *  =============================== LED ===============================
 */
#include <ti/drivers/apps/LED.h>

#define CONFIG_LED_COUNT 2
LED_Object LEDObjects[CONFIG_LED_COUNT];

static const LED_HWAttrs LEDHWAttrs[CONFIG_LED_COUNT] = {
    /* CONFIG_LED_RED */
    /* LaunchPad LED Red */
    {
        .type = LED_GPIO_CONTROLLED,
        .index = CONFIG_GPIO_RLED,
    },
    /* CONFIG_LED_GREEN */
    /* LaunchPad LED Green */
    {
        .type = LED_GPIO_CONTROLLED,
        .index = CONFIG_GPIO_GLED,
    },
};

const LED_Config LED_config[CONFIG_LED_COUNT] = {
    /* CONFIG_LED_RED */
    /* LaunchPad LED Red */
    {
        .object = &LEDObjects[CONFIG_LED_RED],
        .hwAttrs = &LEDHWAttrs[CONFIG_LED_RED]
    },
    /* CONFIG_LED_GREEN */
    /* LaunchPad LED Green */
    {
        .object = &LEDObjects[CONFIG_LED_GREEN],
        .hwAttrs = &LEDHWAttrs[CONFIG_LED_GREEN]
    },
};

const uint_least8_t CONFIG_LED_RED_CONST = CONFIG_LED_RED;
const uint_least8_t CONFIG_LED_GREEN_CONST = CONFIG_LED_GREEN;
const uint_least8_t LED_count = CONFIG_LED_COUNT;

/*
 *  =============================== GPTimer ===============================
 */

#include <ti/drivers/timer/GPTimerCC26XX.h>
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/devices/cc13x4_cc26x4/inc/hw_memmap.h>
#include <ti/devices/cc13x4_cc26x4/inc/hw_ints.h>

#define CONFIG_GPTIMER_COUNT 1

/*
 *  ======== gptimerCC26XXObjects ========
 */
GPTimerCC26XX_Object gptimerCC26XXObjects[CONFIG_GPTIMER_COUNT];

/*
 *  ======== gptimerCC26XXHWAttrs ========
 */
const GPTimerCC26XX_HWAttrs gptimerCC26XXHWAttrs[CONFIG_GPTIMER_COUNT] = {
    /* CONFIG_TIMER_0_GP, used by CONFIG_TIMER_0 */
    {
        .baseAddr = GPT0_BASE,
        .intNum      = INT_GPT0A,
        .intPriority = (~0),
        .powerMngrId = PowerCC26XX_PERIPH_GPT0,
        .pinMux      = GPT_PIN_0A
    },
};

/*
 *  ======== GPTimer_config ========
 */
const GPTimerCC26XX_Config GPTimerCC26XX_config[CONFIG_GPTIMER_COUNT] = {
    /* CONFIG_TIMER_0_GP */
    {
        .object    = &gptimerCC26XXObjects[CONFIG_TIMER_0_GP],
        .hwAttrs   = &gptimerCC26XXHWAttrs[CONFIG_TIMER_0_GP],
        .timerPart = GPT_A
    },
};

const uint_least8_t CONFIG_TIMER_0_GP_CONST = CONFIG_TIMER_0_GP;
const uint_least8_t GPTimer_count = CONFIG_GPTIMER_COUNT;

#include <stdbool.h>

#include <ti/devices/cc13x4_cc26x4/driverlib/ioc.h>
#include <ti/devices/cc13x4_cc26x4/driverlib/cpu.h>

#include <ti/drivers/GPIO.h>

/* Board GPIO defines */
#define BOARD_EXT_FLASH_SPI_CS      38
#define BOARD_EXT_FLASH_SPI_CLK     39
#define BOARD_EXT_FLASH_SPI_PICO    36
#define BOARD_EXT_FLASH_SPI_POCI    37


/*
 *  ======== Board_sendExtFlashByte ========
 */
void Board_sendExtFlashByte(uint8_t byte)
{
    uint8_t i;

    /* SPI Flash CS */
    GPIO_write(BOARD_EXT_FLASH_SPI_CS, 0);

    for (i = 0; i < 8; i++) {
        GPIO_write(BOARD_EXT_FLASH_SPI_CLK, 0); /* SPI Flash CLK */

        /* SPI Flash PICO */
        GPIO_write(BOARD_EXT_FLASH_SPI_PICO, (byte >> (7 - i)) & 0x01);
        GPIO_write(BOARD_EXT_FLASH_SPI_CLK, 1);  /* SPI Flash CLK */

        /*
         * Waste a few cycles to keep the CLK high for at
         * least 45% of the period.
         * 3 cycles per loop: 8 loops @ 48 Mhz = 0.5 us.
         */
        CPUdelay(8);
    }

    GPIO_write(BOARD_EXT_FLASH_SPI_CLK, 0);  /* CLK */
    GPIO_write(BOARD_EXT_FLASH_SPI_CS, 1);  /* CS */

    /*
     * Keep CS high at least 40 us
     * 3 cycles per loop: 700 loops @ 48 Mhz ~= 44 us
     */
    CPUdelay(700);
}

/*
 *  ======== Board_wakeUpExtFlash ========
 */
void Board_wakeUpExtFlash(void)
{
    /* SPI Flash CS*/
    GPIO_setConfig(BOARD_EXT_FLASH_SPI_CS, GPIO_CFG_OUTPUT | GPIO_CFG_OUT_HIGH | GPIO_CFG_OUT_STR_MED);

    /*
     *  To wake up we need to toggle the chip select at
     *  least 20 ns and ten wait at least 35 us.
     */

    /* Toggle chip select for ~20ns to wake ext. flash */
    GPIO_write(BOARD_EXT_FLASH_SPI_CS, 0);
    /* 3 cycles per loop: 1 loop @ 48 Mhz ~= 62 ns */
    CPUdelay(1);
    GPIO_write(BOARD_EXT_FLASH_SPI_CS, 1);
    /* 3 cycles per loop: 560 loops @ 48 Mhz ~= 35 us */
    CPUdelay(560);
}

/*
 *  ======== Board_shutDownExtFlash ========
 */
void Board_shutDownExtFlash(void)
{
    /*
     *  To be sure we are putting the flash into sleep and not waking it,
     *  we first have to make a wake up call
     */
    Board_wakeUpExtFlash();

    /* SPI Flash CS*/
    GPIO_setConfig(BOARD_EXT_FLASH_SPI_CS, GPIO_CFG_OUTPUT | GPIO_CFG_OUT_HIGH | GPIO_CFG_OUT_STR_MED);
    /* SPI Flash CLK */
    GPIO_setConfig(BOARD_EXT_FLASH_SPI_CLK, GPIO_CFG_OUTPUT | GPIO_CFG_OUT_LOW | GPIO_CFG_OUT_STR_MED);
    /* SPI Flash PICO */
    GPIO_setConfig(BOARD_EXT_FLASH_SPI_PICO, GPIO_CFG_OUTPUT | GPIO_CFG_OUT_LOW | GPIO_CFG_OUT_STR_MED);
    /* SPI Flash POCI */
    GPIO_setConfig(BOARD_EXT_FLASH_SPI_POCI, GPIO_CFG_IN_PD);

    uint8_t extFlashShutdown = 0xB9;

    Board_sendExtFlashByte(extFlashShutdown);

    GPIO_resetConfig(BOARD_EXT_FLASH_SPI_CS);
    GPIO_resetConfig(BOARD_EXT_FLASH_SPI_CLK);
    GPIO_resetConfig(BOARD_EXT_FLASH_SPI_PICO);
    GPIO_resetConfig(BOARD_EXT_FLASH_SPI_POCI);
}


#include <ti/drivers/Board.h>

/*
 *  ======== Board_initHook ========
 *  Perform any board-specific initialization needed at startup.  This
 *  function is declared weak to allow applications to override it if needed.
 */
void __attribute__((weak)) Board_initHook(void)
{
}

/*
 *  ======== Board_init ========
 *  Perform any initialization needed before using any board APIs
 */
void Board_init(void)
{
    /* ==== /ti/drivers/Power initialization ==== */
    Power_init();

    /* ==== /ti/devices/CCFG initialization ==== */

    /* ==== /ti/drivers/GPIO initialization ==== */
    /* Setup GPIO module and default-initialise pins */
    GPIO_init();

    /* ==== /ti/drivers/RF initialization ==== */


    Board_shutDownExtFlash();

    Board_initHook();
}

