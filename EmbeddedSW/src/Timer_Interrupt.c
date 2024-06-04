#ifndef SRC_TIMER_INTERRUPT_H_
#define SRC_TIMER_INTERRUPT_H_

#include "Timer_Interrupt.h"


int CheckClockStatus(unsigned int GPIO){
	/*
        clock Enable check
        Parameters : 
            unsigned int GPIO Port : 0(A), 1(B), 2(C), ...
        Returns :
            0 : disable, 1 : enable
    */
   V_UINT32 value = *((V_UINT32*)(AHB1ENR));
   unsigned int mask = (1 << GPIO);
   return (value & mask) == mask;
}

void ClockEnable(unsigned int GPIO){
    /*
        GPIO Clock Enable
        Parameters : 
            unsigned int GPIOport : 0(A), 1(B), 2(C), ...
        Returns : 
            None
    */
   *((V_UINT32)(AHB1ENR)) |= (1 << GPIO);
}

void outSignal(led_t* led, unsigned int signal){
		*((V_UINT32*)(led->port + BSRR)) |= led->on >> (16 * signal);
}

/*
    userLedInit, outSignal is in led_switch.h
*/

void EnableTIM1(void){
    // RCC_APB2ENR -> SYSCFG Clock Enable
    *((V_UINT32 *)(APB2ENR)) |= 0x01;

    // Initialize TIM1 Prescaler
    *((V_UINT32*)(TIM1 + PSC)) &= 0;
    // Initialize TIM1 ARR
    *((V_UINT32*)(TIM1 + ARR)) &= 0;
    // TIM1 DIER UIE enable
    *((V_UINT32*)(TIM1 + DIER)) |= 0x01;
    // TIM1 CR1 CEN enable
    *((V_UINT32*)(TIM1 + CR1)) |= 0x01;
    // TIM1 SR UIF clear
    *((V_UINT32*)(TIM1 + SR)) &= 0x01;
    // 25, NVIC ISER
    *((V_UINT32*)(0xE000E100 + (25 / 32) * 4)) = (1 << (25 % 32));
}

void EnableTIM9(void){
    // RCC_APB2ENR -> SYSCFG Clock Enable
    *((V_UINT32 *)(APB2ENR)) |= (0x01 << 16);

    
}
#endif /* SRC_TIMER_INTERRUPT_H_ */