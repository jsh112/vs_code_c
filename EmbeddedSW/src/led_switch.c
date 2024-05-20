#include "gpio.h"
#include "led_switch.h"

static void SystemClock_Config(void){
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
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    //Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    //Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK){
    //Error_Handler();
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




void MyApp_0411(){
    // LEDOnOff(0xF0F0F1FF);
    // 모든 LED ON
    // MyDelay(5);

    //LEDOnOff(0x0000010F);
    // // 모든 LED off
    // MyDelay(5);

    // LEDOnOff(0x15FF2A01);
    // // 1번 LED 5번, 3번 LED 10번 동시점멸
    // // 2번은 켜고, 4번은 끈다
    // // 즉, 2는 켜져있고 4는 꺼져있고 1,3이 동시점멸을 하는데 1은 on으로 시작 3은 off로 시작
    // LEDOnOff(0x0F0F0F0F);

    // // 모든 LED Off
    // MyDelay(5);

    // LEDOnOff(0xA3138323);
}





/*void LEDOnOff(unsigned int No)
{

    *((V_UINT32*)(GPIOG | BSRR)) &= 0x00;
    *((V_UINT32*)(GPIOE | BSRR)) &= 0x00;
    unsigned int bits[4];
    int on[4] = {0};
    int off[4] = {0};
    // int onoff[4] = {0};
    // int offon[4] = {0};

    INFO info[4] = {0, 0};

    // bit masking
    bits[0] = (No >> 24) & 0xff;
    bits[1] = (No >> 16) & 0xff;
    bits[2] = (No >> 8) & 0xff;
    bits[3] = (No) & 0xff;

    for (int i = 0; i < 4; i++)
    {
        unsigned int p1 = (bits[i]>>4) & 0x0f;
        unsigned int p2 = bits[i] & 0x0f;

        if (p1 == 0x0f)
            on[i] = 1;
        else if (p1 == 0)
            off[i] = 1;
        else
        {
            if (p1 % 2 == 0 && p1 != 0)
            {
                // 짝수 on off
                // onoff[i] = p2;
                info[i].status = 2;
                info[i].n = p2;
            }
            else if (p1 % 2 != 0)
            {
                // 홀수 off on
                // offon[i] = p2;
                info[i].status = 1;
                info[i].n = p2;
            }
            else
            {
                off[i] = 1;
            }
        }
    }

    int cnt[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        if (info[i].status != 0)
            cnt[i] = info[i].n;
        if (on[i])
            LEDOn(i + 1);
        if (off[i])
            LEDOff(i + 1);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            if (cnt[j] < cnt[j + 1])
            { // 버블 정렬 사용
                int temp = cnt[j];
                cnt[j] = cnt[j + 1];
                cnt[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < cnt[0]; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (info[i].n != 0 && info[i].n >= k + 1)
            {
                if (info[i].status == 1)
                    LEDOff(i + 1);
                if (info[i].status == 2)
                    LEDOn(i + 1);
            }
            else
                continue;
        }

        MyDelay_half(1);
        for (int i = 0; i < 4; i++)
        {
            if (info[i].n != 0 && info[i].n >= k + 1)
            {
                if (info[i].status == 1)
                    LEDOn(i + 1);
                if (info[i].status == 2)
                    LEDOff(i + 1);
            }
            else
                continue;
        }
        MyDelay_half(1);
    }
}*/

/*void MyApp_test()
{
    LEDOnOff(0xF0F0F1FF);
    MyDelay_half(10);

    LEDOnOff(0x0000010F);
    MyDelay_half(10);

    LEDOnOff(0x15FF2A01);

    LEDOnOff(0x0F0F0F0F);
    MyDelay_half(10);

    LEDOnOff(0xA3138323);
}*/

// void myDelay(unsigned int n)
// {
//     volatile unsigned int delay;
//     for (delay = 0; delay <= n * (oneSec / 1000); delay++)
//         ;
// }

// void ledTop(unsigned int delay){

//     for(int i=0;i<5;i++) {userLedInit(i);}
//     outSignal(1,0);
//     myDelay(delay * 100);
//     outSignal(1,1);
//     outSignal(2,0);
//     myDelay(delay * 100);
//     outSignal(2,1);
//     outSignal(3,0);
//     myDelay(delay * 100);
//     outSignal(3,1);
//     outSignal(4,0);
//     myDelay(delay * 100);

//     outSignal(1,0);
//     myDelay(delay * 100);
//     outSignal(1,1);
//     outSignal(2,0);
//     myDelay(delay * 100);
//     outSignal(2,1);
//     outSignal(3,0);
//     myDelay(delay * 100);

//     outSignal(1,0);
//     myDelay(delay * 100);
//     outSignal(1,1);
//     outSignal(2,0);
//     myDelay(delay * 100);

//     outSignal(1,0);
//     myDelay(delay * 100);
// }


/*void outSignal(unsigned char No, unsigned char Signal){
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
}*/

void ledTop(unsigned int delay)
{
    int no = 4;
    for(int i=0;i<5;i++){outSignal(i,1);}
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



/*void LEDBlink(unsigned char num)
{
    unsigned char bits[4];
    for (int i = 0; i < 4; i++) bits[i] = ((num >> (6 - 2 * i)) & 0b11) + 1;

    for (int i = 0; i < 4; i++)
    {
        outSignal(bits[i], 0);
        myDelay(500);
        outSignal(bits[i], 1);
        myDelay(500);
    }

    for (int i = 0; i < 4; i++) outSignal(i, 1);
}*/

typedef struct{
    unsigned int status;
    unsigned int duration;
}INFO;

/*void LEDOnOff(unsigned int No)
{
    INFO info[4] = {0, 0};
    unsigned int cnt[4] = {0};

    for (int i = 0; i < 4; i++)
    {
        info[i].status = (No >> 4 * (7 - 2 * i)) & 0xf;
        info[i].duration = (No >> 4 * (6 - 2 * i)) & 0xf;
        if (info[i].status == 0)
            outSignal(i + 1, 1);
        else if (info[i].status == 0xf)
            outSignal(i + 1, 0);
        else
            cnt[i] = info[i].duration;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 4; j > (4 - 1 - i); j++)
        {
            if (cnt[j] < cnt[j + 1])
            {
                unsigned int tmp = cnt[j + 1];
                cnt[j + 1] = cnt[j];
                cnt[j] = tmp;
            }
        }
    }

    for (int k = 0; k < cnt[0]; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (info[i].duration != 0 && info[i].duration >= k + 1 && !((info[i].status == 0xf) || info[i].status == 0))
            {
                if (info[i].status % 2 != 0)
                    outSignal(i + 1, 1);
                if (info[i].status % 2 == 0)
                    outSignal(i + 1, 0);
            }
        }
        myDelay(500);
        for (int i = 0; i < 4; i++)
        {
            if (info[i].duration != 0 && info[i].duration >= k + 1 && !((info[i].status == 0xf) || info[i].status == 0))
            {
                if (info[i].status % 2 != 0)
                    outSignal(i + 1, 0);
                if (info[i].status % 2 == 0)
                    outSignal(i + 1, 1);
            }
        }
        myDelay(500);
    }
}*/



/*typedef struct
{
    unsigned int pin;
    unsigned int duration;
} A;*/

/*void led1(unsigned int no)
{
    A a[4];
    unsigned int cnt[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        a[i].pin = (no >> 4 * (7 - 2 * i)) & 0xf;
        a[i].duration = (no >> 4 * (6 - 2 * i)) & 0xf;
        cnt[i] = a[i].duration;
    }

    for (int i = 0; i < (4 - 1); i++)
    {
        for (int j = 0; j < (4 - 1 - i); j++)
        {
            if (cnt[j] < cnt[j + 1])
            {
                unsigned int tmp = cnt[j];
                cnt[j] = cnt[j + 1];
                cnt[j + 1] = tmp;
            }
        }
    }

    for (int k = 0; k < cnt[0]; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            unsigned int p = a[i].pin;
            unsigned int d = a[i].duration;
            if (d >= k + 1)
            {
                outSignal(p + 1, 0);
            }
        }
        myDelay(500);
        for (int i = 0; i < 4; i++)
        {
            unsigned int p = a[i].pin;
            unsigned int d = a[i].duration;
            if (d >= k + 1)
            {
                outSignal(p + 1, 1);
            }
        }
        myDelay(500);
    }
}*/


typedef struct
{
    unsigned int pin;
    unsigned int delay;
}pin_delay ;



void ledBlink(unsigned char Number){
    unsigned int status[4];
    for(int i=0;i<4;i++){
        status[i] = ((Number >> (6 - 2 * i)) & 0b11) + 0b01;
    }

    for(int i=0;i<4;i++){
        outSignal(status[i],0);
        myDelay(200);
        outSignal(status[i],1);
        myDelay(200);
    }
}

void myDelay(unsigned char delay){
    volatile unsigned int i;
    for(i=0;i<=delay * (oneSec/1000);i++);
}

/*unsigned char MoveLED(unsigned char Dir, unsigned char Start, unsigned char Count, unsigned char Blink)
{
    unsigned char d;
    if (Dir == 0)
    {
        // LED 1->4

        for (int j = 0; j < Count; j++)
        {
        		for(int i=1;i<=4;i++){outSignal(i,1);}
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
                if (Blink == 0)
                {
                    for (int k = 1; k < 5 && k != i; k++)
                    {
                        outSignal(k, 1);
                    }
                    myDelay(1000);
                    if(i == d)break;
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
                    if(i == d)break;
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
                if (Blink == 0)
                {
                    for (int k = 1; k < 5 && k != i; k++)
                    {
                        outSignal(i, 1);
                    }
                    myDelay(1000);
                    outSignal(i,1);
                }
                else
                {
                    myDelay(100);
                    if(i == d) break;
                    outSignal(i, 1);

                    myDelay(100);
                }
            }
        }
    }
    return d;
}
*/


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

int BTN_Check_BNB(int No, int Status){
    if (Status == 0){
        if (No == 1){
            if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)){return 1;}
            else return 0;
        }
        if (No == 2){
            if (*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12)){return 1;}
            else return 0;
        }
    }
    if (Status == 1){
        // 떼면 return
        if (No == 1){
            if (!(*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3))){return 0;}
            while(*((V_UINT32*)(GPIOG | IDR)) & (0x01 << 3));
            return 1;
        }
        if (No == 2){
            if (!(*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))){return 0;}
            while(*((V_UINT32*)(GPIOC | IDR)) & (0x01 << 12));
            return 1;
        }
    }
}

void LED_5_1(void){
    if(*((V_UINT32*)(GPIOG | IDR)) & (0x01 << 3)){
        for (int i = 0; i < 5; i++)
        {
            outSignal(1, 0);
            outSignal(2, 0);
            outSignal(3, 0);
            outSignal(4, 0);
            myDelay(500);
            outSignal(1, 1);
            outSignal(2, 1);
            outSignal(3, 1);
            outSignal(4, 1);
            myDelay(500);
        }
    }
    else return;
}

void LED_5_2(void){
    while(1){
        int n = 1;
        if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)){
            while(n <= 5){
            if (*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)){
                n = 1;
                continue;
            }
            else{
            *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 2 * 14 | 0x01 << 2 * 13;
            *((V_UINT32*)(GPIOE | BSRR)) |= 0x02 << 2 * 10 | 0x01 << 2 * 10;
            myDelay(500);
            *((V_UINT32*)(GPIOG | BSRR)) |= 0x01 << 2 * 6 | 0x01 << 2 * 5;
            *((V_UINT32*)(GPIOE | BSRR)) |= 0x02 << 2 * 2 | 0x01 << 2 * 2;
            myDelay(500);
            }
            n++;
            }
        }
    }
}


int ledpush(void){
    if((*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3))){
        while((*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3) == (0x01 << 3)) & !(*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12)) == (0x01 << 12));
        return 1;
    }
    else if((*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12))){
        while((*((V_UINT32 *)(GPIOC | IDR)) & (0x01 << 12) == (0x01 << 12)) & !(*((V_UINT32 *)(GPIOG | IDR)) & (0x01 << 3)) == (0x01 << 3));
        return 2;
    }
    else {return 0;}
}

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

btn_t btn1 = {GPIOG, (0x03 << 6), (0x01 << 3)};
btn_t btn2 = {GPIOC, (0x03 << 24), (0x01 << 12)};

void BtnInit(btn_t *btn)
{
    *((V_UINT32 *)(AHB1ENR)) |= 0x01 << 2 | 0x01 << 6;

    *((V_UINT32 *)(btn->port + MODER)) &= ~(btn->data);
    *((V_UINT32 *)(btn->port + OSPEEDR)) &= ~(btn->data);
    *((V_UINT32 *)(btn->port + PUPDR)) &= ~(btn->data);
}

void delay(unsigned int ms)
{
    volatile int time;
    for (time = 0; time <= ms * (oneSec / 1000); time++)
        ;
}

int BtnCheck()
{
    int status = 0;
    if (*((V_UINT32 *)(GPIOG + IDR)) & (0x01 << 3))
        status += 1;
    if (*((V_UINT32 *)(GPIOC + IDR)) & (0x01 << 12))
        status += 2;
    return status;
}



