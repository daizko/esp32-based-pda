#ifndef ROT_H
#define ROT_H

#include "drivers/rotary_encoder/rotary_encoder.h"
struct rotaryEncoder
{
    const int A = 4;
    const int B = 5;
};
rotaryEncoder rotE;

namespace rotary_encoder
{
    void begin()
    {
        pinMode(rotE.A, INPUT);
        pinMode(rotE.B, INPUT); // rotary encoder pins as inputs
    }

};

#endif