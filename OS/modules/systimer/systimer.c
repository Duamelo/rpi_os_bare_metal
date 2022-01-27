#include"systimer.h"


systimer_reg_t* sys_timer_base = (systimer_reg_t*) SYSTIMER_BASE;


systimer_reg_t* systimer_configure(void)
{
    return sys_timer_base = (systimer_reg_t*) SYSTIMER_BASE;
}



void systimer_wait_micro_seconds(unsigned int micro_secs)
{
    volatile unsigned int ts = sys_timer_base->counter_low;
    volatile unsigned int x = sys_timer_base->counter_low - ts;

    while( x < micro_secs )
        x = sys_timer_base->counter_low - ts;

}