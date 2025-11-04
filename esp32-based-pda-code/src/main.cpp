#include <Arduino.h>

#include <Adafruit_MCP23X17.h> //gpio expander library

struct gpio_expander
{
  uint8_t adress;
  int INTA;
  int INTB;
  int RESPIN;
};
gpio_expander gpio_exp_1 = {0x40 >> 1, 15, 16, 40}; // i need to shift to 7bit bc manufacter uses 8bit
gpio_expander gpio_exp_2 = {0x41 >> 1, 17, 18, 41}; // not sure about what adress does changing a0 to high make

struct one_pin_devices
{
  int PIN;
};
one_pin_devices led1 = {1}; // case led
one_pin_devices led2 = {6}; // error led
one_pin_devices buzzer = {7};
one_pin_devices vib_motor = {21};
one_pin_devices battery_voltage = {3};

// put function declarations here:

void setup()
{
  Serial.begin(115200);

  pinMode(led1.PIN, OUTPUT); // led set as output
  pinMode(led2.PIN, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
