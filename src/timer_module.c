#include "timer_module.h"

#define TIMER_0_OFFEST_VALUE 300
#define DISABLE_TIMER_0 0b01111111
#define FOSC_4 0b11101111
#define PRESCALER_1_16_1 0b01000000
#define PRESCALER_1_16_2 0b01001111
#define POSTSCALER_1_10_1 0b10010000
#define POSTSCALER_1_10_2 0b10011111
#define TIMER_0_INT_FLAG_ENABLE 0b00100000

unsigned int timer_0_offset = 0;
unsigned char timer_0_low = 0;
unsigned char timer_0_high = 0;

void timer_0_reset (void)
{
    // Timer Inner Counter values
    timer_0_offset = (unsigned int) (TIMER_0_OFFEST_VALUE);
    timer_0_low = (unsigned char) timer_0_offset;
    timer_0_high = (unsigned char) (timer_0_offset >> 8);
    
    // Disable timer
    T0CON0 = T0CON0 & DISABLE_TIMER_0;
    
    // Fosc/4 Clock source
    T0CON1 = T0CON1 & FOSC_4;
    
    // Set Prescaler to 1:16
    T0CON1 = T0CON1 | PRESCALER_1_16_1;
    T0CON1 = T0CON1 & PRESCALER_1_16_2;
    
    // Set Postscaler to 1:10
    T0CON0 = T0CON0 | POSTSCALER_1_10_1;
    T0CON0 = T0CON0 & POSTSCALER_1_10_2;
    
    // Set the timer body values
    TMR0H = timer_0_high;
    TMR0L = timer_0_low;
    
    // Enable timer 0
    T0CON0 = T0CON0 | ~DISABLE_TIMER_0;
    
    // Enable timer_0_interrupt flag
    PIE0 = PIE0 | TIMER_0_INT_FLAG_ENABLE;
}

void timer_0_stop (void)
{
    // Disable timer 0
    T0CON0 = T0CON0 & DISABLE_TIMER_0;

    // Disable timer_0_interrupt flag
    PIE0 = PIE0 & ~TIMER_0_INT_FLAG_ENABLE;
}
