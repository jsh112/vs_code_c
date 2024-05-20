// #include "led.h"
#include <stdio.h>
#define V_UINT32 volatile unsigned int
#define GPIOA 0x40020000U .....
#define GPIOE 0x40021000U
#define GPIOG 0x40021800U
#define MODER 0x00U         // 00 input mode, 01 output mode
#define OSPEEDR 0x08U       // 11 very high speed
#define PUPDR 0x0CU         // Pull-up 01
#define BSRR 0x18U          // High 16 bit reset, low 16 bit set
#define AHB1ENR 0x40023830U // clock enable, 하위 11비트 IO Port Enable
#define IDR 0x10U           // input data read 상위 16개는 사용하지 않음
#define oneSec 36000000

void myDelay(unsigned int delay)
{
    volatile unsigned int i;
    for (i = 0; i <= delay * (oneSec / 1000); i++)
        ;
}

void outSignal(unsigned char No, unsigned char Signal)
{
    switch (No)
    {
    case 1:
        *((V_UINT32 *)(GPIOG | BSRR)) |= (0x01 << 2 * 14) >> (16 * Signal);
        break;
    case 2:
        *((V_UINT32 *)(GPIOE | BSRR)) |= (0x02 << 2 * 10) >> (16 * Signal);
        break;
    case 3:
        *((V_UINT32 *)(GPIOE | BSRR)) |= (0x01 << 2 * 10) >> (16 * Signal);
        break;
    case 4:
        *((V_UINT32 *)(GPIOG | BSRR)) |= (0x01 << 2 * 13) >> (16 * Signal);
        break;
    default:
        break;
    }
}

// 0415

typedef struct
{
    unsigned int status;
    unsigned int duration;
} INFO;

void LEDOnOff(unsigned int No)
{
    INFO info[4] = {0, 0};
    unsigned int cnt[4] = {0};

    for (int i = 0; i < 4; i++)
    {
        info[i].status = (No >> 4 * (7 - 2 * i)) & 0xf;
        info[i].duration = (No >> 4 * (6 - 2 * i)) & 0xf;
        if (info[i].status == 0)
            outSignal(i + 1, 1);
        else if (info[i].status == 0xf)
            outSignal(i + 1, 0);
        else
            cnt[i] = info[i].duration;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < (4 - 1 - i); j++)
        {
            if (cnt[j] < cnt[j + 1])
            {
                unsigned int tmp = cnt[j + 1];
                cnt[j + 1] = cnt[j];
                cnt[j] = tmp;
            }
        }
    }

    for (int k = 0; k < cnt[0]; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (info[i].duration != 0 && info[i].duration >= k + 1 && !((info[i].status == 0xf) || info[i].status == 0))
            {
                if (info[i].status % 2 != 0)
                    outSignal(i + 1, 1);
                if (info[i].status % 2 == 0)
                    outSignal(i + 1, 0);
            }
        }
        myDelay(500);
        for (int i = 0; i < 4; i++)
        {
            if (info[i].duration != 0 && info[i].duration >= k + 1 && !((info[i].status == 0xf) || info[i].status == 0))
            {
                if (info[i].status % 2 != 0)
                    outSignal(i + 1, 0);
                if (info[i].status % 2 == 0)
                    outSignal(i + 1, 1);
            }
        }
        myDelay(500);
    }
}

// 0416

void userLedInit(unsigned char No)
{
    switch (No)
    {
    case 1:
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 6;
        *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 12;
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 6;
        break;
    case 2:
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 4;
        *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 5;
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x02 << 2 * 2;
        break;
    case 3:
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 4;
        *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 4;
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x01 << 2 * 2;
        break;
    case 4:
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 6;
        *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 10;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 10;
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 10;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 5;
        break;
    default:
        break;
    }
}

void ledShift(unsigned char No)
{
    outSignal(1, 1);
    for (int i = No; i <= 4; i++)
    {
        outSignal(i, 0);
        myDelay(800);
        outSignal(i, 1);
        myDelay(800);
    }
    for (int i = 3; i >= 1; i--)
    {
        outSignal(i, 0);
        myDelay(800);
        if (i == 1)
            return;
        outSignal(i, 1);
        myDelay(800);
    }
}

void LEDBlink(unsigned char num)
{
    unsigned char bits[4];
    for (int i = 0; i < 4; i++)
        bits[i] = ((num >> (6 - 2 * i)) & 0b11) + 1;

    for (int i = 0; i < 4; i++)
    {
        outSignal(bits[i], 0);
        myDelay(500);
        outSignal(bits[i], 1);
        myDelay(500);
    }

    for (int i = 0; i < 4; i++)
        outSignal(i, 1);
}

void ledTop(unsigned int delay)
{
    int no = 0;
    for (int i = 1; i < 5; i++)
        outSignal(i, 1);
    while (1)
    {
        if (no == 4)
            break;
        for (int k = 1; k <= (4 - no); k++)
        {
            outSignal(k, 0);
            myDelay(delay * 100);
            if (k == (4 - no))
            {
                myDelay(delay * 100);
                continue;
            }
            outSignal(k, 1);
            myDelay(delay * 100);
        }
        no++;
    }
}

typedef struct
{
    unsigned int pin;
    unsigned int duration;
} A;

void led1(unsigned int no)
{
    A a[4];
    unsigned int cnt[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        a[i].pin = (no >> 4 * (7 - 2 * i)) & 0xf;
        a[i].duration = (no >> 4 * (6 - 2 * i)) & 0xf;
        cnt[i] = a[i].duration;
    }

    for (int i = 0; i < (4 - 1); i++)
    {
        for (int j = 0; j < (4 - 1 - i); j++)
        {
            if (cnt[j] < cnt[j + 1])
            {
                unsigned int tmp = cnt[j];
                cnt[j] = cnt[j + 1];
                cnt[j + 1] = tmp;
            }
        }
    }

    for (int k = 0; k < cnt[0]; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            unsigned int p = a[i].pin;
            unsigned int d = a[i].duration;
            if (d >= k + 1)
            {
                outSignal(p + 1, 0);
            }
        }
        myDelay(500);
        for (int i = 0; i < 4; i++)
        {
            unsigned int p = a[i].pin;
            unsigned int d = a[i].duration;
            if (d >= k + 1)
            {
                outSignal(p + 1, 1);
            }
        }
        myDelay(500);
    }
}

void led2(unsigned char no)
{
    INFO a[2];
    unsigned int cnt[2];
    for (int i = 0; i < 2; i++)
    {
        a[i].status = (no >> (7 - 4 * i)) & 0b1;
        a[i].duration = (no >> (4 - 4 * i)) & 0b111;
        cnt[i] = a[i].duration;
    }
    if (cnt[0] > cnt[1])
    {
        unsigned int tmp = cnt[1];
        cnt[1] = cnt[0];
        cnt[0] = tmp;
    }

    for (int k = 0; k < cnt[1]; k++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (a[i].duration >= k + 1)
            {
                if (a[i].status % 2 == 0)
                {
                    if (a[i].duration % 2 == 0)
                    {
                        outSignal(1, 0);
                        outSignal(3, 0);
                    }
                    else
                    {
                        outSignal(1, 1);
                        outSignal(3, 1);
                    }
                }
                else
                {
                    if (a[i].duration % 2 == 0)
                    {
                        outSignal(2, 0);
                        outSignal(4, 0);
                    }
                    else
                    {
                        outSignal(2, 1);
                        outSignal(4, 1);
                    }
                }
            }
        }
        myDelay(500);
        for (int i = 0; i < 2; i++)
        {
            if (a[i].duration >= k + 1)
            {
                if (a[i].status % 2 == 0)
                {
                    if (a[i].duration % 2 == 0)
                    {
                        outSignal(1, 1);
                        outSignal(3, 1);
                    }
                    else
                    {
                        outSignal(1, 0);
                        outSignal(3, 0);
                    }
                }
                else
                {
                    if (a[i].duration % 2 == 0)
                    {
                        outSignal(2, 1);
                        outSignal(4, 1);
                    }
                    else
                    {
                        outSignal(2, 0);
                        outSignal(4, 0);
                    }
                }
            }
        }
        myDelay(500);
    }
}

void led3(unsigned int no)
{
    A a[4] = {0, 0};
    unsigned int cnt[4];
    for (int i = 0; i < 4; i++)
    {
        a[i].pin = ((no >> 4 * (7 - 2 * i)) & 0xf) / 4 + 1;
        a[i].duration = ((no >> 4 * (6 - 2 * i)) & 0xf);
        cnt[i] = a[i].duration;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < (4 - 1 - i); j++)
        {
            if (cnt[j] < cnt[j + 1])
            {
                unsigned int tmp = cnt[j];
                cnt[j] = cnt[j + 1];
                cnt[j + 1] = tmp;
            }
        }
    }

    //    for(int i=0;i<4;i++){printf("%d\n",cnt[i]);}

    for (int k = 0; k < cnt[0]; k++)
    {
        printf("cycle %d\n\n", k + 1);
        for (int i = 0; i < 4; i++)
        {
            if (a[i].duration >= k + 1)
            {
                printf("led %d on \n", a[i].pin);
                // outSignal(a[i].pin, 0);
            }
        }
        // myDelay(500);
        for (int i = 0; i < 4; i++)
        {
            if (a[i].duration >= k + 1)
            {
                // outSignal(a[i].pin, 1);
                printf("led %d off \n", a[i].pin);
            }
        }
        // myDelay(500);
        printf("\n");
    }
}

typedef struct
{
    unsigned int pin;
    unsigned int delay;
} D;

void led4(unsigned int no)
{
    D d[4] = {0, 0};
    unsigned int cnt[4] = {0};
    unsigned int gcd;
    for (int i = 0; i < 4; i++)
    {
        d[i].pin = i + 1;
        d[i].delay = (no >> 4 * (7 - 2 * i)) & 0xf;
        cnt[i] = d[i].delay;
    }

    for (int i = 1; i <= cnt[0] && i <= cnt[1] && i <= cnt[2] && i <= cnt[3]; ++i)
    {
        if (cnt[0] % i == 0 && cnt[1] % i == 0 && cnt[2] % i == 0 && cnt[3] % i == 0)
        {
            gcd = i;
        }
    }
    for (int i = 1; i <= 60; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i % d[j].delay == 0 && i != 1)
            {
                outSignal(d[j].pin, 0);
            }
            else
            {
                outSignal(d[j].pin, 1);
            }
        }
        myDelay(500);
        for (int j = 0; j < 3; j++)
        {
            if (i % d[j].delay == 0 && i != 1)
            {
                outSignal(d[j].pin, 1);
            }
            else
            {
                outSignal(d[j].pin, 0);
            }
        }
        myDelay(500);
    }
}

int main()
{
    // hwInit();
    // for(int i=0;i<5;i++){userLedInit(i);}
    unsigned int no = 0x70f215a2;

    for (int i = 0; i < 4; i++)
    {
        printf("%d %d\n", ((no >> 4 * (7 - 2 * i)) & 0xf) / 4 + 1, ((no >> 4 * (6 - 2 * i)) & 0xf));
    }
    printf("\n");
    led3(no);

    return 0;
}

// 0x 01 02 03 04

/*`for (int i = 1; i <= 60; i++)
{
    for (int j = 0; j < 3; j++)
    {
        if (i % a[j].delay == 0 && i != 1)
        {
            outSignal(a[j].pin, 0);
        }
        else
        {
            outSignal(a[j].pin, 1);
        }
    }
    myDelay(500);
    for (int j = 0; j < 3; j++)
    {
        if (i % a[j].delay == 0 && i != 1)
        {
            outSignal(a[j].pin, 1);
        }
        else
        {
            outSignal(a[j].pin, 0);
        }
    }
}*/

