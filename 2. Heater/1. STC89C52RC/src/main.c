#include "header.h"

volatile uint16_t temp[3] = {0, 250, 0}; //current, set, ds18, 250 => 25.0
bool heating_switch = false;
uint16_t total = 0;
uint8_t key = 0;
uint8_t str[10] = "CH0: 00.0";
uint8_t adc = 0;

#define HEATER_PIN          P1_7
#define LED_IDLE_PIN        P3_3
#define LED_HEATING_PIN     P3_2

void heater_control(void)
{
    if (temp[0] < temp[1] && heating_switch) {
        HEATER_PIN = 1;
        LED_HEATING_PIN = 0;
        LED_IDLE_PIN = 1;
    } else {
        HEATER_PIN = 0;
        LED_HEATING_PIN = 1;
        LED_IDLE_PIN = 0;
    }
}

int main()
{
    ds18b20_init();
    UART_Init();
    LCD1602_Init();
    EnableTimerInterrupt_ms(TIM0, 10);

    while (1) {
        key_scan();
        heater_control();

        temp[0] = (uint16_t) (calculate_temp(adc) * 10);

        str[2] = key + 48;
        str[5] = temp[key] / 100 % 10 + 48;
        str[6] = temp[key] / 10 % 10 + 48;
        str[8] = temp[key] % 10 + 48;

        UART_SendStr((const char *) str);
        LCD1602_ShowStr(0, 0, str);
    }

    return 0;
}