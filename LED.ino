/**
 * @file      LED.ino
 * @brief     LED control
 * @note      
 * @author    shigara
 * @copyright 
 */

#include <Ticker.h>
#include "pin_config.h"

#define d_LED_port D8

Ticker LED_Control;

void SetupLED(void)
{
  pinMode(d_LED_port, OUTPUT);
  digitalWrite(d_LED_port, LOW); 
}

static void ControlPWMWidth() 
{

  static int flag = 0;
  static int count = 0;

  //increase PWM width
  if(flag == 0){
      ++count;
      if(count == 100){
        flag = 1;
      }
  }else{//decrease PWM width
      --count;
      if(count == 0){
        flag = 0;
      }
  }

  analogWrite(d_LED_port, count);
}

void StartControlLED(int LED_Pattern)
{ 
  switch(LED_Pattern)
  {
    case e_OFF:
      analogWrite(d_LED_port, 0);
    break;

    case e_ON:
      analogWrite(d_LED_port, 100);
    break;

    case e_SLOW:
      LED_Control.attach(0.015, ControlPWMWidth);
    break;

    case e_FAST:
      LED_Control.attach(0.001, ControlPWMWidth);
    break;

  }

}

void ToggleBuildInLED_DBG(void)
{ 
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
