#ifndef _C_GPIO_H_
#define _C_GPIO_H_

#include "../base.h"

#define GPIO_BASE  (PERIPHERAL_BASE + 0x00200000)


#define GPFSEL1     (PERIPHERAL_BASE + 0x00200004)
#define GPSET0      (GPIO_BASE + 0x1c)
#define GPSET1      (GPIO_BASE + 0x20) 
#define GPCLR0      (GPIO_BASE + 0x28)
#define GPCLR1      (GPIO_BASE + 0x2c)
#define GPPUD       (GPIO_BASE + 0x94)
#define GPLEV0      (GPIO_BASE + 0x34)
#define GPLEV1      (GPIO_BASE + 0x38)
#define GPPUDCLK0   (GPIO_BASE + 0x98)



#define      INPUT                 0
#define      OUTPUT                1

#define      GPIO_MAX_PIN         53

#define      PULL_NONE             0
#define      PULL_DOWN             1
#define      PULL_UP               2


#define      LED_RED_GPIO5         5

#define      LED_BLUE_GPIO6        6



#define      LED_WHITE_GPIO26    26



void gpio_init();
unsigned int gpio_pin_configure(unsigned int pin, int function);
void gpio_pin_on(unsigned int  pin);
void gpio_pin_off(unsigned int pin);
unsigned int  gpio_get_value(unsigned int pin);
unsigned int gpio_pin_trigger(unsigned int pin, unsigned int  pull);
void gpio_toggle_pin(unsigned int pin);

#endif