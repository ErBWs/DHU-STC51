/*!
 * Copyright (c) 2023, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "delay.h"

/*!
 * @brief   Soft delay with unit 11.0592MHz xtal
 *
 * @param   n   Delay time
 * @return  none
 */
void SoftDelay_ms(uint32_t n)
{
    uint32_t i, y;
    for (i = n; i > 0; i--)
        for (y = 114; y > 0; y--);
}