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
#include "delay.h"

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

/* the address of write data & command (xmc_a16) */
#define  XMC_LCD_COMMAND                 0x603FFFFE
#define  XMC_LCD_DATA                    0x60400000

/**
  * @brief  this function is write command to lcd.
  * @param  command : the command to write.
  * @retval none
  */
void lcd_wr_command(uint16_t command)
{
  *(__IO uint16_t*) XMC_LCD_COMMAND = command;
}

/**
  * @brief  this function is write data to lcd.
  * @param  data : the data to write.
  * @retval none
  */
void lcd_wr_data(uint16_t data)
{
  *(__IO uint16_t*) XMC_LCD_DATA = data;
}

uint16_t lcd_rd_data(void)
{
  uint16_t data;

  data = *(uint16_t*)XMC_LCD_DATA;

  return data;
}


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

  /* add user code end 2 */

  while(1)
  {
    /* add user code begin 3 */
    lcd_wr_command(0xa5a5);
    delay_sec(1);
    /* add user code end 3 */
  }
}
