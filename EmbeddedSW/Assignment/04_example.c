/* #include "led.h"
#include <stdio.h>
*/

#define V_UINT32 volatile unsigned int

#define RCC_AHB1ENR *(V_UINT32 *)(0x40023830U)

#define GPIOG_BASE 0x40021800U
#define GPIOE_BASE 0x40021000U
#define GPIOC_BASE 0x40020800U

#define MODE_OFFSET 0x00
#define SPEED_OFFSET 0x08
#define PUPD_OFFSET 0x0C
#define IDR_OFFSET 0x10
#define BSR_OFFSET 0x18

typedef struct {
    V_UINT32 port;
    V_UINT32 mode;
    V_UINT32 speed;
    V_UINT32 pupd;
    V_UINT32 bsrr_on;
    V_UINT32 bsrr_off;
} led_t;

typedef struct {
    V_UINT32 port;
    V_UINT32 pin;
} btn_t;

void ledInit(led_t *led);
int btnCheck(btn_t *btn);
void btnInit(void);
void delay(unsigned int ms);

led_t led1 = {GPIOG_BASE, 0x01000000, 0x03000000, 0x01000000, 0x10000000, 0x00001000};
led_t led2 = {GPIOE_BASE, 0x00000400, 0x00000C00, 0x00000400, 0x00200000, 0x00000020};
led_t led3 = {GPIOE_BASE, 0x00000100, 0x00000300, 0x00000100, 0x00100000, 0x00000010};
led_t led4 = {GPIOG_BASE, 0x00100000, 0x00300000, 0x00100000, 0x04000000, 0x00000400};

btn_t btn_sw_1 = {GPIOG_BASE, 0x00000008U};
btn_t btn_sw_2 = {GPIOC_BASE, 0x00001000U};


#define btn_sw_x btn_sw_1 // btn_1
#define BLINK_DELAY 500 // 500ms
#define HOLD_DURATION 3000 // 3s
#define OFF_DURATION 2000 // 2s

int main(void) {
    hwInit();
    ledInit(&led1);
    ledInit(&led2);
    ledInit(&led3);
    ledInit(&led4);
    btnInit();

    unsigned int blinkTimer = 0;
    unsigned int holdTimer = 0;
    unsigned int offTimer = 0;
    int ledState = 1;
    int holdDetected = 0;

    while (1) {
        if (!holdDetected) {
            if (btnCheck(&btn_sw_x)) {
                holdTimer += BLINK_DELAY;
                if (holdTimer >= HOLD_DURATION) {
                    holdDetected = 1;
                    offTimer = 0;
                    ledState = 0;
                    blinkTimer = 0;
                }
            }
            else {
                holdTimer = 0;
            }

            if (blinkTimer >= BLINK_DELAY) {
                blinkTimer = 0;
                ledState = !ledState;
            }
        }
        else {
            if (offTimer >= OFF_DURATION) {
                offTimer = 0;
                holdDetected = 0;
                ledState = 1;
            }
        }

        if (ledState) {
            *(V_UINT32 *)(led1.port + BSR_OFFSET) |= led1.bsrr_on;
            *(V_UINT32 *)(led2.port + BSR_OFFSET) |= led2.bsrr_on;
            *(V_UINT32 *)(led3.port + BSR_OFFSET) |= led3.bsrr_on;
            *(V_UINT32 *)(led4.port + BSR_OFFSET) |= led4.bsrr_on;
        }
        else {
            *(V_UINT32 *)(led1.port + BSR_OFFSET) |= led1.bsrr_off;
            *(V_UINT32 *)(led2.port + BSR_OFFSET) |= led2.bsrr_off;
            *(V_UINT32 *)(led3.port + BSR_OFFSET) |= led3.bsrr_off;
            *(V_UINT32 *)(led4.port + BSR_OFFSET) |= led4.bsrr_off;
        }

        delay(BLINK_DELAY);
        if (!holdDetected) {
            blinkTimer += BLINK_DELAY;
            }
            offTimer += BLINK_DELAY;
    }
}

void btnInit(void) {
    RCC_AHB1ENR |= 0x0000004C;
    *(V_UINT32 *)(GPIOG_BASE + MODE_OFFSET) &= ~0x000000C0U;
    *(V_UINT32 *)(GPIOG_BASE + PUPD_OFFSET) |= 0x00000040U;

    *(V_UINT32 *)(GPIOC_BASE + MODE_OFFSET) &= ~0x0C000000U;
    *(V_UINT32 *)(GPIOC_BASE + PUPD_OFFSET) |= 0x04000000U;
}

void ledInit(led_t *led) {
    if (led->port == GPIOG_BASE)
        RCC_AHB1ENR |= 0x00000040;
    else if (led->port == GPIOE_BASE)
        RCC_AHB1ENR |= 0x00000010;

    *(V_UINT32 *)(led->port + MODE_OFFSET) |= led->mode;
    *(V_UINT32 *)(led->port + SPEED_OFFSET) |= led->speed;
    *(V_UINT32 *)(led->port + PUPD_OFFSET) |= led->pupd;
    *(V_UINT32 *)(led->port + BSR_OFFSET) |= led->bsrr_off;
}

int btnCheck(btn_t *btn) {
    return (*(V_UINT32 *)(btn->port + IDR_OFFSET) & btn->pin) ? 1 : 0;
}

void delay(unsigned int ms) {
    for (unsigned int i = 0; i < ms; i++) {
        for (volatile unsigned int j = 0; j < 36000; j++);
    }
}