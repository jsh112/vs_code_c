#include "gpio.h"
#include "led_switch.h"
#include "Timer_Interrupt.h"

unsigned int ledState = 0;
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

    *((V_UINT32 *)(APB2ENR)) |= 0x01;

    *((V_UINT32 *)(TIM1 + PSC)) &= 0;
    *((V_UINT32 *)(TIM1 + PSC)) |= 21600 - 1; // TIM1 Prescaler
    *((V_UINT32 *)(TIM1 + ARR)) &= 0;
    *((V_UINT32 *)(TIM1 + ARR)) |= 9999;
    *((V_UINT32 *)(TIM1 + DIER)) |= 0x01; // update interrupt enabled
    *((V_UINT32 *)(TIM1 + CR1)) |= 0x01;  // TIM1 CR1 CEN enable
    *((V_UINT32 *)(TIM1 + SR)) &= 0x01;   // TIM1 SR UIF clear

    *((V_UINT32 *)(0xE000E100 + (25 / 32) * 4)) = (1 << (25 % 32)); // 25, NVIC ISER

    *((V_UINT32 *)(0xE000E100 + (23 / 32) * 4)) = (1 << (23 % 32)); // EXTI9_5_IRQn = 23, NVIC ISER

    gpio_t led[4] = {ARD_D0, ARD_D1, ARD_D2, ARD_D3};
    while (1)
    {
        if (ledState)
        {
            for (int j = 0; j < 4; j++)
            {
                Signal(&led[j], !((cnt1 >> j) & 0x01));
            }
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                Signal(&led[j], ((cnt1 >> j) & 0x01));
            }
        }
    }
}

void EXTI9_5_IRQHandler()
{
    if (*((V_UINT32 *)(EXTI + PR)) & (1 << 7))
    {
        *((V_UINT32 *)(EXTI + PR)) |= (1 << 7);
        ledState = !ledState;
    }
}

void TIM1_UP_TIM10_IRQHandler(void)
{
    led_t l[4] = {led1, led2, led3, led4};

    if (*((V_UINT32 *)(TIM1 + SR)) & 0x01)
    {                                        // check if update interrupt flag
        *((V_UINT32 *)(TIM1 + SR)) &= ~0x01; // clear update interrupt flag
        cnt1++;
        cnt1 %= 16;
    }
}
