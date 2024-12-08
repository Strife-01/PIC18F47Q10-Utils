#include "interrupt_setup.h"

#define TX1EN 0b00010000
#define RX1EN 0b00100000
#define CLEAR 0x00

void interrupt_setup (void)
{
    // Enable Global, Pheripheral Interrupts
    // Disable Priority Interrups
    INTCON = INTCON | GIE_ENABLE;
    INTCON = INTCON & IPEN_DISABLE;
    
//    TX_1_interrupt_enable();
    RX_1_interrupt_enable();
    
}

void TX_1_interrupt_enable (void)
{
    PIE3 = PIE3 | TX1EN;
}

void TX_1_interrupt_disable (void)
{
    PIE3 = PIE3 & ~TX1EN;
}

void RX_1_interrupt_enable (void)
{
    PIE3 = PIE3 | RX1EN;
}

void RX_1_interrupt_disable (void)
{
    PIE3 = PIE3 & ~RX1EN;
}

void clear_all_interrupt_flags (void)
{
    PIR0 = CLEAR;
    PIR1 = CLEAR;
    PIR2 = CLEAR;
    PIR3 = CLEAR;
    PIR4 = CLEAR;
    PIR5 = CLEAR;
    PIR6 = CLEAR;
    PIR7 = CLEAR;
}