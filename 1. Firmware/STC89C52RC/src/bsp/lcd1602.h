/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef LCD1602_H
#define LCD1602_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "mcs51/8052.h"
#include "driver/delay.h"

#define LCD1602_RW      P2_5    // Read / write selection
#define LCD1602_RS      P2_6    // Register selection
#define LCD1602_E       P2_7    // Enable
#define LCD1602_PORT    P0

void LCD1602_Clear();
void LCD1602_Init();
void LCD1602_ShowStr(uint8_t x, uint8_t y, const uint8_t str[]);

#ifdef __cplusplus
}
#endif

#endif
