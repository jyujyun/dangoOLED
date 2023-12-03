dangoOLED library 

3shokudango(jyujyun)

2023/10/26

2023/10/28

Github Page:https://github.com/jyujyun/dangoOLED
HomePage :https://3shokudango.web.fc2.com
Mail:jyujyun@aol.com

[EN]
===============================
This library can control SSD1306 OLED i2C.
Both i2C addresses 0x7A and 0x78 (or 0x3C and 0x3D) commonly used in OLED can be used to control two screens.
Please note that the buffer consumes 1Kbyte of RAM.

-Compatible boards
--Fully
Atmega328PU boards(Arduino Uno R1-R3,Arduino Pro Micro etc.)
--Some functions cannot be used
Arduino Mega
ESP32 Dev Module
Arduino R4
Atmega32U boards(Arduino Leonard,Arduino Pro Micro etc.)

-functions
[!]Please include 'dangoOLED.h' first.
[!]Bitmap data must be save in PROGMEM.

*x:0~127 y:0~63
*bx:0~15 by:0~7
OLED.OLED_init() - Init SSD1306. Please run first.
OLED.OLED_clear() - Clear library buffer.
[!]This function is not clear SSD1306 screen. If you want to clear the device screen, run the send function after this function.
OLED.OLED_send(num) - Send the buffer data to SSD1306.
num=0:Send to 0x78 or 0x3C
num=1:Send to 0x7A or 0x3D
OLED.OLED_drawfill(128x64bmp) - Draw 128x64 bitmap to library buffer.
OLED.OLED_draw8(x,y,8x8bmp) - Draw 8x8 bitmap to library buffer.
OLED.OLED_setpixel(x,y,light) - Draw 1x1 dot to library buffer.
OLED.OLED_drawfill(128x64bmp) - Draw 128x64 bitmap.
OLED.OLED_draw8(x,y,8x8bmp) - Draw 8x8 bitmap.
OLED.OLED_setpixel(x,y,light) - Draw 1x1 dot.
light=1:on
light=0:off
OLED.OLED_line(x1,y1,x2,y2) - Draw a line to library buffer.
OLED.OLED_line(x1,y1,x2,y2) - Draw a line.
OLED.OLED_box(x1,y1,x2,y2) - Draw a wire-box.
OLED.OLED_fillbox(x1,y1,x2,y2,color) - Draw a box.
color=0:black
color=1:white
color=2:gray
OLED.OLED_char(bx,by,char) - Draw a char.
OLED.OLED_string(bx,by,String) - Draw a string.
OLED.OLED_num(bx,by,variable) - Draw a number.
OLED.OLED_drawbyte(bx,by,width,height,bitmap) - Draw a bitmap.
-ToDo list
OK draw char or string
-history
2023/10/26 1.0.0
2023/10/28 1.1.0
Add draw box function.
Add text function.
2023/11/23 1.2.0
Add more function.
[JP]
===============================
このライブラリはi2CのSSD1306 OLEDを制御できます。
0x7A版と0x78版(Arduino内だと0x3Cと0x3D)の両方に対応しており、どちらとも並列接続すれば2つの画面を制御できます。
RAMを1Kbyte消費するので注意してください。

-対応ボード
--全機能が使えるボード
Atmega328PUを乗せたボード(Arduino UNO R1-R3,Arduino Pro Miniなど)
--一部機能は使えないボード
Arduino Mega
ESP32 Dev Module
Arduino UNO R4
Atmega32Uを乗せたボード(Arduino Leonard,Arduino Pro Microなど)

-関数リスト
!注意!
最初にdangoOLED.hをインクルードしてください。
ビットマップデータはPROGMEMに保存してください。

bx,byがある関数は座標を1バイト(8ドット)単位で指定する必要があります。
引数にx,yがある関数は座標を1ビット(1ドット)単位で指定できます。
OLED.OLED_init() - SSD1306を初期化する。最初に実行してください。
OLED.OLED_clear() - バッファーのデータを消す。
!注意!この関数はSSD1306の画面を消するわけではありません。消したい場合はこの後にOLED.OLED_send関数を実行してください。
OLED.OLED_send(num) - ライブラリ内のバッファーをSSD1306に送る。
num=0:アドレス0x78(0x3C)に送る
num=1:アドレス0x7A(0x3D)に送る
OLED.OLED_drawfill(128x64bmp) - 128x64のビットマップをバッファーに書き込む。
OLED.OLED_draw8(x,y,8x8bmp) - 8x8のビットマップをx,yの位置に書き込む。
OLED.OLED_setpixel(x,y,light) - x,yの位置に1ドットバッファーに書き込む。
OLED.OLED_drawfill(128x64bmp) - 128x64のビットマップを描く。
OLED.OLED_draw8(x,y,8x8bmp) - 8x8のビットマップをx,yの位置に描く。
OLED.OLED_setpixel(x,y,light) - x,yの位置に1ドット描く。
light=1:オン
light=0:オフ
OLED.OLED_line(x1,y1,x2,y2) - 線をバッファーに書き込む。
OLED.OLED_line(x1,y1,x2,y2) - 線を描く。
OLED.OLED_box(x1,y1,x2,y2) - 四角形を描く。中は塗りつぶされない。
OLED.OLED_fillbox(x1,y1,x2,y2,color) - 四角形を描く。中はcolorの色で塗りつぶされる。
color=0:くろ
color=1:しろ
color=2:しろとくろの市松模様
OLED.OLED_char(bx,by,char) - 1文字描く。ひらがなも対応。
OLED.OLED_string(bx,by,String) - 文字列を描く。こっちはひらがな非対応。
OLED.OLED_num(bx,by,variable) - 数値を描く。
OLED.OLED_drawbyte(bx,by,width,height,bitmap) - ビットマップを書く。
-追加予定の機能
文字列の描写

-更新履歴
2023/10/26 1.0.0
2023/10/28 1.1.0
四角を描く機能と文字を書く機能を追加
四角を描く機能と文字を書く機能を追加
2023/11/23 1.2.0
もっと機能を追加
