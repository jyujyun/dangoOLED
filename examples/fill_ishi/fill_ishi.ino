#include <dangoOLED.h>
#include <Wire.h>
const unsigned char ishi[] PROGMEM = {0x21,0x19,0x7F,0x49,0x49,0x49,0x79,0x0,};

char x = 5;
char y = 5;
char count = 0;
void setup() {
  // put your setup code here, to run once:
  _delay_ms(40);
  OLED.OLED_init();
  OLED.OLED_clear();

  //flip OLED
  Wire.beginTransmission(0x3D);
  Wire.write(0x80);
  Wire.write(0xA0);
  Wire.write(0x80);
  Wire.write(0xC0);
  Wire.endTransmission();
}

void loop() {
  // put your main code here, to run repeatedly:
  //SSD1306.

  OLED.OLED_draw8(x, y, ishi);
  x += 1;
  y += 1;
  if (x > 119)
  {
    x = 0;
    count += 1;
  }
  if (y > 55){
    y = 0;
    count += 1;
  }
  if (count == 24)
  {
    count = 0;
    OLED.OLED_clear();
  }
  OLED.OLED_send(0);

  OLED.OLED_send(1);

  delay(40);

}
