/**
 * @file      Control.ino
 * @brief     LED midi Switch
 * @note      
 * @author    shigara
 * @copyright 
 */
#include "pin_config.h"

enum e_control_mode
{
  e_control_none = 0,
  e_control_normal = 1,
  e_control_looper = 2
};

typedef struct SW_command_info
{
  int i_switch_num;
  int i_looper_command_num;
  int i_control_command_num;
}SW_command_info;

static const SW_command_info c_SW_command_table [6]=
{
  {1,e_loop_rec,e_control_tuner},
  {2,e_loop_play,e_control_tuner},
  {3,e_loop_stop,e_control_sw4},
  {4,e_loop_dubb,e_control_tap},
  {5,e_loop_speed,e_control_tap},
  {6,e_loop_reverse,e_control_sw5}
};

static int g_control_mode = e_control_normal;

void SetupControl(void)
{
  SetupButton();
  SetupLED();
  SetupMidi();
  StartControlLED(e_SLOW);
  g_control_mode = e_control_normal;
}

void ControlMain(void)
{
  int i_button_num = 0;
  int i_command_num = 0;
  int i_change_flag = 0;

  i_change_flag = GetSWInfo();
  if(i_change_flag == 1){
    ToggleControlMode();
  }

  i_button_num  = GetButtonInfo();
  if(i_button_num  < 0){
    return;
  }
  
  if(g_control_mode == e_control_looper){
    SendCommandLooper(c_SW_command_table[i_button_num].i_looper_command_num);
  }else if(g_control_mode == e_control_normal){
    SendCommandControl(c_SW_command_table[i_button_num].i_control_command_num);
  }
}

void ToggleControlMode(void)
{
    if(g_control_mode == e_control_normal ){
    g_control_mode = e_control_looper;
    StartControlLED(e_FAST);

  }else{
    g_control_mode = e_control_normal;
    StartControlLED(e_SLOW);
  }
}
