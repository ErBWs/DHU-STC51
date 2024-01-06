/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "lcd1602.h"


void LCD1602_WriteCmd(uint8_t cmd)
{
    LCD1602_RS = 0;
    LCD1602_RW = 0;
    LCD1602_E = 0;
    LCD1602_PORT = cmd;
    SoftDelay_ms(1);
    LCD1602_E = 1;
    SoftDelay_ms(1);
    LCD1602_E = 0;
}


void LCD1602_WriteData(uint8_t dat)
{
    LCD1602_RS = 1;
    LCD1602_RW = 0;
    LCD1602_E = 0;
    LCD1602_PORT = dat;
    SoftDelay_ms(1);
    LCD1602_E = 1;
    SoftDelay_ms(1);
    LCD1602_E = 0;
}


void LCD1602_Clear()
{
    LCD1602_WriteCmd(0x01);
}


void LCD1602_Init()
{
    LCD1602_WriteCmd(0x38);
    LCD1602_WriteCmd(0x0c);
    LCD1602_WriteCmd(0x06);
    LCD1602_Clear();
}


void LCD1602_ShowStr(uint8_t x, uint8_t y, const uint8_t str[])
{
    uint8_t length = sizeof(&str) - 1;
    uint8_t i = 0;

    if (x + length > 15 || y > 1)
        return;

    while (str[i] != '\0')
    {
        switch (y)
        {
        case 0:
            LCD1602_WriteCmd(0x80 + i + x);
            break;
        case 1:
            LCD1602_WriteCmd(0xc0 + i + x);
            break;
        default:
            break;
        }

        LCD1602_WriteData(str[i]);
        i++;
    }
}