#include "buzzer.h"

void setup_buzzer (void)
{
    TRISD = TRISD & 0b11101111;
    ANSELD = ANSELD & 0b11101111;
    PORTD = PORTD & 0xEF;
}

void fire_buzzer (void)
{
    PORTD = PORTD | BUZZER_ON;
}

void shut_buzzer (void)
{
    PORTD = PORTD & ~BUZZER_ON;
}
