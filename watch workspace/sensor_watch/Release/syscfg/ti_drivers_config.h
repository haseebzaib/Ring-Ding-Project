/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  The macros defines herein are intended for use by applications which
 *  directly include this header. These macros should NOT be hard coded or
 *  copied into library source code.
 *
 *  Symbols declared as const are intended for use with libraries.
 *  Library source code must extern the correct symbol--which is resolved
 *  when the application is linked.
 *
 *  DO NOT EDIT - This file is generated for the LP_EM_CC1314R10
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_LP_EM_CC1314R10
#ifndef DeviceFamily_CC13X4
#define DeviceFamily_CC13X4
#endif

#include <ti/devices/DeviceFamily.h>

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== CCFG ========
 */


/*
 *  ======== AESCCM ========
 */

extern const uint_least8_t                  CONFIG_AESCCM_0_CONST;
#define CONFIG_AESCCM_0                     0
#define CONFIG_TI_DRIVERS_AESCCM_COUNT      1


/*
 *  ======== GPIO ========
 */
extern const uint_least8_t CONFIG_GPIO_RST_CONST;
#define CONFIG_GPIO_RST 4

extern const uint_least8_t CONFIG_GPIO_DC_CONST;
#define CONFIG_GPIO_DC 5

/* Owned by CONFIG_SPI_LCD as  */
extern const uint_least8_t CONFIG_GPIO_SPI_LCD_SCLK_CONST;
#define CONFIG_GPIO_SPI_LCD_SCLK 10

/* Owned by CONFIG_SPI_LCD as  */
extern const uint_least8_t CONFIG_GPIO_SPI_LCD_POCI_CONST;
#define CONFIG_GPIO_SPI_LCD_POCI 8

/* Owned by CONFIG_SPI_LCD as  */
extern const uint_least8_t CONFIG_GPIO_SPI_LCD_PICO_CONST;
#define CONFIG_GPIO_SPI_LCD_PICO 9

/* Owned by CONFIG_DISPLAY_UART as  */
extern const uint_least8_t CONFIG_GPIO_DISPLAY_UART_TX_CONST;
#define CONFIG_GPIO_DISPLAY_UART_TX 3

/* Owned by CONFIG_DISPLAY_UART as  */
extern const uint_least8_t CONFIG_GPIO_DISPLAY_UART_RX_CONST;
#define CONFIG_GPIO_DISPLAY_UART_RX 2

/* Owned by CONFIG_BTN_LEFT as  */
extern const uint_least8_t CONFIG_GPIO_BTN1_CONST;
#define CONFIG_GPIO_BTN1 15

/* Owned by CONFIG_BTN_RIGHT as  */
extern const uint_least8_t CONFIG_GPIO_BTN2_CONST;
#define CONFIG_GPIO_BTN2 14

/* Owned by CONFIG_LED_RED as  */
extern const uint_least8_t CONFIG_GPIO_RLED_CONST;
#define CONFIG_GPIO_RLED 6

/* Owned by CONFIG_LED_GREEN as  */
extern const uint_least8_t CONFIG_GPIO_GLED_CONST;
#define CONFIG_GPIO_GLED 7

/* The range of pins available on this device */
extern const uint_least8_t GPIO_pinLowerBound;
extern const uint_least8_t GPIO_pinUpperBound;

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== NVS ========
 */

extern const uint_least8_t              CONFIG_NVSINTERNAL_CONST;
#define CONFIG_NVSINTERNAL              0
#define CONFIG_TI_DRIVERS_NVS_COUNT     1




/*
 *  ======== SPI ========
 */

/*
 *  PICO: DIO9
 *  POCI: DIO8
 *  SCLK: DIO10
 *  LaunchPad SPI Bus
 */
extern const uint_least8_t              CONFIG_SPI_LCD_CONST;
#define CONFIG_SPI_LCD                  0
#define CONFIG_TI_DRIVERS_SPI_COUNT     1


/*
 *  ======== Timer ========
 */

extern const uint_least8_t                  btn_con_timer_CONST;
#define btn_con_timer                       0
#define CONFIG_TI_DRIVERS_TIMER_COUNT       1


/*
 *  ======== UART2 ========
 */

/*
 *  TX: DIO3
 *  RX: DIO2
 *  XDS110 UART
 */
extern const uint_least8_t                  CONFIG_DISPLAY_UART_CONST;
#define CONFIG_DISPLAY_UART                 0
#define CONFIG_TI_DRIVERS_UART2_COUNT       1


/*
 *  ======== Button ========
 */

extern const uint_least8_t                  CONFIG_BTN_LEFT_CONST;
#define CONFIG_BTN_LEFT                     0
extern const uint_least8_t                  CONFIG_BTN_RIGHT_CONST;
#define CONFIG_BTN_RIGHT                    1
#define CONFIG_TI_DRIVERS_BUTTON_COUNT      2


/*
 *  ======== LED ========
 */

extern const uint_least8_t              CONFIG_LED_RED_CONST;
#define CONFIG_LED_RED                  0
extern const uint_least8_t              CONFIG_LED_GREEN_CONST;
#define CONFIG_LED_GREEN                1
#define CONFIG_TI_DRIVERS_LED_COUNT     2


/*
 *  ======== GPTimer ========
 */

extern const uint_least8_t                  btn_con_gp_timer_CONST;
#define btn_con_gp_timer                    0
#define CONFIG_TI_DRIVERS_GPTIMER_COUNT     1


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */