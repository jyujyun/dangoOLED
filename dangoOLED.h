/*
dangoOLEDライブラリ

3shokudang(jyujyun)
2023/10/25

参考にしたもの:
mgo-tec電子工作 https://www.mgo-tec.com/
SSD1306xledライブラリ https://bitbucket.org/tinusaur/ssd1306xled
Adafruit OLED ライブラリ https://github.com/adafruit/Adafruit_SSD1306

使用した素材:
ひらがなフォント https://littlelimit.net/misaki.htm
ありがとうございます。 Thank you!

*/


#include <Arduino.h>



#ifndef DANGOOLED_H
#define DANGOOLED_H


class dangoOLED
{
	public:
		dangoOLED(void);
		char OLED_ADD = 0x78;
		char OLED_buff [1024];
		void OLED_init(void);
		void OLED_clear(void);
		void OLED_drawfill(const char bmp[]);
		void OLED_draw8(char dx,char dy,const char bmp[]);
		void OLED_send(char oled);
		void OLED_pixel(char dx, char dy, char po);
		void OLED_line(char x1, char y1, char x2, char y2);
		#ifdef __AVR_ATmega328P__
		void OLED_char(char dx, char dy, uint16_t ch, char color = 0);
		void OLED_num(char dx,char dy,int num,char color = 0);
		void OLED_string(char dx, char dy,char* str,char color = 0);
		#endif
		void OLED_box(char x1, char y1, char x2, char y2);
		void OLED_fillbox(int x1, char y1, int x2, char y2,char color);
		void OLED_drawbyte(int dx, char dy, int dw, char dh, const char bmp[]);
		//void tess(void);
		void syoki(void);
};
extern dangoOLED OLED;



#endif
