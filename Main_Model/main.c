#include "setting_hardaware/setting.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"

//change should be simoutaneouly in here and light.c
#define standby 0
#define blank1 1
#define blank2 2
#define fast 3
#define perfect 4
#define slow 5

void set_state(void);
//volatile int beats_count = 0;
//shine whole layer while ready to hit
volatile int hit_state_count[3] = {0, 0, 0};
//char *choose_difficulty;

void main(void) 
{
    SYSTEM_Initialize() ;
    init_cube();
//    int *which_music;
    char *which_music_wait;
    int which_music_num;

    //choose music
//    which_music = music_1_notes;
    choose_difficulty = music_1_hit_trigger_ez;
    which_music_wait = music_1_wait;
    which_music_num = music_1_notes_number;
    while(1)
    {
        while(singing_flag)
        {
            while(beats_count != which_music_wait[cur_note]);
            //PIC 2 change note
            LATCbits.LC4 = 1;
            beats_count = 0;
            cur_note++;
            cur_note %= which_music_num;   
            for(int i = 0; i < 100; i++);
            LATCbits.LC4 = 0;
        }
    }
    return;
}

// old version: 
// void interrupt high_priority Hi_ISR(void)
void __interrupt(high_priority) Hi_ISR(void)
{
    //gong hit interupt
    if(INT0IF)
    {
//        UART_Write_Text("hi\n\r");
        if(hit_timing[0] == 1 || hit_timing[0] == 2)
        {
            switch(game_state[0])
            {
                case standby:
                    break;
                case blank1:
                    break;
                case blank2:
                    break;
                case fast:
                    LATEbits.LE0 = 1;
                    UART_Write_Text("gong1 fast\n\r");
                    --hit_timing[0];
                    LATEbits.LE0 = 0;
                    break;
                case perfect:
                    LATEbits.LE1 = 1;
                    UART_Write_Text("gong1 perfect\n\r");
                    --hit_timing[0];
                    LATEbits.LE1 = 0;
                    break;
                case slow:
                    LATEbits.LE2 = 1;
                    UART_Write_Text("gong1 slow\n\r");
                    --hit_timing[0];
                    LATEbits.LE2 = 0;
                    break;
            }
        }
        INT0IF = 0;
    }
    //drum hit interupt
    if(INT1IF)
    {
        if(hit_timing[1] == 1 || hit_timing[1] == 2)
        {
            switch(game_state[1])
            {
                case standby:
                    break;
                case blank1:
                    break;
                case blank2:
                    break;
                case fast:
                    LATEbits.LE0 = 1;
                    UART_Write_Text("drum fast\n\r");
                    --hit_timing[1];
                    if(!hit_timing[1])
                        LATBbits.LB5 = 0;
                    LATEbits.LE0 = 0;
                    break;
                case perfect:
                    LATEbits.LE1 = 1;
                    UART_Write_Text("drum perfect\n\r");
                    --hit_timing[1];
                    if(!hit_timing[1])
                        LATBbits.LB5 = 0;
                    LATEbits.LE1 = 0;
                    break;
                case slow:
                    LATEbits.LE2 = 1;
                    UART_Write_Text("drum slow\n\r");
                    --hit_timing[1];
                    if(!hit_timing[1])
                        LATBbits.LB5 = 0;
                    LATEbits.LE2 = 0;
                    break;
            }
        }
        INT1IF = 0;
    }
    //gong hit interupt
    if(INT2IF)
    {   
//        UART_Write_Text("AA\n\r");
        if(hit_timing[2] == 1 || hit_timing[2] == 2)
        {
            switch(game_state[2])
            {
                case standby:
                    break;
                case blank1:
                    break;
                case blank2:
                    break;
                case fast:
                    LATEbits.LE0 = 1;
                    UART_Write_Text("gong2 fast\n\r");
                    --hit_timing[2];
                    LATEbits.LE0 = 0;
                    break;
                case perfect:
                    LATEbits.LE1 = 1;
                    UART_Write_Text("gong2 perfect\n\r");
                    --hit_timing[2];
                    LATEbits.LE1 = 0;
                    break;
                case slow:
                    LATEbits.LE2 = 1;
                    UART_Write_Text("gong2 slow\n\r");
                    --hit_timing[2];
                    LATEbits.LE2 = 0;
                    break;
            }
        }
        LATEbits.LE0 = 0;
        INT2IF = 0;
    }
    //count beats delay
    //and detect music trigger
    if(TMR0IF)
    {
        //note count change
        if(singing_flag == 1)
        {
            //note count change
            beats_count++;
            //triger change
            trigger_count = (trigger_count + 1) % trigger_num;
            //music trigger
            if (choose_difficulty[trigger_count] == 11 ||
                choose_difficulty[trigger_count] == 12)
            {
                game_state[0] = blank1;
                if(choose_difficulty[trigger_count] == 11)
                {
                    hit_timing[0] = 3;
                    one_or_three_led[0] = 1;
                }
                else
                {
                    hit_timing[0] = 4;
                    one_or_three_led[0] = 3;
                }
//                LATDbits.LATD3 = 0;
//                LATDbits.LATD2 = 1;
//                LATDbits.LATD1 = 1;
//                LATDbits.LATD0 = 1;
//                UART_Write_Text("gong start\n\r");
                hit_state_count[0] = 0;
            }
            else if (choose_difficulty[trigger_count] == 21 ||
                     choose_difficulty[trigger_count] == 22)
            {
                game_state[1] = blank1;
                if(choose_difficulty[trigger_count] == 21)
                {
                    hit_timing[1] = 3;
                    one_or_three_led[1] = 1;
                }
                else
                {
                    hit_timing[1] = 4;
                    one_or_three_led[1] = 3;
                }
//                LATDbits.LATD7 = 0;
//                LATDbits.LATD6 = 1;
//                LATDbits.LATD5 = 1;
//                LATDbits.LATD4 = 1;
//                LATAbits.LATA3 = 0;
//                LATAbits.LATA2 = 1;
//                LATAbits.LATA1 = 1;
//                LATAbits.LATA0 = 1;
//                UART_Write_Text("drum start\n\r");
                hit_state_count[1] = 0;
            } 
            else if (choose_difficulty[trigger_count] == 31 ||
                       choose_difficulty[trigger_count] == 32) 
            {
                game_state[2] = blank1;
                if(choose_difficulty[trigger_count] == 31)
                {
                    hit_timing[2] = 3;
                    one_or_three_led[2] = 1;
                }
                else
                {
                    hit_timing[2] = 4;
                    one_or_three_led[2] = 3;
                }
//                LATAbits.LATA7 = 0;
//                LATAbits.LATA6 = 1;
//                LATAbits.LATA5 = 1;
//                LATAbits.LATA4 = 1;
//                UART_Write_Text("gong2 start\n\r");
                hit_state_count[2] = 0;
            }
        }
        TMR0 = 28036;
        TMR0IF = 0;
    }
    
    //change state
    if(TMR1IF)
    {
        if(singing_flag == 1)
            set_state();
        
        TMR1 = 28036;  //0.15 seconds
        TMR1IF = 0;
    }
    
    //cube shining
    if(TMR2IF)
    {
        TRISA = 0b11111111;
        TRISD = 0b11111111;
        set_output(game_state);
        shine_1_layer();
        assign_light();
        TRISA = 0b00000000;
        TRISD = 0b00000000;
        TMR2IF = 0;
    }
    //singing
    if(PIR2bits.CCP2IF)
    {
        TMR3 = 0;
        CCP2IF = 0;
    }

}

void set_state(void) {
    //hit_state_count only be resetted to 0, being able to reach 2 
    ++hit_state_count[0];
    ++hit_state_count[1];
    ++hit_state_count[2];
    //gong 1
    if(hit_state_count[0] == 2)  
    {
        switch (game_state[0]) {
            case standby:
                game_state[0] = standby;
                break;
            case blank1:
                game_state[0] = blank2;
//                LATDbits.LATD3 = 1;
//                LATDbits.LATD2 = 0;
                --hit_timing[0];
                break;
            case blank2:
                game_state[0] = fast;
//                LATDbits.LATD2 = 1;
//                LATDbits.LATD1 = 0;
                --hit_timing[0];
                break;
            case fast:
                game_state[0] = perfect;
//                LATDbits.LATD1 = 1;
//                LATDbits.LATD0 = 0;
                break;
            case perfect:
                game_state[0] = slow;
//                LATDbits.LATD0 = 1;
                break;
            case slow:
                game_state[0] = standby;
//                UART_Write_Text("gong go to standby\n\r");
                hit_timing[0] = 0;
                break;
        }
        hit_state_count[0] = 0;
    }
    //drum
    if(hit_state_count[1] == 2)
    {
        switch (game_state[1]) {
            case standby:
                game_state[1] = standby;
                break;
            case blank1:
                game_state[1] = blank2;
//                LATDbits.LATD7 = 1;
//                LATDbits.LATD6 = 0;
//                LATAbits.LATA3 = 1;
//                LATAbits.LATA2 = 0;
                --hit_timing[1];
                break;
            case blank2:
                game_state[1] = fast;
//                LATDbits.LATD6 = 1;
//                LATDbits.LATD5 = 0;
//                LATAbits.LATA2 = 1;
//                LATAbits.LATA1 = 0;
                --hit_timing[1];
                LATBbits.LB5 = 1;
                break;
            case fast:
                game_state[1] = perfect;
//                LATDbits.LATD5 = 1;
//                LATDbits.LATD4 = 0;
//                LATAbits.LATA1 = 1;
//                LATAbits.LATA0 = 0;
                break;
            case perfect:
                game_state[1] = slow;
//                LATDbits.LATD4 = 1;
//                LATAbits.LATA0 = 1;
                break;
            case slow:
                game_state[1] = standby;
//                UART_Write_Text("drum go to standby\n\r");
                hit_timing[1] = 0;
                LATBbits.LB5 = 0;
                break;
        }
        hit_state_count[1] = 0;
    }
    //gong 2
    if(hit_state_count[2])
    {
        switch (game_state[2]) {
            case standby:
                game_state[2] = standby;
                break;
            case blank1:
                game_state[2] = blank2;
//                LATAbits.LATA7 = 1;
//                LATAbits.LATA6 = 0;
                --hit_timing[2];
                break;
            case blank2:
                game_state[2] = fast;
//                LATAbits.LATA6 = 1;
//                LATAbits.LATA5 = 0;
                --hit_timing[2];
                break;
            case fast:
                game_state[2] = perfect;
//                LATAbits.LATA5 = 1;
//                LATAbits.LATA4 = 0;
                break;
            case perfect:
                game_state[2] = slow;
//                LATAbits.LATA4 = 1;
                break;
            case slow:
                game_state[2] = standby;
//                UART_Write_Text("gong2 go to standby\n\r");
                hit_timing[2] = 0;
                break;
        }
    hit_state_count[2] = 0;
    }
}