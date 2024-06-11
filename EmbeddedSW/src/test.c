#include "def.h"
#include "stm32f7xx_hal.h"

// HardWare Initial Function

static void SystemClock_Config(void);
void hwInit(void);
// gpio.c

void set_gpio(gpio_t *GPIO, int _mode);
void Signal(gpio_t *GPIO, int signal);
void segment_7447(unsigned int num);
// Internal LEDs and Switches

void LedInit(led_t *led);
void BtnInit(btn_t *btn);
void delay(unsigned int ms);
int BtnCheck(void);
// Timer and Interrupts

void EnableTIM1(void);

#define V_UINT32 volatile unsigned int

enum shift
{
    A = 0,
    B,
    C,
    D,
    E,
    F,
    G
};

// Base Address
#define GPIOA 0x40020000U
#define GPIOB 0x40020400U
#define GPIOC 0x40020800U
#define GPIOE 0x40021000U
#define GPIOF 0x40021400U
#define GPIOG 0x40021800U
#define APB2ENR 0x40023844U
#define SYSCFG 0x40013800U
#define EXTI 0x40013C00U
#define TIM1 0x40010000U
#define TIM9 0x40014000U

// Interrupt offset
#define IMR 0x00U
#define FTSR 0x0CU
#define EXTICR1 0x08U // EXTI 0~3
#define EXTICR2 0x0CU // EXTI 4~7
#define EXTICR3 0x10U // EXTI 8~11
#define EXTICR4 0x14U // EXTI 12~15
#define PR 0x14U

// Timer offset
#define PSC 0x28U
#define ARR 0x2CU
#define DIER 0x0CU
#define CR1 0x00U
#define SR 0x10U

// GPIO offset
#define MODER 0x00U         // 00 입력 모드, 01 출력 모드
#define OSPEEDR 0x08U       // 11 매우 높은 속도
#define PUPDR 0x0CU         // 풀업 01
#define BSRR 0x18U          // 상위 16비트 리셋, 하위 16비트 셋
#define AHB1ENR 0x40023830U // 클럭 활성화, 하위 11비트 IO 포트 활성화
#define IDR 0x10U           // 입력 데이터 읽기, 상위 16개는 사용하지 않음
#define oneSec 36000000

// Define Input and output
#define input 0
#define output 1

// structure of gpio_t
typedef struct
{
    V_UINT32 clock; // 클럭
    V_UINT32 port;  // GPIO Port
    V_UINT32 pin;   // pin
} gpio_t;

// initialize gpio pins
gpio_t ARD_D0 = {(0x01 << C), GPIOC, 7}; // PC7
gpio_t ARD_D1 = {(0x01 << C), GPIOC, 6}; // PC6
gpio_t ARD_D2 = {(0x01 << G), GPIOG, 6}; // PG6
gpio_t ARD_D3 = {(0x01 << B), GPIOB, 4}; // PB4
gpio_t ARD_D4 = {(0x01 << G), GPIOG, 7}; // PG7
gpio_t ARD_D5 = {(0x01 << A), GPIOA, 8}; // PA8
gpio_t ARD_D6 = {(0x01 << A), GPIOA, 2}; // PA2
gpio_t ARD_D7 = {(0x01 << C), GPIOC, 1}; // PC1

gpio_t ARD_D8 = {(0x01 << C), GPIOC, 2};   // PC2
gpio_t ARD_D9 = {(0x01 << A), GPIOA, 3};   // PA3
gpio_t ARD_D10 = {(0x01 << B), GPIOB, 9};  // PB9
gpio_t ARD_D11 = {(0x01 << B), GPIOB, 15}; // PB15
gpio_t ARD_D12 = {(0x01 << B), GPIOB, 14}; // PB14
gpio_t ARD_D13 = {(0x01 << A), GPIOA, 9};  // PA9
gpio_t ARD_D14 = {(0x01 << B), GPIOB, 7};  // PB7
gpio_t ARD_D15 = {(0x01 << B), GPIOB, 8};  // PB8

gpio_t ARD_A1 = {(0x01 << F), GPIOF, 10}; // PF10
gpio_t ARD_A2 = {(0x01 << F), GPIOF, 9};  // PF9
gpio_t ARD_A3 = {(0x01 << F), GPIOF, 8};  // PF8

// gpio.h and gpio.c
void set_gpio(gpio_t *GPIO, int _mode)
{
    *((V_UINT32 *)(AHB1ENR)) |= GPIO->clock;
    if (_mode == 0)
    {
        // input
        *((V_UINT32 *)(GPIO->port + MODER)) &= ~(0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + PUPDR)) &= ~(0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + OSPEEDR)) &= ~(0x03 << 2 * GPIO->pin);
    }
    else
    {
        // output
        *((V_UINT32 *)(GPIO->port + MODER)) &= ~(0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + MODER)) |= (0x01 << 2 * GPIO->pin);

        *((V_UINT32 *)(GPIO->port + PUPDR)) &= ~(0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + PUPDR)) |= (0x01 << 2 * GPIO->pin);

        *((V_UINT32 *)(GPIO->port + OSPEEDR)) |= (0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + BSRR)) |= (0x01 << GPIO->pin);
    }
}

// External GPIO Port LED function
void Signal(gpio_t *GPIO, int signal)
{
    *((V_UINT32 *)(GPIO->port + BSRR)) |= (0x01 << (GPIO->pin + 16)) >> (16 * signal);
}

// Segment On, Port Pins are variables
void segment_7447(unsigned int num)
{
    set_gpio(&ARD_D0, output); // A
    set_gpio(&ARD_D1, output); // B
    set_gpio(&ARD_D2, output); // C
    set_gpio(&ARD_D3, output); // D

    gpio_t *array[4] = {&ARD_D0, &ARD_D1, &ARD_D2, &ARD_D3};
    for (int j = 0; j < 4; j++)
    {
        Signal(array[j], (num >> j) & 1); // 항상 0, 1이 출력되게 만들어놨으므로 & 1을 해줘야함
    }
}

// board leds and switches

// structure of led_t
typedef struct
{
    V_UINT32 port;
    V_UINT32 mode;
    V_UINT32 speed;
    V_UINT32 pupd;
    V_UINT32 on;
    V_UINT32 off;
} led_t;

// structure of btn_t
typedef struct
{
    V_UINT32 port;
    V_UINT32 data;
    V_UINT32 input_data;
} btn_t;

// Options of leds
led_t led1 = {GPIOG, (0x01 << 24), (0x03 << 24), (0x01 << 24), (0x01 << (12 + 16)), (0x01 << 12)};
led_t led2 = {GPIOE, (0x01 << 10), (0x03 << 10), (0x01 << 10), (0x01 << (5 + 16)), (0x02 << 4)};
led_t led3 = {GPIOE, (0x01 << 8), (0x03 << 8), (0x01 << 8), (0x01 << (4 + 16)), (0x01 << 4)};
led_t led4 = {GPIOG, (0x01 << 20), (0x03 << 20), (0x01 << 20), (0x01 << (10 + 16)), (0x01 << 10)};

// Initialize of leds
void LedInit(led_t *led)
{
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << G | 0x01 << E;

    *((V_UINT32 *)(led->port + MODER)) |= led->mode;
    *((V_UINT32 *)(led->port + OSPEEDR)) |= led->speed;
    *((V_UINT32 *)(led->port + PUPDR)) |= led->pupd;
    *((V_UINT32 *)(led->port + BSRR)) |= led->off;
}

// Switch functions and settings

// PG3
btn_t btn1 = {GPIOG, (0x03 << 2 * 3), (0x01 << 3)};
// PC12
btn_t btn2 = {GPIOC, (0x03 << 2 * 12), (0x01 << 12)};

// Initialize button
void BtnInit(btn_t *btn)
{
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << C | 0x01 << G;

    *((V_UINT32 *)(btn->port + MODER)) &= ~(btn->data);
    *((V_UINT32 *)(btn->port + OSPEEDR)) &= ~(btn->data);
    *((V_UINT32 *)(btn->port + PUPDR)) &= ~(btn->data);
}

// dealy function
void delay(unsigned int ms)
{
    volatile int time;
    for (time = 0; time <= ms * (oneSec / 1000); time++)
        ;
}

// check each button pressed
int BtnCheck(void)
{
    int status = 0;
    if (*((V_UINT32 *)(GPIOG + IDR)) & (0x01 << 3))
        status += 1;
    if (*((V_UINT32 *)(GPIOC + IDR)) & (0x01 << 12))
        status += 2;
    return status;
}

// Timer and Interrupts

// Enable TIM1 Function
void EnableTIM1(void)
{
    // RCC_APB2ENR -> SYSCFG Clock Enable
    *((V_UINT32 *)(APB2ENR)) |= 0x01;

    // Initialize TIM1 Prescaler
    *((V_UINT32 *)(TIM1 + PSC)) &= 0;
    // Initialize TIM1 ARR
    *((V_UINT32 *)(TIM1 + ARR)) &= 0;
    // TIM1 DIER UIE enable
    *((V_UINT32 *)(TIM1 + DIER)) |= 0x01;
    // TIM1 CR1 CEN enable
    *((V_UINT32 *)(TIM1 + CR1)) |= 0x01;
    // TIM1 SR UIF clear
    *((V_UINT32 *)(TIM1 + SR)) &= 0x01;
    // 25, NVIC ISER
    *((V_UINT32 *)(0xE000E100 + (25 / 32) * 4)) = (1 << (25 % 32));
}

// Initialization

static void SystemClock_Config(void)
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;

    /* Enable HSE Oscillator and activate PLL with HSE as source */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 25;
    RCC_OscInitStruct.PLL.PLLN = 432;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 9;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        // Error_Handler();
    }

    /* activate the OverDrive to reach the 216 Mhz Frequency */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK)
    {
        // Error_Handler();
    }

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
       clocks dividers */
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
    {
        // Error_Handler();
    }
}

void hwInit(void)
{
    SCB_EnableICache();
    SCB_EnableDCache();
    HAL_Init();
    SystemClock_Config();
    // __HAL_RCC_GPIOE_CLK_ENABLE(); // RCC_AHB1ENR, IO Port clock Enable, RCC Base=0x40023800, offset=0x30 / 0x40023830U |=0x000000040U (G port)
    //__HAL_RCC_SYSCFG_CLK_ENABLE();
}

unsigned int counter_flag = 0, ledState = 0;
unsigned int cnt1 = 0, cnt2 = 0, sum = 0;

int main()
{
    hwInit();

    // btn init
    BtnInit(&btn1); // PG3
    BtnInit(&btn2); // PC12

    // led init
    LedInit(&led1);
    LedInit(&led2);
    LedInit(&led3);
    LedInit(&led4);

    EnableTIM1();
    *((V_UINT32 *)(TIM1 + PSC)) |= 21600 - 1; // TIM1 Prescaler
    *((V_UINT32 *)(TIM1 + ARR)) |= 9999;

    *((V_UINT32 *)(APB2ENR)) |= (1 << 14);

    // Link PG3, PC12
    *((V_UINT32 *)(SYSCFG + EXTICR1)) &= ~(0xF << 4 * 3);
    *((V_UINT32 *)(SYSCFG + EXTICR1)) |= (0x06 << 4 * 3);

    *((V_UINT32 *)(SYSCFG + EXTICR4)) &= ~(0xF << 0);
    *((V_UINT32 *)(SYSCFG + EXTICR4)) |= (0x02 << 0);

    *((V_UINT32 *)(EXTI + IMR)) |= (1 << 3) | (1 << 12);

    *((V_UINT32 *)(EXTI + FTSR)) |= (1 << 3) | (1 << 12);

    *((V_UINT32 *)(0xE000E100 + (9 / 32) * 4)) = (1 << (9 % 32));   // 9, EXTI3
    *((V_UINT32 *)(0xE000E100 + (40 / 32) * 4)) = (1 << (40 % 32)); // 40, EXTI15_10
    *((V_UINT32 *)(0xE000E100 + (25 / 32) * 4)) = (1 << (25 % 32)); // 25, TIM1

    led_t led[4] = {led1, led2, led3, led4};
    while (1)
    {
        if (!counter_flag)
        {
            cnt2 = 0;
            for (int j = 0; j < 4; j++)
            {
                outSignal(&led[j],!((sum >> j) & 0x01));
            }
            delay(400);
            for (int j = 0; j < 4; j++)
            {
                outSignal(&led[j],((sum >> j) & 0x01));
            }
            delay(400);
            sum++;
            if (sum == 16)sum = 0;
            cnt1 = sum;
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                outSignal(&led[j],!((cnt2 >> j) & 0x01));
            }
        }
    }
}

/*void TIM1_UP_TIM10_IRQHandler(void)
{
    led_t l[4] = {led1, led2, led3, led4};

    if (*((V_UINT32 *)(TIM1 + SR)) & 0x01)
    {                                        // check if update interrupt flag
        *((V_UINT32 *)(TIM1 + SR)) &= ~0x01; // clear update interrupt flag
        cnt1++;
        cnt1 %= 16;
    }
}*/

void EXTI3_IRQHandler(void)
{
    // button 1 pressed
    led_t led[4] = {led1, led2, led3, led4};
    if ((*((V_UINT32 *)(EXTI + PR)) & (1 << 3)) && !counter_flag)
    {
        counter_flag = 1;
        for(int i=0;i<4;i++){
            Signal(&led[i], 1);
        }
        *((V_UINT32 *)(EXTI + PR)) |= (1 << 3);
        delay(100);
    }

    else if((*((V_UINT32 *)(EXTI + PR)) & (1 << 3)) && counter_flag){
        counter_flag = 0;
        sum = cnt2 + cnt1;
        if(sum >= 16) sum = sum % 16;
        *((V_UINT32 *)(EXTI + PR)) |= (1 << 3);
        delay(100);
    }
}

void EXTI15_10_IRQHandler(void){
    // button 2 pressed
    if((*((V_UINT32 *)(EXTI + PR)) & (1 << 12)) && counter_flag){
        cnt2++;
        if(cnt2 == 16) cnt2 = 0;
        *((V_UINT32 *)(EXTI + PR)) |= (1 << 8);
        delay(100);
    }
}
