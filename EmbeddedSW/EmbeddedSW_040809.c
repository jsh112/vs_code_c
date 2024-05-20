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

// LED1 : PG12, LED2 : PE5, LED3 : PE4, LED4 : PG10

//  Delay Function
void MyDelay(unsigned int cnt)
{
    volatile unsigned int i;
    for (i = 0; i <= cnt * oneSec; i++)
        ;
}

// Turn LED1 ON
void LED1On()
{
    // Turn USER_LED1 ON
    // LED1 : PG12
    // AHB1ENR
    *((V_UINT32 *)(AHB1ENR)) |= 0b01 << G;

    // MODER
    *((V_UINT32 *)(GPIOG | MODER)) |= 0b01 << 2 * 12;
    // OSPEEDR
    *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b11 << 2 * 12;
    // PUPDR
    *((V_UINT32 *)(GPIOG | PUPDR)) |= 0b01 << 2 * 12;
    // BSRR
    *((V_UINT32 *)(GPIOG | BSRR)) |= 0b10 << 2 * 14;
}

// Turn LED2 ON
void LED2On()
{
    // LED2 : PE5
    // AHB1ENR
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 5;
    // MODER
    *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 5;
    // OSPEEDR
    *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 5;
    // PUPDR
    *((V_UINT32 *)(GPIOE | PUPDR)) |= 0b01 << 2 * 5;
    // BSRR
    *((V_UINT32 *)(GPIOE | BSRR)) |= 0x02 << 2 * 10;
}

// Turn LED3 ON
void LED3On()
{
    // LED3 : PE4
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 4;
    *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 4;
    *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 4;
    *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 4;
    *((V_UINT32 *)(GPIOE | BSRR)) |= 0x01 << 2 * 10;
}

// Turn LED4 ON
void LED4On()
{
    // LED4 : PG10
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 6;
    *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 10;
    *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 10;
    *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 10;
    *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 13;
}

// Turn LED(No) On
void TurnOnOneLED(unsigned char No)
{
    *((V_UINT32 *)(AHB1ENR)) |= 0b01 << 6;
    *((V_UINT32 *)(AHB1ENR)) |= 0b01 << 4;
    switch (No)
    {
    case 1:
        // LED1 : PG12
        // MODER
        *((V_UINT32 *)(GPIOG | MODER)) |= 0b01 << 2 * 12;
        // OSPEEDR
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b01 << 2 * 12;
        // PUPDR
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0b11 << 2 * 12;
        // BSRR
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 14;
        break;
    case 2:
        // LED2 : PE5
        *((V_UINT32 *)(GPIOE | MODER)) |= 0b01 << 2 * 5;
        // OSPEEDR
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b01 << 2 * 5;
        // PUPDR
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0b11 << 2 * 5;
        // BSRR
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 10;
        break;
    case 3:
        // LED3 : PE4
        *((V_UINT32 *)(GPIOE | MODER)) |= 0b01 << 2 * 4;
        // OSPEEDR
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b01 << 2 * 4;
        // PUPDR
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0b11 << 2 * 4;
        // BSRR
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0b01 << 2 * 10;
        break;
    case 4:
        // LED4 : PG10
        *((V_UINT32 *)(GPIOG | MODER)) |= 0b01 << 2 * 10;
        // OSPEEDR
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b01 << 2 * 10;
        // PUPDR
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0b11 << 2 * 10;
        // BSRR
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 13;
        break;
    default:
        break;
    }
}

// Turn LED(No) Off
void TurnOffOneLED(unsigned char No)
{
    *((V_UINT32 *)(AHB1ENR)) |= 0b01 << 6;
    *((V_UINT32 *)(AHB1ENR)) |= 0b01 << 4;
    switch (No)
    {
    case 1:
        // LED1 : PG12
        // MODER
        *((V_UINT32 *)(GPIOG | MODER)) |= 0b01 << 2 * 12;
        // OSPEEDR
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b01 << 2 * 12;
        // PUPDR
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0b11 << 2 * 12;
        // BSRR
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 6;
        break;
    case 2:
        // LED2 : PE5
        *((V_UINT32 *)(GPIOE | MODER)) |= 0b01 << 2 * 5;
        // OSPEEDR
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b01 << 2 * 5;
        // PUPDR
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0b11 << 2 * 5;
        // BSRR
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 2;
        break;
    case 3:
        // LED3 : PE4
        *((V_UINT32 *)(GPIOE | MODER)) |= 0b01 << 2 * 4;
        // OSPEEDR
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b01 << 2 * 4;
        // PUPDR
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0b11 << 2 * 4;
        // BSRR
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0b01 << 2 * 2;
        break;
    case 4:
        // LED4 : PG10
        *((V_UINT32 *)(GPIOG | MODER)) |= 0b01 << 2 * 10;
        // OSPEEDR
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b01 << 2 * 10;
        // PUPDR
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0b11 << 2 * 10;
        // BSRR
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 5;
        break;
    default:
        break;
    }
}

// LED1 On/Off
void LED1Cycle()
{
    // LED1 ON,OFF
    *((V_UINT32 *)(GPIOG | MODER)) |= 0b01 << 2 * 12;
    // OSPEEDR
    *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b11 << 2 * 12;
    // PUPDR
    *((V_UINT32 *)(GPIOG | PUPDR)) |= 0b01 << 2 * 12;
    // BSRR BR12 set -> ON
    *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 14;
    MyDelay(5);
    // BS12 set -> OFF
    *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0b01 << 2 * 14);
    *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 6;
    MyDelay(5);
}

// LED2 On/Off
void LED2Cycle()
{
    *((V_UINT32 *)(GPIOE | MODER)) |= 0b01 << 2 * 5;
    // OSPEEDR
    *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b11 << 2 * 5;
    // PUPDR
    *((V_UINT32 *)(GPIOE | PUPDR)) |= 0b01 << 2 * 5;
    // BSRR
    *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 10;
    MyDelay(5);
    *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0b10 << 2 * 10);
    *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 2;
    MyDelay(5);
}

// LED3 On/Off
void LED3Cycle()
{
    *((V_UINT32 *)(GPIOE | MODER)) |= 0b01 << 2 * 4;
    // OSPEEDR
    *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b11 << 2 * 4;
    // PUPDR
    *((V_UINT32 *)(GPIOE | PUPDR)) |= 0b01 << 2 * 4;
    // BSRR
    *((V_UINT32 *)(GPIOE | BSRR)) |= 0b01 << 2 * 10;
    MyDelay(5);
    *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0b01 << 2 * 10);
    *((V_UINT32 *)(GPIOE | BSRR)) |= 0b01 << 2 * 2;
    MyDelay(5);
}

// LED4 On/Off
void LED4Cycle()
{
    *((V_UINT32 *)(GPIOG | MODER)) |= 0b01 << 2 * 10;
    // OSPEEDR
    *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b11 << 2 * 10;
    // PUPDR
    *((V_UINT32 *)(GPIOG | PUPDR)) |= 0b01 << 2 * 10;
    // BSRR
    *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 13;
    MyDelay(5);
    *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0b01 << 2 * 13);
    *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 5;
    MyDelay(5);
}

// LED 1->2->3->4
void Cycle()
{
    // LED1->2->3->4
    *((V_UINT32 *)(AHB1ENR)) |= 0b01 << 6;
    *((V_UINT32 *)(AHB1ENR)) |= 0b01 << 4;

    while (1)
    {
        // LED1 ON,OFF
        *((V_UINT32 *)(GPIOG | MODER)) |= 0b01 << 2 * 12;
        // OSPEEDR
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b01 << 2 * 12;
        // PUPDR
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0b11 << 2 * 12;
        // BSRR
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 14;
        MyDelay(5);
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 6;
        MyDelay(5);
        // LED2

        *((V_UINT32 *)(GPIOE | MODER)) |= 0b01 << 2 * 5;
        // OSPEEDR
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b01 << 2 * 5;
        // PUPDR
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0b11 << 2 * 5;
        // BSRR
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 10;
        MyDelay(5);
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 3;
        MyDelay(5);

        // LED3

        *((V_UINT32 *)(GPIOE | MODER)) |= 0b01 << 2 * 4;
        // OSPEEDR
        *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b01 << 2 * 4;
        // PUPDR
        *((V_UINT32 *)(GPIOE | PUPDR)) |= 0b11 << 2 * 4;
        // BSRR
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0b01 << 2 * 10;
        MyDelay(5);
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0b01 << 2 * 3;
        MyDelay(5);

        // LED4
        *((V_UINT32 *)(GPIOG | MODER)) |= 0b01 << 2 * 10;
        // OSPEEDR
        *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b01 << 2 * 10;
        // PUPDR
        *((V_UINT32 *)(GPIOG | PUPDR)) |= 0b11 << 2 * 10;
        // BSRR
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 13;
        MyDelay(5);
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0b01 << 2 * 5;
        MyDelay(5);
    }
}

// No start, (No + 4) % 5 end cycle * Cnt
void CycleLED(unsigned char No, unsigned char Cnt)
{
    // No start, cnt is cycle cnt
    *((V_UINT32 *)(AHB1ENR)) |= 0b01 << 6;
    *((V_UINT32 *)(AHB1ENR)) |= 0b01 << 4;
    unsigned int i;
    switch (No)
    {
    case 1:
        for (i = 0; i < Cnt; i++)
        {
            LED1Cycle();
            LED2Cycle();
            LED3Cycle();
            LED4Cycle();
        }
        break;
    case 2:
        for (i = 0; i < Cnt; i++)
        {
            LED2Cycle();
            LED3Cycle();
            LED4Cycle();
            LED1Cycle();
        }
        break;
    case 3:
        for (i = 0; i < Cnt; i++)
        {
            LED3Cycle();
            LED4Cycle();
            LED1Cycle();
            LED2Cycle();
        }
        break;
    case 4:
        for (i = 0; i < Cnt; i++)
        {
            LED4Cycle();
            LED1Cycle();
            LED2Cycle();
            LED3Cycle();
        }
        break;
    default:
        break;
    }
}

// Odd -> LED1, LED3 cycle, Even -> LED2, LED4 cycle
void OddEven(unsigned char N, unsigned char Cnt)
{
    int i;
    // LED1 : PG12, LED2 : PE5, LED3 : PE4, LED4 : PG10

    // Clock Enable
    *((V_UINT32 *)(AHB1ENR)) |= (0x01) << 6;
    *((V_UINT32 *)(AHB1ENR)) |= (0x01) << 4;
    if (N % 2 != 0)
    {
        // If N is odd
        for (i = 0; i < Cnt; i++)
        {
            // LED1 ON
            *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 12;
            *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b11 << 2 * 12;
            *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 12;
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 14;
            MyDelay(5);

            // LED3 ON
            *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 4;
            // OSPEEDR
            *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b11 << 2 * 4;
            // PUPDR
            *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 4;
            // BSRR
            *((V_UINT32 *)(GPIOE | BSRR)) |= 0x01 << 2 * 10;
            MyDelay(5);

            // LED1 OFF
            *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0x01 << 2 * 14);
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 6;
            MyDelay(5);

            // LED3 OFF
            *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0x01 << 2 * 10);
            *((V_UINT32 *)(GPIOE | BSRR)) |= 0x01 << 2 * 2;
            MyDelay(5);
        }
    }
    else
    {
        // N is even
        for (i = 0; i < Cnt; i++)
        {
            // LED2 ON
            *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 5;
            // OSPEEDR
            *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b11 << 2 * 5;
            // PUPDR
            *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 5;
            // BSRR
            *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 10;
            MyDelay(5);

            // LED4 ON
            *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 10;
            // OSPEEDR
            *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b11 << 2 * 10;
            // PUPDR
            *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 10;
            // BSRR
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 13;
            MyDelay(5);

            // LED2 OFF
            *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0b10 << 2 * 10);
            *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 2;
            MyDelay(5);

            // LED4 OFF
            *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0x01 << 2 * 13);
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 5;
        }
    }
}

// 240411 examples
// No : LED(No), status : ON/OFF
void ControlLED(unsigned char No, unsigned char status)
{
    // Clock Enable
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << E; // PORTE Enable
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << G; // PORTE Enable
    if (status)
    {
        // LED ON status
        // LED1 : PG12, LED2 : PE5, LED3 : PE4, LED4 : PG10
        switch (No)
        {
        case 1:
            // LED1 ON
            *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 12;
            *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b11 << 2 * 12;
            *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 12;
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 14;
            break;
        case 2:
            // LED2 ON
            *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 5;
            *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b11 << 2 * 5;
            *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 5;
            *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 10;
            break;
        case 3:
            // LED3 ON
            *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 4;
            *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0b11 << 2 * 4;
            *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 4;
            *((V_UINT32 *)(GPIOE | BSRR)) |= 0b01 << 2 * 10;
            break;
        case 4:
            *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 10;
            *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0b11 << 2 * 10;
            *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 10;
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 13;
            break;
        default:
            break;
        }
    }
    else
    {
        // LED OFF status
        switch (No)
        {
        case 1:
            // LED1 OFF
            *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0x01 << 2 * 14);
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 6;
            break;
        case 2:
            *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0b10 << 2 * 10);
            *((V_UINT32 *)(GPIOE | BSRR)) |= 0b10 << 2 * 2;
            break;
        case 3:
            *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0b01 << 2 * 10);
            *((V_UINT32 *)(GPIOE | BSRR)) |= 0b01 << 2 * 2;
            break;
        case 4:
            *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0x01 << 2 * 13);
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 5;
            break;
        default:
            break;
        }
    }
}

// No : 1~No On
void LEDLevel(unsigned char No)
{

    // Clock Enable
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << E;
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << G;

    switch (No)
    {
    case 1:
        // LED1 ON
        *((V_UINT32 *)(GPIOG | MODER)) = 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) = 0b11 << 2 * 12;
        *((V_UINT32 *)(GPIOG | PUPDR)) = 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 14;
        break;
    case 2:
        *((V_UINT32 *)(GPIOG | MODER)) = 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) = 0b11 << 2 * 12;
        *((V_UINT32 *)(GPIOG | PUPDR)) = 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 14;

        *((V_UINT32 *)(GPIOE | MODER)) = 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) = 0b11 << 2 * 5;
        *((V_UINT32 *)(GPIOE | PUPDR)) = 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x02 << 2 * 10;
        break;
    case 3:
        *((V_UINT32 *)(GPIOG | MODER)) = 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) = 0b11 << 2 * 12;
        *((V_UINT32 *)(GPIOG | PUPDR)) = 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 14;

        *((V_UINT32 *)(GPIOE | MODER)) = 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) = 0b11 << 2 * 5;
        *((V_UINT32 *)(GPIOE | PUPDR)) = 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x02 << 2 * 10;

        *((V_UINT32 *)(GPIOE | MODER)) = 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) = 0b11 << 2 * 4;
        *((V_UINT32 *)(GPIOE | PUPDR)) = 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x01 << 2 * 10;
        break;
    case 4:
        *((V_UINT32 *)(GPIOG | MODER)) = 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) = 0b11 << 2 * 12;
        *((V_UINT32 *)(GPIOG | PUPDR)) = 0x01 << 2 * 12;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 14;

        *((V_UINT32 *)(GPIOE | MODER)) = 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) = 0b11 << 2 * 5;
        *((V_UINT32 *)(GPIOE | PUPDR)) = 0x01 << 2 * 5;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x02 << 2 * 10;

        *((V_UINT32 *)(GPIOE | MODER)) = 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | OSPEEDR)) = 0b11 << 2 * 4;
        *((V_UINT32 *)(GPIOE | PUPDR)) = 0x01 << 2 * 4;
        *((V_UINT32 *)(GPIOE | BSRR)) |= 0x01 << 2 * 10;

        *((V_UINT32 *)(GPIOG | MODER)) = 0x01 << 2 * 10;
        *((V_UINT32 *)(GPIOG | OSPEEDR)) = 0b11 << 2 * 10;
        *((V_UINT32 *)(GPIOG | PUPDR)) = 0x01 << 2 * 10;
        *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 13;
        break;
    default:
        break;
    }
}

// binary calculator
void CalcBinary_USER1(unsigned char No)
{
    if (No > 15)
        return;
    else
    {
        // No is less than 16
        // Clock Enable
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 4;
        *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 6;

        *((V_UINT32 *)(GPIOG | BSRR)) &= 0x00;
        *((V_UINT32 *)(GPIOE | BSRR)) &= 0x00;
        int i;
        for (i = 1; i <= 4 && No >= 1; i++)
        {
            ControlLED(i, No % 2);
            No = No / 2;
        }
    }
}

void CalcBinary_USER4(unsigned char No)
{
    if (No > 15)
        return;
    else
    {
        int i;
        *((V_UINT32 *)(AHB1ENR)) = 0x01 << 4;
        *((V_UINT32 *)(AHB1ENR)) = 0x01 << 6;

        *((V_UINT32 *)(GPIOE | BSRR)) &= 0x00;
        *((V_UINT32 *)(GPIOG | BSRR)) &= 0x00;
        for (i = 4; i >= 1 && No >= 1; i--)
        {
            ControlLED(i, No % 2);
            No = No / 2;
        }
    }
}

// test SW_USER1
void test_switch()
{
    // clock enable
    int i;
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << E;
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << G;
    // 스위치가 안눌리면 1, 눌리면 0
    if ((*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 2 * 5)) == 0)
        for (i = 0; i < 5; i++)
            LED1Cycle();
    else
        return;
}

void LED1Off()
{
    *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0x01 << 2 * 14);
    *((V_UINT32 *)(GPIOG | BSRR)) |= (0x01 << 2 * 6);
}

void LED2Off()
{
    *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0b10 << 2 * 10);
    *((V_UINT32 *)(GPIOE | BSRR)) |= (0b10 << 2 * 2);
}

void LED3Off()
{
    *((V_UINT32 *)(GPIOE | BSRR)) &= ~(0x01 << 2 * 10);
    *((V_UINT32 *)(GPIOE | BSRR)) |= (0x01 << 2 * 2);
}

void LED4Off()
{
    *((V_UINT32 *)(GPIOG | BSRR)) &= ~(0x01 << 2 * 13);
    *((V_UINT32 *)(GPIOG | BSRR)) |= (0x01 << 2 * 5);
}

// void LEDOnOff(unsigned int a){
//     // Clock Enable
//     *((V_UINT32*)(AHB1ENR)) |= 0x01 << 4;
//     *((V_UINT32*)(AHB1ENR)) |= 0x01 << 6;

//     // 속성 0과 F 구별
//     unsigned int a1 = 0x00000000;
//     unsigned int a2 = 0x00000000;
//     unsigned int a3 = 0x00000000;
//     unsigned int a4 = 0x00000000;

//     a1 = a1 | (a >> 2 * 12); // 상위 1바이트
//     a2 = a2 | (a >> 2 * 8);  // 상위 2바이트
//     a3 = a3 | (a >> 2 * 4);  // 상위 3바이트
//     a4 = a4 | a;
//     a1 &= 0x00FF;
//     a2 &= 0x00FF;
//     a3 &= 0x00FF;
//     a4 &= 0x00FF;

//     // an && 0x000000F0이 1이면 F, 0이면 0
//     if(a1 & 0x000000F0 == 0x0000F0) LED1On();
//     else if(a1 & 0x000000F0 == 0) LED1Off();
//     else{
//         int cnt = a1 & 0x000000F;
//         int k = a1 & 0x000000F0;
//         for(int i=0;i<cnt;i++){
//             if(cnt % 2 == 0){
//                 LED1On();
//                 MyDelay(0.5);
//                 LED1Off();
//                 MyDelay(0.5);
//             }
//             else{
//                 LED1Off();
//                 MyDelay(0.5);
//                 LED1On();
//                 MyDelay(0.5);
//             }
//         }
//     }

//     if(a2 & 0x000000F0 == 0x0000F0) LED2On();
//     else if(a2 & 0x000000F0 == 0) LED2Off();
//     else{
//         int cnt = a2 & 0x000000F;
//         int k = a2 & 0x000000F0;
//         for(int i=0;i<cnt;i++){
//             if(cnt % 2 == 0){
//                 LED2On();
//                 MyDelay(0.5);
//                 LED2Off();
//                 MyDelay(0.5);
//             }
//             else{
//                 LED2Off();
//                 MyDelay(0.5);
//                 LED2On();
//                 MyDelay(0.5);
//             }
//         }
//     }

//     if(a3 & 0x000000F0 == 0x0000F0) LED3On();
//     else if(a3 & 0x000000F0 == 0) LED3Off();
//     else{
//         int cnt = a3 & 0x000000F;
//         int k = a3 & 0x000000F0;
//         for(int i=0;i<cnt;i++){
//             if(cnt % 2 == 0){
//                 LED3On();
//                 MyDelay(0.5);
//                 LED3Off();
//                 MyDelay(0.5);
//             }
//             else{
//                 LED3Off();
//                 MyDelay(0.5);
//                 LED3On();
//                 MyDelay(0.5);
//             }
//         }
//     }

//     if(a4 & 0x000000F0 == 0x0000F0) LED1On();
//     else if(a4 & 0x000000F0 == 0) LED1Off();
//     else{
//         int cnt = a4 & 0x000000F;
//         int k = a4 & 0x000000F0;
//         for(int i=0;i<cnt;i++){
//             if(cnt % 2 == 0){
//                 LED4On();
//                 MyDelay(0.5);
//                 LED4Off();
//                 MyDelay(0.5);
//             }
//             else{
//                 LED4Off();
//                 MyDelay(0.5);
//                 LED4On();
//                 MyDelay(0.5);
//             }
//         }
//     }
// }

// void MyApp_0411(){
//     //LEDOnOff(0xF0F0F1FF);
//     // 모든 LED ON
//     // MyDelay(5);

//     // LEDOnOff(0x0000010F);
//     // // 모든 LED off
//     // MyDelay(5);

//     // LEDOnOff(0x15FF2A01);
//     // // 1번 LED 5번, 3번 LED 10번 동시점멸
//     // // 2번은 켜고, 4번은 끈다
//     // // 즉, 2는 켜져있고 4는 꺼져있고 1,3이 동시점멸을 하는데 1은 on으로 시작 3은 off로 시작
//     // LEDOnOff(0x0F0F0F0F);

//     // // 모든 LED Off
//     // MyDelay(5);

//     // LEDOnOff(0xA3138323);
// }

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

void LEDOnOff(unsigned int No)
{
    unsigned int bits[4];
    int on[4];
    int off[4];
    int onoff[4];
    int offon[4];

    // bit masking
    bits[3] = (No >> 24) & 0xff;
    bits[2] = (No >> 16) & 0xff;
    bits[1] = (No >> 8) & 0xff;
    bits[0] = (No) & 0xff;

    for (int i = 0; i < 4; i++)
    {
        unsigned int p1 = bits[i] & 0xf0;
        unsigned int p2 = bits[i] & 0x0f;

        if (p1 == 0xf0)
            on[i] = 1;
        else if (p1 == 0)
            off[i] = 1;
        else
        {
            if (p2 % 2 == 0 && p2 != 0)
            {
                onoff[i] = p2;
            }
            else if (p2 % 2 != 0)
            {
                offon[i] = p2;
            }
            else
            {
                off[i] = 1;
            }
        }
    }

    for (int j = 0; j < 4; j++)
    {
        if (on[j])
            LEDOn(j + 1);
        if (off[j])
            LEDOff(j + 1);
        else
            continue;
    }
}

void MyApp_test()
{
    // LEDOnoff(0xF0F0F1FF);
    MyDelay(5);
}
int main()
{
    // printf("AHB1ENR is 0x%08x\n", 0b01 << G);
    // printf("MODER is 0x%08x\n", 0b01 << 2 * 12);
    // printf("OSPEEDR is 0x%08x\n", 0b11 << 2 * 12);
    // printf("PUPDR is 0x%08x\n", 0b01 << 2 * 12);
    // printf("BSRR is 0x%08x\n", 0b10 << 2 * 10); // odd : 0b10, even : 0b01 20,21 -> 2 * 10

    // unsigned int a = 0xF0F0F1FF;

    // unsigned int a1 = 0x00000000;
    // unsigned int a2 = 0x00000000;
    // unsigned int a3 = 0x00000000;
    // unsigned int a4 = 0x00000000;

    // a1 = a1 | (a >> 2 * 12); // 상위 1바이트
    // a2 = a2 | (a >> 2 * 8);  // 상위 2바이트
    // a3 = a3 | (a >> 2 * 4);  // 상위 3바이트
    // a4 = a4 | a;
    // a1 &= 0xFF;
    // a2 &= 0xFF;
    // a3 &= 0xFF;
    // a4 &= 0xFF;

    // printf("%x\n",a1);
    // printf("%x\n",a2);
    // printf("%x\n",a3);
    // printf("%x\n",a4);
    // printf("\n");
    // printf("0x%x\n",a1 && 0xF0);
    // printf("0x%x\n",a4 && 0xF0);

    // printf("0x%x\n",(a1&0x000000F0));
    // printf("0x%x\n",(a1&0x000000F0)>>4 * 1);
}

// void LEDOnOff(unsigned int a){
//     // Clock Enable
//     *((V_UINT32*)(AHB1ENR)) |= 0x01 << 4;
//     *((V_UINT32*)(AHB1ENR)) |= 0x01 << 6;

//     // 속성 0과 F 구별
//     unsigned int a1 = 0x00000000;
//     unsigned int a2 = 0x00000000;
//     unsigned int a3 = 0x00000000;
//     unsigned int a4 = 0x00000000;

//     a1 = a1 | (a >> 2 * 12); // 상위 1바이트
//     a2 = a2 | (a >> 2 * 8);  // 상위 2바이트
//     a3 = a3 | (a >> 2 * 4);  // 상위 3바이트
//     a4 = a4 | a;
//     a1 &= 0xFF;
//     a2 &= 0xFF;
//     a3 &= 0xFF;
//     a4 &= 0xFF;

//     // an && 0x000000F0이 1이면 F, 0이면 0
//     if(a1 && 0x000000F0 == 0x01) LED1On();
//     else if(a1 && 0x000000F0 == 0) LED1Off();
//     else{
//         int cnt = a1 & 0x000000F;
//         int k = (a1 & 0x000000F0) >> 4;
//         for(int i=0;i<cnt;i++){
//             if(cnt % 2 == 0){
//                 LED1On();
//                 MyDelay(0.5);
//                 LED1Off();
//                 MyDelay(0.5);
//             }
//             else{
//                 LED1Off();
//                 MyDelay(0.5);
//                 LED1On();
//                 MyDelay(0.5);
//             }
//         }
//     }

//     if(a2 && 0x000000F0 == 0x01) LED2On();
//     else if(a2 && 0x000000F0 == 0) LED2Off();
//     else{
//         int cnt = a2 & 0x000000F;
//         int k = a2 & 0x000000F0;
//         for(int i=0;i<cnt;i++){
//             if(cnt % 2 == 0){
//                 LED2On();
//                 MyDelay(0.5);
//                 LED2Off();
//                 MyDelay(0.5);
//             }
//             else{
//                 LED2Off();
//                 MyDelay(0.5);
//                 LED2On();
//                 MyDelay(0.5);
//             }
//         }
//     }

//     if(a3 && 0x000000F0 == 0x1) LED3On();
//     else if(a3 && 0x000000F0 == 0) LED3Off();
//     else{
//         int cnt = a3 & 0x000000F;
//         int k = a3 & 0x000000F0;
//         for(int i=0;i<cnt;i++){
//             if(cnt % 2 == 0){
//                 LED3On();
//                 MyDelay(0.5);
//                 LED3Off();
//                 MyDelay(0.5);
//             }
//             else{
//                 LED3Off();
//                 MyDelay(0.5);
//                 LED3On();
//                 MyDelay(0.5);
//             }
//         }
//     }

//     if(a4 && 0x000000F0 == 0x1) LED4On();
//     else if(a4 && 0x000000F0 == 0) LED4Off();
//     else{
//         int cnt = a4 & 0x000000F;
//         int k = a4 & 0x000000F0;
//         for(int i=0;i<cnt;i++){
//             if(cnt % 2 == 0){
//                 LED4On();
//                 MyDelay(0.5);
//                 LED4Off();
//                 MyDelay(0.5);
//             }
//             else{
//                 LED4Off();
//                 MyDelay(0.5);
//                 LED4On();
//                 MyDelay(0.5);
//             }
//         }
//     }
// }