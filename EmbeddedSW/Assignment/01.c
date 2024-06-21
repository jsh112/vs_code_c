//#include "led.h"
#include <stdio.h>
#define V_UINT32 volatile unsigned int
#define GPIOA 0x40020000U .....
#define GPIOG 0x40021800U
#define GPIOE 0x40021000U
#define GPIOC 0x40020800U

#define MODER 0x00U         // 00 input mode, 01 output mode
#define OSPEEDR 0x08U       // 11 very high speed
#define PUPDR 0x0CU        // Pull-up 01
#define BSRR 0x18U          // High 16 bit reset, low 16 bit set
#define AHB1ENR 0x40023830U // clock enable, 하위 11비트 IO Port Enable
#define IDR 0x10U           // input data read 상위 16개는 사용하지 않음
#define oneSec 36000000

#define TIME 5000
#define DELAY 200


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



int prob_1(unsigned int mode)
{
	int cnt = 0;
    unsigned int Timer1 = 0;
    if (mode == 1){

        while (1){
            if (Timer1 >= TIME) return cnt;
            if (BtnCheck() == 1) cnt++;
            if (BtnCheck() == 2) cnt++;
            Timer1 += DELAY;
            delay(DELAY);
        }
    }
    if (mode == 2)
    {
        int ledState = 1;
        // int presseDetected = 0;
        while (1) {
            if (BtnCheck() == 1) cnt++;
            if (BtnCheck() == 2) cnt++;
            ledState = !ledState;

								if(ledState){
                    *((V_UINT32*)(led1.port + BSRR)) |= led1.on;
                    *((V_UINT32*)(led2.port + BSRR)) |= led2.on;
                    *((V_UINT32*)(led3.port + BSRR)) |= led3.on;
                    *((V_UINT32*)(led4.port + BSRR)) |= led4.on;
                }
                else{
                    *((V_UINT32*)(led1.port + BSRR)) |= led1.off;
                    *((V_UINT32*)(led2.port + BSRR)) |= led2.off;
                    *((V_UINT32*)(led3.port + BSRR)) |= led3.off;
                    *((V_UINT32*)(led4.port + BSRR)) |= led4.off;
                }
            Timer1 += DELAY;
            delay(DELAY);
            if(Timer1 >= TIME) return cnt;
        }
    }
}

int main(){
    hwInit();
    LedInit(&led1);
    LedInit(&led2);
    LedInit(&led3);
    LedInit(&led4);
    BtnInit(&btn1);
    BtnInit(&btn2);


    unsigned int mode = 2;
    while(BtnCheck() == 0);
    int cnt = prob_1(mode);
    *((V_UINT32*)(led1.port + BSRR)) |= led1.off;
    *((V_UINT32*)(led2.port + BSRR)) |= led2.off;
    *((V_UINT32*)(led3.port + BSRR)) |= led3.off;
    *((V_UINT32*)(led4.port + BSRR)) |= led4.off;
    for(int i=0;i<cnt;i++){
    	*((V_UINT32*)(led3.port + BSRR)) |= led3.on;
    	delay(200);
    	*((V_UINT32*)(led3.port + BSRR)) |= led3.off;
    	delay(200);
    }
}
