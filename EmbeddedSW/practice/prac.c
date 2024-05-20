// #include "led.h"
#include <stdio.h>
#define V_UINT32 volatile unsigned int
#define GPIOA 0x40020000U .....
#define GPIOE 0x40021000U
#define GPIOG 0x40021800U
#define MODER 0x00U         // 00 input mode, 01 output mode
#define OSPEEDR 0x08U       // 11 very high speed
#define PUPDR 0x0CU         // Pull-up 01
#define BSRR 0x18U          // High 16 bit reset, low 16 bit set
#define AHB1ENR 0x40023830U // clock enable, 하위 11비트 IO Port Enable
#define IDR 0x10U           // input data read 상위 16개는 사용하지 않음
#define oneSec 36000000

void myDelay(unsigned int delay){
    volatile unsigned int i;
    for(i=0;i<=delay * (oneSec/1000);i++);
}

void outSignal(unsigned char No, unsigned char Signal){
    switch(No){
        case 1:
            *((V_UINT32*)(GPIOG | BSRR)) |= (0x01 << 2 * 14) >> (16 * Signal);
            break;
        case 2:
            *((V_UINT32*)(GPIOE | BSRR)) |= (0x02 << 2 * 10) >> (16 * Signal);
            break;
        case 3:
            *((V_UINT32*)(GPIOE | BSRR)) |= (0x01 << 2 * 10) >> (16 * Signal);
            break;
        case 4:
            *((V_UINT32*)(GPIOG | BSRR)) |= (0x01 << 2 * 13) >> (16 * Signal);
            break;
    }
}

void userLedInit(unsigned char No){
    switch(No){
        case 1:
            // AHB1ENR
            *((V_UINT32*)(AHB1ENR)) |= 0x01 << 6;
            // MODER
            *((V_UINT32*)(GPIOG | MODER)) |= 0x01 << 2 * 12;
            // OSPEEDR
            *((V_UINT32*)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 12;
            // PUPDR
            *((V_UINT32*)(GPIOG | PUPDR)) |= 0x01 << 2 * 12;
            // set BSRR
            *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 12;
            break;
        case 2:
            // AHB1ENR
            *((V_UINT32*)(AHB1ENR)) |= 0x01 << 4;
            // MODER
            *((V_UINT32*)(GPIOE | MODER)) |= 0x01 << 2 * 5;
            // OSPEEDR
            *((V_UINT32*)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 5;
            // PUPDR
            *((V_UINT32*)(GPIOE | PUPDR)) |= 0x01 << 2 * 5;
            // set BSRR
            *((V_UINT32*)(GPIOE | BSRR)) |= 0x02 << 4;
            break;
        case 3:
            // AHB1ENR
            *((V_UINT32*)(AHB1ENR)) |= 0x01 << 4;
            // MODER
            *((V_UINT32*)(GPIOE | MODER)) |= 0x01 << 2 * 4;
            // OSPEEDR
            *((V_UINT32*)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 4;
            // PUPDR
            *((V_UINT32*)(GPIOE | PUPDR)) |= 0x01 << 2 * 4;
            // set BSRR
            *((V_UINT32*)(GPIOE | BSRR)) |= 0x01 << 4;
        case 4:
            // AHB1ENR
            *((V_UINT32*)(AHB1ENR)) |= 0x01 << 6;
            // MODER
            *((V_UINT32*)(GPIOG | MODER)) |= 0x01 << 2 * 10;
            // OSPEEDR
            *((V_UINT32*)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 10;
            // PUPDR
            *((V_UINT32*)(GPIOG | PUPDR)) |= 0x01 << 2 * 10;
            // set BSRR
            *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 10;
    }
}

void ledShift(unsigned char No){
    for(int i=No;i<=4;i++){
        outSignal(i,0);
        myDelay(100);
        outSignal(i,1);
        myDelay(100);
    }
    for(int i=3;i>0;i--){
        outSignal(i,0);
        if(i == 1) return;
        myDelay(100);
        outSignal(i,1);
        myDelay(100);
    }
}

void ledTop(unsigned int delay)
{
    int no = 4;
    while (1)
    {
        if (no == 0)
            return;
        for (int i = 1; i <= no; i++)
        {
            outSignal(i, 0);
            myDelay(delay * 100);
            outSignal(i, 1);
            if (i == no)
                outSignal(i, 0);
            myDelay(delay * 100);
        }
        no--;
    }
}

void ledBlink(unsigned char Number){
    unsigned int status[4];
    for(int i=0;i<4;i++){
        status[i] = (Number >> (6 - 2 * i)) & 0b11 + 1;
    }

    for(int i=0;i<4;i++){
        outSignal(status[i],0);
        myDelay(200);
        outSignal(status[i],1);
        myDelay(200);
    }
}

typedef struct{
    unsigned int pin;
    unsigned int status;
    unsigned int duration;
}A;

void LEDOnOff(unsigned int No)
{
    // status 0 : OFF, 0xf : on, odd : offon, even : onoff
    A a[4] = {0, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        a[i].pin = i + 1;
        a[i].status = (No >> 4 * (7 - 2 * i)) & 0xf;
        a[i].duration = (No >> 4 * (6 - 2 * i)) & 0xf;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < (3 - i); j++)
        {
            if (a[j].duration < a[j + 1].duration)
            {
                A tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (a[i].status == 0)  {outSignal(a[i].pin, 1);}
        if (a[i].status == 0xf) {outSignal(a[i].pin, 0);}
            
    }
        for (int k = 0; k < a[0].duration; k++)
        {
            for (int i = 0; i < 4; i++)
            {
                if (a[i].duration >= k + 1 && a[i].status != 0 && a[i].status != 0xf)
                {
                    if (a[i].status % 2 != 0)
                    {
                        outSignal(a[i].pin, 0);
                    }
                    else if (a[i].status != 0 && a[i].status % 2 == 0)
                    {
                        outSignal(a[i].pin, 1);
                    }
                }
            }
            myDelay(300);
            for (int i = 0; i < 4; i++)
            {
                if (a[i].duration >= k + 1 && a[i].status != 0 && a[i].status != 0xf)
                {
                    if (a[i].status % 2 != 0)
                    {
                        outSignal(a[i].pin, 1);
                    }
                    else if (a[i].status != 0 && a[i].status % 2 == 0)
                    {
                        outSignal(a[i].pin, 0);
                    }
                }
            }
            myDelay(300);
        }
    }

void prac_ledShift(unsigned char No){
    for(int i=1;i<5;i++){outSignal(i,1);}
    for(int i=No;i<=4;i++){
        outSignal(i,0);
        myDelay(400);
        outSignal(i,1);
        myDelay(400);
    }
    for(int i=3;i>0;i--){
        outSignal(i,0);
        myDelay(400);
        if(i == 1){return;}
        outSignal(i,1);
        myDelay(400);
    }
}

void prac_ledTop(unsigned int delay){
    unsigned int no = 4;
    for(int i=1;i<5;i++){outSignal(i,1);}
    do{
        for(int i=1;i<=no;i++){
        outSignal(i,0);
        myDelay(delay * 100);
        if(i == no) continue;
        outSignal(i,1);
        myDelay(delay * 100);
        }
        no--;
    }while(no != 0);
}

void prac_ledBlink(unsigned char Number){
    unsigned int pin[4];
    for(int i=0;i<4;i++){
        pin[i] = ((Number >> (6 - 2 * i)) & 0b11) + 1;
    }

    for(int i=0;i<4;i++){
        outSignal(pin[i],0);
        myDelay(300);
        outSignal(pin[i],1);
        myDelay(300);
    }
    for(int i=0;i<4;i++){outSignal(i,1);}
}

void prac_led1(unsigned int no){
    typedef struct{
        unsigned int pin;
        unsigned int duration;
    }A;
    A a[4] = {0,0};
    
    for(int i=0;i<4;i++){
        a[i].pin = ((no >> 4 * (7 - 2 * i)) & 0xf) + 1;
        a[i].duration = ((no >> 4 * (6 - 2 * i))&0xf); 
    }

    for(int i = 0;i<4;i++){
        for(int j=0;j<a[i].duration;j++){
            outSignal(a[i].pin,0);
            myDelay(300);
            outSignal(a[i].pin,1);
            myDelay(300);
        }
    }
}

void prac_led2(unsigned int no){
    typedef struct{
        unsigned int pin;
        unsigned int duration;
    }A;

    A a[4] = {0,0};

    for(int i=0;i<4;i++){
        a[i].pin = ((no >> 4 * (7 - 2 * i)) & 0xf) + 1;
        a[i].duration = ((no >> 4 * (6 - 2 * i)) & 0xf);
    }

    for(int i=0;i<3;i++){
        for(int j = 0;j < (3 - i);j++){
            if(a[j].duration < a[j + 1].duration){
                A tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
        }
    }
    unsigned int max = a[0].duration;
    for(int k = 1;k<=max;k++){
        for(int i=0;i<4;i++){
            if(a[i].duration >= k){
                outSignal(a[i].pin,0);
                
            }
        }
        myDelay(300);
        for(int i=0;i<4;i++){
            if(a[i].duration >= k){
                outSignal(a[i].pin,1);       
            }
        }
        myDelay(300);
    }
}

void prac_led3(unsigned int no){
    typedef struct{
        unsigned int pin;
        unsigned int duration;
    }A;

    A a[4] = {0,0};

    for(int i=0;i<4;i++){
        a[i].pin = ((no >> 4 * (7 - 2 * i)) & 0xf) + 1;
        a[i].duration = ((no >> 4 * (6 - 2 * i)) & 0xf);
    }

    for(int i=0;i<3;i++){
        for(int j = 0;j < (3 - i);j++){
            if(a[j].duration < a[j + 1].duration){
                A tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
        }
    }
    unsigned int max = a[0].duration;
    for(int k = 1;k<=max;k++){
        for(int i=0;i<4;i++){
            if(a[i].duration >= k){
                if(a[i].duration % 2 == 0 && a[i].duration != 0){outSignal(a[i].pin,0);}
                else{outSignal(a[i].pin,1);}
            }
        }
        myDelay(500);
        for(int i=0;i<4;i++){
            if(a[i].duration >= k){
                if(a[i].duration % 2 == 0 && a[i].duration != 0){outSignal(a[i].pin,1);}
                else{outSignal(a[i].pin,0);}      
            }
        }
        myDelay(500);
    }
}

void myDelay(unsigned char delay){
    volatile unsigned int i;
    for(i=0;i<=delay * (oneSec/1000);i++);
}

void InitGPIO(){
    // clock enable
    *((V_UINT32*)(AHB1ENR)) |= 0x01 << 4 | 0x01 << 6;

    // MODER
    *((V_UINT32*)(GPIOG | MODER)) |= 0x01 << 2 * 12 | 0x01 << 2 * 10;
    *((V_UINT32*)(GPIOE | MODER)) |= 0x01 << 2 * 5 | 0x01 << 2 * 4;

    // OSPEEDR
    *((V_UINT32*)(GPIOG | OSPEEDR)) |= 0x03 << 2 * 12 | 0x03 << 2 * 10;
    *((V_UINT32*)(GPIOE | OSPEEDR)) |= 0x03 << 2 * 5 | 0x03 << 2 * 4;

    // PUPDR
    *((V_UINT32*)(GPIOG | PUPDR)) |= 0x01 << 2 * 12 | 0x01 << 2 * 10;
    *((V_UINT32*)(GPIOE | PUPDR)) |= 0x01 << 2 * 5 | 0x01 << 2 * 4;

    // BSRR
    *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 2 * 14 | 0x01 << 2 * 13;
    *((V_UINT32*)(GPIOE | BSRR)) |= 0x02 << 2 * 10 | 0x01 << 2 * 10;
}

unsigned char MoveLED(unsigned char Dir, unsigned char Start, unsigned char Count, unsigned char Blink)
{
    unsigned char d;
    if (Dir == 0)
    {
        // LED 1->4
        for (int j = 0; j < Count; j++)
        {
            for (int i = Start; i <= 4; i++)
            {
                outSignal(i, 0);
                if (Blink == 0)
                {
                    for (int k = 1; k < 5 && k != i; k++)
                    {
                        outSignal(k, 1);
                    }
                    myDelay(1000);
                    outSignal(i,1);
                }
                else
                {
                    myDelay(100);
                    outSignal(i, 1);
                    myDelay(100);
                }
            }
            switch(Start){
                case 1:
                    d = 4;
                    break;
                case 2:
                     d = 1;
                     break;
                case 3:
                    d = 2;
                    break;
                case 4:
                    d = 3;
                    break;
            }
            for(int i=1;i<=d;i++){
                outSignal(i, 0);
                if(i == d) break;
                if (Blink == 0)
                {
                    for (int k = 1; k < 5 && k != i; k++)
                    {
                        outSignal(k, 1);
                    }
                    myDelay(1000);
                    outSignal(i,1);
                }
                else
                {
                    myDelay(100);
                    outSignal(i, 1);
                    myDelay(100);
                }
            }
        }   
    }
    else
    {
         for (int j = 0; j < Count; j++)
        {
            for (int i = Start; i >= 1; i--)
            {
                outSignal(i, 0);
                if (Blink == 0)
                {
                    for (int k = 1; k < 5 && k != i; k++)
                    {
                        outSignal(k, 1);
                    }
                    myDelay(1000);
                    outSignal(i,1);
                }
                else
                {
                    myDelay(100);
                    outSignal(i, 1);
                    myDelay(100);
                }
            }
            switch(Start){
                case 1:
                    d = 2;
                    break;
                case 2:
                     d = 3;
                     break;
                case 3:
                    d = 4;
                    break;
                case 4:
                    d = 1;
                    break;
            }
            for(int i=4;i>=d;i--){
                outSignal(i, 0);
                if(i == d) break;
                if (Blink == 0)
                {
                    for (int k = 1; k < 5 && k != i; k++)
                    {
                        outSignal(i, 1);
                    }
                    myDelay(1000);
                }
                else
                {
                    myDelay(100);
                    outSignal(i, 1);
                    myDelay(100);
                }
            }
        }
    }
    return d;
}

void JustOneLED(unsigned int LED1,unsigned int LED2,unsigned int LED3,unsigned int LED4){
    typedef struct{
        unsigned int pin;
        unsigned int cnt;
    }A;

    unsigned int k[4] = {LED1,LED2,LED3,LED4};
    A a[4] ={0,0};

    for(int i=0;i<4;i++){
        a[i].pin = i + 1;
        int cnt = 0;
        for(int i=0;i<32;i++){
            if(k[i] >> (31 - i) & 0b1 == 1) cnt++;
        }
        a[i].cnt = cnt;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<(3 - i);j++){
            if(a[i].cnt < a[i + 1].cnt){
                A tmp = a[i];
                a[i] = a[i + 1];
                a[i+1] = tmp;
            }
        }
    }
    unsigned int max = a[0].cnt;

    for(int i=1;i<=max;i++){
        for(int j=1;j<5;j++){
            if(a[j].cnt == max) outSignal(a[j].pin,0);
            else outSignal(a[j].pin,1);
        }
    }
}

void MyApp(){
    JustOneLED(1,3,5,7);
}

int main()
{
    printf("%x\n",(0x1 & 0x1) % 2);
    // hwInit();
}


