// #include "led.h"
#include <stdio.h>
#define V_UINT32 volatile unsigned int
#define GPIOA 0x40020000U .....
#define GPIOG 0x40021800U
#define GPIOE 0x40021000U
#define GPIOC 0x40020800U
#define MODER 0x00U         // 00 input mode, 01 output mode
#define OSPEEDR 0x08U       // 11 very high speed
#define PUPDR 0x0CU         // Pull-up 01
#define BSRR 0x18U          // High 16 bit reset, low 16 bit set
#define AHB1ENR 0x40023830U // clock enable, 하위 11비트 IO Port Enable
#define IDR 0x10U           // input data read 상위 16개는 사용하지 않음
#define oneSec 36000000

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
    }
}

void myDelay(unsigned int delay)
{
    volatile int i;
    for (i = 0; i <= delay * (oneSec / 1000); i++)
        ;
}

void Init()
{
    // Clock C,E,G Enable
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 2 | 0x01 << 4 | 0x01 << 6;

    // Switch Enable

    // Switch 1 : PG3
    *((V_UINT32 *)(GPIOG | MODER)) &= ~(0x03 << 2 * 3);
    *((V_UINT32 *)(GPIOG | OSPEEDR)) &= ~(0x03 << 2 * 3);
    *((V_UINT32 *)(GPIOG | PUPDR)) &= ~(0x03 << 2 * 3);

    // Switch 2 : PC12
    // MODER : INPUT(00), OSPEEDR : LOW SPEED(00), PUPDR : No pull-up, No pull-down(00)
    *((V_UINT32 *)(GPIOC | MODER)) &= ~(0x03 << 2 * 12);
    *((V_UINT32 *)(GPIOC | OSPEEDR)) &= ~(0x03 << 2 * 12);
    *((V_UINT32 *)(GPIOC | PUPDR)) &= ~(0x03 << 2 * 12);

    // led enable
    *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 12 | 0x01 << 2 * 10;
    // OSPEEDR
    *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 12 | 0x03 << 2 * 10;
    // PUPDR
    *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 12 | 0x03 << 2 * 10;

    *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 5 | 0x01 << 2 * 4;
    //
    *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 5 | 0x03 << 2 * 4;
    // PUPDR
    *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 5 | 0x01 << 2 * 4;

    *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 6 | 0x01 << 2 * 5;
    *((V_UINT32 *)(GPIOE | BSRR)) |= 0x02 << 2 * 2 | 0x01 << 2 * 2;
}

// 01

int BTN_Check(unsigned int No){
    switch (No)
    {
    case 1:
        if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3))
            return 1;
        else
            return 0;
        break;
    case 2:
        if (*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))
            return 1;
        else
            return 0;
        break;
    }
}

// 02

int BTN_Check_BNB(int No, int Status){
    if (Status == 0){
        if (No == 1){
            if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)){return 1;}
            else return 0;
        }
        if (No == 2){
            if (*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12)){return 1;}
            else return 0;
        }
    }
    if (Status == 1){
        // 떼면 return
        if (No == 1){
            if (!(*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3))){return 0;}
            while(*((V_UINT32*)(GPIOG | IDR)) & (0x01 << 3));
            return 1;
        }
        if (No == 2){
            if (!(*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))){return 0;}
            while(*((V_UINT32*)(GPIOC | IDR)) & (0x01 << 12));
            return 1;
        }
    }
}

// 03

void LED_5_1(void){
    if(*((V_UINT32*)(GPIOG | IDR)) & (0x01 << 3)){
        for (int i = 0; i < 5; i++)
        {
            outSignal(1, 0);
            outSignal(2, 0);
            outSignal(3, 0);
            outSignal(4, 0);
            myDelay(500);
            outSignal(1, 1);
            outSignal(2, 1);
            outSignal(3, 1);
            outSignal(4, 1);
            myDelay(500);
        }
    }
    else return;
}

void LED_5_2(void){
    while(1){
        int n = 1;
        if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)){
            while(n <= 5){
            if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)){
                n = 1;
                continue;
            }
            else{
            *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 2 * 14 | 0x01 << 2 * 13;
            *((V_UINT32*)(GPIOE | BSRR)) |= 0x02 << 2 * 10 | 0x01 << 2 * 10;
            myDelay(500);
            *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 2 * 6 | 0x01 << 2 * 5;
            *((V_UINT32*)(GPIOE | BSRR)) |= 0x02 << 2 * 2 | 0x01 << 2 * 2;
            myDelay(500);
            }
            n++;
            }
        }
    }
}

int main()
{
    // hwInit();
    Init();
    
}