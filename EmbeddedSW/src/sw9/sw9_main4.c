#include "gpio.h"
#include "led_switch.h"
#include "Timer_Interrupt.h"

int main(){
	hwInit();

    BtnInit(&btn1);

    LedInit(&led1);
    LedInit(&led2);
    LedInit(&led3);
    LedInit(&led4);

	unsigned int i = 0;
    while(1){
        led_t led[4] = {led1,led2,led3,led4};
        if(BtnCheck() == 1){
            while(i < 5){
                for(int j = 0;j<4;j++) outSignal(&led[j],0);
                if(BtnCheck() == 1) i = 0;
                delay(500);
                for(int j = 0;j<4;j++) outSignal(&led[j],1);
                if(BtnCheck() == 1) i = 0;
                delay(500);
                i++;
            }
        }
        i = 0;
    }
}
