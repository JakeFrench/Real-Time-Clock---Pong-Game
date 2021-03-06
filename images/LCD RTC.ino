
#include <stdio.h>
#include <stdlib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <pgmspace.h>

#define N 16
#define M 5
// http://www.carlos-rodrigues.com/projects/pcd8544/
// pin 7 - Serial clock out 	(SCLK)
// pin 6 - Serial data out	(DIN)
// pin 5 - Data/Command select 	(D/C)
// pin 3 - LCD chip select	(CS)
// pin 4 - LCD reset	 	(RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
//Adafruit_PCD8544 display   = Adafruit_PCD8544(2, 3, 4, 13, 12);
unsigned char wallBasic[]  PROGMEM = {0x1f, 0x11, 0x11, 0x11, 0x1f};
unsigned char wallBonus[]  PROGMEM = {0x1f, 0x15, 0x1f, 0x15, 0x1f};
unsigned char wallBounce[] PROGMEM = {0x1f, 0x1f, 0x1f, 0x1f, 0x1f};


unsigned char MaddisonTitle[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0xF8, 0xC0, 0x00, 0x00, 0x38, 0x38,
0x30, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x07, 0x03, 0x07, 0xFF, 0xFF, 0x03, 0x03, 0xFF,
0xFF, 0xFC, 0x00, 0xCC, 0xEF, 0xEF, 0x63, 0x73, 0xFF, 0xFF, 0xFC, 0x00, 0xFC, 0xFE, 0xFF, 0x03,
0x03, 0x03, 0xFF, 0xFF, 0x70, 0x20, 0xFE, 0xDF, 0x07, 0x03, 0x03, 0x07, 0xFF, 0xFF, 0x00, 0x00,
0xFF, 0xFF, 0x00, 0x00, 0x00, 0x9F, 0xBF, 0x33, 0x73, 0xF7, 0xEF, 0xC4, 0x00, 0xFE, 0xFF, 0x87,
0x03, 0x03, 0x87, 0xFF, 0xFE, 0x70, 0xFF, 0xFF, 0xFF, 0x07, 0x03, 0x03, 0xFF, 0xFF, 0xF8, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00,
0x00, 0x03, 0x07, 0x07, 0x00, 0x03, 0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x07, 0x04, 0x01, 0x03,
0x07, 0x06, 0x06, 0x07, 0x07, 0x07, 0x00, 0x00, 0x01, 0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x07,
0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x03, 0x00, 0x01,
0x03, 0x07, 0x06, 0x06, 0x07, 0x07, 0x01, 0x00, 0x03, 0x07, 0x07, 0x00, 0x00, 0x00, 0x07, 0x07,
0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xE0, 0x40, 0x00, 0xC0, 0xC0,
0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0x00, 0x00,
0xFE, 0xFF, 0xFE, 0xE0, 0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x0E, 0xEE, 0xCE, 0x04, 0x00, 0x80,
0xC0, 0xE0, 0xE0, 0x60, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x7F, 0xFF, 0xE3, 0x80, 0x80, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xF3,
0xFF, 0xDC, 0x8C, 0x8C, 0xDF, 0xFF, 0xFF, 0x80, 0x00, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0xFF, 0xFF,
0x7F, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0xFF, 0xFF, 0x00,
0x00, 0x7F, 0xFF, 0xE1, 0x80, 0x80, 0xC0, 0xF3, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0E, 0x1F, 0x3F, 0x3B, 0x39, 0x3F, 0x1F, 0x0F, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x1F, 0x1F, 0x01, 0x01, 0x01,
0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, };



unsigned char MaddisonOne[] PROGMEM = {  
0xF8, 0xF8, 0xF8, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0,
0xF8, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFC, 0xF8, 0xF0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0F,
0x0F, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0xF8,
0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF8,
0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07,
0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC,
0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x7F, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xF0, 0xF0, 0xF8,
0xF8, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0x00,
0x01, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x0F,
0x0F, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0xC0, 0xC0, 0xE0, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0xC0, 0x00, 0x00, 0x01,
0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  };




unsigned char MaddisonTwo[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0,
0xF8, 0x78, 0x1C, 0x0C, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0C, 0x1C, 0xF8, 0xF0, 0xF0, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0xF8, 0x3C,
0x1C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x1C, 0x3C, 0xF8, 0xF0, 0xE0, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0x78, 0x1C, 0x1C, 0x0F,
0x0F, 0x0F, 0x0E, 0x0E, 0x1E, 0x1C, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1E,
0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
0x0F, 0x1F, 0x1E, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1C, 0x1F, 0x0F, 0x07,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x1F,
0x1C, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1C, 0x1F, 0x0F, 0x03, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xE0, 0x60, 0x70, 0x30, 0x30, 0x30, 0x30, 0x70, 0x60, 0xE0,
0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0xC0, 0xE0, 0xE0, 0x60, 0x70, 0x30, 0x30, 0x30, 0x30, 0x60, 0xE0, 0xE0, 0xC0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
0xC0, 0xE0, 0x60, 0x70, 0x30, 0x30, 0x70, 0x70, 0xF0, 0xE0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0xC0, 0xC0, 0xF0, 0x7E, 0x7F, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x03, 0x1F, 0x7F, 0x7E, 0xF0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0,
0xE0, 0xF8, 0x7F, 0x3F, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x07, 0x3F, 0x7F, 0xFC, 0xE0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xF0, 0x7E,
0x7F, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFC, 0xFE, 0x1F, 0x07, 0x03, 0x03, 0x01,
0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x1F, 0xFE, 0xFC, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0xFC, 0xFE, 0x0F, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01,
0x01, 0x03, 0x03, 0x0F, 0x7E, 0xFE, 0xFC, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xF0, 0xFC, 0xFE, 0x1F, 0x07, 0x03, 0x03, 0x01, 0x01,  };



unsigned char MaddisonThree[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x7C, 0xF8, 0xF8,
0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0xF8, 0x7C, 0x3C, 0x0C, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x3C, 0x7C,
0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0xF8, 0x7C, 0x3C, 0x08, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80,
0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
0x0F, 0x0F, 0x1F, 0x1E, 0x3C, 0x3C, 0x38, 0x38, 0x3C, 0x3C, 0x1E, 0x1F, 0x1F, 0x0F, 0x07, 0x03,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x03, 0x07, 0x0F, 0x1F, 0x1E, 0x3C, 0x3C, 0x38, 0x38, 0x3C, 0x3C, 0x1E, 0x1F, 0x1F, 0x0F,
0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x70, 0xF8, 0xF0, 0xF0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xE0, 0xF0,
0xF8, 0x78, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x30, 0x78, 0xF8, 0xF0, 0xE0, 0xE0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0,
0xE0, 0xF0, 0xF0, 0x70, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x07, 0x03,
0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x1F, 0x3E, 0x7C, 0xF8, 0xF8, 0xF0, 0xF0, 0xF8, 0xF8,
0xFC, 0x7C, 0x3F, 0x1F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x07, 0x0F, 0x1F, 0x3E, 0x7C, 0xF8, 0xF8, 0xF0, 0xF0,
0xF8, 0xF8, 0x7C, 0x3E, 0x3F, 0x1F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };


unsigned char BonusBmpOne[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x7C, 0xFC, 0xFE,
0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x98, 0x98, 0xBC,
0xBF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE3, 0xE0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xF8,
0xF8, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0xC0, 0xC0,
0xE0, 0xE0, 0xE0, 0xE0, 0xF0, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0xC8, 0x71, 0x33, 0x03, 0x00, 0x04, 0x06, 0x04, 0x01,
0x01, 0x00, 0x3B, 0xE3, 0xE0, 0xE0, 0xE0, 0xE1, 0x01, 0x03, 0x03, 0x07, 0x47, 0x6F, 0x6F, 0xDF,
0x1F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x07, 0x03, 0x01,
0x1C, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x0F, 0x8F, 0x87, 0xC7, 0xC1, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xF0,
0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x7C, 0xF0, 0x60, 0x40, 0x80, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00,
0x08, 0x19, 0x08, 0x00, 0xF0, 0x58, 0x5C, 0x0F, 0x28, 0x18, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
0xC0, 0xC0, 0xC0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC, 0xFE, 0xFE, 0xF8,
0xE0, 0x00, 0x00, 0x0F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0x1F, 0x0F, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10,
0x30, 0x70, 0x70, 0x58, 0x1C, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x03, 0x3F, 0x3F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x7F, 0xFF, 0xFF, 0xF3,
0xF3, 0xF3, 0xF3, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x70, 0x78, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x7E, 0x7F, 0x7F, 0x3F, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00,
0x03, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   };


unsigned char BonusBmpTwo[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xE0,
0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC,
0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0,
0xE0, 0xF0, 0x70, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x10, 0x10, 0x30, 0x30, 0x30, 0x70, 0x70, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xD0, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF,
0x1F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x63, 0x00, 0x01, 0x01, 0x21, 0x31,
0x21, 0x01, 0x03, 0x03, 0x9F, 0xEF, 0xEF, 0x1F, 0x03, 0x01, 0x01, 0xA0, 0xF0, 0xF0, 0x20, 0x01,
0x01, 0x03, 0x3F, 0xFF, 0x7F, 0xE7, 0x01, 0x03, 0x01, 0x01, 0x03, 0x0F, 0x3F, 0x1F, 0x03, 0x03,
0x03, 0x43, 0xFF, 0xFF, 0x01, 0x01, 0x03, 0x01, 0xC1, 0xFF, 0xFB, 0x01, 0x01, 0x01, 0x03, 0xFF,
0xFF, 0x1F, 0x03, 0x01, 0x01, 0x01, 0x11, 0x11, 0x01, 0x21, 0x7B, 0xFF, 0xFF, 0x01, 0x01, 0x01,
0x01, 0xCF, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0x30, 0x3F, 0x40, 0x40, 0xC0,
0xC0, 0xC4, 0xC4, 0xC0, 0xC0, 0x40, 0x40, 0x61, 0x7F, 0x7C, 0xE0, 0xE0, 0xC0, 0xC0, 0xC3, 0xC3,
0xC0, 0xC0, 0xE0, 0xF0, 0xF8, 0xFF, 0xFF, 0xF0, 0x80, 0xC0, 0xC0, 0xC2, 0xFC, 0xE0, 0xC0, 0xC0,
0x80, 0x80, 0xC0, 0xFF, 0xFF, 0xFF, 0xF8, 0xE0, 0xC0, 0xC0, 0xC0, 0xC3, 0xC1, 0xC0, 0xC0, 0xE0,
0xF0, 0xFF, 0xFF, 0xEF, 0xE2, 0xC2, 0xC6, 0xC6, 0xC2, 0x60, 0x60, 0x60, 0x70, 0x7F, 0x7F, 0x46,
0x82, 0x82, 0xC2, 0x6E, 0x30, 0x30, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF8, 0xFE, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFE, 0xF8, 0xF0, 0xE0,
0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F,
0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F,
0xFF, 0xFF, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
0x03, 0x03, 0x07, 0x07, 0x06, 0x0C, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, };


unsigned char nextLevel[] PROGMEM = {
0xFF, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
0xF9, 0x7F, 0x3F, 0x1F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x83, 0x81, 0x41, 0x41, 0x41, 0x00, 0x00,
0x20, 0x20, 0x20, 0x00, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x21, 0x01,
0x21, 0x43, 0x47, 0xFF, 0xFE, 0xFC, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0xF8, 0xFC, 0xFF,
0xFF, 0x0C, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0xE0, 0xE0, 0xC0, 0xC0, 0xC7, 0xCC, 0xC8, 0xC8, 0xE7, 0x73, 0x30, 0x10, 0x10,
0x08, 0x07, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0C, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x05, 0x09, 0x11, 0x03, 0x03, 0x07,
0x07, 0x03, 0x03, 0x07, 0x0C, 0x18, 0x70, 0xC7, 0xCC, 0x88, 0x88, 0x84, 0x80, 0x80, 0x80, 0x00,
0x00, 0x00, 0x80, 0x80, 0xFF, 0xFF, 0x7F, 0x7F, 0x0F, 0x01, 0x1F, 0xF1, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xC1, 0x39, 0x3F, 0x3F,
0x3F, 0x3F, 0x7F, 0xF3, 0xC3, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x3F,
0xF8, 0xE0, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x04, 0x7C, 0x3A,
0x3E, 0x1C, 0x1F, 0x1C, 0x18, 0x3E, 0x30, 0x00, 0x00, 0xC0, 0x40, 0x80, 0xC0, 0x40, 0x00, 0x80,
0xC0, 0x60, 0x80, 0xC0, 0x00, 0x00, 0x34, 0x38, 0x18, 0x1E, 0x18, 0x3E, 0x78, 0x7C, 0x40, 0x00,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x38, 0x0F, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x07, 0x1B, 0x20, 0x40, 0xC0, 0x80, 0x80, 0xF0, 0x8E, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFD, 0xFC, 0xFC, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x40, 0x00, 0x00, 0x00, 0x10, 0xA0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x03, 0x01, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02,
0x06, 0x04, 0x08, 0x08, 0x08, 0x10, 0x10, 0x30, 0x20, 0xE0, 0x20, 0x60, 0xE0, 0xE1, 0xC7, 0xCF,
0xCF, 0xDF, 0xDF, 0xCF, 0xCF, 0xC7, 0xC3, 0xC0, 0xC0, 0xE0, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10,
0x10, 0x08, 0x08, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };


unsigned char gameOverOne[] PROGMEM = {
0xFF, 0xFF, 0x07, 0x03, 0x01, 0xC1, 0xE1, 0x71, 0x11, 0x31, 0x31, 0x31, 0x31, 0x61, 0xE1, 0xC1,
0x03, 0x07, 0x0F, 0x1F, 0x3F, 0xFF, 0x07, 0x03, 0x01, 0xC1, 0x61, 0x31, 0x11, 0x11, 0x11, 0x11,
0x31, 0x61, 0xC1, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0xFF, 0x01, 0x01, 0xF1, 0xF1, 0xE1, 0xC1,
0x81, 0x83, 0x83, 0xC1, 0xE1, 0xE1, 0xF1, 0x01, 0x01, 0x01, 0x03, 0x07, 0x0F, 0xFF, 0x01, 0x01,
0xF1, 0xF1, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x01, 0x01, 0x03, 0x07,
0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xC0, 0x80, 0x80, 0x8C, 0x8C, 0x8C, 0xCC,
0x7C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x1C, 0x08, 0x0C, 0x0C,
0x0C, 0x0C, 0x0C, 0x0C, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0xFF,
0x00, 0x00, 0x01, 0x03, 0x03, 0x01, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x00, 0xFF, 0xFF, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x80, 0x80, 0x00, 0x00, 0x00,
0x1C, 0x38, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1,
0xC1, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xF0, 0xFF, 0xF0, 0xE0, 0xC0, 0xC1, 0xC0, 0xC0,
0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xC0, 0xC1, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xFF, 0xF0, 0xE0,
0xC0, 0xC1, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xF0, 0xE0, 0xC0, 0xC1, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
0xE0, 0xFF, 0xF0, 0xE0, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xC0,
0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x07, 0x03, 0x83, 0xC3, 0xE3, 0x63, 0x63,
0x63, 0x63, 0x63, 0xC3, 0xC3, 0x83, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0x03, 0x03, 0x03, 0xE3,
0x03, 0x03, 0x03, 0x07, 0x0F, 0x03, 0x03, 0x03, 0xE3, 0x03, 0x03, 0x03, 0x07, 0x0F, 0x1F, 0xFF,
0x03, 0x03, 0xE3, 0xE3, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x03, 0x03, 0x03,
0x07, 0x0F, 0x1F, 0xFF, 0x03, 0x03, 0xE3, 0xE3, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0xE3, 0xC3,
0x83, 0x03, 0x07, 0x0F, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
0x00, 0x3F, 0x70, 0xE0, 0xC0, 0x80, 0x80, 0x80, 0xC0, 0x60, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00,
0x00, 0x00, 0x70, 0x70, 0xF8, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x08, 0x08, 0x08, 0x08, 0x18, 0x78,
0x78, 0xCF, 0x8F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF0, 0xF0, 0xE0,
0xC1, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xE0, 0xFF,
0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC1, 0x83, 0x83, 0x81, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xE0,
0xF0, 0xF8, 0xFC, 0xFF, 0xE0, 0xC0, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83,
0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xFF, 0xE0, 0xC0, 0x83, 0x83, 0x80, 0x80, 0x80, 0x80,
0x80, 0xE0, 0xC0, 0x83, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFF, 0xFF, };


unsigned char gameOverTwo[] PROGMEM = {
0x00, 0x00, 0x00, 0xF0, 0x38, 0x1C, 0x0C, 0x84, 0xC4, 0xC4, 0xC4, 0xC4, 0x84, 0x04, 0x0C, 0x1C,
0xF8, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0xF0, 0xF8, 0x3C, 0x1C, 0x0C, 0x84, 0xC4, 0xC4, 0xC4, 0xC4,
0x84, 0x04, 0x0C, 0x3C, 0xF8, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0xFC, 0xFC, 0x04, 0x04, 0x04, 0x0C,
0x3C, 0x78, 0x38, 0x1C, 0x0C, 0x04, 0x04, 0x04, 0xFC, 0xFC, 0xF8, 0xF0, 0x00, 0x00, 0xFC, 0xFC,
0x04, 0x04, 0x04, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xCC, 0xFC, 0xFC, 0xF8, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x00, 0x1F, 0x3F, 0x23, 0x23, 0x23, 0x03, 0x03,
0x03, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xE3, 0xE3, 0xE3,
0xE3, 0xE3, 0xE3, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
0x00, 0xFE, 0xFC, 0xFC, 0xFC, 0xFC, 0xFE, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
0xFF, 0xFF, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x38, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF,
0xC3, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x07, 0x00, 0x00, 0x07, 0x0F, 0x0E, 0x1E, 0x1E, 0x1F,
0x1F, 0x1F, 0x1F, 0x07, 0x07, 0x0E, 0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x07, 0x0F,
0x1E, 0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x07, 0x0F, 0x0E, 0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F,
0x00, 0x00, 0x07, 0x0F, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x70, 0x38, 0x18, 0x08, 0x88, 0x88,
0x88, 0x88, 0x08, 0x08, 0x18, 0x78, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0xF8, 0xF8, 0x08, 0x08,
0x08, 0xF8, 0xF8, 0xF0, 0xE0, 0xE0, 0xF8, 0x08, 0x08, 0x08, 0xF8, 0xF8, 0xF0, 0xE0, 0x00, 0x00,
0xF8, 0xF8, 0x08, 0x08, 0x08, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF8, 0xF8,
0xF0, 0xE0, 0x00, 0x00, 0xF8, 0xF8, 0x08, 0x08, 0x08, 0x88, 0x88, 0x88, 0x88, 0x88, 0x08, 0x18,
0x38, 0x70, 0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x3F,
0x7F, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF,
0xC0, 0x80, 0x00, 0x0F, 0x1F, 0x3F, 0x7F, 0x1F, 0x0F, 0x00, 0x80, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF,
0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xFF, 0xFF,
0xFF, 0xFF, 0x87, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xE3, 0xE3, 0xC3, 0xC3, 0x83,
0x03, 0x00, 0x20, 0x60, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0E,
0x1E, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x3C, 0x3E, 0x3F, 0x3F, 0x3F, 0x1F, 0x0F, 0x00, 0x00,
0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1E, 0x38, 0x38, 0x3C, 0x3E, 0x3F, 0x3F, 0x3F, 0x1F, 0x0F,
0x07, 0x03, 0x00, 0x00, 0x0F, 0x1F, 0x3C, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
0x38, 0x3C, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x00, 0x0F, 0x1F, 0x38, 0x38, 0x3C, 0x3F, 0x3F, 0x3F,
0x3F, 0x0F, 0x1F, 0x38, 0x38, 0x3C, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x00, };

uint8_t numerals[4][15] = {  // 1 
                            {0, 1, 0, 
                             0, 1, 0,
                             0, 1, 0,
                             0, 1, 0,
                             0, 1, 0},
                             // 2
                            {1, 1, 1, 
                             0, 0, 1,
                             1, 1, 1,
                             1, 0, 0,
                             1, 1, 1},
                             // 3
                             {1, 1, 1,  
                              0, 0, 1,
                              1, 1, 1,
                              0, 0, 1,
                              1, 1, 1},
                             // 4
                             {0, 1, 1, 
                              1, 0, 1,
                              1, 1, 1,
                              0, 0, 1,
                              0, 0, 1}
                          };





unsigned char *imgPtr[4];
unsigned int blockArray[M][N] = { 0, 1, 0, 3, 3, 3, 0, 0, 0, 2, 2, 2, 0, 0, 1, 1, 
                                  0, 1, 0, 0, 0, 3, 0, 1, 0, 0, 0, 2, 0, 1, 0, 1,
                                  0, 1, 0, 3, 3, 0, 0, 0, 0, 2, 2, 2, 0, 1, 1, 1,
                                  0, 1, 0, 3, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1,
                                  0, 1, 0, 3, 3, 3, 0, 0, 0, 2, 2, 2, 0, 0, 0, 1}; 

const unsigned int beepPin     = 9; 
unsigned int xHumanPaddle      = 20; // Human player paddle x pos.
unsigned int humanPaddleSize   = 12; // Human and AI player paddle size
unsigned int humanPaddlePin    = A5;  // Human pin input - analogue input pin


// Ball details
unsigned int LEVEL = 1;
unsigned int SPEED = 10;
unsigned int xBall = 20;
unsigned int yBall = 20;
int xVelocity      = -1;
int yVelocity      = -1;
int blockCount     = 0;


// Functions
void bonusBlock(unsigned int x, unsigned int y);
void initialise(unsigned int LEVEL);
void moveBall();
void humanPlayer();
void printBlockArray();
bool blockCollision();
void startScreen();
void beep(int delayPos);
void blockCheck();
void gameOverCheck();
int data[2];


void setup()
{     
  data[0] = 0;
  data[1] = 0;
  imgPtr[0] = &MaddisonOne[0];
  imgPtr[1] = &MaddisonTwo[0];
  imgPtr[2] = &MaddisonThree[0];
  imgPtr[3] = &MaddisonTitle[0];
  display.begin();
  display.setContrast(60);
  display.clearDisplay();     
  //startScreen();
  initialise(LEVEL); 
}


void loop() 
{ 
  display.clearDisplay();         
  printBlockArray();
  humanPlayer();     
  moveBall();    
  blockCheck();
  gameOverCheck();
  display.display();   
  delay(SPEED);
  
  while(1){}
}


void initialise(unsigned int LEVEL)
{
  randomSeed(analogRead(humanPaddlePin));
  int i, j;
  
  char buffer[12] = "           ";
  sprintf(buffer, "  LEVEL %d", LEVEL);
  display.setCursor(10,14);
  for(i=0; i<sizeof(buffer); i++)
 {
    display.print( buffer[i] );
    display.display();
    delay(300);
  }
  
  //for(i=0; i<M; i++)
   // for(j=0; j<N; j++)
     // blockArray[i][j] = 1;//random(0, 2);
   
  // place bonus and blocks
 // unsigned int checkBlankBlock = 0;
 // while( checkBlankBlock < ((LEVEL*2)+1) )
  //{ 
   // randomSeed(analogRead(humanPaddlePin));
   // unsigned int X = random(0, M);
   // unsigned int Y = random(0, N);
   // if( blockArray[X][Y] != 3 )
   // {   
   //   blockArray[X][Y] = 3;
   //   checkBlankBlock +=1;
   // }
  //}
  //blockArray[random(1, M-2)][random(1, N-2)] = 2;
  //blockArray[random(1, M-2)][random(1, N-2)] = 2;
  // count the number of blocks to be hit
  for(i=0; i<M; i++)
    for(j=0; j<N; j++)
      if( blockArray[i][j] == 1 )
        blockCount++;
}


void moveBall()
{
     display.drawRect(0, 0, 82, 48, BLACK);
     xBall += xVelocity;
     yBall += yVelocity;
     display.fillRect(xBall, yBall, 3, 3, BLACK);
          
     if( xBall < 1 )
     { xBall = 1;  xVelocity *= -1; }
     else if( xBall > 81 )
     { xBall = 81; xVelocity *= -1; }
     
     // ****************************************     
     // check the ball is hit by the user paddle
     // ****************************************
     if( (yBall > 44) && !((xBall < xHumanPaddle) || (xBall > xHumanPaddle+humanPaddleSize)))
     { // if you hit the ball, deflect the ball
     beep(50);
       yBall = 44; 
       yVelocity *= -1; 
     }
     else if( (yBall > 44) && ((xBall < xHumanPaddle) || (xBall > xHumanPaddle+humanPaddleSize)))
     { // if the human failed to hit the ball - decrease the paddle size
       if( humanPaddleSize >= 2 )
         humanPaddleSize -= 1;
       yBall = 44; 
       yVelocity *= -1; 
     }
     // ***************************************************     
     // check the ball has hit the back wall OR hit a block
     // ***************************************************     
     if( (yBall < 2) || blockCollision() )
       yVelocity *= -1;  
}

void humanPlayer()
{
  float x = analogRead(2);
  float alpha = 0.4, out;   
  data[1] = alpha*data[0] + (1-alpha)*x;
  data[0] = data[1];
  
  if(data[1] > 382)
    data[1] = 380;
  else if(data[1] < 277) 
    data[1] = 280;
    
  xHumanPaddle = map( data[1], 278, 382, (82 - humanPaddleSize), 0);
  //xHumanPaddle = map( analogRead(humanPaddlePin), 0, 1023, 0, (82 - humanPaddleSize) );
  display.fillRect(xHumanPaddle, 45, humanPaddleSize, 2, BLACK);
}



void printBlockArray()
{
  unsigned int xBlock = 0, yBlock = 0;  
  for(unsigned int i=0; i<N; i++)
  {
    for(unsigned int j=0; j<M; j++)
    {
      xBlock = 1 + i*5;
      yBlock = 1 + j*5;
      switch( blockArray[j][i] )
      {
        case 0: // Path - do nothing
          break;

        case 1: // Wall - basic standard block
          display.drawBitmap(xBlock, yBlock, wallBasic, 5, 5, BLACK);
        break;
      
        case 2: // Wall - some sort of bonus round here
          display.drawBitmap(xBlock, yBlock, wallBonus, 5, 5, BLACK);
        break;      
              
        case 3: // Wall - basic standard block
          display.drawBitmap(xBlock, yBlock, wallBounce, 5, 5, BLACK);
        break;        
     }
    }
  }
}


bool blockCollision()
{
  if( yBall > 20 )
    return false;
    
  bool rtnStatus = false;  
  unsigned int xBlock = round(yBall/5);
  unsigned int yBlock = round(xBall/5);
  switch( blockArray[xBlock][yBlock] )
      {
        case 0: // Path - do nothing
          break;

        case 1: // Wall - basic standard block
          blockArray[xBlock][yBlock] = 0;
          blockCount--;
          rtnStatus = true;   
          beep(20);
        break;
      
        case 2: // Bonus Wall - some sort of bonus round here
          rtnStatus = true;
          bonusBlock(xBlock, yBlock);
        break;      
       
        case 3: // Full Wall - black standard block
          rtnStatus = true;
          beep(10);
        break;       
     }
  return rtnStatus;
}


void startScreen()
{
    // display iamges
    for(int i=0; i<4; i++)
    {
      display.clearDisplay();     
      display.drawBitmap(0, 0, imgPtr[i], 82, 48, BLACK);
      display.display();  
      beep(10+(i*100));
      delay(1000);
    }
    delay(500);
    display.clearDisplay(); 
}



void bonusBlock(unsigned int x, unsigned int y)
{
  humanPaddleSize += 1;
  int counter = 1;
  while( counter < 6) 
  {
      display.clearDisplay();   
      if( (counter % 2) == 0 ) 
      {
        display.drawBitmap(0, 0, BonusBmpOne, 82, 48, BLACK);
        beep(40);
      }
      else 
      {
        display.drawBitmap(0, 0, BonusBmpTwo, 82, 48, BLACK);
        beep(80);
      }
      display.display();  
      delay(250);
      counter++;
  }
  
  blockArray[x][y] = 3;
  if( blockArray[x][y-1] == 0 )
  {
    blockArray[x][y-1] = 1;
    blockCount++;
  }
  if( blockArray[x-1][y] == 0 )
  {
    blockArray[x][y+1] = 1;
    blockCount++;
  }
  if( blockArray[x-1][y] == 0)
  {
    blockArray[x-1][y] = 1;
    blockCount++;
  }
  if( blockArray[x+1][y] == 0)  
  {
    blockArray[x+1][y] = 1;
    blockCount++;
  }
  if( blockArray[x+1][y+1] == 0)
  {
    blockArray[x+1][y+1] = 1;
    blockCount++;
  }
  if( blockArray[x+1][y-1] == 0)
  {
    blockArray[x+1][y-1] = 1;
    blockCount++;
  }
  if( blockArray[x-1][y-1] == 0) 
  {
    blockArray[x-1][y-1] = 1;
    blockCount++;
  }
  if( blockArray[x-1][y+1] == 0)
  {
    blockArray[x-1][y+1] = 1; 
    blockCount++;
  }
}

void blockCheck()
{
  if( blockCount > 3 )
    return;
  else
  {
    // start next level
    display.clearDisplay();  
    display.drawBitmap(0, 0, nextLevel, 82, 48, BLACK);
    display.display();      
    
    
    if( SPEED > 2 ) 
      SPEED -= 2;
    humanPaddleSize = 12;
    blockCount      = 0;
    LEVEL          += 1;
    initialise(LEVEL);
  }
}


void gameOverCheck()
{
  if( humanPaddleSize > 1 )
    return;
  else
  {
    int counter = 1;
    while( true )
    {
      display.clearDisplay();  
      if( (counter % 2) == 0 )
      {
        display.drawBitmap(0, 0, gameOverOne, 82, 48, BLACK);
        beep(50);
      }
      else
      {
        display.drawBitmap(0, 0, gameOverTwo, 82, 48, BLACK);
        beep(20);
      }
      display.display();      
      delay(150);
      counter++;    
    }
  }
}


void beep(int delayPos)
{
  analogWrite(beepPin, 250);      // Almost any value can be used except 0 and 255
  delay(delayPos);          // wait for a delayms ms
  analogWrite(beepPin, 0);       // 0 turns it off
  //delay(delayNeg);          // wait for a delayms ms   
}  
