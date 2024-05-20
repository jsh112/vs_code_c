#ifndef LED_H_
#define LED_H_

#include "def.h"
#include "stm32f7xx_hal.h"
static void SystemClock_Config(void);
void hwInit(void);
void MyDelay(unsigned int n);
void MyApp();
void ControlLED(unsigned char No, unsigned char status);

#define V_UINT32 volatile unsigned int
#define GPIOA 0x40020000U
#define GPIOB 0x40020400U
#define GPIOC 0x40020800U
#define GPIOE 0x40021000U
#define GPIOF 0x40021400U
#define GPIOG 0x40021800U

#define MODER_A 0xA8000000U
#define MODER_B 0x00000280U
#define PUPD_A 0x64000000U
#define PUPD_B 0x00000100U
#define MODER 0x00U         // 00 input mode, 01 output mode
#define OSPEEDR 0x08U       // 11 very high speed
#define PUPDR 0x0CU        // Pull-up 01
#define BSRR 0x18U          // High 16 bit reset, low 16 bit set
#define AHB1ENR 0x40023830U // clock enable, 하위 11비트 IO Port Enable
#define IDR 0x10U           // input data read 상위 16개는 사용하지 않음
#define oneSec 36000000

#define input 0
#define output 1

#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#endif
