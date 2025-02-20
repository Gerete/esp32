#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

void app_main(void)
{
  gpio_reset_pin(2);
  gpio_set_direction(2, GPIO_MODE_OUTPUT);
  while (1)
  {
    gpio_set_level(2, 0);
    gpio_set_level(2, 1);
  }
}