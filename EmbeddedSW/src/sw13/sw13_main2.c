#include "gpio.h"
#include "led_switch.h"
#include "Timer_Interrupt.h"

unsigned int counter_flag = 0;
unsigned int cnt1 = 0, cnt2 = 0, sum = 0;

int main()
{
    hwInit();

    // set gpio led pins and switches
    set_gpio(&ARD_D0, output);
    set_gpio(&ARD_D1, output);
    set_gpio(&ARD_D2, output);
    set_gpio(&ARD_D3, output);

    set_gpio(&ARD_D4, input);
    set_gpio(&ARD_D5, input);

    // RCC_APB2ENR -> SYSCFG Clock Enable
    *((V_UINT32 *)(APB2ENR)) |= (1 << 14);

    // Link PG7, PA8 to EXTI
    *((V_UINT32 *)(SYSCFG + EXTICR2)) &= ~(0xF << 4 * 3);
    *((V_UINT32 *)(SYSCFG + EXTICR2)) |= (0x06 << 4 * 3);

    *((V_UINT32 *)(SYSCFG + EXTICR3)) &= ~(0xF << 0);

    // Enable EXTI7,8 Interrupt line
    *((V_UINT32 *)(EXTI + IMR)) |= (1 << 7) | (1 << 8);

    // Set Falling Edge EXTI7,8
    *((V_UINT32 *)(EXTI + FTSR)) |= (1 << 7) | (1 << 8);

    *((V_UINT32 *)(0xE000E100 + (23 / 32) * 4)) = (1 << (23 % 32)); // EXTI9_5_IRQn = 23, NVIC ISER

    *((V_UINT32*)(0xE000E100 + (25 / 32) * 4)) = (1 << (25 % 32)); // 25, NVIC ISER, TIM1

    gpio_t led[4] = {ARD_D0, ARD_D1, ARD_D2, ARD_D3};
    while (1){
        if (!counter_flag){
        	cnt2 = 0;
            for (int j = 0; j < 4; j++){
                Signal(&led[j], !((sum >> j) & 0x01));
            }
            delay(400);
            for (int j = 0; j < 4; j++){
                Signal(&led[j], 1);
            }
            delay(400);
            sum++;
            if (sum == 16) sum = 0;
            cnt1 = sum;
        }
        else{
            for (int j = 0; j < 4; j++){
                Signal(&led[j], !((cnt2 >> j) & 0x01));
            }
        }
    }
}

void EXTI9_5_IRQHandler()
{
    gpio_t led[4] = {ARD_D0, ARD_D1, ARD_D2, ARD_D3};
    if ((*((V_UINT32 *)(EXTI + PR)) & (1 << 7)) && !counter_flag)
    {
        counter_flag = 1;
        for(int i=0;i<4;i++){
            Signal(&led[i], 1);
        }
        *((V_UINT32 *)(EXTI + PR)) |= (1 << 7);
        delay(100);
    }
    else if((*((V_UINT32 *)(EXTI + PR)) & (1 << 8)) && counter_flag){
        cnt2++;
        if(cnt2 == 16) cnt2 = 0;
        *((V_UINT32 *)(EXTI + PR)) |= (1 << 8);
        delay(100);
    }
    else if((*((V_UINT32 *)(EXTI + PR)) & (1 << 7)) && counter_flag){
        counter_flag = 0;
        sum = cnt2 + cnt1;
        if(sum >= 16) sum = sum % 16;
        *((V_UINT32 *)(EXTI + PR)) |= (1 << 7);
        delay(100);
    }
}
