#include "drivers/leds/leds.h"

namespace leds
{
    const int led1 = 1; // case led
    const int led2 = 6; // error led
    void begin()
    {
        pinMode(led1, OUTPUT); // led set as output
        pinMode(led2, OUTPUT);
    }
};