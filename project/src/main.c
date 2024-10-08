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
#include "at32f403a_407_wk_config.h"

/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include <string.h>
#include "delay.h"
#include "st7796s.h"
#include "image.h"
#include "hue.h"
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
lcd_area_t  area1 = {0,0,9,9},     area2 = {310,0,319,9},
            area3 = {0,310,9,319}, area4 = {310,310,319,319};
lcd_area_t  area5 = {0,0,319,319};
lcd_color_t lcdBuff1[10][10], lcdBuff2[10][10], lcdBuff3[320][320];
lcd_color_t color1;
float huv = 0;
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

  /* init debug function. */
  wk_debug_config();

  /* nvic config. */
  wk_nvic_config();

  /* init wk_xmc_gpio function. */
  wk_xmc_gpio_init();

  /* init xmc_bank1_nor_sram1 function. */
  wk_xmc_bank1_nor_sram1_init();

  /* init spi1 function. */
  wk_spi1_init();

  /* init gpio function. */
  wk_gpio_config();

  /* add user code begin 2 */
  delay_init();

  st7796s_init();

  memset(lcdBuff1, 0xaaaa, sizeof(lcdBuff1));
  memset(lcdBuff2, 0x5555, sizeof(lcdBuff2));
  memset(lcdBuff3, 0xffff, sizeof(lcdBuff3));
  st7796s_flush(&area5, lcdBuff3[0]); // 320 * 320 pixels buff in ram need 7.22ms

  /* add user code end 2 */

  while(1)
  {
    /* add user code begin 3 */
    huv += 0.01f;
    if (huv >= 1) {
      huv = 0;
    }
    color1 = rgb565_from_hue(huv);
    lcd_fill(&area5, color1);
    delay_ms(1);
    /* add user code end 3 */
  }
}
