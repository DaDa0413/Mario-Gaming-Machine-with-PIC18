/*
 * File:   tmr.c
 * Author: RRRRRROG
 *
 * Created on 2018?12?21?, ?? 4:08
 */


#include <xc.h>

void TMR0_Initialize(void)
{
    //Timer0 is configured as a 16-bit timer/counter
    T0CONbits.T08BIT = 0;
    //Internal instruction cycle clock (CLKO)
    T0CONbits.T0CS = 0;
    //Timer0 prescaler is assigned. Timer0 clock input comes from prescaler output.
    T0CONbits.PSA = 0;
    //1:4 prescale value
    T0CONbits.T0PS = 0b001;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    //High priority
    INTCON2bits.TMR0IP = 1;
    TMR0 = 28036;//0.15second
    T0CONbits.TMR0ON = 0;
}
//to change the music note
void TMR1_Initialize(void)
{
    //Timer3 is the capture/compare clock source for CCP2;
    //Timer1 is the capture/compare clock source for CCP1
    T3CONbits.T3CCP2 = 0;
    T3CONbits.T3CCP1 = 1;
    
    //0.0625second
    PIE1bits.TMR1IE = 1;
    IPR1bits.TMR1IP = 1;
    PIR1bits.TMR1IF = 0;
    //16 bits
    T1CONbits.RD16 = 1;
    //choose internal clock source
    T1CONbits.TMR1CS = 0;
    //10 = 1:4 Prescale value
    T1CONbits.T1CKPS = 0b10;
    //dynamic due to the playing speed
    TMR1 = 28036;//0.15second
    T1CONbits.TMR1ON = 0;
}


//to trigger special event(CCP2)
void TMR2_Initialize(void)
{
    //1111 = 1:16 Postscale
    T2CONbits.T2OUTPS = 0b1111;
    //1x = Prescaler is 16
    T2CONbits.T2CKPS1 = 0b1; 
    PIE1bits.TMR2IE = 1;
    PIR1bits.TMR2IF = 0;
    IPR1bits.TMR2IP = 1;
    
    PR2 = 23;//0.0015second
    T2CONbits.TMR2ON = 0;
    
}

//to trigger special event(CCP2)
void TMR3_Initialize(void)
{
    //16 bits
    T3CONbits.RD16 = 1;
    //internal clock source
    T3CONbits.TMR3CS = 0;
    //00 = 1:1 Prescale value
    T3CONbits.T3CKPS = 0b00;
//    //Timer3 is the capture/compare clock source for CCP2;
//    //Timer1 is the capture/compare clock source for CCP1
//    T3CONbits.T3CCP2 = 0;
//    T3CONbits.T3CCP1 = 1;
    T3CONbits.TMR3ON = 0; 
}