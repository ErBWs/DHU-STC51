/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "mcs51/8052.h"

void UART_Init();
void UART_SendChar(uint8_t dat);
void UART_SendStr(const char *str);

#ifdef __cplusplus
}
#endif

#endif
