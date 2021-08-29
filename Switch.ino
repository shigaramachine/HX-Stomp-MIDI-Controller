/**
 * @file      switch.ino
 * @brief     switch setting
 * @note      
 * @author    shigara
 * @copyright 
 */

#include <Bounce2.h>
#include "pin_config.h"

#define BOUNCE_WITH_PROMPT_DETECTION

//button define
#define NUM_BUTTONS 6

//button settings
Bounce * g_buttons = new Bounce[NUM_BUTTONS];

/*
4 5 6
1 2 3
*/

//
Bounce * g_sw = new Bounce[1];

//
void SetupButton(void)
{
    //convert mpu pins
    const uint8_t c_button_pins[NUM_BUTTONS] = {D1,D2,D3,D5,D6,D7};
    
    //setup the bounce instance for the current button
    for (int i = 0; i < NUM_BUTTONS; i++) {
        g_buttons[i].attach( c_button_pins[i] , INPUT_PULLUP);
        g_buttons[i].interval(5);
    }
    //setup mode change SW
    g_sw[0].attach(D0,INPUT_PULLUP);
    g_sw[0].interval(10);

    return;
}

//
int GetButtonInfo(void)
{
    //single button detect
    for (int j = 0; j < NUM_BUTTONS; j++){
        g_buttons[j].update();
        if (g_buttons[j].fell()){
            //Serial.println("button fell");
            //Serial.println(j);
            return(j);
        }
    }
    //Serial.println("NoButton");
    return(-1);
}

//
int GetSWInfo(void)
{
    int result = 0;
    g_sw[0].update();
    if(g_sw[0].changed() == 1){
        result = 1;
    }
    return result;
})
