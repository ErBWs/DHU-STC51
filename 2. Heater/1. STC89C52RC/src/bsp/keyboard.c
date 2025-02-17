/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#include "keyboard.h"

extern volatile uint16_t temp[3]; //current, set, ds18, 100 => 10.0
extern bool heating_switch;

void key_scan(void)
{
    if (BUTTON_UP == 0) {
        temp[1] += 10;
        while (!BUTTON_UP);
    }
    if (BUTTON_DOWN == 0) {
        temp[1] -= 10;
        while (!BUTTON_DOWN);
    }
    if (BUTTON_DISPLAY == 0) {
        key = (key + 1) % 3;
        while (!BUTTON_DISPLAY);
    }
    if (BUTTON_SWITCH == 0) {
        heating_switch = !heating_switch;
        while (!BUTTON_SWITCH);
    }
}