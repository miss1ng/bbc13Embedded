#ifndef __TOUCHKEY_H__
#define __TOUCHKEY_H__	 
#include "common.h"

#define TKB1_AREA (tp_dev.x[0]>10)&&(tp_dev.x[0]<100)&&(tp_dev.y[0]>210)&&(tp_dev.y[0]<300)
#define TKB2_AREA (tp_dev.x[0]>110)&&(tp_dev.x[0]<200)&&(tp_dev.y[0]>210)&&(tp_dev.y[0]<300)
#define TKB3_AREA (tp_dev.x[0]>210)&&(tp_dev.x[0]<300)&&(tp_dev.y[0]>210)&&(tp_dev.y[0]<300)
#define TKEY0_AREA (tp_dev.x[0]>390)&&(tp_dev.y[0]>210)&&(tp_dev.x[0]<480)&&(tp_dev.y[0]<300)
#define TKEY1_AREA (tp_dev.x[0]>490)&&(tp_dev.y[0]>210)&&(tp_dev.x[0]<580)&&(tp_dev.y[0]<300)
#define TKEY2_AREA (tp_dev.x[0]>590)&&(tp_dev.y[0]>210)&&(tp_dev.x[0]<680)&&(tp_dev.y[0]<300)
#define TKEY3_AREA (tp_dev.x[0]>690)&&(tp_dev.y[0]>210)&&(tp_dev.x[0]<780)&&(tp_dev.y[0]<300)
#define TKEY4_AREA (tp_dev.x[0]>10)&&(tp_dev.y[0]>350)&&(tp_dev.x[0]<100)&&(tp_dev.y[0]<440)
#define TKEY5_AREA (tp_dev.x[0]>110)&&(tp_dev.y[0]>350)&&(tp_dev.x[0]<200)&&(tp_dev.y[0]<440)
#define TKEY6_AREA (tp_dev.x[0]>210)&&(tp_dev.y[0]>350)&&(tp_dev.x[0]<300)&&(tp_dev.y[0]<440)
#define TKEY7_AREA (tp_dev.x[0]>310)&&(tp_dev.y[0]>350)&&(tp_dev.x[0]<400)&&(tp_dev.y[0]<440)
#define TKEY8_AREA (tp_dev.x[0]>410)&&(tp_dev.y[0]>350)&&(tp_dev.x[0]<500)&&(tp_dev.y[0]<440)
#define TKEY9_AREA (tp_dev.x[0]>510)&&(tp_dev.y[0]>350)&&(tp_dev.x[0]<600)&&(tp_dev.y[0]<440)
#define TWKUP_AREA (tp_dev.x[0]>610)&&(tp_dev.y[0]>350)&&(tp_dev.x[0]<780)&&(tp_dev.y[0]<440)

#define TKB1_PRES		11	//KEY_B1按下
#define TKB2_PRES		12	//KEY_B2按下
#define TKB3_PRES		13	//KEY_B3按下
#define TKEY0_PRES 	1	//KEY0按下
#define TKEY1_PRES	2	//KEY1按下
#define TKEY2_PRES	3	//KEY2按下
#define TKEY3_PRES	4	//KEY3按下
#define TKEY4_PRES	5	//KEY4按下
#define TKEY5_PRES	6	//KEY5按下
#define TKEY6_PRES	7	//KEY6按下
#define TKEY7_PRES	8	//KEY7按下
#define TKEY8_PRES	9	//KEY8按下
#define TKEY9_PRES	10	//KEY9按下
#define TWKUP_PRES  14	//KEY_UP按下(即WK_UP/KEY_UP)

void TKEY_Display(void);
void TKEY_SetSta(u8 keyx,u8 sta);
u8 TKEY_Scan(void);

extern u8 iCurrentPassBit,iLastPassBit;

void TKEYB_Func(u8 bit);
void TKNum_Func(u8 num);

#endif
