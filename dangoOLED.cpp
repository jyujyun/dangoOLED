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

#include <Wire.h>
#include <avr/pgmspace.h>

#include "dangoOLED.h"
#include "font.h";

dangoOLED::dangoOLED(void){}

void dangoOLED::OLED_init(void)
{
	OLED_clear();
	OLED_ADD = 0x3C;
	syoki();
	
	OLED_send(0);
	OLED_ADD = 0x3D;
	syoki();
	OLED_send(1);
	
}
void dangoOLED::OLED_clear(void)
{
	for (int i = 0;i < 1024;i++)
	{
		OLED_buff[i] = 0x00;
	}
}
void dangoOLED::OLED_drawfill(const char bmp[])
{
	uint16_t j = 0;
	for (int i = 0;i < 1024;i++)
	{
		OLED_buff[i] = pgm_read_byte(&bmp[j++]);
	}
}
void dangoOLED::OLED_draw8(char dx,char dy,const char bmp[])
{
	char j = 0;
	char hy = (dy / 8);
	char tmp_buff = 0x00;
	for (int i = 0;i < 8;i++)
	{
		tmp_buff = OLED_buff[(dx + (hy * 128)) + i];
		OLED_buff[(dx + (hy * 128)) + i] = ((tmp_buff & (0xFF >> (8 - (dy % 8)))) + ((pgm_read_byte(&bmp[j++])) << dy % 8));
	}
	j = 0;
	for (int i = 0;i < 8;i++)
	{
		tmp_buff = OLED_buff[(dx + ((hy + 1) * 128)) + i];
		OLED_buff[(dx + ((hy + 1) * 128)) + i] = ((tmp_buff & (0xFF << ((dy % 8)))) + ((pgm_read_byte(&bmp[j++])) >> (8 - (dy % 8))));
	}
}
void dangoOLED::OLED_pixel(char dx, char dy, char po)
{
	char tmp_buff = 0x00;
	char y1 = dy / 8;
	if (po == 0)
	{
		tmp_buff = OLED_buff[(dx + (y1 * 128))] & ~(0b00000001 << (dy % 8));
	}
	if (po == 1)
	{
		tmp_buff = OLED_buff[(dx + (y1 * 128))] | (0b00000001 << (dy % 8));
	}
	OLED_buff[(dx + (y1 * 128))] = tmp_buff;
}
void dangoOLED::OLED_line(char x1, char y1, char x2, char y2) 
{
  char dx = abs(x2-x1), sx = x1<x2 ? 1 : -1;
  char dy = abs(y2-y1), sy = y1<y2 ? 1 : -1;
  char err = (dx>dy ? dx : -dy)/2, e2;
  for(;;){
     OLED_pixel(x1,y1,1);
     if (x1==x2 && y1==y2) break;
     e2 = err;
     if (e2 >-dx) { err -= dy; x1 += sx; }
     if (e2 < dy) { err += dx;y1 += sy; }
  }
}
void dangoOLED::OLED_box(char x1, char y1, char x2, char y2)
{
	for (char i = x1; i <= x2; i++)
	{
		OLED.OLED_pixel(i, y1,1);
		OLED.OLED_pixel(i, y2, 1);
	}
	for (char i = y1; i <= y2; i++)
	{
		OLED.OLED_pixel(x1, i, 1);
		OLED.OLED_pixel(x2, i, 1);
	}
}
void dangoOLED::OLED_send(char oled)
{
	if (oled == 0)
	{
		OLED_ADD = 0x3C;
	}
	else
	{
		OLED_ADD = 0x3D;
	}

	uint8_t i, j, k;
	int l = 0;
	for(i = 0; i < 8; i++)
	{
		Wire.beginTransmission(OLED_ADD);
		Wire.write(0x80);
			Wire.write(0xB0 | i);
		Wire.write(0x00);
			Wire.write(0x21);
			Wire.write(0);
			Wire.write(127);
		Wire.endTransmission();
	
		for(j = 0; j < 16; j++)
		{
		Wire.beginTransmission(OLED_ADD);
			Wire.write(0b01000000);
			for(k = 0; k < 8; k++)
			{
				Wire.write(OLED_buff[l++]);
			}
		Wire.endTransmission();
		}
	}
}
void dangoOLED::OLED_char(char dx, char dy,char ch,char color = 0) {
	ch -= 32;
	dx *= 8;
	for (char i = 0; i < 6; i++)
	{
		if (color == 0)
		{
			OLED_buff[(dy * 128) + dx + i] = pgm_read_byte(&font8[ch * 6 + i]);
		}
		else
		{
			OLED_buff[(dy * 128) + dx + i] = ~(pgm_read_byte(&font8[ch * 6 + i]));
		}
		OLED_buff[(dy * 128) + dx + 6] = 0xFF * color;
		OLED_buff[(dy * 128) + dx + 7] = 0xFF * color;
	}

}
void dangoOLED::OLED_string(char dx, char dy,char* str,char color = 0) {
	while (*str) {
		OLED_char(dx++,dy,*str++,color);
	}
}

void dangoOLED::syoki(void)
{
	Wire.begin();
	Wire.setClock(400000);
	delay(100);
		
	Wire.beginTransmission(OLED_ADD);
	Wire.write(0x80);
	Wire.write(0xAE);
    Wire.write(0x00);
	Wire.write(0xA8);
	Wire.write(0b00111111);
    Wire.write(0x00);
	Wire.write(0xD3);
	Wire.write(0x00);
    Wire.write(0x80);
	Wire.write(0x40);
    Wire.write(0x80);
	Wire.write(0xA1);
    Wire.write(0x80);
	Wire.write(0xC8);
    Wire.write(0x00);
	Wire.write(0xDA);
	Wire.write(0b00010010);
    Wire.write(0x00);
	Wire.write(0x81);
	Wire.write(255);
    Wire.write(0x80);
	Wire.write(0xA4);
    Wire.write(0x00);
	Wire.write(0xA6);
    Wire.write(0x00);
	Wire.write(0xD5);
	Wire.write(0x80);
    Wire.write(0x00);
	Wire.write(0x20);
	Wire.write(0x10);
  	Wire.endTransmission();

  	Wire.beginTransmission(OLED_ADD);
    Wire.write(0x00);
	Wire.write(0x22);
	Wire.write(0);
	Wire.write(7); 
    Wire.write(0x00);
	Wire.write(0x21);
	Wire.write(0);
	Wire.write(127);
    Wire.write(0x00);
	Wire.write(0x8D);
	Wire.write(0x14);
    Wire.write(0x80);
	Wire.write(0xAF);
	Wire.endTransmission();
}

dangoOLED OLED;
// ----------------------------------------------------------------------------
