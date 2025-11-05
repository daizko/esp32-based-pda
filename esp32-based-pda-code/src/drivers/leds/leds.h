#ifndef leds_H
#define leds_H

#include <Arduino.h>

namespace leds
{
    extern unsigned long int currentMillis;
    extern unsigned long int timeEllapsed;
    extern const int led2;
    extern const int led1;
    void begin();
    extern void led1_blink(int speed, int lenght);
};

#endif