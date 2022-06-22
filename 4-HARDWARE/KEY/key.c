#include "stm32f10x.h"
#include "common.h"
u16 iLEDCountG,iLEDCountR,iErrTime;
								    
//按键初始化函数
void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//使能PORTA,PORTE时钟

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;//KEY0-KEY2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE2,3,4

	//初始化 WK_UP-->GPIOA.0	  下拉输入
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//GPIO→AFIO
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);

}

//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY0按下
//2，KEY1按下
//3，KEY2按下 
//4，KEY3按下 WK_UP
//注意此函数有响应优先级,KEY0>KEY1>KEY2>KEY3!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
		else if(WK_UP==1)return WKUP_PRES;
	}else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1; 	    
 	return 0;// 无按键按下
}
void Key0_Func(void)
{
	if(iNum3!=9) iNum3++;
	else if(iNum3==9) iNum3=0;
}
void Key1_Func(void)
{
	if(iNum1!=9) iNum1++;
	else if(iNum1==9) iNum1=0;
}
void Key2_Func(void)
{
	if(iNum2!=9) iNum2++;
	else if(iNum2==9) iNum2=0;
}
void KeyUp_Func(void)
{
	if(cmpPass())
		{
			clear_screen(SCREEN_STA);
		  iLEDCountG=0;
		  pwm_init(5);
			TIM2->CCR2=719;
//	  TIM_SetCompare2(TIM2,719);
		  TIM_Cmd(TIM4, ENABLE);
		  TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
		  iErrTime=0;
		}
	 else
	 {
		 clear_screen(SCREEN_PSD);
		 iNum1=-1;
		 iNum2=-1;
		 iNum3=-1;
		 iErrTime++;
		 if(iErrTime>=3)
		 { 
			 iLEDCountR=0;
			 TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	     TIM_Cmd(TIM3, ENABLE);
//		 iErrTime=0;
		 }
	 }
}
