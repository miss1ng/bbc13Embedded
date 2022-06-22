#include "common.h"
/******************调试模式****************************************/
u8 idbgMode=0; //开启(1)或关闭(0)调试信息
/******************************************************************/

/***********************************************************************************/
u8 key,tkey;
u8 k;

u8 Rec_Buffer[Buffer_Size];

u8 iLastPassBit=0;
u8 iCurrentPassBit=1;

int iNum1=-1;
int iNum2=-1;
int iNum3=-1;
u8 iPwd1=1;
u8 iPwd2=2;
u8 iPwd3=3;

u8 iCurrentScreen=SCREEN_PSD;

u8 cmpPass(void)
{
	if (iNum1==iPwd1&&iNum2==iPwd2&&iNum3==iPwd3)
		return 1;
	else return 0;
}
u8 isValidPass(u8 buffer[])
{
	if ((!buffer[7]=='\0')||(!buffer[3]=='-')||(RxIdx1>Buffer_Size)) return 0;
	else return 1;
}
void Key_Loop(void)
{
	if (!iCurrentScreen==SCREEN_PSD) return;
	
	key=KEY_Scan(0);
	if (key==KEY2_PRES)	Key2_Func();
	else if (key==KEY1_PRES)	Key1_Func();
	else if (key==KEY0_PRES)	Key0_Func();
	else if (key==WKUP_PRES)	KeyUp_Func();
}

void Display_Loop(void)
{
	u8 ioldPwd[3],inewPwd[3],iorgPwd[3];
	sprintf((char*)iorgPwd,"%d%d%d",iPwd1,iPwd2,iPwd3);
	if (isValidPass(Rec_Buffer)){
		sprintf((char*)ioldPwd,"%c%c%c",Rec_Buffer[0],Rec_Buffer[1],Rec_Buffer[2]); 
		sprintf((char*)inewPwd,"%c%c%c",Rec_Buffer[4],Rec_Buffer[5],Rec_Buffer[6]);
	}
	
	if (iCurrentScreen==SCREEN_PSD)
	{
		LCD_ShowString(150,10,24*3,24,24,"PSD");
		
		LCD_ShowString(5,iCurrentPassBit*44,24*2,24,24,"->");
		LCD_ShowString(5,iLastPassBit*44,24*2,24,24,"  ");
		
		if (iNum1!=-1)	LCD_ShowNum(67,50,iNum1,1,24);
		else	LCD_ShowString(30,50,240,24,24,"B1:@     ");
		if (iNum2!=-1)	LCD_ShowNum(67,90,iNum2,1,24);
		else	LCD_ShowString(30,90,240,24,24,"B2:@     ");
		if (iNum3!=-1)	LCD_ShowNum(67,130,iNum3,1,24);
		else	LCD_ShowString(30,130,240,24,24,"B3:@     ");
	}
	else if (iCurrentScreen==SCREEN_STA)
	{
		LCD_ShowString(150,10,24*3,24,24,"STA");
		LCD_ShowString(30,50,24*8,24,24,"F:2000Hz");
		LCD_ShowString(30,90,24*5,24,24,"D:10%");
//		LCD_ShowString(30,130,24*3,24,24,"             ");
	}
	if (idbgMode){
			LCD_ShowString(30+150,190-100,500,24,24,"----DEBUG INFO----");
			LCD_ShowString(30+150,220-100,200,24,24,"Cur:");
			LCD_ShowString(30+150,250-100,200,24,24,"RecBuffer:");
			LCD_ShowString(30+150,280-100,24*16,24,24,"passed:");
			LCD_ShowString(80+150,220-100,200,24,24,iorgPwd);//当前正确的密码
			LCD_ShowString(170+150,250-100,200,24,24,Rec_Buffer);
			LCD_ShowNum((24*16)+24,280-100,cmpPass(),1,24);
	}
	
	/*******************************************************************************************/	
	if (Buffercmp(iorgPwd,ioldPwd,3)==PASSED)//如果原始密码和输入的原始密码相同则可以更改新密码
	{
		if(isValidPass(Rec_Buffer))//判断修改密码字符串的格式是否正确
		{
		iPwd1=Rec_Buffer[4]^48;
		iPwd2=Rec_Buffer[5]^48;
		iPwd3=Rec_Buffer[6]^48;
//		RxIdx1=0;
		}
	}
/*******************************************************************************************/	
}

void TPad_Loop(void)
{
	if (iCurrentScreen!=SCREEN_PSD) return;
	
	TKEY_Display();
	tkey=TKEY_Scan();
	if(tkey==TKB1_PRES)	TKEYB_Func(1);
	else if(tkey==TKB2_PRES)	TKEYB_Func(2);
	else if(tkey==TKB3_PRES)	TKEYB_Func(3);
	else if(tkey==TWKUP_PRES)	KeyUp_Func();
	
	else if(tkey==TKEY0_PRES)	TKNum_Func(0);
	else if(tkey==TKEY1_PRES)	TKNum_Func(1);
	else if(tkey==TKEY2_PRES)	TKNum_Func(2);
	else if(tkey==TKEY3_PRES)	TKNum_Func(3);
	else if(tkey==TKEY4_PRES)	TKNum_Func(4);
	else if(tkey==TKEY5_PRES)	TKNum_Func(5);
	else if(tkey==TKEY6_PRES)	TKNum_Func(6);
	else if(tkey==TKEY7_PRES)	TKNum_Func(7);
	else if(tkey==TKEY8_PRES)	TKNum_Func(8);
	else if(tkey==TKEY9_PRES)	TKNum_Func(9);
}
int main(void)
{
	RCC_Configuration();
	NVIC_Configuration(); 
	delay_init();	    	 //延时函数初始化	 
	Timer_Init();
	uart_init(115200);	 	//串口初始化为115200
	
	pwm_init(10);         //1kHz 50%（初始状态，密码输入界面）
	TIM2->CCR2=3599;
	
//   pwm_init(5);  //2kHz 10%（密码正确时，输出状态界面）
// 	TIM2->CCR2=719;

	
	
	
	
	LED_Init();			     //LED端口初始化	
	KEY_Init(); 
	
	LCD_Init();
	LCD_Display_Dir(1);
	tp_dev.touchtype=1;
	tp_dev.init();

	LCD_Clear(WHITE);
	POINT_COLOR=RED;
	
	LCD_ShowString(30,50,240,24,24,"B1:@     ");
	LCD_ShowString(30,90,240,24,24,"B2:@     ");
	LCD_ShowString(30,130,240,24,24,"B3:@     ");
	
	while(1)
	{
//		ctp_test();	//电容屏测试
		Key_Loop();
		TPad_Loop();
		Display_Loop();
	}
}
