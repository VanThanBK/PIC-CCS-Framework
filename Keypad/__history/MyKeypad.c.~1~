/********************************************
* Keypad Library
* Source file "MyKeypad.c"
********************************************/

//Cai dat cho Button
void KeypadInit(){
 H1_Dir = 0;
 H2_Dir = 0;
 H3_Dir = 0;
 H4_Dir = 0;
 C1_Dir = 1;
 C2_Dir = 1;
 C3_Dir = 1;
 C4_Dir = 1;
 H1 = 1;
 H2 = 1;
 H3 = 1;
 H4 = 1;
}

//Kiem tra nut nhan muc thap
 Button(char but){
 char presskey = 0;
 H1=1; H2=1; H3=1; H4=1; C1=1; C2=1; C3=1; C4=1;
 switch(but){
  case 0: {H4 = 0; if(C2==0) presskey = 1; break;}   //Phim 0
  case 1: {H1 = 0; if(C1==0) presskey = 1; break;}   //Phim 1
  case 2: {H1 = 0; if(C2==0) presskey = 1; break;}   //Phim 2
  case 3: {H1 = 0; if(C3==0) presskey = 1; break;}   //Phim 3
  case 4: {H2 = 0; if(C1==0) presskey = 1; break;}   //Phim 4
  case 5: {H2 = 0; if(C2==0) presskey = 1; break;}   //Phim 5
  case 6: {H2 = 0; if(C3==0) presskey = 1; break;}   //Phim 6
  case 7: {H3 = 0; if(C1==0) presskey = 1; break;}   //Phim 7
  case 8: {H3 = 0; if(C2==0) presskey = 1; break;}   //Phim 8
  case 9: {H3 = 0; if(C3==0) presskey = 1; break;}   //Phim 9
  case A: {H1 = 0; if(C4==0) presskey = 1; break;}  //Phim A
  case B: {H2 = 0; if(C4==0) presskey = 1; break;}  //Phim B
  case C: {H3 = 0; if(C4==0) presskey = 1; break;}  //Phim C
  case D: {H4 = 0; if(C4==0) presskey = 1; break;}  //Phim D
  case Sao: {H4 = 0; if(C1==0) presskey = 1; break;}  //Phim Sao
  case Thang: {H4 = 0; if(C3==0) presskey = 1; break;}  //Phim Thang
 }
 H1=1; H2=1; H3=1; H4=1;
 return presskey;
}
/*
//Kiem tra nut nhan muc cao
Button(char but){
 char presskey = 0;
 H1=0; H2=0; H3=0; H4=0; C1=0; C2=0; C3=0; C4=0;
 switch(but){
  case 0: {H4 = 1; if(C2==1) presskey = 1; break;}   //Phim 0
  case 1: {H3 = 1; if(C1==1) presskey = 1; break;}   //Phim 1
  case 2: {H3 = 1; if(C2==1) presskey = 1; break;}   //Phim 2
  case 3: {H3 = 1; if(C3==1) presskey = 1; break;}   //Phim 3
  case 4: {H2 = 1; if(C1==1) presskey = 1; break;}   //Phim 4
  case 5: {H2 = 1; if(C2==1) presskey = 1; break;}   //Phim 5
  case 6: {H2 = 1; if(C3==1) presskey = 1; break;}   //Phim 6
  case 7: {H1 = 1; if(C1==1) presskey = 1; break;}   //Phim 7
  case 8: {H1 = 1; if(C2==1) presskey = 1; break;}   //Phim 8
  case 9: {H1 = 1; if(C3==1) presskey = 1; break;}   //Phim 9
  case 10: {H1 = 1; if(C4==1) presskey = 1; break;}  //Phim A
  case 11: {H2 = 1; if(C4==1) presskey = 1; break;}  //Phim B
  case 12: {H3 = 1; if(C4==1) presskey = 1; break;}  //Phim C
  case 13: {H4 = 1; if(C4==1) presskey = 1; break;}  //Phim D
  case 14: {H4 = 1; if(C1==1) presskey = 1; break;}  //Phim Sao
  case 15: {H4 = 1; if(C3==1) presskey = 1; break;}  //Phim Thang
 }
 H1=0; H2=0; H3=0; H4=0;
 return presskey;
}
*/