/*
 * par.h
 *
 *  Created on: Jul 28, 2024
 *      Author: hzaib
 */

#ifndef APPLICATION_PAR_H_
#define APPLICATION_PAR_H_

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>
#include "ti_154stack_config.h"
#include "Defines.h"
#include "api_mac.h"

#define total_size_region 0x8000
#define total_size_sector 0x800
#define total_sectors 16




#define control_task_devices_info_len 15  //length of a structure which we want to save
#define control_task_devices_info_total 100  //we save 100 entries just to be on safe side
                                             //although max devices that can be configured are 50


#define control_task_devices_pairing_len 36  //length of a structure which we want to save


typedef enum
{
    device_info = 1,
    device_pairing = 2,

}save_struct;


extern void par_erase(save_struct type_to_erase);
extern void par_save(save_struct type_to_save);
extern void par_load(save_struct type_to_load);
extern void par_init();


#endif /* APPLICATION_PAR_H_ */
