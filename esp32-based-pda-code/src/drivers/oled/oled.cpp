#include "drivers/oled/oled.h"

namespace oled
{
    const int SDA_PIN = 8;
    const int SCL_PIN = 9;
    void begin()
    {
        Wire.begin(SDA, SCL); // i2c inicialisation
    }
};
