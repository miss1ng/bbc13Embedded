#include "sys.h"
//================�ж����ȼ�����
void NVIC_Configuration(void)
{
   NVIC_InitTypeDef  NVIC_InitStructure;  
   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�     
//USART1�ж�
   NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; 
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);  
//USART2�ж�
   NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; 
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; 
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
	
////EXTI0�ж�
//   NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn; 
//   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
//   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//   NVIC_Init(&NVIC_InitStructure);
	 
//TIMER2�ж�
   NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; 
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);  
//TIMER3�ж�
   NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn; 
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);  
// //TIMER4�ж�
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
//===========RCC����HSE����ƵΪ72MHz
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
