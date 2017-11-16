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

  _fade.active = false;
  _fade.speed = 1;

  _resolution = 255.0;

  return;
}


void LEDController::writeColor(){
  analogWrite(_pin.red, _current.red * _current.brightness * _resolution);
  analogWrite(_pin.green, _current.green * _current.brightness * _resolution);
  analogWrite(_pin.blue, _current.blue * _current.brightness * _resolution);

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
  _current.red = this->makeRight(red);
  _current.green = this->makeRight(green);
  _current.blue = this->makeRight(blue);

  this->writeColor();

  return;
}


void LEDController::setColor(float red, float green, float blue, float brightness){
  _current.brightness = this->makeRight(brightness);
  
  this->setColor(red, green, blue);

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


void LEDController::fade1(float speed){
  _fade.speed = speed;
  
  this->fade1();

  return;
}


void LEDController::fade1(){
  _fade.mode = 1;
  
  this->startFade();

  return;
}


void LEDController::fade2(float speed){
  _fade.speed = speed;

  this->fade2();

  return;
}


void LEDController::fade2(){
  _fade.mode = 2;

  this->startFade();

  return;
}


void LEDController::startFade(){
  _fade.active = true;
  _fade.pause = false;
  _fade.lastTime = millis();
  
  this->setColor(1, 1, 1);
}


void LEDController::fadePause(){
  this->fadePause(true);

  return;
}


void LEDController::fadePause(bool pause){
  if(_fade.active) _fade.pause = true;

  return;
}


void LEDController::fadeStop(){
  _fade.active = false;

  return;
}


void LEDController::setFadeSpeed(float speed){
  _fade.speed = speed;

  return;
}


float LEDController::getFadeSpeed(){
  return _fade.speed;
}


float LEDController::getBrightness(){
  return _current.brightness;
}


void LEDController::setBrightness(float brightness){
  _current.brightness = this->makeRight(brightness);

  return;
}


void LEDController::setRandomColor(){
  randomSeed(micros());
  _current.red = random(0, 1000) / 1000.0;
  
  randomSeed(micros()+1);
  _current.green = random(0, 1000) / 1000.0;
  
  randomSeed(micros()+2);
  _current.blue = random(0, 1000) / 1000.0;

  this->writeColor();
}


void LEDController::setRandomBrightness(){
  randomSeed(micros());
  _current.brightness = random(0, 1000) / 1000.0;

  this->writeColor();
}


bool LEDController::setResolution(float resolution){
  if(resolution > 0){
    _resolution = resolution;

    this->writeColor();
    
    return true;
  }

  return false;
}


void LEDController::fadeWork(){
  if(_fade.mode = 1){
    
  }

  if(_fade.mode = 2){
    
  }
}
