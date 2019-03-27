 /*
 * File:   light.c
 * Author: RRRRRROG
 *
 * Created on 2019?1?4?, ?? 6:41
 */

//change should be simoutaneouly in here and light.c
#define standby 0
#define blank1 1
#define blank2 2
#define fast 3
#define perfect 4
#define slow 5

#include <xc.h>
#include <string.h>
char output[16];
char layer[4];
char cur_scan_layer = 0;
char special_effect_delay = 4; 
volatile char one_or_three_led[3] = {0, 0, 0};//1 or 3
//const int effect_1 [5][4][16] = {  //this is snake  *\~~~~~
//    //0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
//    {{0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
//    {{1,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
//    {{1,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
//    {{1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
//    {{1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}
//};

void reset_output(void)
{
    for(int i = 0; i < 16; ++i)
        output[i] = 1;
}

void set_output(int game_state[3])
{
    //gong 1
    if(cur_scan_layer <= one_or_three_led[0])
        switch(game_state[0])
        {
            case blank1:
                LATDbits.LATD3 = 0;
                LATDbits.LATD2 = 1;
                LATDbits.LATD1 = 1;
                LATDbits.LATD0 = 1;
                break;
            case blank2:
                LATDbits.LATD3 = 1;
                LATDbits.LATD2 = 0;
                LATDbits.LATD1 = 1;
                LATDbits.LATD0 = 1;
                break;
            case fast:
                LATDbits.LATD3 = 1;
                LATDbits.LATD2 = 1;
                LATDbits.LATD1 = 0;
                LATDbits.LATD0 = 1;
                break;
            case perfect:
                LATDbits.LATD3 = 1;
                LATDbits.LATD2 = 1;
                LATDbits.LATD1 = 1;
                LATDbits.LATD0 = 0;
                break;
            case standby:
            case slow:
                LATDbits.LATD3 = 1;
                LATDbits.LATD2 = 1;
                LATDbits.LATD1 = 1;
                LATDbits.LATD0 = 1;
                break;
        }
    else
    {
        LATDbits.LATD3 = 1;
        LATDbits.LATD2 = 1;
        LATDbits.LATD1 = 1;
        LATDbits.LATD0 = 1;
    }
    //drum light
    if (cur_scan_layer <= one_or_three_led[1])
        switch (game_state[1]) {
            case blank1:
                LATDbits.LATD7 = 0;
                LATDbits.LATD6 = 1;
                LATDbits.LATD5 = 1;
                LATDbits.LATD4 = 1;
                LATAbits.LATA3 = 0;
                LATAbits.LATA2 = 1;
                LATAbits.LATA1 = 1;
                LATAbits.LATA0 = 1;
                break;
            case blank2:
                LATDbits.LATD7 = 1;
                LATDbits.LATD6 = 0;
                LATDbits.LATD5 = 1;
                LATDbits.LATD4 = 1;
                LATAbits.LATA3 = 1;
                LATAbits.LATA2 = 0;
                LATAbits.LATA1 = 1;
                LATAbits.LATA0 = 1;
                break;
            case fast:
                LATDbits.LATD7 = 1;
                LATDbits.LATD6 = 1;
                LATDbits.LATD5 = 0;
                LATDbits.LATD4 = 1;
                LATAbits.LATA3 = 1;
                LATAbits.LATA2 = 1;
                LATAbits.LATA1 = 0;
                LATAbits.LATA0 = 1;
                break;
            case perfect:
                LATDbits.LATD7 = 1;
                LATDbits.LATD6 = 1;
                LATDbits.LATD5 = 1;
                LATDbits.LATD4 = 0;
                LATAbits.LATA3 = 1;
                LATAbits.LATA2 = 1;
                LATAbits.LATA1 = 1;
                LATAbits.LATA0 = 0;
                break;
            case standby:
            case slow:
                LATDbits.LATD7 = 1;
                LATDbits.LATD6 = 1;
                LATDbits.LATD5 = 1;
                LATDbits.LATD4 = 1;
                LATAbits.LATA3 = 1;
                LATAbits.LATA2 = 1;
                LATAbits.LATA1 = 1;
                LATAbits.LATA0 = 1;
                break;
        }
    else
    {
        LATDbits.LATD7 = 1;
        LATDbits.LATD6 = 1;
        LATDbits.LATD5 = 1;
        LATDbits.LATD4 = 1;
        LATAbits.LATA3 = 1;
        LATAbits.LATA2 = 1;
        LATAbits.LATA1 = 1;
        LATAbits.LATA0 = 1;      
    }
    //gong 2
    if (cur_scan_layer <= one_or_three_led[2])
        switch (game_state[2]) {
            case blank1:
                LATAbits.LATA7 = 0;
                LATAbits.LATA6 = 1;
                LATAbits.LATA5 = 1;
                LATAbits.LATA4 = 1;
                break;
            case blank2:
                LATAbits.LATA7 = 1;
                LATAbits.LATA6 = 0;
                LATAbits.LATA5 = 1;
                LATAbits.LATA4 = 1;
                break;
            case fast:
                LATAbits.LATA7 = 1;
                LATAbits.LATA6 = 1;
                LATAbits.LATA5 = 0;
                LATAbits.LATA4 = 1;
                break;
            case perfect:
                LATAbits.LATA7 = 1;
                LATAbits.LATA6 = 1;
                LATAbits.LATA5 = 1;
                LATAbits.LATA4 = 0;
                break;
            case standby:
            case slow:
                LATAbits.LATA7 = 1;
                LATAbits.LATA6 = 1;
                LATAbits.LATA5 = 1;
                LATAbits.LATA4 = 1;
                break;
        }
    else
    {
        LATAbits.LATA7 = 1;
        LATAbits.LATA6 = 1;
        LATAbits.LATA5 = 1;
        LATAbits.LATA4 = 1;
    }
}


void whole_layer_shine(int state)
{
    if(state % 4== cur_scan_layer)
        memset(output, 0, sizeof output);
}

void shine_1_layer(void)
{ 
    for(int i = 0; i < 4; ++i)
        layer[i] = 0;
    layer[cur_scan_layer] = 1;
    cur_scan_layer = (cur_scan_layer + 1) % 4;
}

void assign_light(void)
{
    //right hand side
//    LATDbits.LD0 = output[0];
//    LATDbits.LD1 = output[1];
//    LATDbits.LD2 = output[2];
//    LATDbits.LD3 = output[3];
//    LATDbits.LD4 = output[4];
//    LATDbits.LD5 = output[5];
//    LATDbits.LD6 = output[6];
//    LATDbits.LD7 = output[7];
//    //left hand side
//    LATAbits.LA0 = output[8];
//    LATAbits.LA1 = output[9];
//    LATAbits.LA2 = output[10];
//    LATAbits.LA3 = output[11];
//    LATAbits.LA4 = output[12];
//    LATAbits.LA5 = output[13];
//    LATAbits.LA6 = output[14];
//    LATAbits.LA7 = output[15];
    //horizontal layer
    LATCbits.LC0 = layer[0];
    LATCbits.LC1 = layer[1];
    LATCbits.LC2 = layer[2];
    LATCbits.LC3 = layer[3];
}

void init_cube(void)
{
    for(int i = 0; i < 16; i++)
        output[i] = 0;
    memset(layer, 0, sizeof layer);
    layer[0] = layer[1] = layer[2] = layer[3] = 1;
   
    assign_light();
}