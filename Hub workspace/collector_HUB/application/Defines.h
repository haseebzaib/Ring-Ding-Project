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
#include "ti_drivers_config.h"
#include <ti/sysbios/knl/Mailbox.h>
#define true 1
#define false 0

 #define TYPEDEF_STRUCT_PACKED        typedef struct __attribute__((__packed__))

#define CLOCK_US(us) ((us * 1)      / Clock_tickPeriod)
#define CLOCK_MS(ms) ((ms * 1000)   / Clock_tickPeriod)
#define CLOCK_S(s)   ((s * 1000000) / Clock_tickPeriod)


typedef enum{

    OK = 0,
    ERROR = 1,
}status;


typedef enum
{
    //c denotes as an identifier for that button code
    cCALL = 0,
    cWATER = 1,
    cORDER = 2,
    cBILL = 3,
    cNONE = 4,
}button_codes;


/*Collector Task Parameters*/

extern Task_Struct collectorTask;        /* not static so you can see in ROV */
extern Task_Params collectorTaskParam;
#define collectorTaskStackSize  (2*1024)
extern uint8_t collectorTaskStack[collectorTaskStackSize];
#define collectorTaskPriority  1


/*Control Task*/
extern Task_Struct controlTask;        /* not static so you can see in ROV */
extern Task_Params controlTaskParam;
#define controlTaskStackSize  (5*1024)
extern uint8_t controlTaskStack[controlTaskStackSize];
#define controlTaskPriority  3

extern Mailbox_Params control_task_joinedDev_mail_params;
extern Mailbox_Handle control_task_joinedDev_mail_handle;

extern Mailbox_Params control_task_DevInfo_mail_params;
extern Mailbox_Handle control_task_DevInfo_mail_handle;


extern Mailbox_Params control_task_NotiInfo_params;
extern Mailbox_Handle control_task_NotiInfo_handle;


/*Console Task*/
extern Task_Struct consoleTask;        /* not static so you can see in ROV */
extern Task_Params consoleTaskParam;
#define consoleTaskStackSize  (5*1024)
extern uint8_t consoleTaskStack[consoleTaskStackSize];
#define consoleTaskPriority  5

#endif /* APPLICATION_DEFINES_H_ */
