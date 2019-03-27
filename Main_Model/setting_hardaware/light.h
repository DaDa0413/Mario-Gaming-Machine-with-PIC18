#ifndef _LIGHT_H
#define _LIGHT_H

extern char output[16];
extern char layer[4];
extern char cur_scan_layer;
extern char special_effect_delay; 
extern volatile char one_or_three_led[3];
void reset_output(void);
void set_output(int game_state[3]);
void whole_layer_shine(int state);
void shine_1_layer(void);
void assign_light(void);
void init_cube(void);

#endif