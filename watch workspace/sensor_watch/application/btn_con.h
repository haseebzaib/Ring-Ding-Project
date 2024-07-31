/*
 * btn_con.h
 *
 *  Created on: Jul 21, 2024
 *      Author: hzaib
 */

#ifndef BTN_CON_H_
#define BTN_CON_H_

#include <stdint.h>

/* POSIX Header files */
#include <pthread.h>

/* RTOS header files */
#include <ti/sysbios/BIOS.h>

#include <ti/drivers/Board.h>

#define RESET 0
#define SET 1

#define DISABLE 0
#define ENABLE 1

typedef enum
{
    //c denotes as an identifier for that button code
    MenuButtonStatus_notPressed=0,
    MenuButtonStatus_heldPressed=10,
    MenuButtonStatus_doubleClick=20,
    MenuButtonStatus_oneClick=30,
    cDWN_BT=40,
    cRGHT_BT=50,
    cLFT_BT=60,
    cSub_menu=70,
    cUP_BT = 80,
    cESC_BT = 90,
    cEnter_BT = 100,
}button_codes;




typedef struct {
    uint32_t buttonTimer; //to debounce the button
    uint8_t buttonTimerEnable;//redundant
    uint8_t buttonFlag;//to know if button is pressed
    uint8_t Sel_BT;//check correct button after debounce
    uint8_t BT_code;//code that transfers to main program
    uint8_t buttonHeldPressedCounter;
    uint8_t buttonStatus;
    uint8_t menu_selection;

} MenuButton_t;

extern volatile MenuButton_t hMenuButton;


extern void btn_con_interrupt(uint_least8_t index);

extern void btn_con_init();

#endif /* BTN_CON_H_ */
