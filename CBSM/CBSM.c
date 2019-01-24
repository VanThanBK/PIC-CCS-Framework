#include <CBSM.h>

#USE FAST_IO (c)
#define led PIN_C0                                             //khai bao chan LED la PIN_C0
volatile unsigned int Valua = 0;                               //bien dem timer

#int_TIMER0
void TIMER0_isr(void) 
{
   Valua++;
   if(Valua>249){   
      output_toggle(led);                                      //dao chan led
      Valua = 0;
   }
   set_timer0(177);                                            //set gia tri ban dau cho tmr0
}

void main()
{  
   set_tris_c(get_tris_c()&0xfe);                              //khao bao chan led output
   enable_interrupts(INT_TIMER0);                              //bat ngat timer0
   enable_interrupts(GlOBAL);                                  //bat ngat tong
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128);                  //setup timer 0   :128
   set_timer0(177);                                            //set gia tri ban dau cho tmr0
   while(TRUE)
   {
   }

}
/*Tinh timer
   


*/
