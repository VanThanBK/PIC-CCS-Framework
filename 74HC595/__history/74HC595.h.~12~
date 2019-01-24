#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#use fast_io(B)

#define SHCP  PIN_B0
#define STCP  PIN_B1
#define DS  PIN_B2
#define HC595_tris set_tris_b

void HC595_Init();
void Output595(char valua);

