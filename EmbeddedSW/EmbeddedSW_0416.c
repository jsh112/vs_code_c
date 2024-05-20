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

void myDelay(unsigned int n)
{
    volatile unsigned int delay;
    for (delay = 0; delay <= n * (oneSec / 1000); delay++)
        ;
}

void outSignal(unsigned char No, unsigned char Signal)
{
    if (Signal == 0)
    {
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
    else
    {
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
}

void userLedInit(unsigned char No)
{
    switch (No)
    {
    case 0:
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 6;
        *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 12;
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 14;
        break;
    case 1:
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 4;
        *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 5;
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x02 << 2 * 10;
        break;
    case 2:
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 4;
        *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 4;
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x01 << 2 * 10;
        break;
    case 3:
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 6;
        *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 10;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 10;
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 10;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 13;
        break;
    default:
        break;
    }
}

void ledShift(unsigned char No)
{
    for (int i = No; i <= 4; i++)
    {
        if (No == 4)
            continue;
        outSignal(i, 0);
        myDelay(500);
    }
    for (int j = 4; j >= 1; j--)
    {
        outSignal(j, 0);
        myDelay(500);
    }
}

void ledTop(unsigned int delay)
{

    for (int i = 0; i < 5; i++)
    {
        userLedInit(i);
    }
    outSignal(1, 0);
    myDelay(delay * 100);
    outSignal(1, 1);
    outSignal(2, 0);
    myDelay(delay * 100);
    outSignal(2, 1);
    outSignal(3, 0);
    myDelay(delay * 100);
    outSignal(3, 1);
    outSignal(4, 0);
    myDelay(delay * 100);

    outSignal(1, 0);
    myDelay(delay * 100);
    outSignal(1, 1);
    outSignal(2, 0);
    myDelay(delay * 100);
    outSignal(2, 1);
    outSignal(3, 0);
    myDelay(delay * 100);

    outSignal(1, 0);
    myDelay(delay * 100);
    outSignal(1, 1);
    outSignal(2, 0);
    myDelay(delay * 100);

    outSignal(1, 0);
    myDelay(delay * 100);
}

void ledBlink(unsigned char Number){
    unsigned int a1 = Number >> 6 & 0b11 + 1;
    unsigned int a2 = Number >> 4 & 0b11 + 1;
    unsigned int a3 = Number >> 2 & 0b11 + 1;
    unsigned int a4 = Number  & 0b11 + 1;

    outSignal(a1,0);
    myDelay(100);
    outSignal(a1,1);
    myDelay(100);

    outSignal(a2,0);
    myDelay(100);
    outSignal(a2,1);
    myDelay(100);

    outSignal(a3,0);
    myDelay(100);
    outSignal(a3,1);
    myDelay(100);

    outSignal(a4,0);
    myDelay(100);
    outSignal(a4,1);
    myDelay(100);

    for(int i=1;i<=4;i++){
        outSignal(i,1);
    }
    
}

int main(){
    
}