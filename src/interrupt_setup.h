#ifndef INTERRUPT_SETUP_H
#define	INTERRUPT_SETUP_H

#include <xc.h>

#define GIE_ENABLE 0b11000000
#define IPEN_DISABLE 0b11011111

void interrupt_setup (void);
void TX_1_interrupt_enable (void);
void TX_1_interrupt_disable (void);
void RX_1_interrupt_enable (void);
void RX_1_interrupt_disable (void);
void clear_all_interrupt_flags (void);

#endif	/* INTERRUPT_SETUP_H */

