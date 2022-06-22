#ifndef __TIMER_H
#define __TIMER_H	 
#include "stm32f10x.h"

extern u16 iLEDCountG;//中断服务函数运行的次数，只运行一次绿灯5s点亮，后面都是熄灭了
extern u16 iErrTime;//密码错误的次数
extern u16 iLEDCountR;//中断服务函数运行的次数，只运行一次红灯5s闪烁，后面都是熄灭了
void Timer_Init(void);
void pwm_init(u16 psc);

#endif
