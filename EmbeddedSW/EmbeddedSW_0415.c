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
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define I 8
#define J 9
#define K 10

void MyDelay(unsigned int n)
{
    volatile unsigned int delay;
    for (delay = 0; delay <= n * oneSec; delay++)
        ;
}

void LEDOn(unsigned int No)
{
    // Clock E,G enable
    *((V_UINT32 *)AHB1ENR) |= 0x01 << 4 | 0x01 << 6;

    switch (No)
    {
    case 1:
        *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 12;
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 14;
        break;
    case 2:
        *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 5;
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x02 << 2 * 10;
        break;
    case 3:
        *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 4;
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x01 << 2 * 10;
        break;
    case 4:
        *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 10;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 10;
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 10;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 13;
        break;
    default:
        break;
    }
}

void LEDOff(unsigned int No)
{
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 4 | 0x01 << 6;

    switch (No)
    {
    case 1:
        *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0x01 << 2 * 14);
        *((V_UINT32 *)(GPIOG | BSRR)) |= (0x01 << 2 * 6);
        break;
    case 2:
        *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0x02 << 2 * 10);
        *((V_UINT32 *)(GPIOE | BSRR)) |= (0x02 << 2 * 2);
        break;
    case 3:
        *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0x01 << 2 * 10);
        *((V_UINT32 *)(GPIOE | BSRR)) |= (0x01 << 2 * 2);
        break;
    case 4:
        *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0x01 << 2 * 13);
        *((V_UINT32 *)(GPIOG | BSRR)) |= (0x01 << 2 * 5);
        break;
    default:
        break;
    }
}

typedef struct
{
    int status; // 1 -> offon, 2 -> onoff
    int n;
} INFO;

void MyDelay_half(unsigned int No){
    volatile int delay;
    for(delay=0;delay <= No * (oneSec/2);delay++);
}

void LEDOnOff(unsigned int No)
{

    *((V_UINT32*)(GPIOG | BSRR)) &= 0x00;
    *((V_UINT32*)(GPIOE | BSRR)) &= 0x00;
    unsigned int bits[4];
    int on[4] = {0};
    int off[4] = {0};
    // int onoff[4] = {0};
    // int offon[4] = {0};

    INFO info[4] = {0, 0};

    // bit masking
    bits[0] = (No >> 24) & 0xff;
    bits[1] = (No >> 16) & 0xff;
    bits[2] = (No >> 8) & 0xff;
    bits[3] = (No) & 0xff;

    for (int i = 0; i < 4; i++)
    {
        unsigned int p1 = (bits[i]>>4) & 0x0f;
        unsigned int p2 = bits[i] & 0x0f;

        if (p1 == 0x0f)
            on[i] = 1;
        else if (p1 == 0)
            off[i] = 1;
        else
        {
            if (p1 % 2 == 0 && p1 != 0)
            {
                // 짝수 on off
                // onoff[i] = p2;
                info[i].status = 2;
                info[i].n = p2;
            }
            else if (p1 % 2 != 0)
            {
                // 홀수 off on
                // offon[i] = p2;
                info[i].status = 1;
                info[i].n = p2;
            }
            else
            {
                off[i] = 1;
            }
        }
    }

    int cnt[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        if (info[i].status != 0)
            cnt[i] = info[i].n;
        if (on[i])
            LEDOn(i + 1);
        if (off[i])
            LEDOff(i + 1);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            if (cnt[j] < cnt[j + 1])
            { // 버블 정렬 사용
                int temp = cnt[j];
                cnt[j] = cnt[j + 1];
                cnt[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < cnt[0]; k++)
    {
        // 0 ~ (cnt[0] - 1)
        for (int i = 0; i < 4; i++)
        {
            if (info[i].n != 0 && info[i].n >= k + 1)
            {
                if (info[i].status == 1)
                    LEDOff(i + 1);
                if (info[i].status == 2)
                    LEDOn(i + 1);
            }
            else
                continue;
        }
        MyDelay_1(0.5);
        for (int i = 0; i < 4; i++)
        {
            if (info[i].n != 0 && info[i].n >= k + 1)
            {
                if (info[i].status == 1)
                    LEDOn(i + 1);
                if (info[i].status == 2)
                    LEDOff(i + 1);
            }
            else
                continue;
        }
        MyDelay_1(0.5);
    }
}

void MyApp_test()
{
    LEDOnOff(0xF0F0F1FF);
    MyDelay(5);

    LEDOnOff(0x0000010F);
    MyDelay(5);

    LEDOnOff(0x15FF2A01);

    LEDOnOff(0x0F0F0F0F);
    MyDelay(5);

    LEDOnOff(0xA3138323);
}

// int main()
// {
//     unsigned int No = 0x15FF2A01;

//     unsigned int bits[4];
//     int on[4] = {0};
//     int off[4] = {0};
//     int onoff[4] = {0};
//     int offon[4] = {0};

//     INFO info[4] = {0, 0};

//     bit masking
//     bits[0] = (No >> 24) & 0xff;
//     bits[1] = (No >> 16) & 0xff;
//     bits[2] = (No >> 8) & 0xff;
//     bits[3] = (No) & 0xff;

//     for (int i = 0; i < 4; i++)
//     {
//         unsigned int p1 = bits[i] & 0xf0;
//         unsigned int p2 = bits[i] & 0x0f;

//         if (p1 == 0xf0)
//             on[i] = 1;
//         else if (p1 == 0)
//             off[i] = 1;
//         else
//         {
//             if ((p1 >> 4) % 2 == 0 && p1 != 0)
//             {
//                 짝수 on off
//                 onoff[i] = p2;
//                 info[i].status = 2;
//                 info[i].n = p2;
//             }
//             else if ((p1 >> 4) % 2 != 0)
//             {
//                 홀수 off on
//                 offon[i] = p2;
//                 info[i].status = 1;
//                 info[i].n = p2;
//             }
//             else
//             {
//                 off[i] = 1;
//             }
//         }
//     }

//     int cnt[4] = {0};
//     for (int i = 0; i < 4; i++)
//     {
//         if (info[i].status != 0)
//             cnt[i] = info[i].n;
//         if (on[i])
//             LEDOn(i + 1);
//         if (off[i])
//             LEDOff(i + 1);
//     }

//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 3 - i; j++)
//         {
//             if (cnt[j] < cnt[j + 1])
//             { // 버블 정렬 사용
//                 int temp = cnt[j];
//                 cnt[j] = cnt[j + 1];
//                 cnt[j + 1] = temp;
//             }
//         }
//     }

//     return 0;
// }
