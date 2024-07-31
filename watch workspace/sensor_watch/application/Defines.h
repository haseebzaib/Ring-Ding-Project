/*
 * Defines.h
 *
 *  Created on: Jul 24, 2024
 *      Author: hzaib
 */

#ifndef APPLICATION_DEFINES_H_
#define APPLICATION_DEFINES_H_


#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Mailbox.h>
#include "api_mac.h"
#define TYPEDEF_STRUCT_PACKED        typedef struct __attribute__((__packed__))
#define CLOCK_US(us) ((us * 1)      / Clock_tickPeriod)
#define CLOCK_MS(ms) ((ms * 1000)   / Clock_tickPeriod)
#define CLOCK_S(s)   ((s * 1000000) / Clock_tickPeriod)

extern int gmt;


extern  uint32_t devInfoConfirmationTimer;
extern  uint8_t devInfoConfirmationFlag;
extern  uint8_t devInfoConfirmationMail;

typedef enum{

    OK = 0,
    ERROR = 1,
}status;

/*Collector Task Parameters*/

extern Task_Struct sensorTask;        /* not static so you can see in ROV */
extern Task_Params sensorTaskParam;
#define sensorTaskStackSize  (2*1024)
extern uint8_t sensorTaskStack[sensorTaskStackSize];
#define sensorTaskPriority  1

/*Control Task*/
extern Task_Struct controlTask;        /* not static so you can see in ROV */
extern Task_Params controlTaskParam;
#define controlTaskStackSize  (5*1024)
extern uint8_t controlTaskStack[controlTaskStackSize];
#define controlTaskPriority  3

extern Mailbox_Params control_task_InfoToHub_params;
extern Mailbox_Handle control_task_InfoToHub_handle;

/*Display Task*/
extern Task_Struct displayTask;        /* not static so you can see in ROV */
extern Task_Params displayTaskParam;
#define displayTaskStackSize  (2*1024)
extern uint8_t displayTaskStack[controlTaskStackSize];
#define displayTaskPriority  4


extern ApiMac_sAddr_t collectorAddr_app ;


enum
{
    main_menu_ = 1,

}menu_number;

//typedef enum
//{
//    //c denotes as an identifier for that button code
//    cNONE=0,
//    cEnter_BT=10,
//    cESC_BT=20,
//    cUP_BT=30,
//    cDWN_BT=40,
//    cRGHT_BT=50,
//    cLFT_BT=60,
//    cSub_menu=70,
//}button_codes;

extern char network_info[20];
extern void display_taskInit();


#endif /* APPLICATION_DEFINES_H_ */