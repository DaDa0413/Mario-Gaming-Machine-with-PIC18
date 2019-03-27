#include <xc.h>
#include <string.h>
    //setting TX/RX

char mystring[10];
int lenStr = 0;
volatile int input_difficulty = 0;
volatile char which_difficulty = '0';
volatile int beats_count = 0;
volatile int singing_flag = 0;
volatile int cur_note = 0;
volatile int trigger_count = -1;
volatile int hit_timing[3] = {1, 1, 1};
int game_state[3] = {0, 0, 0};
char *choose_difficulty;


//winnie new here////////////////////////////////////////////////  
//EZ
char music_1_hit_trigger_ez[488] = {
  //1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //1-1
    0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, //1-2
    0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 11, 0, 0, 0, 0, 0, //1-3
    
    0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, //2-1
    0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, //2-2
    0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, //2-3
    
    0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, //3-1
    0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //3-2
    11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, //3-3
    
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, //4-1
    0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //4-2
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, //4-3
    
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, //5-1
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, //5-2
    0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //5-3
    
    0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, //6-1
    0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, //6-2
    0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //6-3
    
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0,//7-1
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, //7-2
    0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 31, 0, 0,//7-3
    
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, //8-1
    0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, //8-2
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, //8-3
    
    0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, //9-1
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, //9-2
    0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 21, 0, 0,//9-3
    
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, //10-1
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 11, 0, 0,//10-2

};
     //hard
char music_1_hit_trigger_hard[488] = {
  //1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22
    0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //1-1
    0, 0, 0, 22, 0, 32, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, //1-2
    12, 0, 0, 22, 0, 0, 0, 0, 32, 0, 0, 0, 31, 0, 0, 0, 0, 0, //1-3
    
    0, 0, 0, 22, 0, 0, 0, 31, 0, 0, 12, 0, 0, 0, 0, 0, //2-1
    12, 0, 0, 32, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, //2-2
    0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, //2-3
    
    0, 31, 0, 21, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, //3-1
    0, 32, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, //3-2
    31, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, //3-3
    
    0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, //4-1
    0, 11, 0, 31, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, //4-2
    0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, //4-3
    
    11, 0, 0, 22, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, //5-1
    11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, //5-2
    0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, //5-3
    
    0, 0, 0, 21, 12, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, //6-1
    0, 0, 12, 0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, //6-2
    0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, //6-3
    
    31, 0, 0, 21, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0,//7-1
    0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, //7-2
    21, 0, 0, 31, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 31, 0, 0,//7-3
    
    0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 21, 0, 0, 0, 0, 0, //8-1
    0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 22, 0, 0, //8-2
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, //8-3
    
    0, 0, 0, 0, 21, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 31, 0, 0, //9-1
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 21, //9-2
    0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 21, 0, 0,//9-3
    
    31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, //10-1
    0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 11, 0, 0,//10-2

};

void UART_Initialize() {
        
    /*portC pin6/7 is mult with usart setting their tris*/    
    TRISCbits.TRISC6 = 1;            // Setting by data sheet 
    TRISCbits.TRISC7 = 1;            //  
    
    /*
           Serial Setting      
     * 1.   Setting Baud rate
     * 2.   choose sync/async mode 
     * 3.   enable Serial port (configures RX/DT and TX/CK pins as serial port pins)
     * 3.5  enable Tx, Rx Interrupt(optional)
     * 4.   Enable Tx & RX
     */      
    //  Setting baud rate
    TXSTAbits.SYNC = 0;             //choose the async moode
    BAUDCONbits.BRG16 = 0 ;          //Read Baud rate table
    TXSTAbits.BRGH = 1;
    SPBRG = 207;      
    
   //   Serial enable
    RCSTAbits.SPEN = 1;              //open serial port
    PIR1bits.TXIF = 1;
    PIR1bits.RCIF = 0;
    TXSTAbits.TXEN = 1;             //Enable Tx
    RCSTAbits.CREN = 1;             //Enable Rx
    //setting TX/RX interrupt
    PIE1bits.TXIE = 0;              //disable Tx interrupt
    IPR1bits.TXIP = 0;              //Setting Tx as low priority interrupt
    PIE1bits.RCIE = 1;              //Enable Rx interrupt
    IPR1bits.RCIP = 0;              //Setting Rc as low priority interrupt
    }

void UART_Write(unsigned char data)  // Output on Terminal
{
    while(!TXSTAbits.TRMT);
    TXREG = data;              //write to TXREG will send data 
}

char *GetString(){ // 
    return &mystring[0];
}

void UART_Write_Text(char* text) { // Output on Terminal, limit:10 chars
    for(int i=0;text[i]!='\0';i++)
        UART_Write(text[i]);
}

void ClearBuffer(){
    for(int i = 0; i < 10 ; i++)
        mystring[i] = '\0';
    lenStr = 0;
}

void MyusartRead()
{
    mystring[lenStr] = RCREG;
    mystring[lenStr + 1] = '\0';
    UART_Write_Text(GetString());
    UART_Write_Text("\n\r");
    lenStr++;
    lenStr %= 10;
   
    if(input_difficulty)
    {
        which_difficulty = RCREG;
        UART_Write(which_difficulty);
        if(RCREG == '1')
             choose_difficulty = music_1_hit_trigger_ez;
        else
            choose_difficulty = music_1_hit_trigger_hard;
        ClearBuffer();
        input_difficulty = 0;
    }
    if(!strcmp(GetString(), "change"))
    {
        input_difficulty = 1;
        UART_Write_Text("Which? 1 or 2\n\r");
        ClearBuffer();
    }
    if(!strcmp(GetString(), "music 1"))
    {
        singing_flag = 1;
        LATCbits.LC5 = 0;
        LATBbits.LB4 = 1;
        T0CONbits.TMR0ON = 1;
        T1CONbits.TMR1ON = 1;
        T2CONbits.TMR2ON = 1;
//        T3CONbits.TMR3ON = 1; 
        ClearBuffer();
    }
    if(!strcmp(GetString(), "q"))
    {
        singing_flag = 0;
        LATCbits.LC5 = 0;
        LATBbits.LB4 = 0;
        T0CONbits.TMR0ON = 0;
        T1CONbits.TMR1ON = 0;
        T2CONbits.TMR2ON = 0;
//        T3CONbits.TMR3ON = 0; 

        UART_Write_Text("Pause\n\r");
        ClearBuffer();
    }
    if(!strcmp(GetString(), "reset"))
    {
        input_difficulty = 0;
        which_difficulty = '0';
        singing_flag = 0;
        LATCbits.LC5 = 1;
        LATBbits.LB4 = 0;
        cur_note = 0;
        beats_count = 0;
        T0CONbits.TMR0ON = 0;
        T1CONbits.TMR1ON = 0;
        T2CONbits.TMR2ON = 0;
//        T3CONbits.TMR3ON = 0; 
        trigger_count = -1;
        game_state[0] = game_state[1] = game_state[2] = 0;
        hit_timing[0] = hit_timing[1] = hit_timing[2] = 1;
        UART_Write_Text("Reset\n\r");
        ClearBuffer();
        //just for PIC2 interrupt, so we have set to 0 quickly
        LATBbits.LB2 = 0;
    }

    return ;
}

// old version: 
// void interrupt low_priority Lo_ISR(void)
void __interrupt(low_priority)  Lo_ISR(void)
{
    if(RCIF)
    {
        if(RCSTAbits.OERR)
        {
            CREN = 0;
            Nop();
            CREN = 1;
        }
        
        MyusartRead();
    }
    
   // process other interrupt sources here, if required
    return;
}
