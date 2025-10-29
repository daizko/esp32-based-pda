#include <Arduino.h>

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h> //OLED libraries
#include <Adafruit_I2CDevice.h>

#include <Adafruit_MCP23X17.h> //gpio expander library

#include <Wire.h>
#include <SPI.h>

#include <FS.h> //handles files
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
// GxEPD2_3C<GxEPD2_420c_GDEY042Z98, GxEPD2_420c_GDEY042Z98::HEIGHT> display(GxEPD2_420c_GDEY042Z98(/*CS=5*/ eInk.CS_PIN, /*DC=*/eInk.DC_PIN, /*RES=*/eInk.RES_PIN, /*BUSY=*/eInk.BUSY_PIN)); // 400x300, SSD1683 color display

struct SD_Slot
{
  int CS_PIN;
  int MOSI_PIN;
  int MISO_PIN; // sdslot pins
  int SCK_PIN;
};
SD_Slot sdSlot = {10, 11, 13, 12};

#define led1 (1) // led pin

#define SDA (8) // i2c pins
#define SCL (9)
struct gpio_expander
{
  uint8_t adress;
  int INTA;
  int INTB;
  int RESPIN;
};
gpio_expander gpio_exp_1 = {0x40 >> 1, 15, 16, 40}; // i need to shift to 7bit bc manufacter uses 8bit
gpio_expander gpio_exp_2 = {0x41 >> 1, 17, 18, 41}; // not sure about what adress does changing a0 to high make

struct rotaryEncoder
{
  int A;
  int B;
};
rotaryEncoder rotE = {48, 47};

SPIClass *fspi = NULL; // pointers to spi objects
SPIClass *hspi = NULL;

// put function declarations here:

void setup()
{
  Serial.begin(115200);

  pinMode(led1, OUTPUT); // led set as output

  Wire.begin(SDA, SCL); // i2c inicialisation

  fspi = new SPIClass(FSPI); // fspi bc vpsi is older name for it
  hspi = new SPIClass(HSPI);
  fspi->begin(sdSlot.SCK_PIN, sdSlot.MISO_PIN, sdSlot.MOSI_PIN, sdSlot.CS_PIN);
  hspi->begin(eInk.CLK_PIN, -1, eInk.MOSI_PIN, eInk.CS_PIN);

  pinMode(fspi->pinSS(), OUTPUT);    // VSPI SS
  pinMode(hspi->pinSS(), OUTPUT);    // HSPI SS
  digitalWrite(fspi->pinSS(), HIGH); // Start with SS high
  digitalWrite(hspi->pinSS(), HIGH);

  display.init(115200, true, 50, false);

  if (!SD.begin(sdSlot.CS_PIN, *fspi))
  {
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
