#include <Arduino.h>

#include "drivers/buzzer/buzzer.h"
#include "drivers/eink/eink.h"
#include "drivers/gpio_expander/gpio_expander.h"
#include "drivers/leds/leds.h"
#include "drivers/oled/oled.h"
#include "drivers/rotary_encoder/rotary_encoder.h"
#include "drivers/sd_card/sd_card.h"
#include "drivers/vib_motor/vib_motor.h"

void setup()
{
  Serial.begin(115200);
  leds::begin();
}

void loop()
{
  leds::led1_blink(500);
  // put your main code here, to run repeatedly:
}

// put function definitions here:
