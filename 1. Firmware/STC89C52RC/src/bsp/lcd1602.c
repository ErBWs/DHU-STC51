/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "lcd1602.h"

/**
 * @brief   Write cmd
 *
 * @param   cmd
 *
 * @return  None
 */
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


/**
 * @brief   Write data
 *
 * @param   dat
 * @return  None
 */
void LCD1602_WriteDat(uint8_t dat)
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


/**
 * @brief   Initialize LCD1602
 *
 * @param   None
 * @return  None
*/
void LCD1602_Init()
{
    LCD1602_WriteCmd(0x38);
    LCD1602_WriteCmd(0x0c);
    LCD1602_WriteCmd(0x06);
    LCD1602_WriteCmd(0x01);
}


/**
 * @brief   CLear LCD1602
 *
 * @param   None
 * @return  None
 */
void LCD1602_Clear()
{
    LCD1602_WriteCmd(0x01);
}