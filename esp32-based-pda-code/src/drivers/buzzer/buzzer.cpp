#include "drivers/buzzer/buzzer.h"

namespace buzzer
{
    

    void begin()
    {
        pinMode(buzzer::pin, OUTPUT);
    }
};