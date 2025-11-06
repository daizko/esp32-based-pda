#include "drivers/leds/leds.h"

namespace leds
{

    const int led1 = 1; // case led
    const int led2 = 6; // error led

    static bool ledState1 = false;
    static bool ledState2 = false;

    static unsigned long int currentMillis1;
    static unsigned long int currentMillis2;

    static bool active1 = false;
    static bool active2 = false;

    static int remaining_blinks1;
    static int remaining_blinks2;

    static int length1;
    static int lenght2;

    void begin()
    {

        pinMode(led1, OUTPUT); // led set as output
        pinMode(led2, OUTPUT);
        currentMillis1 = 0;
    }
    void start_blink_led1(int lenght1, int times)
    {
        remaining_blinks1 = times * 2; // bc on and off is one time
        if (times <= 0)
            return; // returns if minus number
        ledState1 = false;
        digitalWrite(led1, LOW);
        currentMillis1 = millis();
        active1 = true;
    }

    void start_blink_led2(int lenght2, int times)
    {
        remaining_blinks2 = times * 2; // bc on and off is one time
        if (times <= 0)
            return; // returns if minus number
        ledState2 = false;
        digitalWrite(led2, LOW);
        currentMillis2 = millis();
        active2 = true;
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
        if (millis() - currentMillis1 >= length1)
        {
            ledState1 = !ledState1;
            digitalWrite(led1, ledState1 ? HIGH : LOW);
            currentMillis1 = millis();
            remaining_blinks1--;
            return;
        }
    }

    void led2_blink()
    {
        if (!active2)
            return;
        if (remaining_blinks2 <= 0)
        {
            active2 = false;
            digitalWrite(led2, LOW);
            return;
        }
        if (millis() - currentMillis2 >= length1)
        {
            ledState2 = !ledState2;
            digitalWrite(led2, ledState2 ? HIGH : LOW);
            currentMillis2 = millis();
            remaining_blinks2--;
            return;
        }
    }
};