/*
 * btn_con.c
 *
 *  Created on: Jul 21, 2024
 *      Author: hzaib
 */


#include <stdint.h>

/* POSIX Header files */
#include <pthread.h>

/* RTOS header files */
#include <ti/sysbios/BIOS.h>

#include <ti/drivers/Board.h>

#include <semaphore.h>
#include <unistd.h>


/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/SPI.h>
#include <ti/display/Display.h>
#include <ti/drivers/dpl/ClockP.h>
#include <ti/drivers/Timer.h>

/* Board Header file */
#include "ti_drivers_config.h"
/* Driver configuration */
#include "ti_drivers_config.h"

#include "btn_con.h"
#include "Defines.h"
#include "control_task.h"


volatile MenuButton_t hMenuButton;
uint8_t retrn = RESET;
uint32_t compare_timer = 0;
void setTimer(uint32_t* timer)
{
    *timer = ClockP_getSystemTicks();
}
uint8_t checkTimer(uint32_t* timer, uint32_t msTime)
{
    retrn = RESET;
    compare_timer = ClockP_getSystemTicks();
    retrn = ((compare_timer - *timer) > msTime)  ? ENABLE : DISABLE;
    return retrn;
}

/*
void btn_con_interrupt(uint_least8_t index)
{
//    if(GPIO_read(LCD_BUTTON) == 0)
//    {

        //GPIO_toggle(CONFIG_GPIO_LED_0);
        hMenuButton.buttonFlag = 1;

//    }
}

void btn_con_loop(Timer_Handle handle, int_fast16_t status)
{
    if(hMenuButton.buttonFlag)
                     {
                             if(GPIO_read(LCD_BUTTON) == 0)                                          //for applying debounce
                              {
                                  hMenuButton.buttonFlag = RESET;                       //Reset interrupt flag

                                  if(hMenuButton.buttonTimerEnable != SET)                      //Start timer when the menu button gets pressed for the first time
                                  {
                                      hMenuButton.buttonTimerEnable = SET;                      //Enable software timer
                                      hMenuButton.buttonStatus = MenuButtonStatus_oneClick;     //The menu button has been pressed for one time
                                      setTimer(&hMenuButton.buttonTimer);                       //Start software timer
                                  }
                                  else
                                  {
                                     hMenuButton.buttonStatus = MenuButtonStatus_doubleClick; //If the timer is already started this means that the button is pressed for the second time
                                  }
                              }
                          }


                      if((hMenuButton.buttonStatus == MenuButtonStatus_oneClick) || hMenuButton.buttonStatus == MenuButtonStatus_heldPressed )//(checkTimer(&hMenuButton.buttonTimer, 5 * hMenuButton.buttonHeldPressedCounter)) &&
                          {
                              if(GPIO_read(LCD_BUTTON) == 0)     //To check if the button is still pressed
                              {
                                  ++hMenuButton.buttonHeldPressedCounter;                       //Increment samples number
                              }


                             if(hMenuButton.buttonHeldPressedCounter >= 20)
                             {
                                  hMenuButton.buttonStatus = MenuButtonStatus_heldPressed;
                             }

                          }                                                                     //If the button is held pressed change button status


                      //this if statement can be removed if double press feature is not being used.
                      if( (checkTimer(&hMenuButton.buttonTimer, 500)) && hMenuButton.buttonTimerEnable)//(checkTimer(&hMenuButton.buttonTimer, 40)) &&
                          {
                          if((GPIO_read(LCD_BUTTON)  == 0) && (hMenuButton.buttonHeldPressedCounter >= 20) )
                             {
                              switch(hMenuButton.buttonStatus)
                                {

                                    case MenuButtonStatus_heldPressed:
                                    { GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_ON);
                                          GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
                                         hMenuButton.buttonTimerEnable         = RESET;                    //Disable software timer
                                         hMenuButton.menu_selection = 3;
                                         break;
                                    }
                                 }


                             }


                          if(GPIO_read(LCD_BUTTON) == 1)
                          {
                              switch(hMenuButton.buttonStatus)
                                 {
                                              case  MenuButtonStatus_oneClick:
                                                  {
                                                    GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_OFF);
                                                    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
                                                    hMenuButton.menu_selection = 1;
                                                    break;
                                                  }
                                              case  MenuButtonStatus_doubleClick:
                                                  {
                                                   GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_ON);
                                                   GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
                                                   hMenuButton.menu_selection = 2;
                                                    break;
                                                  }


                                    }
                                          hMenuButton.buttonTimerEnable         = RESET;                    //Disable software timer


                          }



                          }





                      if(GPIO_read(LCD_BUTTON) == 1 && !hMenuButton.buttonTimerEnable )//resets everything when button is unpressed
                      {
                          hMenuButton.buttonTimerEnable         = RESET;                    //Disable software timer
                            hMenuButton.buttonHeldPressedCounter    = RESET;                    //Reset counter
                             hMenuButton.buttonStatus               = MenuButtonStatus_notPressed;
                      }
}
*/

void timer_callback(Timer_Handle handle, int_fast16_t status)
{

    if(devInfoConfirmationFlag == 1)
     {
        devInfoConfirmationTimer++;

        if(devInfoConfirmationTimer > 6000)
        {
            devInfoConfirmationTimer = 0;
            devInfoConfirmationMail = 1;

        }

     }

}


void btn_con_init()
{
//    GPIO_setConfig(LCD_BUTTON, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
//    GPIO_setCallback(LCD_BUTTON, btn_con_interrupt);
//    GPIO_enableInt(LCD_BUTTON);
    Timer_Handle timer0;
     Timer_Params params;

     Timer_Params_init(&params);
     params.period        = 1*1000;
     params.periodUnits   = Timer_PERIOD_US;
     params.timerMode     = Timer_CONTINUOUS_CALLBACK;
     params.timerCallback = timer_callback;

     timer0 = Timer_open(btn_con_timer, &params);

     if (timer0 == NULL)
     {
         /* Failed to initialized timer */
         while (1) {}
     }

     if (Timer_start(timer0) == Timer_STATUS_ERROR)
     {
         /* Failed to start timer */
         while (1) {}
     }
}
