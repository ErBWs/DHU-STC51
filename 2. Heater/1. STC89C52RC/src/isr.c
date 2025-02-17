/*!
 * Copyright (c) 2023, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "isr.h"

extern volatile uint8_t temp[8];
extern uint16_t total;
uint8_t j = 15, i = 0;

void TIM0_isr() __interrupt(1)
{
    j--;
    if (j != 0)
        return;

    j = 15;
    total += (uint16_t) (ds18b20_read_temperture() * 10);
    i++;

    if (i == 8)
    {
        temp[0] = total / 8;
        total = 0;
        i = 0;
    }
}

void TIM1_isr() __interrupt(3)
{

}