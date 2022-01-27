#include"led.h"



void led_init(void)
{
    gpio_init();
}



void led_red_on(void)
{

   gpio_pin_on(LED_RED_GPIO5);

}


void led_white_on(void)
{

    gpio_pin_on(LED_WHITE_GPIO26);

}



void led_blue_on(void)
{

    gpio_pin_on(LED_BLUE_GPIO6);

}

void led_white_off(void)
{
    gpio_pin_off(LED_WHITE_GPIO26);
}



void led_red_off(void)
{
    gpio_pin_off(LED_RED_GPIO5);
}



void led_blue_off(void)
{
    gpio_pin_off(LED_BLUE_GPIO6);
}


/*
void led_all_set(void)
{
    led_init();
    led_red_on();
    led_white_on();
    led_blue_on();
}
*/
/*
void led_all_get(void)
{

}

*/