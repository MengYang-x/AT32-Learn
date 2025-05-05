#include "st7735s.h"

static void st7735s_lcd_reset(void);
static void st7735s_load_parameter(void);

void st7735s_lcd_init(void)
{
    // 1. LCD复位
    st7735s_lcd_reset();
    LCD_BLK_SET;
    // 2. 加载LCD参数
    st7735s_load_parameter();
}

static void st7735s_lcd_reset(void)
{
    LCD_RES_CLR;
    delay_ms(100);
    LCD_RES_SET;
    delay_ms(120);
}

/**
 * @brief 软件模拟SPI发送8位数据
 */
static void software_spi_transmit_u8(u8 data)
{
    // 1.拉低CS
    LCD_CS_CLR;

    // 2.将D0~D7从最高位依次发出，在CLK上升沿发送
    for (u8 i = 0; i < 8; i++)
    {
        LCD_SCLK_CLR;
        if (data & 0x80) // if bitx = 1
        {
            LCD_MOSI_SET;
        }
        else // if bitx = 0
        {
            LCD_MOSI_CLR;
        }
        LCD_SCLK_SET;
        data <<= 1; // 左移一位
    }
    // 3.拉高CS
    LCD_CS_SET;
}

/**
 * @brief 向LCD写入命令
 * @note DC=0，写命令。DC=1，写数据。
 */
static void st7735s_write_commend(u8 data)
{
    LCD_DC_CLR;
    software_spi_transmit_u8(data);
}

/**
 * @brief 向LCD写入8位数据
 * @note DC=0，写命令。DC=1，写数据。
 */
static void st7735s_write_data_u8(u8 data)
{
    LCD_DC_SET;
    software_spi_transmit_u8(data);
}

/**
 * @brief 向LCD写入16位数据，主要用于颜色设置(RGB565，16位)
 * @note DC=0，写命令。DC=1，写数据。
 */
static void st7735s_write_data_u16(u16 data)
{
    st7735s_write_data_u8(data >> 8); // 发送高8位
    st7735s_write_data_u8(data);      // 发送低8位
}

static void st7735s_load_parameter(void)
{
    st7735s_write_commend(0x11); // Sleep out
    delay_ms(120);

    st7735s_write_commend(0xB1); // Normal mode
    st7735s_write_data_u8(0x05);
    st7735s_write_data_u8(0x3C);
    st7735s_write_data_u8(0x3C);
    st7735s_write_commend(0xB2); // Idle mode
    st7735s_write_data_u8(0x05);
    st7735s_write_data_u8(0x3C);
    st7735s_write_data_u8(0x3C);
    st7735s_write_commend(0xB3); // Partial mode
    st7735s_write_data_u8(0x05);
    st7735s_write_data_u8(0x3C);
    st7735s_write_data_u8(0x3C);
    st7735s_write_data_u8(0x05);
    st7735s_write_data_u8(0x3C);
    st7735s_write_data_u8(0x3C);
    st7735s_write_commend(0xB4); // Dot inversion
    st7735s_write_data_u8(0x03);
    st7735s_write_commend(0xC0); // AVDD GVDD
    st7735s_write_data_u8(0xAB);
    st7735s_write_data_u8(0x0B);
    st7735s_write_data_u8(0x04);
    st7735s_write_commend(0xC1); // VGH VGL
    st7735s_write_data_u8(0xC5); // C0
    st7735s_write_commend(0xC2); // Normal Mode
    st7735s_write_data_u8(0x0D);
    st7735s_write_data_u8(0x00);
    st7735s_write_commend(0xC3); // Idle
    st7735s_write_data_u8(0x8D);
    st7735s_write_data_u8(0x6A);
    st7735s_write_commend(0xC4); // Partial+Full
    st7735s_write_data_u8(0x8D);
    st7735s_write_data_u8(0xEE);
    st7735s_write_commend(0xC5); // VCOM
    st7735s_write_data_u8(0x0F);
    st7735s_write_commend(0xE0); // positive gamma
    st7735s_write_data_u8(0x07);
    st7735s_write_data_u8(0x0E);
    st7735s_write_data_u8(0x08);
    st7735s_write_data_u8(0x07);
    st7735s_write_data_u8(0x10);
    st7735s_write_data_u8(0x07);
    st7735s_write_data_u8(0x02);
    st7735s_write_data_u8(0x07);
    st7735s_write_data_u8(0x09);
    st7735s_write_data_u8(0x0F);
    st7735s_write_data_u8(0x25);
    st7735s_write_data_u8(0x36);
    st7735s_write_data_u8(0x00);
    st7735s_write_data_u8(0x08);
    st7735s_write_data_u8(0x04);
    st7735s_write_data_u8(0x10);
    st7735s_write_commend(0xE1); // negative gamma
    st7735s_write_data_u8(0x0A);
    st7735s_write_data_u8(0x0D);
    st7735s_write_data_u8(0x08);
    st7735s_write_data_u8(0x07);
    st7735s_write_data_u8(0x0F);
    st7735s_write_data_u8(0x07);
    st7735s_write_data_u8(0x02);
    st7735s_write_data_u8(0x07);
    st7735s_write_data_u8(0x09);
    st7735s_write_data_u8(0x0F);
    st7735s_write_data_u8(0x25);
    st7735s_write_data_u8(0x35);
    st7735s_write_data_u8(0x00);
    st7735s_write_data_u8(0x09);
    st7735s_write_data_u8(0x04);
    st7735s_write_data_u8(0x10);

    st7735s_write_commend(0xFC);
    st7735s_write_data_u8(0x80);

    st7735s_write_commend(0x3A); // 像素格式
    st7735s_write_data_u8(0x05); // RGB565格式(0x05)、RGB444格式(0x03)、RGB666格式(0x06)
    st7735s_write_commend(0x36);
#if LCD_DISPLAY_HORIZONTAL == 0
    st7735s_write_data_u8(0x08); // 默认方向
#elif LCD_DISPLAY_HORIZONTAL == 1

    st7735s_write_data_u8(0xC8); // 水平镜像
#elif LCD_DISPLAY_HORIZONTAL == 2
    st7735s_write_data_u8(0x78); // 垂直镜像
#else
    st7735s_write_data_u8(0xA8); // 旋转180°
#endif

#if COLOR_INVERSION_EN == 1
    st7735s_write_commend(0x21); // display color inversion on，开启颜色反转
#else
    st7735s_write_commend(0x20); // display color inversion off，关闭颜色反转
#endif

    st7735s_write_commend(0x29); // Display on
}

/**
 * @brief 设置显示窗口的大小，并写入显存(GRAM)
 * @note 0x2A：Column Address Set，行地址设置
 * @note 0x2B：Row Address Set，列地址设置
 * @note 0x2C：Memory Write，设置显存
 */
static void st7735s_lcd_address_set(u16 x1, u16 y1, u16 x2, u16 y2)
{
#if LCD_DISPLAY_HORIZONTAL == 0

    st7735s_write_commend(0x2A);
    st7735s_write_data_u16(x1 + 26);
    st7735s_write_data_u16(x2 + 26);

    st7735s_write_commend(0x2B);
    st7735s_write_data_u16(y1 + 1);
    st7735s_write_data_u16(y2 + 1);

    st7735s_write_commend(0x2C);
#else
    st7735s_write_commend(0x2A);
    st7735s_write_data_u16(x1);
    st7735s_write_data_u16(x2);

    st7735s_write_commend(0x2B);
    st7735s_write_data_u16(y1 + 26);
    st7735s_write_data_u16(y2 + 26);

    st7735s_write_commend(0x2C);
#endif
}

/**
 * @brief 将屏幕清屏为指定颜色
 */
void st7735s_lcd_clear(u16 color)
{
    st7735s_lcd_address_set(0, 0, LCD_W - 1, LCD_H - 1);

    for (u16 i = 0; i < LCD_W; i++)
    {
        for (u16 j = 0; j < LCD_H; j++)
        {
            st7735s_write_data_u16(color);
        }
    }
}

/**
 * @brief 在指定区域填充颜色
 */
void st7735s_lcd_fill_color(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{
    u16 x_length = x2 - x1 + 1;
    u16 y_length = y2 - y1 + 1;
    st7735s_lcd_address_set(x1, y1, x2, y2);

    for (u16 i = 0; i < x_length; i++)
    {
        for (u16 j = 0; j < y_length; j++)
        {
            st7735s_write_data_u16(color);
        }
    }
}

/**
 * @brief 在指定位置画点
 */
void st7735s_lcd_draw_point(u16 x, u16 y, u16 color)
{
    st7735s_lcd_address_set(x, y, x, y);
    st7735s_write_data_u16(color);
}
