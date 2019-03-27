/*
 * File:   pin.c
 * Author: RRRRRROG
 *
 * Created on 2018?12?22?, ?? 1:26
 */
#include <xc.h>
#include <pic18f4520.h>

void PIN_MANAGER_Initialize(void)
{
    //change note
    TRISCbits.TRISC4 = 0;
    //reset
    TRISCbits.TRISC5 = 0;
    //PIC 2 playing
    TRISBbits.TRISB4 = 0;
    //PIC 2 beat_timing
    TRISBbits.TRISB5 = 0;
    //INT0
    TRISBbits.TRISB0 = 1;
    //INT1
    TRISBbits.TRISB1 = 1;
    //INT2
    TRISBbits.TRISB2 = 1;

    //output
    TRISA = 0;
    TRISD = 0;
    //layer
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC3 = 0;
    
    //initialize
    LATCbits.LC4 = 0;
    LATCbits.LC5 = 0;
    LATBbits.LB4 = 0;
    LATBbits.LB5 = 0;


    //fast perfect slow
    TRISEbits.TRISE0 = 0;
    TRISEbits.TRISE1 = 0;
    TRISEbits.TRISE2 = 0;
    
    LATEbits.LE0 = 0;
    LATEbits.LE1 = 0;
    LATEbits.LE2 = 0;
//    LATA = 0;
//    LATD = 0;
//    LATCbits.LC0 = 1;
//    LATCbits.LC1 = 1;
//    LATCbits.LC2 = 1;
//    LATCbits.LC3 = 1;
}