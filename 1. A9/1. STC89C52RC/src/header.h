/*!
 * Copyright (c) 2023, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef HEADER_H
#define HEADER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "isr.h"
#include "mcs51/8052.h"

// Driver
#include "driver/delay.h"
#include "driver/uart.h"
#include "driver/interrupt.h"

// Bsp
#include "bsp/as3461.h"
#include "bsp/keyboard.h"
#include "bsp/ds18b20.h"
#include "bsp/lcd1602.h"

#ifdef __cplusplus
}
#endif

#endif
