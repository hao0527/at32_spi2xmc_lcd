/**
 * @file st7796s.h
 */

#ifndef ST7796S_H
#define ST7796S_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include <stdint.h>
#include "at32f403a_407.h"
#include "at32f403a_407_wk_config.h"

/*********************
 *      DEFINES
 *********************/
#define ST7796S_RST                 LCD_RST_GPIO_PORT, LCD_RST_PIN
#define ST7796S_INVERT_COLORS       1
#define ST7796S_DISPLAY_ORIENTATION 0
#define CONFIG_LV_PREDEFINED_DISPLAY_WROVER4


/*******************
 * ST7796S REGS
*********************/

/* MIPI DCS Type1  */
#define ST7796S_CMD_NOP 0x00
#define ST7796S_CMD_SOFTWARE_RESET 0x01
#define ST7796S_CMD_READ_DISP_POWER_MODE 0x0A
#define ST7796S_CMD_READ_DISP_MADCTRL 0x0B // bits 7:3 only
#define ST7796S_CMD_READ_DISP_PIXEL_FORMAT 0x0C
#define ST7796S_CMD_READ_DISP_IMAGE_MODE 0x0D
#define ST7796S_CMD_READ_DISP_SIGNAL_MODE 0x0E
#define ST7796S_CMD_READ_DISP_SELF_DIAGNOSTIC 0x0F // bits 7:6 only
#define ST7796S_CMD_ENTER_SLEEP_MODE 0x10
#define ST7796S_CMD_SLEEP_OUT 0x11
#define ST7796S_CMD_PARTIAL_MODE_ON 0x12
#define ST7796S_CMD_NORMAL_DISP_MODE_ON 0x13
#define ST7796S_CMD_DISP_INVERSION_OFF 0x20
#define ST7796S_CMD_DISP_INVERSION_ON 0x21
#define ST7796S_CMD_DISPLAY_OFF 0x28
#define ST7796S_CMD_DISPLAY_ON 0x29
#define ST7796S_CMD_COLUMN_ADDRESS_SET 0x2A
#define ST7796S_CMD_PAGE_ADDRESS_SET 0x2B
#define ST7796S_CMD_MEMORY_WRITE 0x2C
#define ST7796S_CMD_MEMORY_READ 0x2E
#define ST7796S_CMD_PARTIAL_AREA 0x30
#define ST7796S_CMD_VERT_SCROLL_DEFINITION 0x33
#define ST7796S_CMD_TEARING_EFFECT_LINE_OFF 0x34
#define ST7796S_CMD_TEARING_EFFECT_LINE_ON 0x35
#define ST7796S_CMD_MEMORY_ACCESS_CONTROL 0x36 // bits 7:3,1:0 only
#define ST7796S_CMD_VERT_SCROLL_START_ADDRESS 0x37
#define ST7796S_CMD_IDLE_MODE_OFF 0x38
#define ST7796S_CMD_IDLE_MODE_ON 0x39
#define ST7796S_CMD_COLMOD_PIXEL_FORMAT_SET 0x3A
#define ST7796S_CMD_WRITE_MEMORY_CONTINUE 0x3C
#define ST7796S_CMD_READ_MEMORY_CONTINUE 0x3E
#define ST7796S_CMD_SET_TEAR_SCANLINE 0x44
#define ST7796S_CMD_GET_SCANLINE 0x45

#define ST7796S_DDB_START 0xA1
#define ST7796S_DDB_CONTINUE 0xA8

/* other */
#define ST7796S_CMD_ACCESS_PROTECT 0xB0
#define ST7796S_CMD_LOW_POWER_CONTROL 0xB1
#define ST7796S_CMD_FRAME_MEMORY_ACCESS 0xB3
#define ST7796S_CMD_DISPLAY_MODE 0xB4
#define ST7796S_CMD_DEVICE_CODE 0xBF

#define ST7796S_CMD_PANEL_DRIVE 0xC0
#define ST7796S_CMD_DISP_TIMING_NORMAL 0xC1
#define ST7796S_CMD_DISP_TIMING_PARTIAL 0xC2
#define ST7796S_CMD_DISP_TIMING_IDLE 0xC3
#define ST7796S_CMD_FRAME_RATE 0xC5
#define ST7796S_CMD_INTERFACE_CONTROL 0xC6
#define ST7796S_CMD_GAMMA_SETTING 0xC8

#define ST7796S_CMD_POWER_SETTING 0xD0
#define ST7796S_CMD_VCOM_CONTROL 0xD1
#define ST7796S_CMD_POWER_CONTROL_NORMAL 0xD2
#define ST7796S_CMD_POWER_CONTROL_IDEL 0xD3
#define ST7796S_CMD_POWER_CONTROL_PARTIAL 0xD4

#define ST7796S_CMD_NVMEM_WRITE 0xE0
#define ST7796S_CMD_NVMEM_PROTECTION_KEY 0xE1
#define ST7796S_CMD_NVMEM_STATUS_READ 0xE2
#define ST7796S_CMD_NVMEM_PROTECTION 0xE3

  /**********************
 *      TYPEDEFS
 **********************/
/** Represents an area of the screen.*/
typedef struct {
    uint16_t x1;
    uint16_t y1;
    uint16_t x2;
    uint16_t y2;
} lcd_area_t;

typedef uint16_t lcd_color_t;

  /**********************
 * GLOBAL PROTOTYPES
 **********************/

void st7796s_init(void);
void st7796s_flush(const lcd_area_t *area, lcd_color_t *color_map);

void lcd_fill(const lcd_area_t *area, lcd_color_t color);

  /**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*ST7796S_H*/
