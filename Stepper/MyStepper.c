/********************************************
* Step Library
* Source file "MyStepper.c"
********************************************/

#int_timer1
void TIMER1_isr(void){      //Ngat timer 1. 1 lan ngat tuong ung voi 1  step
   if(mode_step==0){
      if(k==0){
         if(INTDEM > s_step){
            disable_interrupts(INT_TIMER1);
            INTDEM = 0;
         } else {
            Step();
            INTDEM++;
         }
      } else {
         Step();
      }
   } else {
      if(k==0){
         if(INTDEM > s_step){
            disable_interrupts(INT_TIMER1);
            INTDEM = 0;
         } else {
            Step_L298(mode_l);
            if(dir_step==0){mode_l++;if(mode_l > 4){ mode_l = 1;}}
               else {mode_l -- ;if(mode_l < 1){ mode_l = 4;}}
            INTDEM++;
         }
      } else {
         Step_L298(mode_l);
         if(dir_step==0){mode_l++;if(mode_l > 4){ mode_l = 1;}}
            else {mode_l--;if(mode_l < 1){ mode_l = 4;}}
      }
   }
   set_timer1(val_timer);
}

void BeginStep(int val_mode,int val_micro){                           //Khao báo step - val_micro: vi buoc chon trên driver A4988 1-2-4-8-16
   micro_step = val_micro;                                            //              - val_mode  0: A4988      
   mode_step  = val_mode;                                             //                          1: L298N
   if(mode_step==0){                                                  // * val_mode == 1 thì   val_micro =1
      STEP_PORT_DIR(STEP_PORT_DIR1()&0xf8);
   } else {
      STEP_PORT_DIR(STEP_PORT_DIR1()&0xf0);
   }
   setup_timer_1 ( T1_INTERNAL | T1_DIV_BY_8 );
   enable_interrupts(GLOBAL);
   disable_interrupts(INT_TIMER1);
   DisableStep();
}

void EnableStep(){                                       //Ham dong co
   output_bit(Step_EN,0);
}

void DisableStep(){                                         // Bo hãm dong co
   if(mode_step==0){
      output_bit(Step_EN,1);
   } else {
      output_bit(Step_P1,0);
      output_bit(Step_P2,0);
      output_bit(Step_P3,0);
      output_bit(Step_P4,0);
   }
}

void Step(){                                             //Chay 1 buoc A4988 = 1 xung
      EnableStep();
      if(s_speed>0){
         output_bit(Step_SDA,1);
         delay_us(2);
         output_bit(Step_SDA,0);
      }
}
void Step_L298(int Lval){                                //Chay 1 buoc L298 :thay doi trang thai chan
      switch (Lval)
      {
         case 1:{    // 1010
            output_bit(Step_P1,1);
            output_bit(Step_P2,0);
            output_bit(Step_P3,0);
            output_bit(Step_P4,0);
            break;}
         case 2:{    // 0110
            output_bit(Step_P1,0);
            output_bit(Step_P2,1);
            output_bit(Step_P3,0);
            output_bit(Step_P4,0);
            break;}
         case 3:{    //0101
            output_bit(Step_P1,0);
            output_bit(Step_P2,0);
            output_bit(Step_P3,1);
            output_bit(Step_P4,0);
            break;}
         case 4:{    //1001
            output_bit(Step_P1,0);
            output_bit(Step_P2,0);
            output_bit(Step_P3,0);
            output_bit(Step_P4,1);
            break;}
    }
}

long Cal_TMR1(float cal_speed){                          //Tinh tu van toc ra TMR1
   float stepa;
   float time_1step;
   long re;
   s_speed = cal_speed;
   if(cal_speed > MaxSpeed/micro_step) cal_speed = MaxSpeed/micro_step;
   stepa = cal_speed*200*micro_step;
   time_1step = (float) 1000000/stepa;
   re = (long) time_1step/1.6;
   re = 65536 - re;
   return re;
}

void StepMove(int dir_v,float speed_v,float angle_v){                //Quay 1 goc angle_v voi toc do speed_v va chieu dir_v
   k = 0;
   if(mode_step==0){
      output_bit(Step_DIR,dir_v);
   } else {
      dir_step = dir_v;
   }
   val_timer = Cal_TMR1(speed_v);
   set_timer1(val_timer);
   s_step = (long)angle_v*micro_step/1.8;
   enable_interrupts(INT_TIMER1);
}

void StepSpin(int dir_v,float speed_v){                              //quay lien tuc voi van toc speed_v va chieu dir_v
   k = 1;
   if(mode_step==0){
      output_bit(Step_DIR,dir_v);
   } else {
      dir_step = dir_v;
   }
   val_timer = Cal_TMR1(speed_v);
   set_timer1(val_timer);
   enable_interrupts(INT_TIMER1);
}

void StepStop(){                                                     //Dung dong co
   disable_interrupts(INT_TIMER1);
   INTDEM = 0;
   s_step = 0;
   val_timer = 0;
}
