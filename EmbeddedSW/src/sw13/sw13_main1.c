#include "gpio.h"
#include "led_switch.h"
#include "Timer_Interrupt.h"

// Timer offset
#define PSC 0x28U
#define ARR 0x2CU
#define DIER 0x0CU
#define CR1 0x00U
#define SR 0x10U

int k = 1;

int main(){
    hwInit();

    set_gpio(&ARD_D0,output);		// A
    set_gpio(&ARD_D1,output);       // B
    set_gpio(&ARD_D2,output);		// C
    set_gpio(&ARD_D3,output);       // D

    // Enable RCC APB2ENR, TIM9EN enable
    *((V_UINT32*)(APB2ENR)) |= 0x0001;

    *((V_UINT32*)(TIM1 + PSC)) &= 0; // PSC Reset
    *((V_UINT32*)(TIM1 + ARR)) &= 0; // ARR Reset

    *((V_UINT32*)(TIM1 + PSC)) |= 21600 - 1; 			// TIM1 Prescaler
    *((V_UINT32*)(TIM1 + ARR)) |= 10000 * 1 - 1;  // TIM1 ARR
    *((V_UINT32*)(TIM1 + DIER)) |= 0x01;  // update interrupt enabled
    *((V_UINT32*)(TIM1 + CR1)) |= 0x01;   // TIM1 CR1 CEN enable
    *((V_UINT32*)(TIM1 + SR)) &= 0x01;    // TIM1 SR UIF clear

    *((V_UINT32*)(0xE000E100 + (25 / 32) * 4)) = (1 << (25 % 32)); // 25, NVIC ISER
    while(1){}
}
void TIM1_UP_TIM10_IRQHandler(){
    if (*((V_UINT32*)(TIM1 + SR)) & 0x01){ // check if update interrupt flag
			*((V_UINT32*)(TIM1 + SR)) &= ~0x01;  // clear update interrupt flag
			if(k >= 10) k = 1;
			segment_7447(k);
			k++;
    }
}
