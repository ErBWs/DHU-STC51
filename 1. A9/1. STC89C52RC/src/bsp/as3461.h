/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef AS3461_H
#define AS3461_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "mcs51/8052.h"
#include "driver/delay.h"

// Macros
#define AS3461_SEL      P2
#define AS3461_SEG      P0

extern uint8_t digitCode[10];
void AS3461_Display(const uint8_t *dat);

#ifdef __cplusplus
}
#endif

#endif
