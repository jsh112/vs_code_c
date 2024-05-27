#include "gpio.h"
#include "led_switch.h"
#include "Timer_Interrupt.h"

int main(){
    hwInit();

    // PC12 : Button 2 Init
    BtnInit(&btn2);

    // RCC_APB2ENR -> SYSCFG Clock Enable
    *((V_UINT32*)(APB2ENR)) |= (1 << 14);

    // Link PC12 and EXTI12
    *((V_UINT32*)(SYSCFG + EXTICR4)) &= ~(0xF << 0);
    *((V_UINT32*)(SYSCFG + EXTICR4)) |= (0x2 << 0);

    // Enable EXTI12 Interrupt line
    *((V_UINT32*)(EXTI + IMR)) |= (1 << 12);

    // Set Falling Edge EXTI12
    *((V_UINT32*)(EXTI + FTSR)) |= (1 << 12);

    *((V_UINT32*)(0xE000E100 + (40 / 32) * 4)) = (1 << (40 % 32)); // EXTI15_10_IRQn = 40, NVIC ISER

    led_t l[4] = {led1,led2,led3,led4};
    for(int i=0;i<4;i++){
    	LedInit(&l[i]);
    	outSignal(&l[i],1);
    }

    while (1) {
        // 인터럽트 발생안했을 때 지속적으로 수행할 동작코드
        for(int i=0; i<4; i++){ outSignal(&l[i],0); }
        for(int i=0; i<36000000; i++){}
        for(int i=0; i<4; i++){ outSignal(&l[i],1); }
        for(int i=0; i<36000000; i++){}
      }
}

void EXTI15_10_IRQHandler(){
	 // Check Interrupt 12 is triggered
	 if(*((V_UINT32*)(EXTI + PR)) & (1 << 12)){
		 // after 2 sec interrupt clear
		 *((V_UINT32*)(EXTI + PR)) |= (1 << 12);
		 for(int i=0; i<36000000 * 2; i++){}
	 }
}
