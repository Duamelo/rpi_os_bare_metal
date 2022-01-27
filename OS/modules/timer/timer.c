#include "../../utils.h"
#include "../../printf.h"
#include "timer.h"
#include"../led/led.h"
#include"../../app.h"

#ifdef USE_QEMU
unsigned int interval = (1 << 26); // xzl: around 1 sec
#else
unsigned int interval = 5 * 1000 * 1000; // xzl: around 1 sec
#endif

/* 	These are for Arm generic timer. 
	They are fully functional on both QEMU and Rpi3 
	Recommended.
*/

// xzl: CNTFRQ_EL0 reports the frequency of the system count
static unsigned int read_cntfrq(void)
{
	unsigned int val;
	asm volatile ("mrs %0, cntfrq_el0" : "=r" (val));
  	return val;
}

void generic_timer_init ( void )
{
//	interval = read_cntfrq();
//  printf("System count freq (CNTFRQ) is: %u\n", interval);

	printf("interval is set to: %u\n", interval);

	gen_timer_init();
	gen_timer_reset(interval);
}

void handle_generic_timer_irq( void ) 
{
    boot_fired();
	printf("Timer interrupt received. next in %u ticks\n\r", interval);
	gen_timer_reset(interval);
}



