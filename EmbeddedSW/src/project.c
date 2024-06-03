#include "gpio.h"
#include "led_switch.h"
#include "Timer_Interrupt.h"

#define TIME_STR 6000
#define BLINK_DELAY 1200

// state
enum SignalState {
    North_South,
    Left1,
    East_West,
    Left2
};

SignalState currentState = North_South;

int main(){
    hwInit();

    // East and west road
    set_gpio(&ARD_D0,output);
    set_gpio(&ARD_D1,output);
    set_gpio(&ARD_D2,output);
    set_gpio(&ARD_D3,output);

    // North and South road
    set_gpio(&ARD_D4,output);
    set_gpio(&ARD_D5,output);
    set_gpio(&ARD_D6,output);
    set_gpio(&ARD_D7,output);

    // road
    set_gpio(&ARD_D8,output);       // LED1
    set_gpio(&ARD_D9,output);       // LED2
    set_gpio(&ARD_D10,output);      // LED3
    set_gpio(&ARD_D11,output);      // LED4
    set_gpio(&ARD_D12,output);      // LED5

    unsigned int Timer1 = 0;
    unsigned int Duration1 = 400;
    unsigned int Duration2 = 300;
    while(1){
        if(currentState == North_South){
            // North and South road straight

            Signal(&ARD_D3,0);      // straight signal

            Signal(&ARD_D8,0);      // LED1 ON
            Signal(&ARD_D12,0);     // LED5 ON
            delay(Duration1);       // delay

            Signal(&ARD_D8,1);      // LED1 OFF
            Signal(&ARD_D12,1);     // LED5 OFF
            Signal(&ARD_D9,0);      // LED2 ON
            Signal(&ARD_D11,0);     // LED4 ON
            delay(Duration1);       // delay

            Signal(&ARD_D9,1);      // LED2 OFF
            Signal(&ARD_D11,1);     // LED4 OFF
            Timer1 += BLINK_DELAY;
            if(Timer1 >=TIME_STR) currentState = Left1;
        }
        else if(currentState == Left1){
            // North and South road going left steering
            Signal(&ARD_D8,0);      // LED1 ON
            Signal(&ARD_D12,0);     // LED5 ON
            delay(Duration2);       // delay

            Signal(&ARD_D8,1);      // LED1 OFF
            Signal(&ARD_D12,1);     // LED5 OFF
            Signal(&ARD_D9,0);      // LED2 ON
            Signal(&ARD_D11,0);     // LED4 ON
            delay(Duration2);       // delay

            Signal(&ARD_D9,1);      // LED2 OFF
            Signal(&ARD_D11,1);     // LED4 OFF
            Timer1 += BLINK_DELAY;
            if(Timer1 >=TIME_STR) currentState = Left1;
        }
        else if(currentState == East_West){
            // East and West road straight
        }
        else if(currentState == Left2){ 
            // East and west road going left steering
        }
    }
}
