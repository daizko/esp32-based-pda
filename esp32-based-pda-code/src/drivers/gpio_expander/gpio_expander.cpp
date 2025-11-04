#include "drivers/gpio_expander/gpio_expander.h"

namespace gpioexpander
{
    gpio_expander gpio_exp_1 = {0x40 >> 1, 15, 16, 40}; // i need to shift to 7bit bc manufacter uses 8bit
    gpio_expander gpio_exp_2 = {0x41 >> 1, 17, 18, 41}; // not sure about what adress does changing a0 to high make
};