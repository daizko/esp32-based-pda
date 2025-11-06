#include "drivers/leds/leds.h"

namespace leds
{

    const int led1 = 1; // case led
    const int led2 = 6; // error led

    static bool ledState = false;
    static unsigned long int currentMillis;
    static bool active1 = false;
    static int remaining_blinks1;
    static int length;

    void begin()
    {

        pinMode(led1, OUTPUT); // led set as output
        pinMode(led2, OUTPUT);
        currentMillis = 0;
    }
    void start_blink_led1(int lenght, int times)
    {
        remaining_blinks1 = times * 2; // bc on and off is one time
        if (times <= 0)
            return; // returns if minus number
        ledState = false;
        digitalWrite(led1, LOW);
        currentMillis = millis();
        active1 = true;
    }
    void led1_blink()
    {
        if (!active1)
            return;
        if (remaining_blinks1 <= 0)
        {
            active1 = false;
            digitalWrite(led1, LOW);
            return;
        }
        if (millis() - currentMillis >= length)
        {
            ledState = !ledState;
            digitalWrite(led1, ledState ? HIGH : LOW);
            currentMillis = millis();
            remaining_blinks1--;
            return;
        }
    }
};