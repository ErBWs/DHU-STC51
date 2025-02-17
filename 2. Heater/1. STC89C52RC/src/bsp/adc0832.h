/*!
 * Copyright (c) 2025, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef ADC0832_H
#define ADC0832_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"
#include "mcs51/8052.h"

#define ADC0832_CS      P1_2
#define ADC0832_CLK     P1_0
#define ADC0832_DIO     P1_1

#define T25 (273.15+25)
#define Bx (4050.0)
#define Ka (273.15)
#define Rp (10000.0)
#define ntcR25 (10000.0)

#define DELAY   \
        __asm   \
        nop     \
        nop     \
        __endasm

uint8_t adc_read_data(uint8_t channel);

float calculate_temp(uint8_t adc_val);

#ifdef __cplusplus
}
#endif

#endif
