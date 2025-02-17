/*!
 * Copyright (c) 2024, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "mcs51/8052.h"

#define BUTTON_UP           P1_3
#define BUTTON_DOWN         P1_4
#define BUTTON_DISPLAY      P1_5
#define BUTTON_SWITCH       P1_6

void key_scan(void);

#ifdef __cplusplus
}
#endif

#endif
