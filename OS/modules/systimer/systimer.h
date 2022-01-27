#ifndef SYSTIMER_H
#define SYSTIMER_H

#include"../base.h"

#define SYSTIMER_BASE  (PERIPHERAL_BASE + 0x3000)

// interrupt fiq number for arm

#define systimer_match_1      1
#define systimer_match_3      3


typedef struct
{
    unsigned int timer0_matched: 1;
    unsigned int timer1_matched: 1;
    unsigned int timer2_matched: 1;
    unsigned int timer3_matched: 1;
    unsigned int reserved: 28;
}
systimer_control_reg_t;

typedef struct 
{
    systimer_control_reg_t control;
    unsigned int counter_low;
    unsigned int control_high;
    unsigned int compare0;
    unsigned int compare1;
    unsigned int compare2;
    unsigned int compare3;
}
systimer_reg_t;


extern systimer_reg_t* systimer_base(void);
extern void systimer_wait_micro_seconds(unsigned int us);
systimer_reg_t* systimer_configure(void);


#endif 