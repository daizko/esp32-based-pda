# esp32-based-pda

esp32 based pda device with eink and oled display

## Overview

This project will be my walkthrough about how i built and programmed my pda like device.
It's nothing that big but it's my first more difficult project since im making ui myself.

## Functionality

I want this to be pocketable device, that will be able to mainly write notes. I'm also thinking about adding fuctionality for more apps but thats for other time. It will have micro sd card support for saving notes and other stuff. The keyboard will be based on 3 button matrixes each 4x4 so 48 buttons in total and some of the left buttons that weren't used for text will be for navigation. The main e ink module will show all the text you are currently working on, but the main oled will be used for typing so you can see change fast. Then it will be sent to the eink, either by user input or by itself. Also it will be battery powered with usb-c charging.

## Parts

- Esp32-S3 44pin
- Eink 4.2" display (primary)
- Oled 0.91" I2C display (secondary)
- Button matrix 16 buttons x3 -> 48 buttons
- Sd card slot
- Gpio expanders x2 -> 32 pins
- TP4056 charging module
- 3.7V battery

## Features i need to implement

- Pda like notetaking (oled is used as writing display and then its sent onto eink display)
- Saving onto micro sd card
- Adding support for more programs
- Keyboard and other navigation buttons functionality
- Status leds
- Other features i will think of along the way
