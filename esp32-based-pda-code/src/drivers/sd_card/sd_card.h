#ifndef sd_card_H
#define sd_card_H

#include <Arduino.h>
#include "drivers/leds/leds.h"

#include <SPI.h>
#include <FS.h> //handles files
#include <SD.h> //Micor sd card library

namespace sd_card
{
    void begin();
};

#endif