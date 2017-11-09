/*
 * LEDControler(int portRed, int portBlue, int portGreen);
 *  Init
 * 
 * LEDControler.getRed();
 * LEDControler.getBlue();
 * LEDControler.getGreen();
 *  Returns the individual Color wert
 *  
 * LEDControler.getRedFromEEPROM();
 * LEDControler.getRedFromEEPROM();
 * LEDControler.getRedFromEEPROM();
 *  Returns the specific color after the reading from eeprom or writing to it
 * 
 * LEDControler.setColor(float red, float green, float blue);
 *  Set the color and than show it on the LED strip
 * 
 * LEDControler.saveToEEPROM();
 *  Saves the current color to the EEPROM
 *  
 * LEDControler.fade1(float speed);
 * LEDControler.fade2(float speed);
 *  Start color fade and/or change the Speed of the fade
 *  Speed = x complete Changes per Minute
 * LEDControler.fadePause();
 *  Pause fade and stop at the current color
 * LEDControler.fadeStop();
 *  Returns to single color mode
 * LEDControler.setFadeSpeed();
 *  Just edit Speed of the Fade (Fade will not be acticated throu this)
 * LEDControler.getFadeSpeed();
 *  Get Speed of the Fade
 *  
 * LEDControler.getBrightness();
 *  Get current brighntess;
 * LEDControler.setBrightness(float Brightness);
 *  Set Brightness
 *  
 * LEDControler.setRandomColor();
 *  Sets a random color
 * LEDControler.setRandomBrightness();
 *  Sets a random Brightness
 *  
 * LEDControler.instantRed();
 * LEDControler.instantGreen();
 * LEDControler.instantBlue();
 * LEDControler.instantYellow();
 * LEDControler.instantViolett();
 * LEDControler.instantMagenta();
 * LEDControler.instantBabyblue();
 *  Show the named color instantly
 * 
 * LEDControler.do();
 *  !!!Has to be called min once per loop!!!
 *  If not, fade would be not funktional
 *  (just put it on the beginning of your loop, so you won't have any trouble)
 */
