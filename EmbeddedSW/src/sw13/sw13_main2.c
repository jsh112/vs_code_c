#include "gpio.h"
#include "led_switch.h"
#include "Timer_Interrupt.h"

int flag1 = 0, flag_cnt = 0;
int cnt1 = 0, cnt2 = 0, sum = 0;

int main(){
    hwInit();

    gpio_t led[4] = {ARD_D2, ARD_D3, ARD_D4, ARD_D5};

    set_gpio(&ARD_D0,input); // PC7
    set_gpio(&ARD_D1,input); // PC6

    // LED 1,2,3,4
    set_gpio(&ARD_D2,output);
    set_gpio(&ARD_D3,output);
    set_gpio(&ARD_D4,output);
    set_gpio(&ARD_D5,output);

    /*
    // RCC_APB2ENR -> SYSCFG Clock Enable
    *((V_UINT32*)(APB2ENR)) |= (1 << 14);

    // Link EXTI 6,7 Interrupt Line
    *((V_UINT32*)(SYSCFG + EXTICR2)) &= (~(0xF << 4 * 2) | ~(0xF << 4 * 3));
    *((V_UINT32*)(SYSCFG + EXTICR2)) |= ((0x2 << 4 * 2) | (0x2 << 4 * 3));

    *((V_UINT32*)(EXTI + IMR)) |= (1 << 6) | (1 << 7);

    // Set Falling Edge EXTI 6, 7
    *((V_UINT32*)(EXTI + FTSR)) |= (1 << 6) | (1 << 7);

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

    *((V_UINT32*)(0xE000E100 + (23 / 32) * 4)) = (1 << (23 % 32)); // EXTI9_5_IRQn = 23, NVIC ISER*/
    while(1){
        if(!flag_cnt){
            for(int i=0;i<4;i++){Signal(&led[3 - i], !((cnt1 >> i) & 0x1));}
            delay(500);
            for(int i=0;i<4;i++){Signal(&led[i],1);}
            delay(500);
            cnt1++;
            if(cnt1 == 16) cnt1 = 0;
        }
        else{
            for(int i=0;i<4;i++){Signal(&led[3 - i], !((cnt2 >> i) & 0x1));}
            cnt2++;
            if(cnt2 == 16) cnt2 = 0;
        }
    }
}

void EXTI9_5_IRQHandler(){
	gpio_t led[4] = {ARD_D2, ARD_D3, ARD_D4, ARD_D5};
    // Check Interrupt 7 is triggered
    if(*((V_UINT32*)(EXTI + PR)) & (1 << 7)){
        *((V_UINT32*)(EXTI + PR)) |= (1 << 7);
        if(flag1 == 0){
            // initial push switch 1
            for(int i=0;i<4;i++){Signal(&led[i],1);}
            flag1 = 1;
        }
        else{
            sum = cnt1 + cnt2;
            if(sum >= 16) sum = sum % 16;
            flag_cnt = 0;
            cnt1 = sum;
            flag1 = 0;
        }
    }
    else if(*((V_UINT32*)(EXTI + PR)) & (1 << 6)){
        *((V_UINT32*)(EXTI + PR)) |= (1 << 6);
        cnt2++;
    }
}
