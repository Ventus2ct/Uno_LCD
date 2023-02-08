// ST7789 library example
// (c) 2019 Pawel A. Hernik

/*
 ST7789 240x240 IPS (without CS pin) connections (only 6 wires required):

 #01 GND -> GND
 #02 VCC -> VCC (3.3V only!)
 #03 SCL -> D13/SCK
 #04 SDA -> D11/MOSI
 #05 RES -> D8 or any digital
 #06 DC  -> D7 or any digital
 #07 BLK -> NC
*/

//#define TFT_CS    6

// #define SPI_MODE0 0x00
// #define SPI_MODE1 0x04
// #define SPI_MODE2 0x08
// #define SPI_MODE3 0x0C

// #define SPI
#define CS_ALWAYS_LOW
#define TFT_DC    7
#define TFT_RST   8 
#define SCR_WD   240
#define SCR_HT   240   // 320 - to allow access to full 240x320 frame buffer
//#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Arduino_ST7789_Fast.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeSans9pt7b.h>

Arduino_ST7789 lcd = Arduino_ST7789(TFT_DC, TFT_RST);
//Arduino_ST7789 lcd = Arduino_ST7789(TFT_DC, TFT_RST, TFT_CS);

int x,y;
unsigned long testText(int rot);

void setup(void) 
{
  Serial.begin(115200);
  lcd.init();
  // tft.setFont(&FreeMonoBoldOblique9pt7b);
  // lcd.setFont(&FreeSans9pt7b);
  Serial.println("Start");
  lcd.clearScreen();
  lcd.init(SCR_WD, SCR_HT);
  lcd.fillScreen(BLACK);
  lcd.setCursor(0, 0);
  lcd.setTextColor(WHITE,BLUE);
  lcd.setTextSize(3);
  lcd.println("EA");
  //lcd.println("Bjoernevik");
  
  Serial.println("Setup end..");
  delay(2000);
  // lcd.drawCircle(0,0,20,20);
  lcd.setTextSize(2);
  lcd.setTextColor(GREY);
  lcd.setCursor(10, 100);
  lcd.println("LRB Tech AS");
  lcd.drawRoundRect( 160, 15, 300, 150, 15, DGREY); //x y width high radius color rectangle A 
 }


void loop()
{
// for(uint8_t rot = 0; rot < 4; rot++) {
//     testText(rot);
//     delay(2000);
//   }
}

// unsigned long testText(int rot)
// {
//   lcd.setRotation(rot);
//   lcd.fillScreen(BLACK);
//   lcd.setCursor(0, 0);
//   lcd.setTextColor(BLUE);
//   lcd.setTextSize(1);
//   lcd.println("Hello Ea BB!");
//   lcd.setTextColor(WHITE);
//   lcd.print("Rotation = ");
//   lcd.println(rot);
//   lcd.setTextColor(YELLOW);
//   lcd.setTextSize(2);
//   lcd.println(1234.56);
//   lcd.setTextColor(RED);
//   lcd.setTextSize(3);
//   lcd.println(0xDEAD, HEX);
//   lcd.println();
//   lcd.setTextColor(GREEN);
//   lcd.setTextSize(4);
//   lcd.println("Hello");
// }