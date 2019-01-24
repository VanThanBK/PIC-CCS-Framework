#include <new.h>
#USE FAST_IO (e)

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)

void main()
{
   set_tris_e(0x00);
   output_bit(PIN_E1,0);
   while(TRUE)
   {
         output_bit(PIN_E1,0);
         delay_ms(500);
         output_bit(PIN_E1,1);
         delay_ms(500);
   }

}
