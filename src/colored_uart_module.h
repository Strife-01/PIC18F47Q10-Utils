#ifndef COLORED_UART_MODULE_H
#define	COLORED_UART_MODULE_H

#include "interrupt_control.h"
#include "curiosity_leds_module.h"
#include "UART_setup.h"
#include <string.h>

void check_command_uart_1_rx (void);

unsigned char led_on = 0;

#endif	/* COLORED_UART_MODULE_H */

