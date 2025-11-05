#ifndef leds_H
#define leds_H

#include <Arduino.h>

namespace leds
{

    extern const int led2;
    extern const int led1;

    void begin();
    void led1_blink(int speed);
    void start_blink_led1(int times);
};

#endif