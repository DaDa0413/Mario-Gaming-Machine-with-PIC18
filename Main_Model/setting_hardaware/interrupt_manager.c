#include <xc.h>
#include <pic18f4520.h>

void INTERRUPT_Initialize (void)
{
    RCONbits.IPEN = 1;      //enable Interrupt Priority mode
    INTCONbits.GIEH = 1;    //enable high priority interrupt
    INTCONbits.GIEL = 1;     //disable low priority interrupt
    
    INTCON3bits.INT2IE = 1;  //Enables the INT0 external interrupt
    INTCON3bits.INT2IF = 0;
    INTCON2bits.INTEDG2 = 1;//Interrupt on rising edge
    INTCON3bits.INT2IP = 1;
    
    INTCON3bits.INT1IE = 1;  //Enables the INT0 external interrupt
    INTCON3bits.INT1IF = 0;
    INTCON2bits.INTEDG1 = 1;//Interrupt on rising edge
    INTCON3bits.INT1IP = 1;//1 = High priority

    INTCONbits.INT0IE = 1;
    INTCONbits.INT0IF = 0;
    INTCON2bits.INTEDG0 = 1;//1 = Interrupt on rising edge
}

