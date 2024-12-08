#ifndef UART_SETUP_H
#define	UART_SETUP_H

#include <xc.h>

void RX_setup (void);
void TX_setup (void);

void RX1_enable (void);
void RX1_disable (void);

void TX1_enable (void);
void TX1_disable (void);

void boud_rate_setup (void);
void baud_9600 (void);

void start_sending (unsigned char* source_buffer, unsigned long source_buffer_length);

unsigned char sending_in_progress = 0;
unsigned char* local_sending_buffer;
unsigned long local_sending_buffer_length;
unsigned long local_sending_buffer_index;


#endif	/* UART_SETUP_H */

