#ifndef _ds18b20_H
#define _ds18b20_H

#include <stdint.h>
#include "mcs51/8052.h"
#include "driver/delay.h"

//管脚定义
#define DS18B20_PORT    P3_7

#define DELAY   \
        __asm   \
        nop     \
        nop     \
        __endasm


//函数声明
uint8_t ds18b20_init(void);

float ds18b20_read_temperture(void);

#endif