#include "drivers/buzzer/buzzer.h"

namespace buzzer
{
    const int pin = 7;

    void begin()
    {
        pinMode(buzzer::pin, OUTPUT);
    }
};