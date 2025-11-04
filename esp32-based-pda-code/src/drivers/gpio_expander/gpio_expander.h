#ifndef gpio_expander_H
#define gpio_expander_H

#include <Arduino.h>

#include <Adafruit_MCP23X17.h> //gpio expander library

namespace gpioexpander
{
    struct gpio_expander
    {
        uint8_t adress;
        int INTA;
        int INTB;
        int RESPIN;
    };
    void begin();
}
#endif