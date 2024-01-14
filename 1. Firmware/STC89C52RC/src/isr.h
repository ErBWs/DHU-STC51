/*!
 * Copyright (c) 2023, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef ISR_H
#define ISR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "mcs51/8052.h"
#include "header.h"

void TIM0_isr() __interrupt(1);
void TIM1_isr() __interrupt(3);

#ifdef __cplusplus
}
#endif

#endif
