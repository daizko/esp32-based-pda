#ifndef OLED_H
#define OLED_H

#include <Arduino.h>

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h> //OLED libraries
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

namespace oled
{
    void begin();
};
#endif