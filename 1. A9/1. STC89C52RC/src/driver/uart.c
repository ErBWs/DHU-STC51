/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "uart.h"

void UART_Init()
{
    TMOD |= 0X20;
    SCON = 0X50;
    PCON = 0X80;
    TH1 = 0xfa;     // 9600
    TL1 = 0xfa;
    EA = 1;
    TR1 = 1;
}


void UART_SendChar(uint8_t dat)
{
    SBUF = dat;
    while (!TI);
    TI = 0;
}


void UART_SendStr(const char *str)
{
    while(*str)
    {
        UART_SendChar(*str++);
    }
}