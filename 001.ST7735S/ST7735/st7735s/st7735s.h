#ifndef __ST7735S_H
#define __ST7735S_H
#include "user_config.h"

#define LCD_WIDE    160
#define LCD_HIGH    80

#define LCD_DISPLAY_HORIZONTAL              0
#if LCD_DISPLAY_HORIZONTAL == 1
#define LCD_W       LCD_WIDE
#define LCD_H       LCD_HIGH
#else
#define LCD_W       LCD_HIGH
#define LCD_H       LCD_WIDE
#endif

#define COLOR_INVERSION_EN    (0)   // 显示颜色反转

// 颜色定义RGB565
// R R R R R G G G G G G B B B B B  
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1  = WHITE
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0  = BLACK
// 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0  = RED
#define COLOR_WHITE             (0xFFFF)
#define COLOR_BLACK             (0x0000)
#define COLOR_RED               (0xF800)
#define COLOR_GREEN             (0x07E0)
#define COLOR_BLUE              (0x001F)
#define COLOR_YELLOW            (0xFFE0)

void st7735s_lcd_init(void);
void st7735s_lcd_clear(u16 color);
void st7735s_lcd_fill_color(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);
void st7735s_lcd_draw_point(u16 x, u16 y, u16 color);

#if (SPI_TYPE == SOFTWARE_SPI && MCU_ID == AT32)
#define LCD_SCLK_CLR                      gpio_bits_reset(LCD_SCL_GPIO_PORT, LCD_SCL_PIN)
#define LCD_SCLK_SET                      gpio_bits_set(LCD_SCL_GPIO_PORT, LCD_SCL_PIN)
#define LCD_MOSI_CLR                      gpio_bits_reset(LCD_SDA_GPIO_PORT, LCD_SDA_PIN)
#define LCD_MOSI_SET                      gpio_bits_set(LCD_SDA_GPIO_PORT, LCD_SDA_PIN)
#define LCD_RES_CLR                       gpio_bits_reset(LCD_RST_GPIO_PORT, LCD_RST_PIN)
#define LCD_RES_SET                       gpio_bits_set(LCD_RST_GPIO_PORT, LCD_RST_PIN)
#define LCD_DC_CLR                        gpio_bits_reset(LCD_DC_GPIO_PORT, LCD_DC_PIN)
#define LCD_DC_SET                        gpio_bits_set(LCD_DC_GPIO_PORT, LCD_DC_PIN)
#define LCD_CS_CLR                        gpio_bits_reset(LCD_CS_GPIO_PORT, LCD_CS_PIN)
#define LCD_CS_SET                        gpio_bits_set(LCD_CS_GPIO_PORT, LCD_CS_PIN)
#define LCD_BLK_CLR                       gpio_bits_reset(LCD_BLK_GPIO_PORT, LCD_BLK_PIN)
#define LCD_BLK_SET                       gpio_bits_set(LCD_BLK_GPIO_PORT, LCD_BLK_PIN)
#endif


#endif
