#include "sys.h"
//================中断优先级配置
void NVIC_Configuration(void)
{
   NVIC_InitTypeDef  NVIC_InitStructure;  
   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级     
//USART1中断
   NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; 
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);  
//USART2中断
   NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; 
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; 
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
	
////EXTI0中断
//   NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn; 
//   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
//   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//   NVIC_Init(&NVIC_InitStructure);
	 
//TIMER2中断
   NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; 
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);  
//TIMER3中断
   NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn; 
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);  
// //TIMER4中断
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
//===========RCC配置HSE，主频为72MHz
void RCC_Configuration(void) 
{
   RCC_DeInit(); 

   RCC_HSEConfig(RCC_HSE_ON);
   while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);

   RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
   RCC_PLLCmd(ENABLE); 
   while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); 

   RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); 
   while(RCC_GetSYSCLKSource() != 0x08); 

   RCC_HCLKConfig(RCC_SYSCLK_Div1); 
   RCC_PCLK1Config(RCC_HCLK_Div2);  
   RCC_PCLK2Config(RCC_HCLK_Div1);  
}
