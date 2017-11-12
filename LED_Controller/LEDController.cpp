#include <Arduino.h>
#include <EEPROM.h>
#include "LEDController.h"

LEDController::LEDController(int pinRed, int pinGreen, int pinBlue){
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);

  _pin.red = pinRed;
  _pin.green = pinGreen;
  _pin.blue = pinBlue;

  _current.red = 0;
  _current.green = 0;
  _current.blue = 0;

  _current.eepromRedRead = false;
  _current.eepromGreenRead = false;
  _current.eepromBlueRead = false;

  _slot.set = false;
}


float LEDController::getRed(){
  return _current.red;
}


float LEDController::getGreen(){
  return _current.green;
}


float LEDController::getBlue(){
  return _current.blue;
}


bool LEDController::setEEPROMSlots(int slotRed, int slotGreen, int slotBlue){
  if(slotRed > 0 && slotGreen > 0 && slotBlue > 0){
    if(slotRed != slotGreen && slotRed != slotBlue && slotGreen != slotBlue){
      _slot.red = slotRed;
      _slot.green = slotGreen;
      _slot.blue = slotBlue;

      _slot.set = true;

      return _slot.set;
    }
  }
    
  _slot.set = false;
  return _slot.set;
}


int LEDController::getEEPROMSlotRed(){
  if (_slot.set) return _slot.red; else return -1;
}


int LEDController::getEEPROMSlotGreen(){
  if (_slot.set) return _slot.green; else return -1;
}


int LEDController::getEEPROMSlotBlue(){
  if (_slot.set) return _slot.blue; else return -1;
}


float LEDController::getRedFromEEPROM(){
  if (_current.eepromRedRead) return _current.eepromRed;
  if (_slot.set){
    EEPROM.get(_slot.red, _current.eepromRed);
    _current.eepromRedRead = true;
    return _current.eepromRed;
  }

  return -1;
}

