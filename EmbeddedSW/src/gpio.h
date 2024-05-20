/*
 * gpio.h
 *
 *  Created on: 2024. 5. 16.
 *      Author: jshkr
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "def.h"
#include "stm32f7xx_hal.h"

enum shift{
    A = 0,
    B,C,D,E,F,G
};

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
#define MODER 0x00U         // 00 입력 모드, 01 출력 모드
#define OSPEEDR 0x08U       // 11 매우 높은 속도
#define PUPDR 0x0CU        // 풀업 01
#define BSRR 0x18U          // 상위 16비트 리셋, 하위 16비트 셋
#define AHB1ENR 0x40023830U // 클럭 활성화, 하위 11비트 IO 포트 활성화
#define IDR 0x10U           // 입력 데이터 읽기, 상위 16개는 사용하지 않음
#define oneSec 36000000

#define input 0
#define output 1

typedef struct {
    V_UINT32 clock; // 클럭
    V_UINT32 port;  // GPIO Port
    V_UINT32 pin;   // pin
} gpio_t;   

extern gpio_t ARD_D0;
extern gpio_t ARD_D1;
extern gpio_t ARD_D2;
extern gpio_t ARD_D3;
extern gpio_t ARD_D4;
extern gpio_t ARD_D5;
extern gpio_t ARD_D6;
extern gpio_t ARD_D7;
extern gpio_t ARD_D8;
extern gpio_t ARD_D9;
extern gpio_t ARD_D10;
extern gpio_t ARD_D11;
extern gpio_t ARD_D12;
extern gpio_t ARD_D13;
extern gpio_t ARD_D14;
extern gpio_t ARD_D15;

#define a ARD_D0
#define b ARD_D1
#define c ARD_D2
#define d ARD_D3
#define e ARD_D4
#define f ARD_D5
#define g ARD_D6

// gpio 입출력 설정 함수
void set_gpio(gpio_t *GPIO, int _mode);
// 출력 포트 bsrr 함수
void Signal(gpio_t *GPIO, int signal);
// 7-segment on
void segmenton(int num);
// 7-segment off
void segmentoff(int num);

void switch_led(void);
#endif /* GPIO_H_ */
