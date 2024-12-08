#ifndef IR_TRANS_REC_H
#define	IR_TRANS_REC_H

#include <xc.h>

#define ANSEL_IR_TR_RE_A 0b11111101
#define INPUT_IR_TR_RE_A 0b00000010
#define PERIPHERAL_INT_0 0x01

void porta_setup_for_ir_tr_rec (void);
void setup_pin_for_interrupt (void);

#endif	/* IR_TRANS_REC_H */

