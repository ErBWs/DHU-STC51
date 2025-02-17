#include "header.h"

volatile uint8_t temp[8] = {0, 53, 125, 45, 57, 81, 67, 101};
//volatile uint8_t tempData[8] = {0x00};
uint16_t total = 0;
uint8_t keyTmp = 0, key = 0;
uint8_t str[10] = "CH0: 00.0";

int main()
{
    ds18b20_init();
    UART_Init();
    LCD1602_Init();
    EnableTimerInterrupt_ms(TIM0, 10);

    while (1)
    {
        keyTmp = KeyboardScan();

        str[2] = key + 48;
        str[5] = temp[key - 1] / 100 % 10 + 48;
        str[6] = temp[key - 1] / 10 % 10 + 48;
        str[8] = temp[key - 1] % 10 + 48;

        UART_SendStr((const char *) str);
        LCD1602_ShowStr(0, 0, str);

        if (keyTmp != 0)
            key = keyTmp;
    }

    return 0;
}