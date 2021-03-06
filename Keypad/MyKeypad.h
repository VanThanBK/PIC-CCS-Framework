/***********************************
* Keypad 4x4 library
* Header file "MyKeypad.h"
********************************************/

//Khai bao cac chan cho Button
#use fast_io(b)

#define KEY_PORT_Dir    set_tris_b

#define H1          PIN_B0
#define H2          PIN_B1
#define H3          PIN_B2
#define H4          PIN_B3
#define C1          PIN_B4
#define C2          PIN_B5
#define C3          PIN_B6
#define C4          PIN_B7


int Keyval[4][4] = { 8,  9,  10,  11,
                     5,  6,  7,   12,
                     2,  3,  4,   13,
                     15, 1,  16,  14};
//Khai bao ham
void KeypadInit();
int Button();

/********************************************
* Include source file
********************************************/
#include "MyKeypad.c"
