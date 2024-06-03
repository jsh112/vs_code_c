#include "gpio.h"

gpio_t ARD_D0 = {(0x01 << C), GPIOC, 7}; // PC7
gpio_t ARD_D1 = {(0x01 << C), GPIOC, 6}; // PC6
gpio_t ARD_D2 = {(0x01 << G), GPIOG, 6}; // PG6
gpio_t ARD_D3 = {(0x01 << B), GPIOB, 4}; // PB4
gpio_t ARD_D4 = {(0x01 << G), GPIOG, 7}; // PG7
gpio_t ARD_D5 = {(0x01 << A), GPIOA, 8}; // PA8
gpio_t ARD_D6 = {(0x01 << A), GPIOA, 2}; // PA2
gpio_t ARD_D7 = {(0x01 << C), GPIOC, 1}; // PC1

gpio_t ARD_D8 = {(0x01 << C), GPIOC, 2};     // PC2
gpio_t ARD_D9 = {(0x01 << A), GPIOA, 3};     // PA3
gpio_t ARD_D10 = {(0x01 << B), GPIOB, 9};    // PB9
gpio_t ARD_D11 = {(0x01 << B), GPIOB, 15};   // PB15
gpio_t ARD_D12 = {(0x01 << B), GPIOB, 14};   // PB14
gpio_t ARD_D13 = {(0x01 << A), GPIOA, 9};    // PA9
gpio_t ARD_D14 = {(0x01 << B), GPIOB, 7};    // PB7
gpio_t ARD_D15 = {(0x01 << B), GPIOB, 8};    // PB8

gpio_t ARD_A1  = {(0x01 << F), GPIOF, 10};   // PF10
gpio_t ARD_A2  = {(0x01 << F), GPIOF, 9};    // PF9
gpio_t ARD_A3  = {(0x01 << F), GPIOF, 8};    // PF8

#define a ARD_D0
#define b ARD_D1
#define c ARD_D2
#define d ARD_D3
#define e ARD_D4
#define f ARD_D5
#define g ARD_D6


void set_gpio(gpio_t *GPIO, int _mode)
{
    *((V_UINT32 *)(AHB1ENR)) |= GPIO->clock;
    if (_mode == 0){
        // input
        *((V_UINT32 *)(GPIO->port + MODER)) &= ~(0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + PUPDR)) &= ~(0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + OSPEEDR)) &= ~(0x03 << 2 * GPIO->pin);
    }
    else{
        // output
    	*((V_UINT32*)(GPIO->port + MODER)) &= ~(0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + MODER)) |= (0x01 << 2 * GPIO->pin);

        *((V_UINT32 *)(GPIO->port + PUPDR)) &= ~(0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + PUPDR)) |= (0x01 << 2 * GPIO->pin);

        *((V_UINT32 *)(GPIO->port + OSPEEDR)) |= (0x03 << 2 * GPIO->pin);
        *((V_UINT32 *)(GPIO->port + BSRR)) |= (0x01 << GPIO->pin);
    }
}

void Signal(gpio_t *GPIO, int signal){
	*((V_UINT32*)(GPIO->port + BSRR)) |= (0x01 << (GPIO->pin + 16)) >> (16 * signal);
}

void segmenton(int num){
    switch (num)
    {
    case 0:
        Signal(&a,0);
        Signal(&b,0);
        Signal(&c,0);
        Signal(&d,0);
        Signal(&e,0);
        Signal(&f,0);
        break;
    case 1:
        Signal(&b,0);
        Signal(&c,0);
        break;
    case 2:
        Signal(&a,0);
        Signal(&b,0);
        Signal(&g,0);
        Signal(&e,0);
        Signal(&d,0);
        break;
    case 3:
        Signal(&a,0);
        Signal(&b,0);
        Signal(&c,0);
        Signal(&d,0);
        Signal(&g,0);
        break;
    case 4:
        Signal(&b,0);
        Signal(&c,0);
        Signal(&g,0);
        Signal(&f,0);
        break;
    case 5:
        Signal(&a,0);
        Signal(&c,0);
        Signal(&d,0);
        Signal(&g,0);
        Signal(&f,0);
        break;
    case 6:
        Signal(&a,0);
        Signal(&c,0);
        Signal(&d,0);
        Signal(&e,0);
        Signal(&f,0);
        Signal(&g,0);
        break;
    case 7:
        Signal(&a,0);
        Signal(&b,0);
        Signal(&c,0);
        break;
    case 8:
        Signal(&a,0);
        Signal(&b,0);
        Signal(&c,0);
        Signal(&d,0);
        Signal(&e,0);
        Signal(&f,0);
        Signal(&g,0);
        break;
    case 9:
        Signal(&a,0);
        Signal(&b,0);
        Signal(&c,0);
        Signal(&d,0);
        Signal(&f,0);
        Signal(&g,0);
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        break;
    case 15:
        break;
    }
}

void segmentoff(int num){
    switch (num)
    {
    case 0:
        Signal(&a,1);
        Signal(&b,1);
        Signal(&c,1);
        Signal(&d,1);
        Signal(&e,1);
        Signal(&f,1);
        break;
    case 1:
        Signal(&b,1);
        Signal(&c,1);
        break;
    case 2:
        Signal(&a,1);
        Signal(&b,1);
        Signal(&g,1);
        Signal(&e,1);
        Signal(&d,1);
        break;
    case 3:
        Signal(&a,1);
        Signal(&b,1);
        Signal(&c,1);
        Signal(&d,1);
        Signal(&g,1);
        break;
    case 4:
        Signal(&b,1);
        Signal(&c,1);
        Signal(&g,1);
        Signal(&f,1);
        break;
    case 5:
        Signal(&a,1);
        Signal(&c,1);
        Signal(&d,1);
        Signal(&g,1);
        Signal(&f,1);
        break;
    case 6:
        Signal(&a,1);
        Signal(&c,1);
        Signal(&d,1);
        Signal(&e,1);
        Signal(&g,1);
        Signal(&f,1);
        break;
    case 7:
        Signal(&a,1);
        Signal(&b,1);
        Signal(&c,1);
        break;
    case 8:
        Signal(&a,1);
        Signal(&b,1);
        Signal(&c,1);
        Signal(&d,1);
        Signal(&e,1);
        Signal(&f,1);
        Signal(&g,1);
        break;
    case 9:
        Signal(&a,1);
        Signal(&b,1);
        Signal(&c,1);
        Signal(&d,1);
        Signal(&f,1);
        Signal(&g,1);
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        break;
    case 15:
        break;
    }
}

void switch_led(){
    set_gpio(&ARD_D0,output);
    set_gpio(&ARD_D1,output);
    set_gpio(&ARD_D2,output);
    set_gpio(&ARD_D3,output);
    set_gpio(&ARD_D4,input);
    set_gpio(&ARD_D5,input);
    set_gpio(&ARD_D6,input);
    set_gpio(&ARD_D7,input);

    gpio_t* sw1 = &ARD_D4;
    gpio_t* sw2 = &ARD_D5;
    gpio_t* sw3 = &ARD_D6;
    gpio_t* sw4 = &ARD_D7;
    if(!(*((V_UINT32*)(sw1->port + IDR)) & (0x01 << sw1->pin))){
        Signal(&ARD_D0,0);
    }
    if(!(*((V_UINT32*)(sw2->port + IDR)) & (0x01 << sw2->pin))){
        Signal(&ARD_D1,0);
    }
    if(!(*((V_UINT32*)(sw3->port + IDR)) & (0x01 << sw3->pin))){
        Signal(&ARD_D2,0);
    }
    if(!(*((V_UINT32*)(sw4->port + IDR)) & (0x01 << sw4->pin))){
        Signal(&ARD_D3,0);
    }
}

void segment_7447(unsigned int num){
    	set_gpio(&ARD_D0,output);	// A
		set_gpio(&ARD_D1,output);   // B
		set_gpio(&ARD_D2,output);	// C
		set_gpio(&ARD_D3,output);   // D

		gpio_t* array[4] = {&ARD_D0,&ARD_D1,&ARD_D2,&ARD_D3};
		for(int j=0;j<4;j++){
			Signal(array[j],(num >> j) & 1);    // 항상 0, 1이 출력되게 만들어놨으므로 & 1을 해줘야함
		}
}
