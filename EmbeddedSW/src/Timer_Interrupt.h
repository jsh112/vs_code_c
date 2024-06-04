#include "led_switch.h"
#include "gpio.h"

int CheckClockStatus(unsigned int GPIO);
void ClockEnable(unsigned int GPIO);
void outSignal(led_t* led, unsigned int signal);
void EnableTIM1(void);