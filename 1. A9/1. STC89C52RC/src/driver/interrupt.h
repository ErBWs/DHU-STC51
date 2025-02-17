/*!
 * Copyright (c) 2023, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef INTERRUPT_H
#define INTERRUPT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "mcs51/8052.h"

#define SYS_CLOCK    11059200

typedef enum
{
    TIM0,
    TIM1
} TIM_e;

void EnableTimerInterrupt_ms(TIM_e timer, uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif
