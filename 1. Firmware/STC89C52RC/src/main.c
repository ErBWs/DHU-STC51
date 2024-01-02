#include "mcs51/8052.h"
#include "header.h"

uint8_t i = 0x80;
int main()
{
    uint8_t modeFlag = 0;
//    EnableTimerInterrupt_ms(TIM0, 10);

    while (1)
    {
        P1_7 = 0;
        if (P1_3 == 0)
           modeFlag = 1;    // Led
        if (P1_2 == 0)
            modeFlag = 2;   // Buzzer
        if (P1_1 == 0)
            modeFlag = 3;   // Digital
        if (P1_0 == 0)
            modeFlag = 0;

        switch (modeFlag)
        {
        case 1:
            P2 = ~i;
            SoftDelay_ms(100);
            i >>= 1;
            if (i == 0)
                i = 0x80;
            break;
        case 2:
            P2_5 = 0;
            SoftDelay_ms(1);
            P2_5 = 1;
            break;
        case 3:
            P2 = 0x00;
            P0 = 0x66;
            SoftDelay_ms(1);
            P2 = 0x04;
            P0 = 0x4f;
            SoftDelay_ms(1);
            P2 = 0x08;
            P0 = 0x5b;
            SoftDelay_ms(1);
            P2 = 0x0c;
            P0 = 0x06;
            SoftDelay_ms(1);
            break;
        default:
            break;
        }

//        P2_0 = 0;
//        P0 = 0x39; C
//        P0 = 0x63; o
    }

    return 0;
}