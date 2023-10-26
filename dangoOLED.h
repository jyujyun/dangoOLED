/*
dangoOLEDライブラリ

3shokudang(jyujyun)
2023/10/25

参考にしたもの:
mgo-tec電子工作 https://www.mgo-tec.com/
SSD1306xledライブラリ https://bitbucket.org/tinusaur/ssd1306xled
Adafruit OLED ライブラリ https://github.com/adafruit/Adafruit_SSD1306
ありがとうございます。 Thank you!
*/


#include <Arduino.h>

#include <util/delay.h>

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
		void syoki(void);
};
extern dangoOLED OLED;



#endif
