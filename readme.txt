dangoOLED library 

3shokudango(jyujyun) 2023/10/26

Mail:jyujyun@aol.com

[EN]
===============================
This library can control SSD1306 OLED i2C.
Both i2C addresses 0x7A and 0x78 (or 0x3C and 0x3D) commonly used in OLED can be used to control two screens.
Please note that the buffer consumes 1Kbyte of RAM.

-functions
[!]Please include 'dangoOLED.h' first.
[!]Bitmap data must be save in PROGMEM.

OLED.OLED_init() - Init SSD1306. Please run first.
OLED.OLED_clear() - Clear library buffer.
[!]This function is not clear SSD1306 screen. If you want to clear the device screen, run the send function after this function.
OLED.OLED_send(num) - Send the buffer data to SSD1306.
num=0:Send to 0x78 or 0x3C
num=1:Send to 0x7A or 0x3D
OLED.OLED_drawfill(128x64bmp) - Draw 128x64 bitmap to library buffer.
OLED.OLED_draw8(x,y,8x8bmp) - Draw 8x8 bitmap to library buffer.
OLED.OLED_setpixel(x,y,light) - Draw 1x1 dot to library buffer.
light=1:on
light=0:off
OLED.OLED_line(x1,y1,x2,y2) - Draw a line to library buffer.
-ToDo list
draw char or string
-history
2023/10/26 1.0.0
[JP]
===============================
このライブラリはi2CのSSD1306 OLEDを制御できます。
0x7A版と0x78版(Arduino内だと0x3Cと0x3D)の両方に対応しており、どちらとも並列接続すれば2つの画面を制御できます。
RAMを1Kbyte消費するので注意してください。
-関数リスト
!注意!
最初にdangoOLED.hをインクルードしてください。
ビットマップデータはPROGMEMに保存してください。

OLED.OLED_init() - SSD1306を初期化する。最初に実行してください。
OLED.OLED_clear() - バッファーのデータを消す。
!注意!この関数はSSD1306の画面を消するわけではありません。消したい場合はこの後にOLED.OLED_send関数を実行してください。
OLED.OLED_send(num) - ライブラリ内のバッファーをSSD1306に送る。
num=0:アドレス0x78(0x3C)に送る
num=1:アドレス0x7A(0x3D)に送る
OLED.OLED_drawfill(128x64bmp) - 128x64のビットマップをバッファーに書き込む。
OLED.OLED_draw8(x,y,8x8bmp) - 8x8のビットマップをx,yの位置に書き込む。
OLED.OLED_setpixel(x,y,light) - x,yの位置に1ドットバッファーに書き込む。
light=1:オン
light=0:オフ
OLED.OLED_line(x1,y1,x2,y2) - 線をバッファーに書き込む。
-追加予定の機能
文字列の描写
-更新履歴
2023/10/26 1.0.0