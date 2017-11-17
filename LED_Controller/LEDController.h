#ifndef LEDController_h
#define LEDController_h

class LEDController
{
  public:
    LEDController(int pinRed, int pinGreen, int pinBlue);

    float getRed();       //
    float getGreen();     //
    float getBlue();      //
    bool setEEPROMSlots(int slotRed, int slotGreen, int slotBlue, int slotBrightness);  //
    int getEEPROMSlotRed();   //
    int getEEPROMSlotGreen(); //
    int getEEPROMSlotBlue();  //
    float getRedFromEEPROM();   //
    float getGreenFromEEPROM(); //
    float getBlueFromEEPROM();  //
    float getBrightnessFromEEPROM(); //
    bool forceReloadFromEEPROM(); //
    void setColor(float red, float green, float blue); //
    void setColor(float red, float green, float blue, float brightness); //
    bool setFromEEPROM(); //
    void saveToEEPROM(float red, float green, float blue, float brightness);  //
    void saveToEEPROM(); //
    void saveCurrentToEEPROM(); //
    void fade1(float speed); //
    void fade1(); //
    void fade2(float speed); //
    void fade2(); //
    void fadeStop(); //
    void setFadeSpeed(float speed); //
    float getFadeSpeed(); //
    float getBrightness(); //
    void setBrightness(float brightness); //
    void setRandomColor(); //
    void setRandomBrightness(); //
    bool setResolution(float resolution); //

    void fadeWork();

  private:
    void writeColor();
    float makeRight(float var);
    void startFade();
    void doFade1();
    void doFade2();

    float _resolution;

    struct _pin {
      int red, green, blue;
    } _pin;

    struct _slot {
      int red, green, blue, brightness;
      bool set;
    } _slot;

    struct _current {
      float red, green, blue, brightness;
      float eepromRed, eepromGreen, eepromBlue, eepromBrightness;
      bool eepromRedRead, eepromGreenRead, eepromBlueRead, eepromBrightnessRead;
    } _current;

    struct _fade {
      float speed, delta;
      int mode, lastTime, deltaTime, count;
      bool active;
    } _fade;
};

#endif
