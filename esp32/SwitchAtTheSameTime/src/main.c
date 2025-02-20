#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "esp_rom_sys.h"

#include "soc/gpio_reg.h"

void gpio_set(int32_t value, int32_t mask)
{
    int32_t *OutAdd = (int32_t *)GPIO_OUT_REG;
    *OutAdd = (*OutAdd & ~mask) | (value & mask);
}

void app_main(void)
{
    gpio_reset_pin(2);
    gpio_set_direction(2, GPIO_MODE_OUTPUT);
    gpio_reset_pin(4);
    gpio_set_direction(4, GPIO_MODE_OUTPUT);

    int32_t mask = 1 << 2 | 1 << 4;
    int32_t value1 = 0 << 2 | 1 << 4;
    int32_t value2 = 1 << 2 | 0 << 4;

    while (1)
    {
        gpio_set(value1, mask);
        gpio_set(value2, mask);
    }
}