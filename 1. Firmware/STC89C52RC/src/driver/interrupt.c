/*!
 * Copyright (c) 2023, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "interrupt.h"

#define SYS_CLOCK    11059200

void EnableTimerInterrupt_ms(TIM_e timer, uint32_t ms)
{
    uint16_t temp;
    temp = 65536 - (SYS_CLOCK / (12 * (1000 / ms)));

    switch (timer)
    {
    case TIM0:
        TMOD |= 0x01;
        TL0 = temp;
        TH0 = temp >> 8;
        ET0 = 1;
        TR0 = 1;
        break;
    case TIM1:
        TMOD |= 0x10;
        TL1 = temp;
        TH1 = temp >> 8;
        ET1 = 1;
        TR1 = 1;
        break;
    default:
        break;
    }

    EA = 1;
}