#ifndef __TOUCH_FUNC_H
#define __TOUCH_FUNC_H
#include "lcd.h"

void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color);
void gui_fill_circle(u16 x0,u16 y0,u16 r,u16 color);
void lcd_draw_bline(u16 x1, u16 y1, u16 x2, u16 y2,u8 size,u16 color);
//void rtp_test(void)
void ctp_test(void);
void clear_screen(u8 currentScreen);

typedef enum
{
	FAILED = 0,
	PASSED = !FAILED
}TestStatus;
extern volatile TestStatus TransferStatus1;

TestStatus Buffercmp(u8*buffer1,u8*buffer2,u16 BufferLength);

#endif
