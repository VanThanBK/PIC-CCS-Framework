/***********************************************
* DHT Library
* Source file "My_DHT.c"
***********************************************/
void DHTStart(){                                    // 11: DHT11 22:DHT22
   output_drive(DHT_Data);
   output_bit(DHT_Data ,0);delay_ms(25);
   output_bit(DHT_Data ,1);delay_us(30);
   output_float(DHT_Data);
}

int DHTcheck(){
   delay_us(40);
   if(!input(DHT_Data))
   { 
      delay_us(80);
      if(input(DHT_Data)) {
         delay_us(50);
         return 1;
      } else {
         return 0;
      }
   } else {
      return 0;
   }
}

int Read_DHT(){
   unsigned int buffer[5]={0x00,0x00,0x00,0x00,0x00};
   unsigned int i,ii;
   unsigned long check_s;
   long T_tam,H_tam;
   int Time_out = 0;
   DHTStart();
   if(DHTcheck()==1){
      while(input(DHT_Data)){
         Time_out++;
         if(Time_out > 80) {break;}
         delay_us(1);
      }
   } else {
      return 0;
   }
   
   for(i=0;i<5;i++)  // nhan 5byte du lieu
    {
        for(ii=0;ii<8;ii++)     // nhan tung bit
        {    
            while((!input(DHT_Data))){}; //Doi Data len 1
            delay_us(50);
            if(input(DHT_Data))
            {
               buffer[i]|=(0x01<<(7-ii));
               while(input(DHT_Data)) ;   //Doi Data xuong 0
            }
        }
    }
   check_s = buffer[0]+buffer[1]+buffer[2]+buffer[3];
   if(check_s!=buffer[4]) return 0;
   if(DHT==11){
      Temp = buffer[0];
      Humi = buffer[2];
   } else if(DHT==22){
      T_tam = buffer[0];
      T_tam = (T_tam<<8)|buffer[1];
      H_tam = buffer[2];
      H_tam = (H_tam<<8)|buffer[3];
      Temp = (float)T_tam/10;
      Humi = (float)H_tam/10;
   }
   return 1;
}

