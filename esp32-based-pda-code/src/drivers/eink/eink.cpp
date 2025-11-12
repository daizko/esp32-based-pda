

#include "drivers/eink/eink.h"

struct Eink_Display
{
    const int CS_PIN = 39;
    const int BUSY_PIN = 14;
    const int RES_PIN = 40; // eink pins
    const int DC_PIN = 37;
    const int CLK_PIN = 36;
    const int MOSI_PIN = 35;
};
Eink_Display eInk;

// 4.2'' EPD Module
GxEPD2_BW<GxEPD2_420_GDEY042T81, GxEPD2_420_GDEY042T81::HEIGHT> display(GxEPD2_420_GDEY042T81(/*CS=5*/ eInk.CS_PIN, /*DC=*/eInk.DC_PIN, /*RES=*/eInk.RES_PIN, /*BUSY=*/eInk.BUSY_PIN)); // 400x300, SSD1683

SPIClass *hspi = NULL;

namespace Eink
{
    void begin()
    {
        hspi = new SPIClass(HSPI);

        hspi->begin(eInk.CLK_PIN, -1, eInk.MOSI_PIN, eInk.CS_PIN);
        display.init(115200, true, 50, false);
        pinMode(hspi->pinSS(), OUTPUT); // HSPI SS
        digitalWrite(hspi->pinSS(), HIGH);

        display.init(115200);
        display.setRotation(1);              // 1 - probably landscape
        display.setFont(&FreeMonoBold9pt7b); // default font size, you have to call function setFont with different pt sizes before printing heading and so on
        display.setTextColor(GxEPD_BLACK);   // display parametres
    }
};