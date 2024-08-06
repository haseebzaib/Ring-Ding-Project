/*
 * control_task.c
 *
 *  Created on: Jul 25, 2024
 *      Author: hzaib
 */


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
#include <stdio.h>
#include <string.h>
#include "smsgs.h"
#include "api_mac.h"
#include "control_task.h"
#include "console.h"
#include "mac_util.h"
#include "par.h"
#include "time_clock.h"
#include "utc_clock.h"


Task_Struct controlTask;
Task_Params controlTaskParam;
 uint8_t controlTaskStack[controlTaskStackSize];

 Mailbox_Params control_task_joinedDev_mail_params;
 Mailbox_Handle control_task_joinedDev_mail_handle = NULL;

 Mailbox_Params control_task_DevInfo_mail_params;
 Mailbox_Handle control_task_DevInfo_mail_handle = NULL;

 Mailbox_Params control_task_NotiInfo_params;
 Mailbox_Handle control_task_NotiInfo_handle= NULL;


 control_task_joinedDev_mail joinedDev_mail;
  control_task_devices_info DevInfomail;




 control_task_devices_info control_task_dev_info[CONFIG_MAX_DEVICES*2];
 control_task_devices_pairing control_task_devPairing[CONFIG_MAX_DEVICES*2];


  typedef union {
     uint8_t B[4];
     uint32_t L;
  }bit32_4_8bits;

  bit32_4_8bits macAddrLsb;
  bit32_4_8bits macAddrMsb;


  typedef union {

      uint8_t B[2];
      uint16_t L;
  }bit16_2_8bits;


  bit16_2_8bits conv;


  bit16_2_8bits conv_notiinfo;


  uint8_t save_par = 0;
  /*Static variable */

  static control_task_CallButtonNotification_Info NotiInfo_mail;
  static control_task_Sendnotification_info SendNotiInfo;


 static uint16_t Num_MsgJoinedDevMail = 0;
 static uint16_t Num_MsgDevInfoMail = 0;
 static uint16_t Num_MsgNotiInfoMail = 0;

/*Function prototypes*/
 static void check_NotiInfoMail();
 static void check_devInfoMail();
static void controlTask_(uintptr_t arg1, uintptr_t arg2);


static void check_NotiInfoMail()
{
    uint16_t iteration = 0;
    uint32_t timeout = 0;
    Num_MsgNotiInfoMail = Mailbox_getNumPendingMsgs(
            control_task_NotiInfo_handle);

    if (Num_MsgNotiInfoMail > 0)
    {

        bool success = Mailbox_pend(control_task_NotiInfo_handle,
                                    &NotiInfo_mail, BIOS_WAIT_FOREVER);
        if (success)
        {
            //cli_printf(cli, " NotiReceived from %d", NotiInfo_mail.dev_shortAddr);



            /*First we check even if this button is paired with any watch in the network*/

            for (int i = 0; i < CONFIG_MAX_DEVICES * 2; i++)
             {
                if (control_task_devPairing[i].structValid == 0xBEEF)
                  {
                    /*if signature match then move forward*/
                    if (NotiInfo_mail.dev_signature == control_task_devPairing[i].Ding_Devsignature)
                    {
                        /*Now we want to find the paired watch in our device info structure and send message to it*/
                        /*Also look for manager and send message to him as well if any manager is assigned to this callbutton*/


                        SendNotiInfo.Ding_ReferenceNumber =  control_task_devPairing[i].Ding_ReferenceNumber;
                        SendNotiInfo.Watch_ReferenceNumber =  control_task_devPairing[i].Watch_ReferenceNumber;
                        SendNotiInfo.Noti_Code = NotiInfo_mail.Noti_Code;
                        for (int j = 0; j < CONFIG_MAX_DEVICES * 2; j++)
                        {

                            /*This tell us that the stuff stored in struct is valid*/
                            if(control_task_dev_info[j].structValid == 0xBEEF)
                            {
                                if(control_task_dev_info[j].dev_signature == control_task_devPairing[i].Watch_Devsignature)
                                {
                                    uint8_t buffer[6];
                                    buffer[0] = (uint8_t)Smsgs_cmdIds_SensorNotiToWatch;
                                    buffer[1] =  (uint8_t) SendNotiInfo.Noti_Code;
                                    conv_notiinfo.L = SendNotiInfo.Watch_ReferenceNumber;
                                    buffer[2] = conv_notiinfo.B[0];
                                    buffer[3] = conv_notiinfo.B[1];
                                    conv_notiinfo.L = SendNotiInfo.Ding_ReferenceNumber;
                                    buffer[4] = conv_notiinfo.B[0];
                                    buffer[5] = conv_notiinfo.B[1];

                                    //if(sendMsg(Smsgs_cmdIds_SensorNotiToWatch,control_task_dev_info[j].dev_shortAddr,false, 6, buffer);
                                  //  Task_sleep(CLOCK_MS(600));
                                    while(!sendMsg(Smsgs_cmdIds_SensorNotiToWatch,control_task_dev_info[j].dev_shortAddr,false, 6, buffer)  && timeout < 10)
                                    {
                                        Task_sleep(CLOCK_MS(100));
                                        timeout++;
                                    }
                                    timeout = 0;

                                }

                                if(control_task_dev_info[j].dev_signature == control_task_devPairing[i].Manager_Devsignature)
                                {
                                    uint8_t buffer[6];
                                    buffer[0] = (uint8_t)Smsgs_cmdIds_SensorNotiToWatch;
                                    buffer[1] =  (uint8_t) SendNotiInfo.Noti_Code;
                                    conv_notiinfo.L = SendNotiInfo.Watch_ReferenceNumber;
                                    buffer[2] = conv_notiinfo.B[0];
                                    buffer[3] = conv_notiinfo.B[1];
                                    conv_notiinfo.L = SendNotiInfo.Ding_ReferenceNumber;
                                    buffer[4] = conv_notiinfo.B[0];
                                    buffer[5] = conv_notiinfo.B[1];
                                   // Task_sleep(CLOCK_MS(600));
                                    while(!sendMsg(Smsgs_cmdIds_SensorNotiToWatch,control_task_dev_info[j].dev_shortAddr,false, 6, buffer) && timeout < 10)
                                    {
                                        Task_sleep(CLOCK_MS(100));
                                        timeout++;
                                    }

                                    timeout = 0;

                                }


                            }



                        }




                        break;

                    }

                  }


             }





        }

    }



}

static void check_devInfoMail()
{

    Num_MsgDevInfoMail = Mailbox_getNumPendingMsgs(control_task_DevInfo_mail_handle);

           if(Num_MsgDevInfoMail > 0)
           {

               bool success = Mailbox_pend(control_task_DevInfo_mail_handle,
                                           &DevInfomail,BIOS_WAIT_FOREVER);
               if(success)
               {



                   int i;
                   cli_printf(cli, " joinee: %d", DevInfomail.dev_shortAddr);
                   for( i=0; i<CONFIG_MAX_DEVICES*2; i++)
                   {
                       /*This tell us that the stuff stored in struct is valid*/
                       if(control_task_dev_info[i].structValid == 0xBEEF)
                       {
                           /*In all valid structs we also check*/
                           /*That this new struct we received did not have same dev
                            * signature as this one so we replace it and dont occupyt useless space*/

                           if(control_task_dev_info[i].dev_signature == DevInfomail.dev_signature)
                           {
                               /*This means that the same device came in with another ID*/
                               /*There could be many reason it could have wiped clean */
                               /*Disaccociate from network and joined as different ID*/
                               /*dev signature are unique to all MCU*/
                               if(control_task_dev_info[i].dev_shortAddr != DevInfomail.dev_shortAddr
                                       || control_task_dev_info[i].isWatch == DevInfomail.isDing) //this is unlikely to happen but still a good condition to have incase
                               {
                               memcpy(&control_task_dev_info[i],&DevInfomail,sizeof(control_task_devices_info)); //no need to check anything else just copy this struct
                               save_par = 1;

                               }

                               break;
                           }

                       }
                       else
                       {
                           /*we found unoccupied struct*/
                           if(DevInfomail.structValid == 0xBEEF) //first check if structure is valid
                           {
                           memcpy(&control_task_dev_info[i],&DevInfomail,sizeof(control_task_devices_info));
                           save_par = 1;
                           }

                           break; //we have stored it no need to search more

                       }
                   }

                   if(save_par == 1)
                   {
                      par_save(device_info);
                       save_par = 0;
                   }
                   joinedDev_mail.shortAddr = DevInfomail.dev_shortAddr;
                 //  Util_setEvent(&Collector_events, COLLECTOR_SENSORS_SEND_Device_Info);
                 //  Task_sleep(CLOCK_MS(500));

                   uint8_t buffer[1];
                       /* Build the message */
                       buffer[0] = (uint8_t)Smsgs_cmdIds_SensorSendDeviceInfoConfirmation;

                    sendMsg(Smsgs_cmdIds_SensorSendDeviceInfoConfirmation,
                            joinedDev_mail.shortAddr,
                            false, 1, buffer);
               }

           }
}

/*
 * Task to control features
 */
static void controlTask_(uintptr_t arg1, uintptr_t arg2)
{

    par_init();
    for(int i=0; i<CONFIG_MAX_DEVICES*2; i++)
    {
        control_task_dev_info[i].structValid = 0xFFFF;
    }

    for(int i=0; i<CONFIG_MAX_DEVICES*2; i++)
    {
        control_task_devPairing[i].structValid = 0xFFFF;
    }

   par_load(device_info);
   par_load(device_pairing);





    while(1)
    {


       check_devInfoMail();
       check_NotiInfoMail();


       Task_sleep(CLOCK_MS(200));

    }

}


/*Global Functions*/


status control_Task_Noti_Info_mail(ApiMac_mcpsDataInd_t *pDataInd)
{


    control_task_CallButtonNotification_Info mail;
    status status_ = OK;

    uint8_t *pBuf = pDataInd->msdu.p;
    Smsgs_cmdIds_t cmd = (Smsgs_cmdIds_t)*pBuf++;


    conv.B[0] = *pBuf++;
    conv.B[1] = *pBuf++;
    mail.dev_shortAddr = conv.L;
    macAddrLsb.B[0]= *pBuf++;
    macAddrLsb.B[1]= *pBuf++;
    macAddrLsb.B[2]= *pBuf++;
    macAddrLsb.B[3]= *pBuf++;
    macAddrMsb.B[0]= *pBuf++;
    macAddrMsb.B[1]= *pBuf++;
    macAddrMsb.B[2]= *pBuf++;
    macAddrMsb.B[3]= *pBuf++;
    mail.dev_signature = ((uint64_t)(macAddrMsb.L) << 32) | (uint64_t)(macAddrLsb.L);
    mail.Noti_Code = (button_codes)*pBuf;



    /*Immediately send Confirmation to Callbutton as well*/
    uint8_t buffer[2];
    buffer[0] = (uint8_t)Smsgs_cmdIds_SensorNotiConfirmation;
    buffer[1] =  (uint8_t)mail.Noti_Code;
    sendMsg(Smsgs_cmdIds_SensorNotiConfirmation,mail.dev_shortAddr,false, 2, buffer);


    if (control_task_NotiInfo_handle)
    {
        if (!Mailbox_post(control_task_NotiInfo_handle, &mail, CLOCK_MS(100)))
        {
            status_ = ERROR;
        }
    }
    else
    {
        status_ = ERROR;
    }

    return status_;
}

status control_task_mail_post_DevInfo(ApiMac_mcpsDataInd_t *pDataInd)
{
    control_task_devices_info mail;

    status status_ = OK;
    uint8_t *pBuf = pDataInd->msdu.p;
    Smsgs_cmdIds_t cmd = (Smsgs_cmdIds_t)*pBuf++;

    conv.B[0] = *pBuf++;
    conv.B[1] = *pBuf++;
    mail.dev_shortAddr = conv.L;
    macAddrLsb.B[0]= *pBuf++;
    macAddrLsb.B[1]= *pBuf++;
    macAddrLsb.B[2]= *pBuf++;
    macAddrLsb.B[3]= *pBuf++;
    macAddrMsb.B[0]= *pBuf++;
    macAddrMsb.B[1]= *pBuf++;
    macAddrMsb.B[2]= *pBuf++;
    macAddrMsb.B[3]= *pBuf++;
    mail.dev_signature = ((uint64_t)(macAddrMsb.L) << 32) | (uint64_t)(macAddrLsb.L);
    mail.isWatch = *pBuf++;
    mail.isDing = *pBuf++;
    mail.isManager = *pBuf++;
    conv.B[0] = *pBuf++;
    conv.B[1] = *pBuf++;
    mail.structValid = conv.L;


  if(control_task_DevInfo_mail_handle)
  {
      if (!Mailbox_post(control_task_DevInfo_mail_handle, &mail, CLOCK_MS(100)))
         {
          status_ = ERROR;
         }
  }
  else
  {
      status_ = ERROR;
  }




    return status_;
}

/*
 *Post mail to the control task from outside the scope
 */
status control_task_mail_post_DevJoined(uint16_t shortAdr)
{
    control_task_joinedDev_mail mail;

    status status_ = OK;

  mail.shortAddr = shortAdr;

  if(control_task_joinedDev_mail_handle)
  {
      if (!Mailbox_post(control_task_joinedDev_mail_handle, &mail, CLOCK_MS(100)))
         {
          status_ = ERROR;
         }
  }
  else
  {
      status_ = ERROR;
  }




    return status_;
}

/*
 * Initialization function
 */
void control_taskInit()
{

    Mailbox_Params_init(&control_task_joinedDev_mail_params);
    control_task_joinedDev_mail_handle = Mailbox_create(sizeof(control_task_joinedDev_mail), 50, &control_task_joinedDev_mail_params,
                                       NULL);

    Mailbox_Params_init(&control_task_DevInfo_mail_params);
    control_task_DevInfo_mail_handle = Mailbox_create(sizeof(control_task_devices_info), 50, &control_task_DevInfo_mail_params,
                                        NULL);

    Mailbox_Params_init(&control_task_NotiInfo_params);
    control_task_NotiInfo_handle = Mailbox_create(
            sizeof(control_task_CallButtonNotification_Info), 50,
            &control_task_NotiInfo_params, NULL);

    Task_Params_init(&controlTaskParam);
    controlTaskParam.stack = controlTaskStack;
    controlTaskParam.stackSize = controlTaskStackSize;
    controlTaskParam.priority = controlTaskPriority;
    Task_construct(&controlTask, controlTask_, &controlTaskParam, NULL);



}

