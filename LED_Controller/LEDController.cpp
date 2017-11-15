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
  _current.brightness = 1;

  _current.eepromRedRead = false;
  _current.eepromGreenRead = false;
  _current.eepromBlueRead = false;

  _slot.set = false;

  return;
}


void LEDController::writeColor(float red, float green, float blue, float brightness){
  analogWrite(_pin.red * brightness * 255, red);
  analogWrite(_pin.green * brightness * 255, green);
  analogWrite(_pin.blue * brightness * 255, blue);

  return;
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


bool LEDController::setEEPROMSlots(int slotRed, int slotGreen, int slotBlue, int slotBrightness){
  if(slotRed >= 0 && slotGreen >= 0 && slotBlue >= 0 && slotBrightness >= 0){
    if((slotRed != slotGreen && slotRed != slotBlue && slotRed != slotBrightness) && (slotGreen != slotBlue && slotGreen != slotBrightness) && (slotBlue != slotBrightness)){
      _slot.red = slotRed;
      _slot.green = slotGreen;
      _slot.blue = slotBlue;
      _slot.brightness = slotBrightness;

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


float LEDController::getGreenFromEEPROM(){
  if (_current.eepromGreenRead) return _current.eepromGreen;
  if (_slot.set){
    EEPROM.get(_slot.green, _current.eepromGreen);
    _current.eepromGreenRead = true;
    return _current.eepromGreen;
  }

  return -1;
}


float LEDController::getBlueFromEEPROM(){
  if (_current.eepromBlueRead) return _current.eepromBlue;
  if (_slot.set){
    EEPROM.get(_slot.blue, _current.eepromBlue);
    _current.eepromBlueRead = true;
    return _current.eepromBlue;
  }

  return -1;
}


float LEDController::getBrightnessFromEEPROM(){
  if (_current.eepromBrightnessRead) return _current.eepromBrightness;
  if (_slot.set){
    EEPROM.get(_slot.brightness, _current.eepromBrightness);
    _current.eepromBrightnessRead = true;
    return _current.eepromBrightness;
  }

  return -1;
}


bool LEDController::forceReloadFromEEPROM(){
  if(_slot.set){
    EEPROM.get(_slot.red, _current.eepromRed);
    _current.eepromRedRead = true;

    EEPROM.get(_slot.green, _current.eepromGreen);
    _current.eepromGreenRead = true;

    EEPROM.get(_slot.blue, _current.eepromBlue);
    _current.eepromBlueRead = true;

    EEPROM.get(_slot.brightness, _current.eepromBrightness);
    _current.eepromBrightnessRead = true;

    return true;
  }

  return false;
}


void LEDController::setColor(float red, float green, float blue){
  this->writeColor(red, green, blue, _current.brightness);

  _current.red = red;
  _current.green = green;
  _current.blue = blue;

  return;
}


void LEDController::setColor(float red, float green, float blue, float brightness){
  this->writeColor(red, green, blue, brightness);

  _current.red = red;
  _current.green = green;
  _current.blue = blue;
  _current.brightness = brightness;

  return;
}


bool LEDController::setFromEEPROM(){
  if(this->getRedFromEEPROM() == -1) return false;
  if(this->getGreenFromEEPROM() == -1) return false;
  if(this->getBlueFromEEPROM() == -1) return false;
  if(this->getBrightnessFromEEPROM() == -1) return false;

  this->setColor(_current.eepromRed, _current.eepromGreen, _current.eepromBlue, _current.eepromBrightness);
  return true;
}


void LEDController::saveToEEPROM(float red, float green, float blue, float brightness){
  EEPROM.put(_slot.red, red);
  EEPROM.put(_slot.green, green);
  EEPROM.put(_slot.blue, blue);
  EEPROM.put(_slot.brightness, brightness);

  return;
}


void LEDController::saveCurrentToEEPROM(){
  this->saveToEEPROM(_current.red, _current.green, _current.blue, _current.brightness);

  return;
}


void LEDController::saveToEEPROM(){
  this->saveCurrentToEEPROM();

  return;
}

