#include"gpio.h"

//static gpio_t* gpio_base = (gpio_t*)GPIO_BASE;


// write into a register

void mmio_write(long reg, unsigned int val) 
{ 
    *(volatile unsigned int *)reg = val; 
}


//read from a register

unsigned int mmio_read(long reg) 
{ 
    return *(volatile unsigned int *)reg; 
}



// general function which apply some specfic operation
unsigned int gpio_call(unsigned int pin, unsigned int value, unsigned int base, unsigned int field_size, unsigned int field_max) 
{
    unsigned int field_mask = (1 << field_size) - 1;
  
    if (pin > field_max) return 0;
    if (value > field_mask) return 0; 

    unsigned int num_fields = 32 / field_size;
    unsigned int reg = base + ((pin / num_fields) * 4);
    unsigned int shift = (pin % num_fields) * field_size;

    unsigned int curval = mmio_read(reg);
    curval &= ~(field_mask << shift);
    curval |= value << shift;
    mmio_write(reg, curval);

    return 1;
}


//provide 3.3 volts to a pin by writing a 1 to GPSETn register

unsigned int gpio_set(unsigned int pin, unsigned int value) 
{ 
  
        if ( (pin / 32) == 0  )
            return gpio_call(pin, value, GPSET0, 1, GPIO_MAX_PIN);
    
        else
            return gpio_call(pin, value, GPSET1, 1, GPIO_MAX_PIN);
       
}



// provide 0 volt to a pin by writing a 1 to GPCLRn register

unsigned int gpio_clear (unsigned int pin, unsigned int value) 
{ 
  
        if ( (pin / 32) == 0  )
            return gpio_call(pin, value, GPCLR0, 1, GPIO_MAX_PIN);
    
        else
            return gpio_call(pin, value, GPCLR1, 1, GPIO_MAX_PIN);
     
}


//set a specific pull to a pin

unsigned int gpio_pin_trigger (unsigned int pin, unsigned int pull) 
{ 
    return gpio_call(pin, pull, GPPUD, 2, GPIO_MAX_PIN); 
}




//attribute a function to a pin

unsigned int gpio_pin_configure(unsigned int  pin, int function) 
{ 
    return gpio_call(pin, function, GPIO_BASE, 3, GPIO_MAX_PIN); 
}




// check if a pin value is pull_down, pull_up or pull_none


unsigned int gpio_get_value( unsigned int pin)
{
    unsigned int  result = PULL_UP;

    switch( pin / 32 )
    {
        case 0:
            result = ( GPLEV0 & ( 1 << pin ) );
            break;

        case 1:
            result = ( GPLEV1 & ( 1 << ( pin - 32 ) ) );
            break;

        default:
            break;
    }

    if( result != PULL_UP )
    {
        if( result )
            result = PULL_DOWN;
    }

    return result;
}

//probleme avec get_value() 



//toggle pin from pull_down to pull_up or vice versa

void gpio_toggle_pin(unsigned int  pin)
{

    if (gpio_get_value(pin) == PULL_UP )
        gpio_pin_trigger(pin, PULL_DOWN);

    else if ( gpio_get_value(pin) == PULL_DOWN )
        gpio_pin_trigger(pin, PULL_UP);

}


//set pin to output with tension (3,3 volts)

void gpio_pin_on(unsigned int pin)
{
   // gpio_pin_trigger(pin, PULL_UP);
   gpio_pin_configure(pin, OUTPUT);
    gpio_set(pin, 1);
}



// set pin to output wiht no tension (0 volt)

void gpio_pin_off(unsigned int pin)
{
    //gpio_pin_trigger(pin, PULL_NONE);
     gpio_pin_configure(pin, INPUT);
    gpio_clear(pin, 1);   
}


void gpio_init(void)
{
    gpio_pin_configure(LED_RED_GPIO5, INPUT);
    gpio_pin_configure(LED_BLUE_GPIO6, INPUT);
    gpio_pin_configure(LED_WHITE_GPIO26, INPUT);
  //  gpio_pin_off(LED_RED_GPIO5);
  //  gpio_pin_off(LED_BLUE_GPIO6);
    //gpio_pin_off(LED_WHITE_GPIO26);

}