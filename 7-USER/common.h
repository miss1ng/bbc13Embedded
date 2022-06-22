#ifndef __COMMON_H
#define __COMMON_H

#include "led.h"
#include "usart.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "TIMER.h"
#include "24cxx.h"
#include "w25qxx.h"
#include "touch.h"
#include "touch_func.h"
#include "touch_key.h"

extern void *memset(void *s,int c,size_t n);
extern u8 k;

/*全局变量*/
extern int iNum1;//KEY2输入的密码
extern int iNum2;//KEY1输入的密码
extern int iNum3;//KEY0输入的密码
extern u8 iPwd1;
extern u8 iPwd2;
extern u8 iPwd3;

extern u8 iCurrentScreen; //PSD:0 STA:1

#define SCREEN_PSD 0
#define SCREEN_STA 1

#define Buffer_Size 7
	
/***********************************************************************************/

extern u8 RxIdx1;
extern u8 Rec_Buffer[Buffer_Size];

u8 cmpPass(void);

#endif
