#ifndef __TIMER_H
#define __TIMER_H	 
#include "stm32f10x.h"

extern u16 iLEDCountG;//�жϷ��������еĴ�����ֻ����һ���̵�5s���������涼��Ϩ����
extern u16 iErrTime;//�������Ĵ���
extern u16 iLEDCountR;//�жϷ��������еĴ�����ֻ����һ�κ��5s��˸�����涼��Ϩ����
void Timer_Init(void);
void pwm_init(u16 psc);

#endif
