/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef THERMOMETER_LCD1602_H
#define THERMOMETER_LCD1602_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "mcs51/8052.h"
#include "driver/delay.h"

// Macros
#define LCD1602_RW      P2_5    // Read/write selection
#define LCD1602_RS      P2_6    // Register selection
#define LCD1602_E       P2_7    // Enable
#define LCD1602_PORT    P0

#ifdef __cplusplus
}
#endif

#endif
