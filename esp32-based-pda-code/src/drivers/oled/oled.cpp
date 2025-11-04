#include "drivers/oled/oled.h"

#define SDA (8) // i2c pins
#define SCL (9)

namespace oled
{
    void begin()
    {
        Wire.begin(SDA, SCL); // i2c inicialisation
    }
};
