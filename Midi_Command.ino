/**
 * @file      midi_command.ino
 * @brief     midi command
 * @note      
 * @author    shigara
 * @copyright 
 */

#include <MIDI.h>
#include "pin_config.h"

//speed flag
#define SPEED_HALF 0
#define SPEED_FULL 1
//reverse flag
#define REVERSE_OFF 0
#define REVERSE_ON  1

//global
int g_speed_flag = 0;
int g_reverse_flag = 0;

MIDI_CREATE_DEFAULT_INSTANCE();

void SetupMidi(void)
{
    MIDI.begin();
}

//mode 1 Looper
void SendCommandLooper(int i_command_num)
{

  switch(i_command_num){
    case e_loop_rec:// Looper record
      MIDI.sendControlChange(60, 127, 1); 
    break;
    
    case e_loop_play:// Looper play
      MIDI.sendControlChange(61, 127, 1); 
    break;

    case e_loop_stop:// Looper stop
      MIDI.sendControlChange(61, 0, 1); 
    break;

    case e_loop_dubb:// Looper overdub
      MIDI.sendControlChange(60, 0, 1); 
    break;

    case e_loop_speed://looper half/full
      if(g_speed_flag == SPEED_FULL){
        MIDI.sendControlChange(66, 0, 1);//full
        g_speed_flag = SPEED_HALF;
      }else if(g_speed_flag == SPEED_HALF){
        MIDI.sendControlChange(66, 127, 1);//half
        g_speed_flag = SPEED_FULL;
      }
    break;

    case e_loop_reverse:// Looper reverse
      if(g_reverse_flag == REVERSE_OFF){
        MIDI.sendControlChange(65, 0, 1); 
        g_reverse_flag = REVERSE_ON;
      }else if(g_reverse_flag == REVERSE_ON){
        MIDI.sendControlChange(65, 127, 1); 
        g_reverse_flag = REVERSE_OFF;
      }
    break;
  }
}

//mode 2 control
void SendCommandControl(int i_command_num)
{

  switch(i_command_num){
    case e_control_exp1:
      MIDI.sendControlChange(1, 127, 1); 
    break;
    
    case e_control_exp2:
      MIDI.sendControlChange(2, 127, 1); 
    break;

    case e_control_sw1:
      MIDI.sendControlChange(49, 127, 1); 
    break;

    case e_control_sw2:
      MIDI.sendControlChange(50, 127, 1); 
    break;

    case e_control_sw3:
      MIDI.sendControlChange(51, 127, 1); 
    break;

    case e_control_sw4:
      MIDI.sendControlChange(52, 127, 1); 
    break;

    case e_control_sw5:
      MIDI.sendControlChange(53, 127, 1); 
    break;
    
    case e_control_tap:
      MIDI.sendControlChange(64, 127, 1); 
    break;

    case e_control_tuner:
      MIDI.sendControlChange(68, 127, 1); 
    break;
  }
}
