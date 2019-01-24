#include <74HC595.h>

void main()
{
   HC595_Init();
   while(TRUE)
   {
      Output595(0xf0);
      delay_ms(1000);
      Output595(0x0f);
      delay_ms(1000);
   }

}

void HC595_Init(){
   HC595_tris(0x00);
   output_high(SHCP);
   output_high(STCP);
   output_high(DS);  
}

void Output595(unsigned char valua){
   int i;
   unsigned char ch;
   output_low(STCP);
   for(i=0;i<8;i++){
      output_low(SHCP);
      ch = valua;
      if((ch&0x80)==0x80) output_high(DS);
      else output_low(DS);
      valua <<= 1;
      delay_us(1);
      output_high(SHCP);                                          
   }
   output_high(STCP);
}
