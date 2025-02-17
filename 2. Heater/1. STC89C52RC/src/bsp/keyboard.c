/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "keyboard.h"

uint8_t KeyboardScan()
{
    uint8_t keyVal = 0;
    
    KEYBOARD_PORT = 0x0f;
    if (KEYBOARD_PORT != 0x0f)
    {
        KEYBOARD_PORT = 0x0f;
        switch (KEYBOARD_PORT)
        {
        case 0x07: keyVal = 1;
            break;
        case 0x0b: keyVal = 2;
            break;
        case 0x0d: keyVal = 3;
            break;
        case 0x0e: keyVal = 4;
            break;
        default:
            break;
        }

        KEYBOARD_PORT = 0xf0;
        switch (KEYBOARD_PORT)
        {
        case 0x70: keyVal = keyVal;
            break;
        case 0xb0: keyVal += 4;
            break;
        case 0xd0: keyVal += 8;
            break;
        case 0xe0: keyVal += 12;
            break;
        default:
            break;
        }
    } else
        keyVal = 0;

    return keyVal;
}