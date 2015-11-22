#include <stdio.h>
#include <stdlib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <pgmspace.h>

#define N               17
#define M               8
#define RTC_ARRAY       7
#define CANVAS_ARRAY    4
#define NUMERALS_NUM    10
#define NUMERALS_WIDTH  3

uint8_t wallBasic[]  PROGMEM = {0xff, 0xff, 0xff, 0xff};
uint8_t wallBonus[]  PROGMEM = {0x0f, 0x09, 0x09, 0x0f};

// pin 7 - Serial clock out 	(SCLK)
// pin 6 - Serial data out	(DIN)
// pin 5 - Data/Command select 	(D/C)
// pin 3 - LCD chip select	(CS)
// pin 4 - LCD reset	 	(RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

uint8_t timeArray[RTC_ARRAY]       = {0};
uint8_t timeCanvas[CANVAS_ARRAY]   = {0};
uint8_t canvas[N][M]               = {0};
uint8_t numerals[NUMERALS_NUM][NUMERALS_WIDTH] = {  /*0*/ {0x1e, 0x21, 0x1e},
                        			    /*1*/ {0x22, 0x3f, 0x20},
                        			    /*2*/ {0x3d, 0x25, 0x27},
                        			    /*3*/ {0x25, 0x25, 0x3f},
                        			    /*4*/ {0x0c, 0x0a, 0x3f},
                                                    /*5*/ {0x27, 0x25, 0x3d},
                                                    /*6*/ {0x3f, 0x25, 0x3d},
                        			    /*7*/ {0x01, 0x01, 0x3f},
                        			    /*8*/ {0x3f, 0x25, 0x3f},
                                                    /*9*/ {0x07, 0x05, 0x3f} };

void printTime();
void printBlockArray();

uint8_t NUMBER_JF = 0;
void setup()
{     
  display.begin();
  display.setContrast(60);
}
  

void loop() 
{
  display.clearDisplay(); 
  printTime();
  printBlockArray();
  display.display();
  
  delay(1000);
  if( NUMBER_JF > 9)
    NUMBER_JF = 0;
}












void printTime()
{
  timeCanvas[0] = NUMBER_JF++;
  timeCanvas[1] = 9;
  timeCanvas[2] = 2;
  timeCanvas[3] = 6;
  
  
  // shows the time, i.e.  1   3 : 4   9
  uint8_t offsetArray[4] = {0,  4,  10, 14};
  uint8_t i, j, number, digit, offset, numberCnt;
	
  for(numberCnt=0; numberCnt<4; numberCnt++)
  {
    number = timeCanvas[numberCnt];
    offset = offsetArray[numberCnt];
    // e.g. print number 0 = {0x3c, 0x42, 0x3c} 
    for(i=0; i<3; i++)
    {
      digit = numerals[number][i];
      for(j=0; j<8; j++)
      {
        if( (digit & (1 << j)) == 0 )
	  canvas[offset+i][j] = 0;
	else
	  canvas[offset+i][j] = 1;
      }
     }
  }
  // place the two dots in the canvasArray, i.e. 13[:]49
  canvas[8][1] = canvas[8][4] = 2;
}



void printBlockArray()
{
  uint8_t xBlock = 0, yBlock = 0;  
  for(uint8_t i=0; i<N; i++)
  {
    for(uint8_t j=0; j<M; j++)
    {
      xBlock = i*5;
      yBlock = j*5;
      switch( canvas[i][j] )
      {
        case 0: // Path - do nothing
          break;

        case 1: // Wall - basic standard block
          display.drawBitmap(xBlock, yBlock, wallBasic, 4, 4, BLACK);
        break;
      
        case 2: // Wall - some sort of bonus round here
          display.drawBitmap(xBlock, yBlock, wallBonus, 4, 4, BLACK);
        break;      
      }
    }
  }
}
