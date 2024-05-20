#include "led.h"

// LED functions and settings

typedef struct{
    V_UINT32 port;
    V_UINT32 mode;
    V_UINT32 speed;
    V_UINT32 pupd;
    V_UINT32 on;
    V_UINT32 off;
}led_t;

led_t led1 = {GPIOG,(0x01 << 24),(0x03 << 24),(0x01 << 24),(0x01 << 28),(0x01 << 12)};
led_t led2 = {GPIOE,(0x01 << 10),(0x03 << 10),(0x01 << 10),(0x02 << 20),(0x02 << 4)};
led_t led3 = {GPIOE,(0x01 << 8),(0x03 << 8),(0x01 << 8),(0x01 << 20),(0x01 << 4)};
led_t led4 = {GPIOG,(0x01 << 20),(0x03 << 20),(0x01 << 20),(0x01 << 26),(0x01 << 10)};

void LedInit(led_t *led){
    *((V_UINT32*)(AHB1ENR)) |= 0x01 << 4 | 0x01 << 6;

    *((V_UINT32*)(led->port + MODER)) |= led->mode;
    *((V_UINT32*)(led->port + OSPEEDR)) |= led->speed;
    *((V_UINT32*)(led->port + PUPDR)) |= led->pupd;
    *((V_UINT32*)(led->port + BSRR)) |= led->off;
}

// Switch functions and settings

typedef struct
{
    V_UINT32 port;
    V_UINT32 data;
    V_UINT32 input_data;
} btn_t;

btn_t btn1 = {GPIOG,(0x03 << 6),(0x01 << 3)};
btn_t btn2 = {GPIOC,(0x03 << 24),(0x01 << 12)};

void BtnInit(btn_t *btn){
    *((V_UINT32*)(AHB1ENR)) |= 0x01 << 2 | 0x01 << 6;

    *((V_UINT32*)(btn->port + MODER)) &= ~(btn->data);
    *((V_UINT32*)(btn->port + OSPEEDR)) &= ~(btn->data);
    *((V_UINT32*)(btn->port + PUPDR)) &= ~(btn->data);
}

void delay(unsigned int ms)
{
    volatile int time;
    for (time = 0; time <= ms * (oneSec / 1000); time++);
}

int BtnCheck()
{
    int status = 0;
    if (*((V_UINT32 *)(GPIOG + IDR)) & (0x01 << 3))
        status += 1;
    if (*((V_UINT32 *)(GPIOC + IDR)) & (0x01 << 12))
        status += 2;
    return status;
}

int main(){
			hwInit();
	    /*LedInit(&led1);
	    LedInit(&led2);
	    LedInit(&led3);
	    LedInit(&led4);
	    BtnInit(&btn1);
	    BtnInit(&btn2);*/
	    *((V_UINT32*)(AHB1ENR)) |= 0x01 << 6;

	    *((V_UINT32*)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 7;
	    *((V_UINT32*)(GPIOG | PUPDR)) |= 0x01 << 2 * 7;

	    *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << (7 + 16);


	    // 7-segment
        // clock C, F, G Enable
        // PF10 : A1, PF9 : A2, PF8 : A3, PC2 : D8, PC1 : D7, PC7 : D0, PC6 : D1
        // PG6 : D2, PG7 : D4
        // PF : 10,9,8
        // PC : 1, 6, 7
        // PG : 6, 7
	    *((V_UINT32*)(AHB1ENR)) |= 0x01 << 3 | 0x01 << 5 | 0x01 << 6;

        // PORT F
        *((V_UINT32*)(GPIOF + MODER)) &= ~(0x03 << 2 * 8) | ~(0x03 << 2 * 9) | ~(0x03 << 2 * 10);
        *((V_UINT32*)(GPIOF + OSPEEDR)) &= ~(0x03 << 2 * 8) | ~(0x03 << 2 * 9) | ~(0x03 << 2 * 10);
        *((V_UINT32*)(GPIOF + PUPDR)) &= ~(0x03 << 2 * 8) | ~(0x03 << 2 * 9) | ~(0x03 << 2 * 10);

        // PORTC
        *((V_UINT32*)(GPIOC + MODER)) &= ~(0x03 << 2 * 1) | ~(0x03 << 2 * 6) | ~(0x03 << 2 * 7);
        *((V_UINT32*)(GPIOC + OSPEEDR)) &= ~(0x03 << 2 * 1) | ~(0x03 << 2 * 6) | ~(0x03 << 2 * 7);
        *((V_UINT32*)(GPIOC + PUPDR)) &= ~(0x03 << 2 * 1) | ~(0x03 << 2 * 6) | ~(0x03 << 2 * 7);

        // PORTG
        *((V_UINT32*)(GPIOG + MODER)) &= ~(0x03 << 2 *7) | ~(0x03 << 2 * 6);
        *((V_UINT32*)(GPIOG + OSPEEDR)) &= ~(0x03 << 2 * 7) | ~(0x03 << 2 * 6);
        *((V_UINT32*)(GPIOG + PUPDR)) &= ~(0x03 << 2 * 7) | ~(0x03 << 2 * 6);

}
