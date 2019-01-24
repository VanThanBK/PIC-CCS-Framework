#include <16F887.h>
#include <string.h>
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)

#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)
//#include <A:\PIC_CCS\7SEG\My_7seg.h>
//#include <A:\PIC_CCS\Keypad\MyKeypad.h>
#include <A:\PIC_CCS\LCD\MyLCD.h>
//#include <A:\PIC_CCS\Stepper\MyStepper.h>
//#include <A:\PIC_CCS\DHT\My_DHT.h>
//#include <A:\PIC_CCS\Homephone\Homephone.h>



