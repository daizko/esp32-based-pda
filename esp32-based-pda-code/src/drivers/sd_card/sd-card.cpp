#include "drivers/sd_card/sd_card.h"

struct SD_Slot
{
    const int CS_PIN = 10;
    const int MOSI_PIN = 11;
    const int MISO_PIN = 13; // sdslot pins
    const int SCK_PIN = 12;
};
SD_Slot sdSlot;

SPIClass *fspi = NULL; // pointers to spi objects

namespace sd_card
{
    void begin()
    {
        fspi = new SPIClass(FSPI); // fspi bc vpsi is older name for it

        fspi->begin(sdSlot.SCK_PIN, sdSlot.MISO_PIN, sdSlot.MOSI_PIN, sdSlot.CS_PIN);

        pinMode(fspi->pinSS(), OUTPUT);    // VSPI SS
        digitalWrite(fspi->pinSS(), HIGH); // Start with SS high

        if (!SD.begin(sdSlot.CS_PIN, *fspi))
        {
            Serial.println("Card Mount Failed");
            digitalWrite(leds::led2, HIGH); // error led
            return;
        }
        uint8_t cardType = SD.cardType();
    }
};