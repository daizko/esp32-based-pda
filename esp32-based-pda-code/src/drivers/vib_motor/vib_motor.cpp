#include "drivers/vib_motor/vib_motor.h"

namespace vib_motor
{

    void begin()
    {
        pinMode(vib_motor::pin, OUTPUT);
    }
};