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

#define KEYBOARD_PORT   P1

uint8_t KeyboardScan();

#ifdef __cplusplus
}
#endif

#endif
