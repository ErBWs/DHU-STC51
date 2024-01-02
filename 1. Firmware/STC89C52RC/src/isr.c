/*!
 * Copyright (c) 2023, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "isr.h"

extern uint8_t i;
uint8_t j = 10;
void TIM0_isr() __interrupt(1)
{
    j--;
    if (j == 0)
    {
        i >>= 1;
        j = 10;
    }
}

void TIM1_isr() __interrupt(3)
{

}