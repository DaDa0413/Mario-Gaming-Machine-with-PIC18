#ifndef SETTING_H
#define	SETTING_H
#include <xc.h>
#include <pic18f4520.h>
#include "pin.h"
#include "tmr.h"
//#include "tmr1.h"
#include "uart.h"
#include "ccp.h"
#include "adc.h"
#include "interrupt_manager.h"
#include "pin_manager.h"
#include "song.h"
#include "light.h"

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);


#endif