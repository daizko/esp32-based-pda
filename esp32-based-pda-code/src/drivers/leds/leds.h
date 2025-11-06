#ifndef leds_H
#define leds_H

#include <Arduino.h>

namespace leds
{

    extern const int led2;
    extern const int led1;

    void begin();
    void led1_blink();
    void start_blink_led1(int lenght1, int times);
    void led2_blink();
    void start_blink_led2(int lenght2, int times);
};

#endif