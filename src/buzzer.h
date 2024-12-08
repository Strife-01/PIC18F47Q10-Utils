#ifndef BUZZER_H
#define	BUZZER_H

#include <xc.h>

#define BUZZER_ON 0b00010000

void setup_buzzer (void);

void fire_buzzer (void);
void shut_buzzer (void);

#endif	/* BUZZER_H */

