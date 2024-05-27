//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 1. 인터럽트 기본 코드, 코드 완성을 위해서 기존의 자신의 코드에 잘 포함시켜서 사용하면 됨.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////


#define V_UINT32 volatile unsigned int

int CheckClockStatus(unsigned char GPIO){
  /*
      clock Enable Check
      Parameters:
          unsigned char GPIOPort : 1(A), 2(B), ... n=K 까지
      Returns:
          0 : not enable state, 1 : enable state
  */
  V_UINT32 value  = *((V_UINT32*)(0x40023830U));
  unsigned char mask   = (1 << (GPIO - 1));
  return (value & mask) == mask; //AHB1ENR clock check
}

void ClockEnable(unsigned char GPIO){
  /*
      GPIO Clock Enable
      Parameters:
          unsigned char GPIOPort : 1(A), 2(B), ... n=K 까지
      Returns:
          None
  */
  *( (V_UINT32*)(0x40023830U) ) |= (1 << (GPIO-1)); //AHB1ENR clock enable
}

void userLedInit(unsigned char num){
  /*
      User LED Register setup
      Parameters:
          unsigned char num : 1(LED1), 2(LED2), 3(LED3), 4(LED4)
      Returns:
          None
  */
  switch(num){
    case 1 : //PG12
      if(!CheckClockStatus(7)) ClockEnable(7);
      *((V_UINT32*)(0x40021800U + 0x00U)) &= ~(3 << (12 * 2)); // Clear MODER
      *((V_UINT32*)(0x40021800U + 0x00U)) |= (1 << (12 * 2));  // Set MODER to output
      *((V_UINT32*)(0x40021800U + 0x08U)) |= (3 << (12 * 2));  // Set OSPEEDR to high speed
      *((V_UINT32*)(0x40021800U + 0x18U)) |= 1 << 12; //GPIOG12 BSRR set
      break;
    case 2 : //PE5
      if(!CheckClockStatus(5)) ClockEnable(5);
      *((V_UINT32*)(0x40021000U + 0x00U)) &= ~(3 << (5 * 2)); // Clear MODER
      *((V_UINT32*)(0x40021000U + 0x00U)) |= (1 << (5 * 2));  // Set MODER to output
      *((V_UINT32*)(0x40021000U + 0x08U)) |= (3 << (5 * 2));  // Set OSPEEDR to high speed
      *((V_UINT32*)(0x40021000U + 0x18U)) |= 1 << 5; //GPIOE5 BSRR set
      break;
    case 3 : //PE4
      *((V_UINT32*)(0x40021000U + 0x00U)) &= ~(3 << (4 * 2)); // Clear MODER
      *((V_UINT32*)(0x40021000U + 0x00U)) |= (1 << (4 * 2));  // Set MODER to output
      *((V_UINT32*)(0x40021000U + 0x08U)) |= (3 << (4 * 2));  // Set OSPEEDR to high speed
      *((V_UINT32*)(0x40021000U + 0x18U)) |= 1 << 4; //GPIOE4 BSRR set
      break;
    case 4 : //PG10
      if(!CheckClockStatus(7)) ClockEnable(7);
      *((V_UINT32*)(0x40021800U + 0x00U)) &= ~(3 << (10 * 2)); // Clear MODER
      *((V_UINT32*)(0x40021800U + 0x00U)) |= (1 << (10 * 2));  // Set MODER to output
      *((V_UINT32*)(0x40021800U + 0x08U)) |= (3 << (10 * 2));  // Set OSPEEDR to high speed
      *((V_UINT32*)(0x40021800U + 0x18U)) |= 1 <<10 ; //GPIOG10 BSRR set
      break;
  }
}

void outSignal(unsigned char num, unsigned char signal){
  /*
      User LED Register setup
      Parameters:
          unsigned char num : 1(LED1), 2(LED2) ...
          unsigned char signal : 0 or 1 (reset or set)
      Returns:
          None
  */
  if(signal){ // set
    if(num==1)      *((V_UINT32*)(0x40021800U + 0x18U)) |= 1 << 12;
    else if(num==2) *((V_UINT32*)(0x40021000U + 0x18U)) |= 1 << 5;
    else if(num==3) *((V_UINT32*)(0x40021000U + 0x18U)) |= 1 << 4;
    else if(num==4) *((V_UINT32*)(0x40021800U + 0x18U)) |= 1 << 10;
  }
  else{ // reset
    if(num==1)      *((V_UINT32*)(0x40021800U + 0x18U)) |= 1 << 12 << 16;
    else if(num==2) *((V_UINT32*)(0x40021000U + 0x18U)) |= 1 << 5 << 16;
    else if(num==3) *((V_UINT32*)(0x40021000U + 0x18U)) |= 1 << 4 << 16;
    else if(num==4) *((V_UINT32*)(0x40021800U + 0x18U)) |= 1 << 10 << 16;
  }
}

int main(void) {
  bspInit(); // hwInit()으로 대체 가능
  // GPIOC Clock 활성화
  *((V_UINT32*)(0x40023800 | 0x30)) |= (1 << 2); // RCC_AHB1ENR

  // PC12 input mode설정
  *((V_UINT32*)(0x40020800 | 0x00)) &= ~(3 << (12 * 2)); // GPIOC_MODER

  // PC12 no pull 설정
  *((V_UINT32*)(0x40020800 | 0x0C)) &= ~(3 << (12 * 2)); // GPIOC_PUPDR

  // SYSCFG Clock 활성화
  *((V_UINT32*)(0x40023800 | 0x44)) |= (1 << 14); // RCC_APB2ENR

  // EXTI12를 PC12와 연결
  *((V_UINT32*)(0x40013800 | 0x14)) &= ~(0xF << 0); // SYSCFG_EXTICR4
  *((V_UINT32*)(0x40013800 | 0x14)) |= (2 << 0);    // SYSCFG_EXTICR4

  // EXTI12를 인터럽트 line 활성화
  *((V_UINT32*)(0x40013C00 | 0x00)) |= (1 << 12); // EXTI_IMR

  // EXTI12 Falling Edge 설정
  *((V_UINT32*)(0x40013C00 | 0x0C)) |= (1 << 12); // EXTI_FTSR

  *((V_UINT32*)(0xE000E100 + (40 / 32) * 4)) = (1 << (40 % 32)); // EXTI15_10_IRQn = 40, NVIC ISER

  for(int i=1; i<5; i++){
    userLedInit(i);
    outSignal(i,0);
  }
  // Main loop
  while (1) {
    // 인터럽트 발생안했을 때 지속적으로 수행할 동작코드
    for(int i=1; i<5; i++){ outSignal(i,0); }
    for(int i=0; i<36000000; i++){}
    for(int i=1; i<5; i++){ outSignal(i,1); }
    for(int i=0; i<36000000; i++){}
  }
}

void EXTI15_10_IRQHandler(void) {
    // 인터럽트 12번이 트리거됐는지 확인
    if (*((V_UINT32*)(0x40013C00 | 0x14)) & (1 << 12)) { // EXTI_PR
        // interrupt flag 클리어 후 2초
        *((V_UINT32 *)(0x40013C00 | 0x14)) |= (1 << 12); // EXTI_PR
        for(int i=0; i<36000000*2; i++){}

        /* 2초 후 interrupt flag 클리어
        for(int i=0; i<36000000*2; i++){}
        *((V_UINT32 *)(0x40013C00 | 0x14)) |= (1 << 12); // EXTI_PR */

    }
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 2. 타이머 기본 코드, 코드 완성을 위해서 기존의 자신의 코드에 잘 포함시켜서 사용하면 됨.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#define V_UINT32 volatile unsigned int

int main(void) {
  bspInit(); // hwInit()으로 대체 가능
  *((V_UINT32*)(0x40023844)) |= 0x0001; // RCC APB2ENR, TIM1EN enable

  *((V_UINT32*)(0x40010000 | 0x28)) |= 21600*5-1; // TIM1 PSC
  *((V_UINT32*)(0x40010000 | 0x2C)) |= 9999; // TIM1 ARR
  *((V_UINT32*)(0x40010000 | 0x0C)) |= 0x01; // TIM1 DIER UIE enable
  *((V_UINT32*)(0x40010000 | 0x00)) |= 0x01; // TIM1 CR1 CEN enable
  *((V_UINT32*)(0x40010000 | 0x10)) &= 0x01; // TIM1 SR UIF clear

  *((V_UINT32*)(0xE000E100 + (25 / 32) * 4)) = (1 << (25 % 32)); // 25, NVIC ISER
  for(int i=1; i<5; i++){
    userLedInit(i);
    outSignal(i,0);
  }
  // Main loop
  while (1) {
    for(int i=1; i<5; i++){ outSignal(i,0); }
    for(int i=0; i<36000000*2; i++){}
    for(int i=1; i<5; i++){ outSignal(i,1); }
    for(int i=0; i<36000000*2; i++){}
  }
}

void TIM1_UP_TIM10_IRQHandler(void){
  /*
       Timer1 1sec cnt -> led blink
       Parameters:
           None
       Returns:
           None
  */

  if (*((V_UINT32*)(0x40010000 + 0x10)) & 0x01){ // check if update interrupt flag
    *((V_UINT32*)(0x40010000 + 0x10)) &= ~0x01; // clear update interrupt flag

    // 인터럽트 발생시 수행할 코드
    for(int i=0; i<36000000; i++){
        for(int i=1; i<5; i++){ outSignal(i,0); }
        for(int i=0; i<36000000/5; i++){}
        for(int i=1; i<5; i++){ outSignal(i,1); }
        for(int i=0; i<36000000/5; i++){}
    }
  }
}

