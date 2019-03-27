#include <xc.h>
#pragma config OSC  = INTIO67,WDT=OFF,LVP=OFF
#pragma PBADEN = 0 

#define B41 1072

#define G3 2551


#define C4 1911
#define C4D 1804
#define D4 1702
#define E4 1515
#define F4 1432
#define F4D 1351
#define G4 1276
#define G4D 1204
#define A4 1136
#define A4D 1072
#define B4 1012


#define C5 956
#define C5D 902
#define D5 851
#define D5D 806
#define E5 758
#define F5 716
#define F5D 676
#define G5 638
#define G5D 602
#define A5 568
#define B5 506

#define C6 477 
#define D6 425
#define E6 379
#define F6 358
#define G6 319
#define A6 284
#define B6 253

int music_1_harmony_notes[326] = {
    0, 0, 0, F4D, F4D, F4D, 0, F4D, F4D, B4, 0, 0, 0, //10
    E4, 0, C4, 0, G3, 0, C4, D4, 0, C4D, C4, //11
    C4, G4, B4, C5, A4, B4, 0, A4, E4, F4, D4, 0, //12
    E4, 0, C4, 0, G3, 0, C4, D4, 0, C4D, C4, //11 //4
    C4, G4, B4, C5, A4, B4, 0, A4, E4, F4, D4, 0, //12
    0, E5, D5D, D5, B4, C5, 0, E4, F4, G4 , 0, C4, E4, F4,//14
    0, E5, D5D, D5, B4, C5, 0, F5, F5, F5, 0, //11     //7
    0, E5, D5D, D5, B4, C5, 0, E4, F4, G4 , 0, C4, E4, F4,//14
    0, G4D, 0, F4, 0, E4, 0, 0, 0, //9
    0, E5, D5D, D5, B4, C5, 0, E4, F4, G4 , 0, C4, E4, F4,//14 //10
    0, E5, D5D, D5, B4, C5, 0, F5, F5, F5, 0,//11
    0, E5, D5D, D5, B4, C5, 0, E4, F4, G4 , 0, C4, E4, F4,//14
    0, G4D, 0, F4, 0, E4, 0, 0, 0,//9        //13
    G4D, G4D, G4D, 0, G4D, A4D, G4, E4, E4, C4, 0,//11   //14
    G4D, G4D, G4D, 0, G4D, A4D, G4, 0, 0, 0, 0, //11  
    G4D, G4D, G4D, 0, G4D, A4D, G4, E4, E4, C4, 0, //11 //16
    F4D, F4D, F4D , 0, F4D, F4D, B4, 0, 0, 0, //10
    E4, 0, C4, 0, G3, 0, C4, D4, 0, C4D, C4, //11
    C4, G4, B4, C5, A4, B4, 0, A4, E4, F4, D4, 0, //12  //19  //218
    E4, 0, C4, 0, G3, 0, C4, D4, 0, C4D, C4, //11
    C4, G4, B4, C5, A4, B4, 0, A4, E4, F4, D4, 0, //12
    A4, F4, E4, 0, E4, F4, C5, C5, F4, 0,//10  //22
    G4, F5, F5, F5, E5, D5, C5, A4, F4, E4, 0, //11
    C5, A4, E4, 0, E4, F4, C5, C5, F4, 0, //10
    G4, D5, D5, D5, C5, B4, G4, 0, 0, 0, //10  //25
    E4, 0, E4, 0, 0, F4, C5, C5, F4, 0, //10
    G4, F5, F5, F5, E5, D5, C5, A4, F4, E4, 0, //11
    C5, A4, E4, 0, E4, F4, C5, C5, F4, 0, //10 //28
    G4, D5, D5, D5, C5, B4, G4, 0, 0, 0, //10
};

int music_1_harmony_wait[326] = {
    2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 2, 2, 2,
    2, 1, 1, 2, 2, 1, 2, 1, 1, 1, 2, 
    2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 
    2, 1, 1, 2, 2, 1, 2, 1, 1, 1, 2, 
    2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 
    2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
    2, 1, 1, 1, 2, 1, 1, 2, 1, 2, 2,
    2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 1, 2, 1, 2, 2, 2, 2,
    2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 1, 1, 1, 2, 1, 1, 2, 1, 2, 2,
    2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 1, 2, 1, 2, 2, 2, 2,  //13
    1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 2,
    1, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2,
    1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 2, //16
    1, 2, 1, 1, 1, 2, 2, 2, 2, 2,
    2, 1, 1, 2, 2, 1, 2, 1, 1, 1, 2, 
    2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, //19
    2, 1, 1, 2, 2, 1, 2, 1, 1, 1, 2,
    2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 
    1, 2, 1, 2, 2, 1, 2, 1, 2, 2, //22
    2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2,
    1, 2, 1, 2, 2, 1, 2, 1, 2, 2,
    1, 2, 1, 2, 2, 2, 2, 2, 2, 2, //25
    1, 2, 1, 2, 2, 1, 2, 1, 2, 2,
    2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2,
    1, 2, 1, 2, 2, 1, 2, 1, 2, 2, //28
    1, 2, 1, 2, 2, 2, 2, 2, 2, 2,
};
int music_1_harmony_num = 326;
void INTERRUPT_Initialize (void);
void adc_init(void);
void ccp1_init(void);
void ccp2_init(void);
void tmr_init(void);
int delay = 0;
int playing = 0;
int cur_note = 0;
int change_note = 0;
void __interrupt(high_priority) Hi_ISR(void)
{
    //deal ccp2 interrupt and adc interrupt
    if(PIR1bits.ADIF)
    {//AD conversion finish
        //delay and beat timing
        if(!delay && PORTBbits.RB4)
        {
            if(ADRES > 20)
            {
                LATDbits.LD0 = 1;
                LATDbits.LD3 = 1;
                delay = 1;
            }
        }
        else {
            LATDbits.LD0 = 0;
            LATDbits.LD3 = 0;
        }
        PIR1bits.ADIF = 0;
    }
    else if(PIR1bits.CCP1IF)
    {
        TMR1 = 0;
        CCP1IF = 0;
    }
    else if(PIR2bits.CCP2IF){ //special event triger
        PIR2bits.CCP2IF = 0;
    }
    else if(INT0IF)
    {
        change_note = 1;
        INT0IF = 0;
    }
    //RESET
    else if(INT1IF)
    {
        cur_note = 0;
        TMR1ON = 0;
        playing = 0;
        CCPR1 = 100000;
        
        INT1IF = 0;
    }
    return ;
}

void main(void) {
    //change OSC // default setting 4M Hz
    OSCCONbits.IRCF = 0b110;
    //change note
    TRISBbits.TRISB0 = 1;
    //reset
    TRISBbits.TRISB1 = 1;
    //start playing
    TRISBbits.TRISB2 = 1;
    //beat timing
    TRISBbits.TRISB4 = 1;
    PORTB = 0;
    TRISD = 0;
    LATD = 0;

    INTERRUPT_Initialize();
    adc_init();
    tmr_init();
    ccp1_init();
    ccp2_init();
    
    LATDbits.LD0 = 0;
    LATDbits.LD1 = 0;
    while(1)
    {
        if (PORTBbits.RB2) {
            T1CONbits.TMR1ON = 1;
            playing = 1;
            LATDbits.LD1 = 1;
        }
        while(playing)
        {
            if (!PORTBbits.RB2) {
                T1CONbits.TMR1ON = 0;
                CCPR1 = 100000;
                playing = 0;
                LATDbits.LD1 = 0;
                break;
            }
//            if (delay) {
//                for (int i = 0; i < 10000; i++);
//                delay = 0;
//            }
            while(!change_note);
            delay = 0;
//            beats_count = 0;
            cur_note++;
            cur_note %= music_1_harmony_num;
            CCPR1 = 100000;
            for(int i = 0; i < 1000; i++);
            if(music_1_harmony_notes[cur_note] != 0)
            {
                //set TRISC2 as output
                TRISCbits.TRISC2 = 0;
                TMR1ON = 1;
                PIE1bits.CCP1IE = 1;
                CCPR1 = music_1_harmony_notes[cur_note];
            }
            else
            {
                //set TRISC2 as input
                //because we don't want any sound
                //at this time
                TRISCbits.TRISC2 = 1;
                TMR1ON = 0;
                PIE1bits.CCP1IE = 0;
            }
            change_note = 0;
        }
    }
    return;
}

void adc_init(void){
    //datasheet p232 TABLE 19-2
    //Configure the A/D module
    
    //**ADCON0**
    //select analog channel
    ADCON0bits.CHS = 0b0101;//AN5 input
    //set TRIS
    TRISEbits.RE0 = 1;
    //Turn on A/D module
    ADCON0bits.ADON = 1;
    //ADCON1 //set refer voltage
    ADCON1bits.VCFG = 0b00;//default voltage
    
    // A/D Port Configuration Control bits
    //which pins are analog, the others are digital
    ADCON1bits.PCFG = 0b0111;

    //**ADCON2**
    //A/D Conversion Clock
    ADCON2bits.ADCS = 0b011;//Tad = RC

    //Acquisition Time
    ADCON2bits.ACQT = 0b001;//Acquisition Time = 2Tad
    
    //left or right justified
    ADCON2bits.ADFM = 1;
    
    //Configure A/D interrupt(optional)
    PIR1bits.ADIF = 0;
    PIE1bits.ADIE = 1;
    INTCONbits.GIE = 1;
    
    //enable Interrupt Priority mode
    RCONbits.IPEN = 1;
}


//to create the frequency of music note
void ccp1_init(void) {

    TRISCbits.TRISC2=0;
    
    CCP1CONbits.CCP1M = 0b0010;     //Compare mode, toggle output on match (CCPxIF bit is set)
    IPR1bits.CCP1IP = 1;
    PIR1bits.CCP1IF = 0;
    PIE1bits.CCP1IE = 1;
    CCPR1 = 100000;
}

void ccp2_init(void){
    //Configure CCP2 mode,ref datasheet p139
    //configure CCP2 interrupt

    // Compare mode: trigger special event,
    //reset timer, start A/D conversion on 
    //CCP2 match (CCPxIF bit is set)
    CCP2CONbits.CCP2M = 0b1011;
    
    //configure CCP2 comparator value
    CCPR2 = 2500;
}

void tmr_init(void) {
    //set up timer1
    //for music playing
    //for frequency
    T1CONbits.RD16 = 1; //16bit
    T1CONbits.TMR1CS = 0; //internal

    T1CONbits.T1CKPS = 0b00; //1:1
    T1CONbits.TMR1ON = 0;
    
    
    //set up timer3, ref datasheet p135
    //no need to turn up timer3 interrupt
    //trigger ad
    T3CONbits.RD16 = 1; //16bits
    
    T3CONbits.T3CCP2 = 0;//Timer3 is the capture/compare clock source for CCP2;
    T3CONbits.T3CCP1 = 1;
    
    T3CONbits.T3CKPS = 0b10;//prescale:4
 
    T3CONbits.TMR3CS = 0;   //from clock cycle
    T3CONbits.TMR3ON = 1;
}

void INTERRUPT_Initialize (void)
{
    RCONbits.IPEN = 1;      //enable Interrupt Priority mode
    INTCONbits.GIEH = 1;    //enable high priority interrupt
    INTCONbits.GIEL = 1;     //disable low priority interrupt
    //change note
    INTCONbits.INT0IE = 1;  //Enables the INT0 external interrupt
    INTCONbits.INT0IF = 0;
    INTCON2bits.INTEDG0 = 1;//Interrupt on rising edge
    //reset
    INTCON3bits.INT1IE = 1;  //Enables the INT0 external interrupt
    INTCON3bits.INT1IF = 0;
    INTCON2bits.INTEDG1 = 1;//Interrupt on rising edge
}