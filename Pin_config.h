#ifndef _CONFIG_H_
#define _CONFIG_H_

#define PIN_WIRE_SDA (4)
#define PIN_WIRE_SCL (5)

#define D0    16
#define D1    5
#define D2    4
#define D3    0
#define D4    2
#define D5    14
#define D6    12
#define D7    13
#define D8    15
#define D9    3
#define D10   1

enum e_loop_command
{
    e_loop_rec = 1,
    e_loop_play = 2,
    e_loop_stop = 3,
    e_loop_dubb = 4,
    e_loop_speed = 5,
    e_loop_reverse = 6
};

enum e_control_command
{
    e_control_sw1 = 1,
    e_control_sw2 = 2,
    e_control_sw3 = 3,
    e_control_sw4 = 4,
    e_control_sw5 = 5,
    e_control_exp1 = 6,
    e_control_exp2 = 7,
    e_control_tuner = 8,
    e_control_tap = 9
};

enum e_LED_pattern
{
  e_OFF = 0,
  e_ON = 1,
  e_SLOW = 2,
  e_FAST = 3
};

#endif
