#include "../boot/boot.h"
#include"../gpio/gpio.h"




void led_init(void); // init gpio

void led_red_on(void);
void led_white_on(void);
void led_blue_on(void);


void led_red_off(void);
void led_white_off(void);
void led_blue_off(void);

void led_all_set(void);  // position all led values
void led_all_get(void);  //get status of all led


void led_red_toggle(void);
void led_white_toggle(void);
void led_blue_toggle(void);

