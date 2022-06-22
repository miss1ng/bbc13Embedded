#include "touch_key.h"
void TKEY_Display(void)
{
	LCD_DrawRectangle(10, 210, 100, 300);
	LCD_DrawRectangle(110, 210, 200, 300);
	LCD_DrawRectangle(210, 210, 300, 300);
	
	LCD_DrawRectangle(390, 210, 480, 300);
	LCD_DrawRectangle(490, 210, 580, 300);
	LCD_DrawRectangle(590, 210, 680, 300);
	LCD_DrawRectangle(690, 210, 780, 300);
	LCD_DrawRectangle(10, 350, 100, 440);
	LCD_DrawRectangle(110, 350, 200, 440);
	LCD_DrawRectangle(210, 350, 300, 440);
	LCD_DrawRectangle(310, 350, 400, 440);
	LCD_DrawRectangle(410, 350, 500, 440);
	LCD_DrawRectangle(510, 350, 600, 440);
	LCD_DrawRectangle(610, 350, 780, 440);

	
	
	LCD_ShowString(10+35,210+35,48,24,24,"B1");
	LCD_ShowString(10+40+95,210+35,48,24,24,"B2");
	LCD_ShowString(10+40+195,210+35,48,24,24,"B3");
	
	
	LCD_ShowString(10+40+380,210+35,24,24,24,"0");
	LCD_ShowString(10+40+480,210+35,24,24,24,"1");
	LCD_ShowString(10+40+580,210+35,24,24,24,"2");
	LCD_ShowString(10+40+680,210+35,24,24,24,"3");

	LCD_ShowString(10+40,350+35,24,24,24,"4");
	LCD_ShowString(10+40+100,350+35,24,24,24,"5");
	LCD_ShowString(10+40+200,350+35,24,24,24,"6");
	LCD_ShowString(10+40+300,350+35,24,24,24,"7");
	LCD_ShowString(10+40+400,350+35,24,24,24,"8");
	LCD_ShowString(10+40+500,350+35,24,24,24,"9");
	LCD_ShowString(10+40+615,350+35,120,24,24,"ENTER");

}
void TKEY_SetSta(u8 keyx,u8 sta)
{		  
	if(keyx>14)return;
	if(sta){
		switch(keyx){
			case TKB1_PRES:{
 				LCD_Fill(10, 210, 100, 300,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+35,210+35,48,24,24,"B1");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKB2_PRES:{
 				LCD_Fill(110, 210, 200, 300,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+95,210+35,48,24,24,"B2");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKB3_PRES:{
 				LCD_Fill(210, 210, 300, 300,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+195,210+35,48,24,24,"B3");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY0_PRES:{
 				LCD_Fill(390, 210, 480, 300,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+380,210+35,24,24,24,"0");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY1_PRES:{
 				LCD_Fill(490, 210, 580, 300,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+480,210+35,24,24,24,"1");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY2_PRES:{
 				LCD_Fill(590, 210, 680, 300,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+580,210+35,24,24,24,"2");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY3_PRES:{
 				LCD_Fill(690, 210, 780, 300,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+680,210+35,24,24,24,"3");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY4_PRES:{
 				LCD_Fill(10, 350, 100, 440,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40,350+35,24,24,24,"4");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY5_PRES:{
 				LCD_Fill(110, 350, 200, 440,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+100,350+35,24,24,24,"5");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY6_PRES:{
 				LCD_Fill(210, 350, 300, 440,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+200,350+35,24,24,24,"6");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY7_PRES:{
 				LCD_Fill(310, 350, 400, 440,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+300,350+35,24,24,24,"7");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY8_PRES:{
 				LCD_Fill(410, 350, 500, 440,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+400,350+35,24,24,24,"8");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY9_PRES:{
 				LCD_Fill(510, 350, 600, 440,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+500,350+35,24,24,24,"9");
 				BACK_COLOR=WHITE;
				break;
			}
			case TWKUP_PRES:{
 				LCD_Fill(610, 350, 780, 440,RED);
 				BACK_COLOR=RED;
 				LCD_ShowString(10+40+615,350+35,120,24,24,"ENTER");
 				BACK_COLOR=WHITE;
				break;
			}				
		}
	}
	else {
		switch(keyx){
		case TKB1_PRES:{
 				LCD_Fill(10, 210, 100, 300,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+35,210+35,48,24,24,"B1");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKB2_PRES:{
 				LCD_Fill(110, 210, 200, 300,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+95,210+35,48,24,24,"B2");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKB3_PRES:{
 				LCD_Fill(210, 210, 300, 300,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+195,210+35,48,24,24,"B3");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY0_PRES:{
 				LCD_Fill(390, 210, 480, 300,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+380,210+35,24,24,24,"0");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY1_PRES:{
 				LCD_Fill(490, 210, 580, 300,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+480,210+35,24,24,24,"1");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY2_PRES:{
 				LCD_Fill(590, 210, 680, 300,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+580,210+35,24,24,24,"2");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY3_PRES:{
 				LCD_Fill(690, 210, 780, 300,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+680,210+35,24,24,24,"3");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY4_PRES:{
 				LCD_Fill(10, 350, 100, 440,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40,350+35,24,24,24,"4");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY5_PRES:{
 				LCD_Fill(110, 350, 200, 440,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+100,350+35,24,24,24,"5");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY6_PRES:{
 				LCD_Fill(210, 350, 300, 440,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+200,350+35,24,24,24,"6");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY7_PRES:{
 				LCD_Fill(310, 350, 400, 440,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+300,350+35,24,24,24,"7");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY8_PRES:{
 				LCD_Fill(410, 350, 500, 440,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+400,350+35,24,24,24,"8");
 				BACK_COLOR=WHITE;
				break;
			}
			case TKEY9_PRES:{
 				LCD_Fill(510, 350, 600, 440,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+500,350+35,24,24,24,"9");
 				BACK_COLOR=WHITE;
				break;
			}
			case TWKUP_PRES:{
 				LCD_Fill(610, 350, 780, 440,WHITE);
 				BACK_COLOR=WHITE;
 				LCD_ShowString(10+40+615,350+35,120,24,24,"ENTER");
 				BACK_COLOR=WHITE;
				break;
			}
		}
	}
}
u8 TKEY_Scan(void)
{
	static u16 key_x=0;
	u16 key=0;
	tp_dev.scan(0);
	if(tp_dev.sta&TP_PRES_DOWN)
	{	
			if(TKB1_AREA)
					key=TKB1_PRES;
			else if(TKB2_AREA)
					key=TKB2_PRES;
			else if(TKB3_AREA)
					key=TKB3_PRES;
			else if(TKEY0_AREA)
					key=TKEY0_PRES;
			else if(TKEY1_AREA)
					key=TKEY1_PRES;
			else if(TKEY2_AREA)
					key=TKEY2_PRES;
			else if(TKEY3_AREA)
					key=TKEY3_PRES;
			else if(TKEY4_AREA)
					key=TKEY4_PRES;
			else if(TKEY5_AREA)
					key=TKEY5_PRES;	
			else if(TKEY6_AREA)
					key=TKEY6_PRES;
			else if(TKEY7_AREA)
					key=TKEY7_PRES;
			else if(TKEY8_AREA)
					key=TKEY8_PRES;
			else if(TKEY9_AREA)
					key=TKEY9_PRES;
			else if(TWKUP_AREA)
					key=TWKUP_PRES;

			if(key) //key!=0
			{	   
				if(key_x==key)key=0;
				else
				{
					TKEY_SetSta(key_x,0);
					key_x=key;
					TKEY_SetSta(key_x,1);
				}
			}
 
	}
	else if(key_x)
	{
		TKEY_SetSta(key_x,0);
		key_x=0;
	} 
	return key; 
}
void TKEYB_Func(u8 bit)
{
	if (bit==iCurrentPassBit) return;
	
	iLastPassBit=iCurrentPassBit;
	iCurrentPassBit=bit;
}
void TKNum_Func(u8 num)
{
	if (iCurrentPassBit==1) iNum1=num;
	else if (iCurrentPassBit==2) iNum2=num;
	else if (iCurrentPassBit==3) iNum3=num;
}
