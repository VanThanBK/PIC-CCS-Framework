#use fast_io(d)
#use fast_io(e)

#define SEG_PORT        output_d
#define SEG_PORT_Dir    set_tris_d
#define seg_0           PIN_A0
#define seg_1           PIN_A1
#define seg_2           PIN_A2
#define seg_3           PIN_A3

#define seg_dir         set_tris_a

volatile unsigned long num = 0;
void SegInit();
void SegLed(char num);
void SegNumber(long number);

#include "My_7seg.c"
