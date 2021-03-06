#include <7SEG_Demo.h>

char receString[16];

void main()
{
   output_low(PIN_C1);   // Set CCP2 output low 
   output_low(PIN_C2);   // Set CCP1 output low 
   setup_ccp1(CCP_PWM);  // Configure CCP1 as a PWM 
   LCDInit();
   LCDClear();
   LCDMove(1, 1);
   
   printf(LCDPutChar, "%s", "Than");
   setup_timer_2 (T2_DIV_BY_16, 130, 10);
   set_pwm1_duty(10);
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_RDA);
   //LCDPutChar('A');
   while(TRUE)
   {  
      putchar('H'); 
      
      LCDMove(2, 1);
      if(receString[0] == 'M'){
         set_pwm1_duty(receString[1]);
         putchar('1');
      }
      if(receString[0] == 'D'){
         //LCDPrint(2, 1, receString);
         LCDPutChar(receString[1]);
         LCDPutChar(receString[2]); 
         LCDPutChar(receString[3]);  
      }
      delay_ms(10);
   }
}

#INT_RDA
void callbackRDA() {
   int i = 0;
   while(kbhit()){
         receString[i] = getchar();
         i=i+1;
      }
}


