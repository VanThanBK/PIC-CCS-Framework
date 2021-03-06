/********************************************
* LCD Library
* Header file "MyLCD.h"
********************************************/
#INCLUDE <string.h>
#use fast_io(d)

#define LCD_RS       PIN_D1
#define LCD_RW       PIN_D2
#define LCD_E        PIN_D3
#define LCD_D4       PIN_D4
#define LCD_D5       PIN_D5
#define LCD_D6       PIN_D6
#define LCD_D7       PIN_D7
#define LCD_DIR      set_tris_d
#define LCD_DIR1      get_tris_d
//char str[15];
void LCDInit(); //Khoi dong LCD
void LCDMode4Bit(); //Chon LCD hoat dong LCD o che do 4 bit
void LCDWriteByte(unsigned char ch);
void LCDWriteData(unsigned char dt);
void LCDWriteCommand(unsigned char dt);
void LCDLatchData();
void LCDClear();
void LCDMove(unsigned char y, unsigned char x);
void LCDPutChar(unsigned int ch);
void LCDPrint(char y, char x, char* str);   //In chuoi ky tu str tai dong x, cot y
void LCDPrintNumber(char y, char x, int num); //Hien thi so nguyen num tai dong x, cot y
void LCDPrintFNumber(char y, char x, float fnum, char f); //Hien thi so thuc fnum o dong x cot y
void LCDcreateChar(char ch,char* str);
/********************************************
* Include source file
********************************************/
#include "MyLCD.c"
