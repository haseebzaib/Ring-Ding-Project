/* RTOS header files */

#include <ti/sysbios/BIOS.h>

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
#include <ti/sysbios/knl/Mailbox.h>
#include "Defines.h"
/* Header files required to enable instruction fetch cache */
#include <ti/drivers/dpl/HwiP.h>

#include "cpu.h"
#include "collector.h"

#include <string.h>


#include "control_task.h"
#include "console.h"
#include "embedded_cli.h"
#include "csf.h"
#include "par.h"
#include "time_clock.h"
#include "utc_clock.h"
#include "mac_util.h"
int32_t gmt = 5;
uint8_t gmt_zone = 18;

void onClearCLI(EmbeddedCli *cli, char *args, void *context) {
    cli_printf(cli, "\33[2J");
}

void onFormNWK(EmbeddedCli *cli, char *args, void *context)
{
    const char *network = "Form Network";
    const char *newLine = "\r\n";

    cli_printf(cli, network);

    Csf_CLI_formnetwork();
}

void onOpenNWK(EmbeddedCli *cli, char *args, void *context)
{
    const char *network = "Open Network";
    const char *newLine = "\r\n";


    cli_printf(cli, network);

    Csf_CLI_opennetwork();
}

void onCloseNWK(EmbeddedCli *cli, char *args, void *context)
{
    const char *network = "Close Network";
    const char *newLine = "\r\n";
    cli_printf(cli, network);
    Csf_CLI_closenetwork();
}

void allDevicesInNetwork(EmbeddedCli *cli, char *args, void *context)
{


    for(int i=0; i<CONFIG_MAX_DEVICES*2; i++)
    {
        if(control_task_dev_info[i].structValid == 0xBEEF)
        {
            cli_printf(cli, "_____________________________");
            cli_printf(cli, "Index: %d",i);
            cli_printf(cli, "Dev Addr: %d",control_task_dev_info[i].dev_shortAddr );
            cli_printf(cli, "Dev signature: 0x%x",control_task_dev_info[i].dev_signature);
            if(control_task_dev_info[i].isWatch)
            {
                cli_printf(cli, "Watch");
            }
            else if(control_task_dev_info[i].isDing)
            {
                cli_printf(cli, "Ding");
            }
            else if(control_task_dev_info[i].isManager)
            {
                cli_printf(cli, "Manager");
            }

        }

    }





}


void eraseDevInfo(EmbeddedCli *cli, char *args, void *context)
{
    par_erase(device_info);
    cli_printf(cli, "Device Info Erased");


}


void setTime(EmbeddedCli *cli, char *args, void *context)
{
    setTimeEpoch();
}


 void displayTime(EmbeddedCli *cli, char *args, void *context)
{
     uint32_t time =UTC_getClock();
     UTCTimeStruct tm;
     EPOCH_convertTime(&tm,time,gmt);
     static char print_str[300];
     uint16_t res_len = 0;

     cli_printf(cli," Time Stamp: %d-%d-%d %dH %dM %dS ", tm.day, tm.month, tm.year, tm.hour, tm.minutes, tm.seconds);

}

 void setWatchsTime(EmbeddedCli *cli, char *args, void *context)
 {
     cli_printf(cli, "Sending Time to all the watches in the network");

     Util_setEvent(&Collector_events, COLLECTOR_SENSOR_SEND_EPOCH_TIME);

 }