/*!
 * Copyright (c) 2023, ErBW_s
 * All rights reserved.
 * 
 * @author  Baohan
 */

#ifndef _DELAY_H
#define _DELAY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "mcs51/8052.h"

void SoftDelay_ms(uint32_t n);

#ifdef __cplusplus
}
#endif

#endif
