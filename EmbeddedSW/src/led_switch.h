#ifndef LED_SWITCH_H_
#define LED_SWITCH_H_
#include "gpio.h"
typedef struct
{
    V_UINT32 port;
    V_UINT32 mode;
    V_UINT32 speed;
    V_UINT32 pupd;
    V_UINT32 on;
    V_UINT32 off;
} led_t;

extern led_t led1;
extern led_t led2;
extern led_t led3;
extern led_t led4;

typedef struct
{
    V_UINT32 port;
    V_UINT32 data;
    V_UINT32 input_data;
} btn_t;

extern btn_t btn1;
extern btn_t btn2;

void LedInit(led_t *led);
void BtnInit(btn_t *btn);
void delay(unsigned int ms);
int BtnCheck(void);

#endif /* LED_SWITCH_H_ */
