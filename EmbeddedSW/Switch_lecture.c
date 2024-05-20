#include <stdio.h>
#define V_UINT32 volatile unsigned int
#define GPIOA 0x40020000U .....
#define GPIOE 0x40021000U
#define GPIOC 0x40020800U
#define GPIOG 0x40021800U
#define MODER 0x00U         // 00 input mode, 01 output mode
#define OSPEEDR 0x08U       // 11 very high speed
#define PUPDR 0x0CU         // Pull-up 01
#define BSRR 0x18U          // High 16 bit reset, low 16 bit set
#define AHB1ENR 0x40023830U // clock enable, 하위 11비트 IO Port Enable
#define IDR 0x10U           // input data read 상위 16개는 사용하지 않음
#define oneSec 36000000

void my_switch1(void)
{
    // Clock C, G Enable(Switch2 and LED1)
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 2 | 0x01 << 4 | 0x01 << 6;
    // LED Input
    *((V_UINT32 *)(GPIOC | MODER)) &= ~(0x03 << 2 * 12);
    // SPEED low
    *((V_UINT32 *)(GPIOC | OSPEEDR)) &= ~(0x03 << 2 * 12);
    // PUPDR
    *((V_UINT32 *)(GPIOC | PUPDR)) &= ~(0x03 << 2 * 12);

    // pg12 set
    *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 12;
    *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 12;
    *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 12;

    while (1)
    {
        if (*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 14;
        else
            *((V_UINT32 *)(GPIOG | BSRR)) |= 0x01 << 2 * 6;
    }
}

void my_switch2(void)
{
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 2 | 0x01 << 4 | 0x01 << 6;

    while (1)
    {
    }
}

int DelayWithBTN(volatile int n)
{
    n = n * 10000000; // 1 milion
    while (n--)
    {
        // if(btn-1 == pressed && btn-2 == pressed) return 3;
        // elif(btn -1 == pressed) return 1;
        // elif(btn -2 == pressed) return 2;
    }
    return 0;
}

int BTN_Check(int No)
{
    switch (No)
    {
    case 1:
        if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3))
        {
            return 1;
        }
        else
            return 0;
        break;
    case 2:
        if (*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))
        {
            return 1;
        }
        else
            return 0;
        break;
    default:
        break;
    }
}

void myDelay(unsigned int delay){
    volatile unsigned int i;
    for(i=0;i<=delay * (oneSec/1000);i++);
}

int main()
{
    // hwInit();
    //  clock enable
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 2 | 0x01 << 4 | 0x01 << 6;

    // Switch enable
    // Input
    *((V_UINT32 *)(GPIOC | MODER)) &= ~(0x03 << 2 * 12);
    // SPEED low
    *((V_UINT32 *)(GPIOC | OSPEEDR)) &= ~(0x03 << 2 * 12);
    // PUPDR
    *((V_UINT32 *)(GPIOC | PUPDR)) &= ~(0x03 << 2 * 12);

    // LED Input
    *((V_UINT32 *)(GPIOG | MODER)) &= ~(0x03 << 2 * 3);
    // SPEED low
    *((V_UINT32 *)(GPIOG | OSPEEDR)) &= ~(0x03 << 2 * 3);
    // PUPDR
    *((V_UINT32 *)(GPIOG | PUPDR)) &= ~(0x03 << 2 * 3);

    // led enable
    *((V_UINT32 *)(GPIOG | MODER)) |= 0x01 << 2 * 12 | 0x01 << 2 * 10;
    //
    *((V_UINT32 *)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 12 | 0x03 << 2 * 10;
    // PUPDR
    *((V_UINT32 *)(GPIOG | PUPDR)) |= 0x01 << 2 * 12 | 0x03 << 2 * 10;

    *((V_UINT32 *)(GPIOE | MODER)) |= 0x01 << 2 * 5 | 0x01 << 2 * 4;
    //
    *((V_UINT32 *)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 5 | 0x03 << 2 * 4;
    // PUPDR
    *((V_UINT32 *)(GPIOE | PUPDR)) |= 0x01 << 2 * 5 | 0x01 << 2 * 4;

    *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 2 * 6 | 0x01 << 2 * 5;
	*((V_UINT32*)(GPIOE | BSRR)) |= 0x02 << 2 * 2 | 0x01 << 2 * 2;

    while(1){
        int n = 1;
        if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)){
            do{
            if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)){
                n = 1;
                continue;
            }
            *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 2 * 14;
	        *((V_UINT32*)(GPIOE | BSRR)) |= 0x02 << 2 * 10;
            *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 2 * 13;
	        *((V_UINT32*)(GPIOE | BSRR)) |= 0x01 << 2 * 10;
            myDelay(500);
            *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 2 * 6 | 0x01 << 2 * 5;
	        *((V_UINT32*)(GPIOE | BSRR)) |= 0x02 << 2 * 2 | 0x01 << 2 * 2;
            myDelay(500);
            n++;
            }while(n <= 5);
        }
    }
}



int BTN_Check_BNB(int No, int Status)
{
    if (Status == 0)
    {
        if (No == 1)
        {
            if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3))
            {
                return 1;
            }
            else
                return 0;
        }
        else if (No == 2)
        {
            if (*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))
            {
                return 1;
            }
            else
                return 0;
        }
    }
    else if (Status == 1)
    {
        // 떼면 return
        if (No == 1)
        {
            if (!(*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)))
            {
                return 0;
            }
            else
            {
                while (1)
                {
                    if (!(*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)))
                    {
                        return 1;
                    }
                }
            }
        }
        else if (No == 2)
        {
            if (!(*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12)))
            {
                return 0;
            }
            else
            {
                while (1)
                {
                    if (!(*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12)))
                    {
                        return 1;
                    }
                }
            }
        }
    }
}

