#include<stdint.h>
#include<stdio.h>
#include<assert.h>
#include"../headers/rpi_gpio.h"

//static gpio_t* rpiGpio = (gpio_t*)GPIO_BASE;


gpio_t element = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

static gpio_t* rpiGpio = &element;



gpio_t* get_gpio(void)
{
    return rpiGpio;
}


gpio_value_t get_gpio_value( gpio_pin_t* gpio )
{

    gpio_value_t result = RPI_IO_UNKNOWN;

    switch (*gpio / 32)
    {
        case 0:
            result = (rpiGpio->GPLEV0 & ( 1 << *gpio));
            break;

        case 1:
            result = ( (1 << *gpio - 32) & rpiGpio->GPLEV1 ); 
            break;

        default:
            break;
    }

    if( result != RPI_IO_UNKNOWN)
    {
        if (result)
            result = RPI_IO_HI;
    }
    return result;
}


void set_gpio_hi(gpio_pin_t pin)
{
    rpiGpio->GPSET0 = 1;
}