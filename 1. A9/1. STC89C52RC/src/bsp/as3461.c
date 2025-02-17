/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "as3461.h"

// Digits of 0-9
uint8_t digitCode[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void AS3461_Display(const uint8_t *dat)
{
    for (int i = 0; i < 8; ++i)
    {
        if (dat[i] == 0x00)
            continue;

        switch (i)
        {
        case 0: AS3461_SEL = 0x1c;
            break;
        case 1: AS3461_SEL = 0x18;
            break;
        case 2: AS3461_SEL = 0x14;
            break;
        case 3: AS3461_SEL = 0x10;
            break;
        case 4: AS3461_SEL = 0x0c;
            break;
        case 5: AS3461_SEL = 0x08;
            break;
        case 6: AS3461_SEL = 0x04;
            break;
        case 7: AS3461_SEL = 0x00;
            break;
        default:
            break;
        }

        AS3461_SEG = dat[i];
        SoftDelay_us(70);
        AS3461_SEG = 0x00;
    }
}