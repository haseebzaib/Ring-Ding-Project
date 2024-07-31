/******************************************************************************

 @file console.h

 @brief Console API

 Group: WCS LPC
 Target Device: cc13xx_cc26xx

 ******************************************************************************
 
 Copyright (c) 2016-2023, Texas Instruments Incorporated
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
#ifndef CONSOLE_H
#define CONSOLE_H

/******************************************************************************
 Includes
 *****************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include "embedded_cli.h"
 

typedef struct _cons_mail_t {
    uint8_t type;
    uint8_t *data;
} cons_mail_t ;
enum {
    CONS_PRINT_MAIL
};
#define  CONS_MAILBOX_NUMBER 1


typedef enum {
    console_debug = 0,
    console_info,
    console_flash,
    console_log,
    console_dev_info,
    console_Network_info,
    console_dev_stat,
    console_assert
}console_t;


#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
 Constants
 *****************************************************************************/
#define CON_PRINT_CONSOLE 0x0001
#define RECEIVE_BUFFER_SIZE 1024
#define XMODEM_PACKET_SIZE 128


extern EmbeddedCli *cli;

/******************************************************************************
 Typedefs
 *****************************************************************************/

/******************************************************************************
 Function Prototypes
 *****************************************************************************/

/******************************************************************************
 Externs
 *****************************************************************************/

extern int32_t gmt;
extern uint8_t gmt_zone;
/*Bindings*/
extern void onClearCLI(EmbeddedCli *cli, char *args, void *context);
extern void onFormNWK(EmbeddedCli *cli, char *args, void *context) ;
extern void onOpenNWK(EmbeddedCli *cli, char *args, void *context) ;
extern void onCloseNWK(EmbeddedCli *cli, char *args, void *context) ;
extern void allDevicesInNetwork(EmbeddedCli *cli, char *args, void *context);
extern void eraseDevInfo(EmbeddedCli *cli, char *args, void *context);
extern void setTime(EmbeddedCli *cli, char *args, void *context);
extern void displayTime(EmbeddedCli *cli, char *args, void *context);
extern void setWatchsTime(EmbeddedCli *cli, char *args, void *context);


extern void setTimeEpoch();
//extern uint32_t receiveEpochTime(UART2_Handle uart2Handle);
extern void cli_printf(EmbeddedCli *cli, const char *format, ...);
extern void console_taskInit();

#ifdef __cplusplus
}
#endif

#endif