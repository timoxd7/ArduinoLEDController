#ifndef LEDController_h
#define LEDController_h

#include "Arduino.h"

class LEDController
{
  public:
    LEDController(int pinRed, int pinGreen, int pinBlue);
  private:
    int _pinRed, _pinGreen, _pinBlue;
};

#endif
