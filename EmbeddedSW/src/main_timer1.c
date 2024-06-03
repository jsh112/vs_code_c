#include "gpio.h"
#include "led_switch.h"
#include "Timer_Interrupt.h"

int main(){
    hwInit();

    // Enable RCC APB2ENR, TIM1EN enable
    *((V_UINT32*)(APB2ENR)) |= 0x01;
    led_t l[4] = {led1,led2,led3,led4};

    *((V_UINT32*)(TIM1 + PSC)) |= 21600 * 5 - 1; // TIM1 Prescaler
    *((V_UINT32*)(TIM1 + ARR)) |= 9999;
    *((V_UINT32*)(TIM1 + DIER)) |= 0x01;  // update interrupt enabled
    *((V_UINT32*)(TIM1 + CR1)) |= 0x01;   // TIM1 CR1 CEN enable
    *((V_UINT32*)(TIM1 + SR)) &= 0x01;    // TIM1 SR UIF clear

    *((V_UINT32*)(0xE000E100 + (25 / 32) * 4)) = (1 << (25 % 32)); // 25, NVIC ISER

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

void TIM1_UP_TIM10_IRQHandler(void){
  /*
       Timer1 1sec cnt -> led blink
       Parameters:
           None
       Returns:
           None
  */
	led_t l[4] = {led1,led2,led3,led4};

  if (*((V_UINT32*)(TIM1 + SR)) & 0x01){ // check if update interrupt flag
    *((V_UINT32*)(TIM1 + SR)) &= ~0x01; // clear update interrupt flag

    // 인터럽트 발생시 수행할 코드
    for(int i=0; i<36000000; i++){
        for(int i=0; i<4; i++){ outSignal(&l[i],0); }
        for(int i=0; i<36000000/2; i++){}
        for(int i=0; i<4; i++){ outSignal(&l[i],1); }
        for(int i=0; i<36000000/2; i++){}
    }
  }
}
