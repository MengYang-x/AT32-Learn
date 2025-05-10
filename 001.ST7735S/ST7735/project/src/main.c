/* add user code begin Header */
/**
  **************************************************************************
  * @file     main.c
  * @brief    main program
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */
/* add user code end Header */

/* Includes ------------------------------------------------------------------*/
#include "at32f421_wk_config.h"
#include "wk_usart.h"
#include "wk_gpio.h"
#include "wk_system.h"

/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include "st7735s.h"
/* add user code end private includes */

/* private typedef -----------------------------------------------------------*/
/* add user code begin private typedef */

/* add user code end private typedef */

/* private define ------------------------------------------------------------*/
/* add user code begin private define */

/* add user code end private define */

/* private macro -------------------------------------------------------------*/
/* add user code begin private macro */

/* add user code end private macro */

/* private variables ---------------------------------------------------------*/
/* add user code begin private variables */

/* add user code end private variables */

/* private function prototypes --------------------------------------------*/
/* add user code begin function prototypes */

/* add user code end function prototypes */

/* private user code ---------------------------------------------------------*/
/* add user code begin 0 */

/* add user code end 0 */

/**
  * @brief main function.
  * @param  none
  * @retval none
  */
int main(void)
{
  /* add user code begin 1 */

  /* add user code end 1 */

  /* system clock config. */
  wk_system_clock_config();

  /* config periph clock. */
  wk_periph_clock_config();

  /* nvic config. */
  wk_nvic_config();

  /* timebase config. */
  wk_timebase_init();

  /* usart1 already supports printf. */
  /* init usart1 function. */
  wk_usart1_init();

  /* init gpio function. */
  wk_gpio_config();

  /* add user code begin 2 */
  st7735s_lcd_init();
  st7735s_lcd_clear(COLOR_BLACK);
 // st7735s_lcd_fill_color(0, 0, 20, 20, COLOR_RED);
 // st7735s_lcd_fill_color(20, 20, 40, 40, COLOR_GREEN);
 // st7735s_lcd_fill_color(40, 40, 60, 60, COLOR_BLUE);
 // st7735s_lcd_fill_color(60, 60, 80, 80, COLOR_YELLOW);

  // st7735s_lcd_draw_string(0, 20, "1234567890", COLOR_WHITE, COLOR_BLACK, 32, 0);
	// st7735s_lcd_draw_string(0, 48, "1234567890", COLOR_RED, COLOR_BLACK, 32, 0);
	// st7735s_lcd_draw_string(0, 76, "1234567890", COLOR_YELLOW, COLOR_BLACK, 32, 0);
  LCD_ShowIntNum(0, 60, 12345, 5, COLOR_WHITE, COLOR_BLACK, 32);
  float t = 0;
  /* add user code end 2 */

  while(1)
  {
    /* add user code begin 3 */
    LCD_ShowFloatNum1(10, 60, t, 4, COLOR_WHITE, COLOR_BLACK, 32);
    t+=0.11;
    delay_ms(500);
    /* add user code end 3 */
  }
}

  /* add user code begin 4 */

  /* add user code end 4 */
