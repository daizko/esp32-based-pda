#include <Arduino.h>

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h> //OLED libraries
#include <Adafruit_I2CDevice.h>

#include <Adafruit_MCP23X17.h> //gpio expander library

#include <Wire.h>
#include <SPI.h>

#include <SD.h> //Micor sd card library

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h> //eink libraries
#include <Fonts/FreeMonoBold9pt7b.h>

struct Eink_Display
{
  int CS_PIN;
  int BUSY_PIN;
  int RES_PIN; // eink pins
  int DC_PIN;
  int CLK_PIN;
  int MOSI_PIN;
};
Eink_Display eInk = {39, 14, 40, 37, 36, 35};

// 4.2'' EPD Module
GxEPD2_BW<GxEPD2_420_GDEY042T81, GxEPD2_420_GDEY042T81::HEIGHT> display(GxEPD2_420_GDEY042T81(/*CS=5*/ eInk.CS_PIN, /*DC=*/eInk.DC_PIN, /*RES=*/eInk.RES_PIN, /*BUSY=*/eInk.BUSY_PIN)); // 400x300, SSD1683
// GxEPD2_3C<GxEPD2_420c_GDEY042Z98, GxEPD2_420c_GDEY042Z98::HEIGHT> display(GxEPD2_420c_GDEY042Z98(/*CS=5*/ eInk.CS_PIN, /*DC=*/eInk.DC_PIN, /*RES=*/eInk.RES_PIN, /*BUSY=*/eInk.BUSY_PIN)); // 400x300, SSD1683

struct SD_Slot
{
  int CS_PIN;
  int MOSI_PIN;
  int MISO_PIN; // sdslot pins
  int SCK_PIN;
};
SD_Slot sdSlot = {10, 11, 13, 12};

#define led1 (1) // led pin

struct rotaryEncoder
{
  int A;
  int B;
};
rotaryEncoder rotE = {48, 47};

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}