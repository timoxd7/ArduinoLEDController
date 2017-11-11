#include <Arduino.h>
#include "LEDController.h"

LEDController::LEDController(int pinRed, int pinGreen, int pinBlue)
{
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);

  _pinRed = pinRed;
  _pinGreen = pinGreen;
  _pinBlue = pinBlue;
}
