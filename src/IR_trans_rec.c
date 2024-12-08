#include "IR_trans_rec.h"


void porta_setup_for_ir_tr_rec(void)
{
    // Disable analogic function
    ANSELA = ANSELA & ANSEL_IR_TR_RE_A;
    
    // Set pin as input
    TRISA = TRISA | INPUT_IR_TR_RE_A ;
    
    // Set pin on 1
    PORTA = PORTA & ANSEL_IR_TR_RE_A;
}

void setup_pin_for_interrupt (void)
{
    INT0PPS = 0x01;
    PIE0 = PIE0 | PERIPHERAL_INT_0;
}