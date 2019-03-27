#ifndef _UART_H
#define _UART_H
#define trigger_num 488
void UART_Initialize(void);
char * GetString();
void UART_Write(unsigned char data);
void UART_Write_Text(char* text);
void ClearBuffer();
void MyusartRead();

extern volatile int input_difficulty;
extern volatile char which_difficulty;
extern volatile int beats_count;
extern volatile int singing_flag;
extern volatile int cur_note;
extern volatile int trigger_count;
extern volatile int hit_timing[3];
extern int game_state[3];
extern char music_1_hit_trigger_ez[trigger_num];
extern char music_1_hit_trigger_hard[trigger_num];
extern char *choose_difficulty;
#endif