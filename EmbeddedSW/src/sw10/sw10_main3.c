#include "gpio.h"
#include "led_switch.h"
#include "Timer_Interrupt.h"

int main(){
	hwInit();

	BtnInit(&btn1);
	BtnInit(&btn2);

	LedInit(&led1);
	LedInit(&led2);

	while(1){
		if(BtnCheck() == 1){
			if(BtnCheck() == 3){
				outSignal(&led1,0);
				outSignal(&led2,1);
			}
		}
		else if(BtnCheck() == 2){
			if(BtnCheck() == 3){
				outSignal(&led2,0);
				outSignal(&led1,1);
			}
		}
	}
}
