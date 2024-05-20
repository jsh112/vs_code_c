// #include "led.h"
#include <stdio.h>
#include <time.h>
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

void outSignal(unsigned char No, unsigned char Signal){
    switch(No){
        case 1:
            *((V_UINT32*)(GPIOG | BSRR)) |= (0x01 << 2 * 14) >> (16 * Signal);
            break;
        case 2:
            *((V_UINT32*)(GPIOE | BSRR)) |= (0x02 << 2 * 10) >> (16 * Signal);
            break;
        case 3:
            *((V_UINT32*)(GPIOE | BSRR)) |= (0x01 << 2 * 10) >> (16 * Signal);
            break;
        case 4:
            *((V_UINT32*)(GPIOG | BSRR)) |= (0x01 << 2 * 13) >> (16 * Signal);
            break;
    }
}



void myDelay(unsigned int delay){
    volatile int i;
    for(i = 0;i<=delay * (oneSec / 1000);i++);
}

int btn_check(){
    if((*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3))) return 1;
    if((*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))) return 2;
    if((*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)) && (*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))) return 3;
    if(!((*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)) && !(*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12)))) return 0;
}

void led_signal(unsigned int No, unsigned int cnt){

}

int ledpush(void){
    if((*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3))){
        while(!(*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12)));
        return 1;
    }
    if((*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))){
        while(!(*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)));
        return 2;
    }
    return 0;
}

int main(){
    // hwInit();

    // LED,Switch setting
    // Clock C,E,G Enable
    *((V_UINT32*)(AHB1ENR)) |= 0x01 << 2 | 0x01 << 4 | 0x01 << 6;

    // Switch Enable
    // Switch 1 : PC12
    // MODER : INPUT(00), OSPEEDR : LOW SPEED(00), PUPDR : No pull-up, No pull-down(00)
    *((V_UINT32*)(GPIOC | MODER)) &= ~(0x03 << 2 * 12);
    *((V_UINT32*)(GPIOC | OSPEEDR)) &= ~(0x03 << 2 * 12);
    *((V_UINT32*)(GPIOC | PUPDR)) &= ~(0x03 << 2 * 12);

    // Switch 2 : PG3
    *((V_UINT32*)(GPIOG | MODER)) &= ~(0x03 << 2 * 3);
    *((V_UINT32*)(GPIOG | OSPEEDR)) &= ~(0x03 << 2 * 3);
    *((V_UINT32*)(GPIOG | PUPDR)) &= ~(0x03 << 2 * 3);

    // led enable
	*((V_UINT32*) (GPIOG | MODER)) |= 0x01 << 2 * 12 | 0x01 << 2 * 10;
	// OSPEEDR
	*((V_UINT32*) (GPIOG | OSPEEDR)) |= 0x03 << 2 * 12 | 0x03 << 2 * 10;
	// PUPDR
	*((V_UINT32*) (GPIOG | PUPDR)) |= 0x01 << 2 * 12 | 0x03 << 2 * 10;

	*((V_UINT32*) (GPIOE | MODER)) |= 0x01 << 2 * 5 | 0x01 << 2 * 4;
	//
	*((V_UINT32*) (GPIOE | OSPEEDR)) |= 0x03 << 2 * 5 | 0x03 << 2 * 4;
	// PUPDR
	*((V_UINT32*) (GPIOE | PUPDR)) |= 0x01 << 2 * 5 | 0x01 << 2 * 4;

	*((V_UINT32*) (GPIOG | BSRR)) |= 0x01 << 2 * 6 | 0x01 << 2 * 5;
	*((V_UINT32*) (GPIOE | BSRR)) |= 0x02 << 2 * 2 | 0x01 << 2 * 2;

    while(1){
        int c = ledpush();
        if(c == 1) {
            outSignal(c,0);
            outSignal(2,1);
        }
        if(c == 2){
            outSignal(c,0);
            outSignal(1,1);
        }
    }
}