/*!
 * Copyright (c) 2023, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "delay.h"


void SoftDelay_ms(uint32_t ms)
{
    uint16_t i;
    do {
        i = SYS_CLOCK / 6000 + 1;
        while(--i);
    }while(--ms);
}


void SoftDelay_us(uint32_t us)
{
    uint16_t i;
    do {
        i = SYS_CLOCK / 7000000 + 1;
        while(--i);
    }while(--us);
}