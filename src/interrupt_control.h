#ifndef INTERRUPT_CONTROL_H
#define	INTERRUPT_CONTROL_H

#define RX1IF_M 0b00100000
#define TX1IF_M 0b00010000
#define TMR0IF_M 0b00100000
#define PHERIPHERAL_0_IF 0b00000001
#define UART_1_RECEIVE_BUFFER_LENGTH 100

void clear_command_copy_buffer (void);
void busy_wait (unsigned long time);


unsigned char rx_1_buffer_receive[UART_1_RECEIVE_BUFFER_LENGTH];
unsigned char rx_copy_buffer[UART_1_RECEIVE_BUFFER_LENGTH];
unsigned char rx_1_buffer_size = 0;
unsigned char rx_1_copy_buffer_size = 0;
unsigned char finished_received_buffer = 0;
unsigned char rx_1_index = 0;
unsigned char ir_tr_rec_is_has_signal = 0;
unsigned char is_buzzer_on = 0;

#endif	/* INTERRUPT_CONTROL_H */

