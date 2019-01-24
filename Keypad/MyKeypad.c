/********************************************
* Keypad Library
* Source file "MyKeypad.c"
********************************************/

//Cai dat cho Button
void KeypadInit(){
 port_b_pullups(1);
 
 KEY_PORT_Dir(0xf0);
 
 output_bit(H1 ,1);
 output_bit(H2 ,1);
 output_bit(H3 ,1);
 output_bit(H4 ,1);
}

//Kiem tra nut nhan muc thap
 Button(){
   int keyV = 0;
   for(int i=0;i<4;i++){
      switch(i){
         case 0:{output_bit(H1 ,0);break;}
         case 1:{output_bit(H2 ,0);break;}
         case 2:{output_bit(H3 ,0);break;}
         case 3:{output_bit(H4 ,0);break;}
      }
      if(input(C1)==0){ keyV = Keyval[i][0];}
 else if(input(C2)==0){ keyV = Keyval[i][1];}
 else if(input(C3)==0){ keyV = Keyval[i][2];}
 else if(input(C4)==0){ keyV = Keyval[i][3];}
 
      switch(i){
         case 0:{output_bit(H1 ,1);break;}
         case 1:{output_bit(H2 ,1);break;}
         case 2:{output_bit(H3 ,1);break;}
         case 3:{output_bit(H4 ,1);break;}
      }
   } 
   return keyV;
}
