#ifndef LEDController_h
#define LEDController_h

class LEDController
{
  public:
    LEDController(int pinRed, int pinGreen, int pinBlue);

    float getRed();       //
    float getGreen();     //
    float getBlue();      //
    bool setEEPROMSlots(int slotRed, int slotGreen, int slotBlue);  //
    int getEEPROMSlotRed();   //
    int getEEPROMSlotGreen(); //
    int getEEPROMSlotBlue();  //
    float getRedFromEEPROM(); 
    float getGreenFromEEPROM();
    float getBlueFromEEPROM();
    void setColor(float red, float green, float blue);
    void setFromEEPROM();
    void saveToEEPROM();
    void fade1(float speed);
    void fade2(float speed);
    void fadePause();
    void fadeStop();
    void setFadeSpeed(float speed);
    float getFadeSpeed();
    float getBrightness();
    void setBrightness(float brightness);
    void setRandomColor();
    void setRandomBrightness();

    void work();
    
  private:
    struct _pin {
      int red, green, blue;
    } _pin;

    struct _slot {
      int red, green, blue;
      bool set;
    } _slot;

    struct _current {
      float red, green, blue;
      float eepromRed, eepromGreen, eepromBlue;
      bool eepromRedRead, eepromGreenRead, eepromBlueRead;
    } _current;
};

#endif
