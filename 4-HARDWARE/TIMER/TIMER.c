#include "common.h"
#include "stm32f10x.h"	

void Timer_Init(void)
{ 
 	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV2;
	TIM_TimeBaseStructure.TIM_Prescaler= (12-1);  //5s
	TIM_TimeBaseStructure.TIM_Period=(60000-1); 
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Down;
	TIM_ARRPreloadConfig(TIM4,DISABLE); 
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);


	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV2;
	TIM_TimeBaseStructure.TIM_Prescaler= (120-1);   //0.1s
	TIM_TimeBaseStructure.TIM_Period=(60000-1); 
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Down;
	TIM_ARRPreloadConfig(TIM3,DISABLE); 
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);

}
void pwm_init(u16 psc)
{
//	u16 PrescalerValue = 0;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_AFIO, ENABLE);
	
//	GPIO_PinRemapConfig(GPIO_PartialRemap2_TIM2,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
//	PrescalerValue = (u16) (SystemCoreClock /1000000) - 1;
	TIM_TimeBaseStructure.TIM_Period = (7200-1); //ARR
//  TIM_TimeBaseStructure.TIM_Prescaler = 9999;
	TIM_TimeBaseStructure.TIM_Prescaler = (psc-1); //PSC
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC2Init(TIM2, &TIM_OCInitStructure);

  TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM2,ENABLE);
//	TIM_ITConfig(TIM2,  TIM_IT_CC2 , ENABLE);
	
	TIM_Cmd(TIM2, ENABLE);
	
}
/***********************************************************************************/
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET)
	{
		iLEDCountR++;
		if(iLEDCountR<=50)
			GPIO_WriteBit(GPIOB,GPIO_Pin_5,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_5))); 
    else
			GPIO_SetBits(GPIOB, GPIO_Pin_5);
		
    TIM_ClearITPendingBit(TIM3,TIM_IT_Update);		
	}
}
/******************************************************************************************/
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update) != RESET)
	{
		iLEDCountG++;
		if(iLEDCountG<=500)
			GPIO_ResetBits(GPIOE, GPIO_Pin_5);
		else{
			GPIO_SetBits(GPIOE, GPIO_Pin_5);
				
			TIM_Cmd(TIM4,DISABLE);
			clear_screen(SCREEN_PSD);
			pwm_init(10);
			TIM2->CCR2=3599;
//	TIM_SetCompare2(TIM2,3599);
		}
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);

	}
}
