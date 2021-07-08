#include<unity.h>
#include"../headers/rpi_gpio.h"


int gpio = 1;
int * pin = &gpio;


void setUp(void)
{
 
}

void tearDown(void)
{
}


/*
void test_address_gpio_gplev0()
{
  TEST_ASSERT_EQUAL_HEX32(0x3F200034, &get_gpio()->GPLEV0);
}

*/

/*
void test_contenu_gpio_gplev0()
{
  TEST_ASSERT_EQUAL(1, get_gpio()->GPLEV0);
}
*/

void test_gpio_value()
{

  TEST_ASSERT_EQUAL(RPI_IO_LO, get_gpio_value(pin));
}


void test_gpio_high()
{
  set_gpio_hi(*pin);
  TEST_ASSERT_EQUAL(RPI_IO_HI, get_gpio()->GPSET0);
}


int main(void)
{
    UNITY_BEGIN();
    

     RUN_TEST(test_gpio_value);
     RUN_TEST(test_gpio_high);
     //RUN_TEST(test_address_gpio_gplev0);
     //RUN_TEST(test_value_gpio_gplev0);


    return UNITY_END();
}
