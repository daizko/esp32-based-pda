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
// GxEPD2_3C<GxEPD2_420c_GDEY042Z98, GxEPD2_420c_GDEY042Z98::HEIGHT> display(GxEPD2_420c_GDEY042Z98(/*CS=5*/ eInk.CS_PIN, /*DC=*/eInk.DC_PIN, /*RES=*/eInk.RES_PIN, /*BUSY=*/eInk.BUSY_PIN)); // 400x300, SSD1683 color display

struct SD_Slot
{
  const int CS_PIN = 10;
  const int MOSI_PIN = 11;
  const int MISO_PIN = 13; // sdslot pins
  const int SCK_PIN = 12;
};
SD_Slot sdSlot;

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
  const int A = 4;
  const int B = 5;
};
rotaryEncoder rotE;
struct one_pin_devices
{
  int PIN;
};
one_pin_devices led1 = {1}; // case led
one_pin_devices led2 = {6}; // error led
one_pin_devices buzzer = {7};
one_pin_devices vib_motor = {21};
one_pin_devices battery_voltage = {3};

SPIClass *fspi = NULL; // pointers to spi objects
SPIClass *hspi = NULL;

// put function declarations here:

void setup()
{
  Serial.begin(115200);

  pinMode(led1.PIN, OUTPUT); // led set as output
  pinMode(led2.PIN, OUTPUT);

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
    digitalWrite(led2.PIN, HIGH); // error led
    return;
  }
  uint8_t cardType = SD.cardType();

  pinMode(rotE.A, INPUT_PULLUP);
  pinMode(rotE.B, INPUT_PULLUP); // rotary encoder pullups
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
