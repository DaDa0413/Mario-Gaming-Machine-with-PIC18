#include <xc.h>


//to create the frequency of music note
void CCP2_Initialize() {

//    TRISCbits.TRISC1=0;	// Set CCP2 pin as output
    TRISBbits.TRISB3=0;
    
    CCP2CONbits.CCP2M = 0b0010;     //Compare mode, toggle output on match (CCPxIF bit is set)
    IPR2bits.CCP2IP = 1;
    PIR2bits.CCP2IF = 0;
    PIE2bits.CCP2IE = 1;
    
//    CCPR2 = 100000;
}

