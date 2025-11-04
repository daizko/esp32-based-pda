#ifndef OLED_H
#define OLED_H

#include <Arduino.h>

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h> //OLED libraries
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

namespace oled
{
    const int SDA_PIN = 8;
    const int SCL_PIN = 9;
    void begin();
};
#endif