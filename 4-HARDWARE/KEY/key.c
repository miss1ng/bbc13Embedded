#include "stm32f10x.h"
#include "common.h"
u16 iLEDCountG,iLEDCountR,iErrTime;
								    
//������ʼ������
void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//ʹ��PORTA,PORTEʱ��

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;//KEY0-KEY2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4

	//��ʼ�� WK_UP-->GPIOA.0	  ��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0���ó����룬Ĭ������	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.0
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//GPIO��AFIO
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);

}

//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY0����
//2��KEY1����
//3��KEY2���� 
//4��KEY3���� WK_UP
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>KEY3!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
	{
		delay_ms(10);//ȥ���� 
		key_up=0;
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
		else if(WK_UP==1)return WKUP_PRES;
	}else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1; 	    
 	return 0;// �ް�������
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
