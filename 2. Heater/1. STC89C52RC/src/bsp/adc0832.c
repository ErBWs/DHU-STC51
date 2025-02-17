/*!
 * Copyright (c) 2025, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "adc0832.h"

uint8_t adc_read_data(uint8_t channel)
{
    uint8_t i, dat0 = 0, dat1 = 0;

    ADC0832_CS = 0;
    ADC0832_CLK = 0;

    ADC0832_DIO = 1;
    DELAY;
    ADC0832_CLK = 1;
    DELAY;
    ADC0832_CLK = 0;
    ADC0832_DIO = 1;
    DELAY;

    ADC0832_CLK = 1;
    DELAY;
    ADC0832_CLK = 0;
    ADC0832_DIO = channel;
    DELAY;
    ADC0832_CLK = 1;
    DELAY;
    ADC0832_CLK = 0;
    ADC0832_DIO = 1;
    DELAY;
    for (i = 0; i < 8; i++) {
        ADC0832_CLK = 1;
        DELAY;
        ADC0832_CLK = 0;
        DELAY;
        dat0 = dat0 << 1 | ADC0832_DIO;
    }
    for (i = 0; i < 8; i++) {
        dat1 = dat1 | ((uint8_t) (ADC0832_DIO) << i);
        ADC0832_CLK = 1;
        DELAY;
        ADC0832_CLK = 0;
        DELAY;
    }
    ADC0832_CS = 1;
    return (dat0 == dat1) ? dat0 : 0;
}

float calculate_temp(uint8_t adc_val)
{
    float tempV = (float)adc_val * 5 / 255;
    float current = (5 - tempV) / Rp;
    float rt = tempV / current;
    return ((Bx * T25) / (T25 * (logf(rt) - logf(ntcR25)) + Bx)) - Ka;
}