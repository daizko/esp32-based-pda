#include "drivers/leds/leds.h"

namespace leds
{

    const int led1 = 1; // case led
    const int led2 = 6; // error led
    unsigned long int currentMillis;
    unsigned long int timeEllapsed;
    void begin()
    {
        pinMode(led1, OUTPUT); // led set as output
        pinMode(led2, OUTPUT);
        currentMillis = 0;
        timeEllapsed = 0;
    }

    void led1_blink(int speed, int lenght)
    {
        if (timeEllapsed > lenght)
        {
            return;
        }
        if (millis() - currentMillis >= speed)
            digitalWrite(led1, !digitalRead(led1));
        currentMillis = millis();
        timeEllapsed = millis() - currentMillis;
    }
};