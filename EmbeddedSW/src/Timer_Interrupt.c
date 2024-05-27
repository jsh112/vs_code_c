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



#endif /* SRC_TIMER_INTERRUPT_H_ */