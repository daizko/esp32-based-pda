#include "drivers/oled/oled.h"

namespace oled
{

    void begin()
    {
        Wire.begin(SDA, SCL); // i2c inicialisation
    }
};
