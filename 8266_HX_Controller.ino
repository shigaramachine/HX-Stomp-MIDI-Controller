/**
 * @file      8622_hx_switcher.ino
 * @brief     main
 * @note      ESP8266
 * @author    shigara
 * @copyright 
 */

#include "pin_config.h"

void setup(){
  // Serial port for debugging purposes 
  // When you debug programming, stop the midi process.

  //Serial.begin(115200);
  //Serial.println("Start Setup");
  pinMode(LED_BUILTIN, OUTPUT);
  
  SetupControl();
  
  SetupWLAN();
}
 
void loop(){
  ControlMain();
  
}
