/***********************************
* Step
* Header file "MyStepper.h"
********************************************/

#use fast_io(c)

// A4988,...........
#define Step_EN        PIN_C0
#define Step_DIR       PIN_C1
#define Step_SDA       PIN_C2
// L298
#define Step_P1       PIN_C0
#define Step_P2       PIN_C1
#define Step_P3       PIN_C2
#define Step_P4       PIN_C3

#define STEP_PORT_DIR      set_tris_c
#define STEP_PORT_DIR1      get_tris_c

#define MaxSpeed        500

int micro_step = 0;
volatile int mode_step = 0;
volatile int dir_step = 0;
volatile int mode_l = 1;
float s_speed;
volatile long val_timer =0;
volatile long INTDEM= 0;
volatile long s_step;
volatile int k=0;
void BeginStep(int val_mode,int val_micro);  
void EnableStep();
void DisableStep();
void Step();
void Step_L298(int Lval);
void StepMove(int dir_v,float speed_v,float angle_v);
void StepSpin(int dir_v,float speed_v);
void StepStop();
long Cal_TMR1(float cal_speed);
/********************************************
* Include source file
********************************************/


#include "MyStepper.c"
