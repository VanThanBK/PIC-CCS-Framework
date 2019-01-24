/********************************************
* LCD Library
* Source file "MyLCD.c"
********************************************/
void LCDInit()
   {
      LCD_DIR(0x00);
      //__delay_ms(200);
      LCDMode4Bit();
      LCDWriteCommand(0x28);
      LCDWriteCommand(0x0C);
      LCDWriteCommand(0x06);
   }
void LCDMode4Bit()
   {
      output_bit(LCD_RS,0);
      output_bit(LCD_RW,0);
      output_bit(LCD_D4,0);
      output_bit(LCD_D5,1);
      output_bit(LCD_D6,0);
      output_bit(LCD_D7,0);
      LCDLatchData();
   }
void LCDWriteByte(unsigned char ch)
   {
      output_bit(LCD_D7,(ch>>7)&0x01);
      output_bit(LCD_D6,(ch>>6)&0x01);
      output_bit(LCD_D5,(ch>>5)&0x01);
      output_bit(LCD_D4,(ch>>4)&0x01);
      LCDLatchData();
      output_bit(LCD_D7,(ch>>3)&0x01);
      output_bit(LCD_D6,(ch>>2)&0x01);
      output_bit(LCD_D5,(ch>>1)&0x01);
      output_bit(LCD_D4,ch&0x01);
      LCDLatchData();
   }
void LCDWriteData(unsigned char dt)
   {
      output_bit(LCD_RS,1);
      //LCD_RW=0;
      LCDWriteByte(dt);
   }
void LCDWriteCommand(unsigned char dt)
   {
      output_bit(LCD_RS,0);
      //LCD_RW=0;
      LCDWriteByte(dt);
   }
void LCDLatchData()
   {
      //LCD_RW=0;
      output_bit(LCD_E,1);
      output_bit(LCD_E,0);
      delay_ms(2);
   }
void LCDClear()
   {
      LCDWriteCommand(0x01);
   }
void LCDMove(unsigned char y, unsigned char x)
   {
      unsigned int Ad;
      Ad = 64*(y-1)+(x-1)+0x80;
      LCDWriteCommand(Ad);
   }
void LCDPutChar(unsigned int ch)
   {
      LCDWriteData(ch);
   }
void LCDPrint(char y, char x, char *str)
   {
      LCDMove(y,x);
      while(*str)
         {
            LCDPutChar(*str);
            str++;
         }
   }
void LCDPrintNumber(char y, char x, int num)
   {
      char str[7];
      sprintf(str,"%d",num);
      LCDPrint(y,x,str);
   }
void LCDPrintFNumber(char y, char x, float fnum, char f){
   char i,dem[10];
   char *str1;
   sprintf(dem,"%4.2f",fnum);
   str1 = strtok(dem, ' ');
   for(i=0;i<15;i++){
      if(str1[i] == '.') break;
   }
   i = (i+f+1);
   str1[i] = ' ';
   i++;
   while(str1[i]){
      str1[i] = ' ';
      i++;
   }
   LCDPrint(y,x,str1);
}
void LCDcreateChar(char ch,char* str){
   ch &= 0x7;
   LCDWriteCommand(0x40|(ch<<3));
   for (int i=0; i<8; i++) {
      LCDPutChar(str[i]);
   }
}
