/*
 * LEDController(int portRed, int portGreen, int portBlue);
 *  Init
 * 
 * LEDController.getRed();
 * LEDController.getGreen();
 * LEDController.getBlue();
 *  Returns the individual Color wert
 *  
 * LEDController.getRedFromEEPROM();
 * LEDController.getRedFromEEPROM();
 * LEDController.getRedFromEEPROM();
 *  Returns the specific color after the reading from eeprom or writing to it
 * 
 * LEDController.setColor(float red, float green, float blue);
 *  Set the color and than show it on the LED strip
 * 
 * LEDController.saveToEEPROM();
 *  Saves the current color to the EEPROM
 *  
 * LEDController.fade1(float speed);
 * LEDController.fade2(float speed);
 *  Start color fade and/or change the Speed of the fade
 *  Speed = x complete Changes per Minute
 * LEDController.fadePause();
 *  Pause fade and stop at the current color
 * LEDController.fadeStop();
 *  Returns to single color mode
 * LEDController.setFadeSpeed(float speed);
 *  Just edit Speed of the Fade (Fade will not be acticated throu this)
 * LEDController.getFadeSpeed();
 *  Get Speed of the Fade
 *  
 * LEDController.getBrightness();
 *  Get current brighntess;
 * LEDController.setBrightness(float Brightness);
 *  Set Brightness
 *  
 * LEDController.setRandomColor();
 *  Sets a random color
 * LEDController.setRandomBrightness();
 *  Sets a random Brightness
 *  
 * LEDController.instantRed();
 * LEDController.instantGreen();
 * LEDController.instantBlue();
 * LEDController.instantYellow();
 * LEDController.instantViolett();
 * LEDController.instantMagenta();
 * LEDController.instantBabyblue();
 *  Show the named color instantly
 * 
 * LEDController.work();
 *  !!!Has to be called min once per loop!!!
 *  If not, fade would be not funktional
 *  (just put it on the beginning of your loop, so you won't have any trouble)
 * 
 * 
 * Private:
 * 
 */
