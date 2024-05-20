// #include "led.h"
#include <stdio.h>
#define V_UINT32 volatile unsigned int

#define GPIOA 0x40020000U
#define GPIOG 0x40021800U
#define GPIOE 0x40021000U
#define GPIOC 0x40020800U
#define AHB1ENR 0x40023830U // clock enable, 하위 11비트 IO Port Enable

#define MODER 0x00   // 00 input mode, 01 output mode
#define OSPEEDR 0x08 // 11 very high speed
#define PUPDR 0x0C   // Pull-up 01
#define BSRR 0x18    // High 16 bit reset, low 16 bit set
#define IDR 0x10     // input data read 상위 16개는 사용하지 않음
#define oneSec 36000000

#define btn_x 1
#define BLINK_DELAY 500
#define HOLD_DURATION 3000
#define OFF_DURATION 2000

// LED functions and settings

typedef struct
{
    V_UINT32 port;
    V_UINT32 mode;
    V_UINT32 speed;
    V_UINT32 pupd;
    V_UINT32 on;
    V_UINT32 off;
} led_t;

led_t led1 = {GPIOG, (0x01 << 24), (0x03 << 24), (0x01 << 24), (0x01 << 28), (0x01 << 12)};
led_t led2 = {GPIOE, (0x01 << 10), (0x03 << 10), (0x01 << 10), (0x02 << 20), (0x02 << 4)};
led_t led3 = {GPIOE, (0x01 << 8), (0x03 << 8), (0x01 << 8), (0x01 << 20), (0x01 << 4)};
led_t led4 = {GPIOG, (0x01 << 20), (0x03 << 20), (0x01 << 20), (0x01 << 26), (0x01 << 10)};

void LedInit(led_t *led)
{
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 4 | 0x01 << 6;

    *((V_UINT32 *)(led->port + MODER)) |= led->mode;
    *((V_UINT32 *)(led->port + OSPEEDR)) |= led->speed;
    *((V_UINT32 *)(led->port + PUPDR)) |= led->pupd;
    *((V_UINT32 *)(led->port + BSRR)) |= led->off;
}

// Switch functions and settings

typedef struct
{
    V_UINT32 port;
    V_UINT32 data;
    V_UINT32 input_data;
} btn_t;

btn_t btn1 = {GPIOG, (0x03 << 6), (0x01 << 3)};
btn_t btn2 = {GPIOC, (0x03 << 24), (0x01 << 12)};

void BtnInit(btn_t *btn)
{
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 2 | 0x01 << 6;

    *((V_UINT32 *)(btn->port + MODER)) &= ~(btn->data);
    *((V_UINT32 *)(btn->port + OSPEEDR)) &= ~(btn->data);
    *((V_UINT32 *)(btn->port + PUPDR)) &= ~(btn->data);
}

void delay(unsigned int ms) {
    for (unsigned int i = 0; i < ms; i++) {
        for (volatile unsigned int j = 0; j < (oneSec / 1000); j++);
    }
}

int BtnCheck()
{
    int status = 0;
    if (*((V_UINT32 *)(btn1.port | IDR)) & btn1.input_data)
        status += 1;
    if (*((V_UINT32 *)(btn2.port | IDR)) & btn2.input_data)
        status += 2;
    return status;
}

int main()
{
    hwInit();
    LedInit(&led1);
    LedInit(&led2);
    LedInit(&led3);
    LedInit(&led4);
    BtnInit(&btn1);
    BtnInit(&btn2);
    unsigned int holdTimer = 0;
    unsigned int offTimer = 0;
    unsigned int blinkTimer = 0;
    // Flags
    int holdDetected = 0;
    int ledState = 1;
    // non hold : hold < HOLD_DURATION
    while (1)
    {
        if (!holdDetected)
        {
            // btn_x pressed
            if (BtnCheck() == btn_x)
            {
                holdTimer += BLINK_DELAY;
                if (holdTimer >= HOLD_DURATION)
                {
                    holdDetected = 1;
                    offTimer = 0;
                    ledState = 0;
                    blinkTimer = 0;
                }
            }
            else
            {
                holdTimer = 0;
            }

            if (blinkTimer >= BLINK_DELAY)
            {
                blinkTimer = 0;
                ledState = !ledState;
            }
        }
        // hold detect
        else
        {
            if (offTimer >= OFF_DURATION)
            {
                offTimer = 0;
                holdDetected = 0;
                ledState = 1;
            }
        }

        if (ledState)
        {
            *((V_UINT32 *)(led1.port + BSRR)) |= led1.on;
            *((V_UINT32 *)(led2.port + BSRR)) |= led2.on;
            *((V_UINT32 *)(led3.port + BSRR)) |= led3.on;
            *((V_UINT32 *)(led4.port + BSRR)) |= led4.on;
        }
        else
        {
            *((V_UINT32 *)(led1.port + BSRR)) |= led1.off;
            *((V_UINT32 *)(led2.port + BSRR)) |= led2.off;
            *((V_UINT32 *)(led3.port + BSRR)) |= led3.off;
            *((V_UINT32 *)(led4.port + BSRR)) |= led4.off;
        }
        delay(BLINK_DELAY);
        if (!holdDetected)
        {
            blinkTimer += BLINK_DELAY;
        }
        offTimer += BLINK_DELAY;
    }
}
