#include "config_bits.h"
#include "curiosity_leds_module.h"
#include "interrupt_setup.h"
#include "UART_setup.h"
#include "interrupt_control.h"
#include "colored_uart_module.h"
#include "buzzer.h"
#include "IR_trans_rec.h"

#define BUSY_WAIT_TIME 100000
#define BUFFER_LENGTH 12


unsigned char buffer[BUFFER_LENGTH];
unsigned char hello_buffer[BUFFER_LENGTH] = "Hello World!";
unsigned char fuck_off[BUFFER_LENGTH] = "ce faci? :))";

int main(int argc, char** argv)
{    
    porta_setup_for_ir_tr_rec();
    clear_all_interrupt_flags();
    colored_leds_setup();
    curiosity_leds_setup();
    interrupt_setup();
    setup_pin_for_interrupt();
    setup_buzzer();
    boud_rate_setup();
    RX_setup();
    TX_setup();
    
    while (TRUE)
    {
        if (finished_received_buffer == 1)
        {
            check_command_uart_1_rx();
            fire_buzzer();
            busy_wait(10000);
            shut_buzzer();
        }
        else
        {
            // DO NOTHING
        }
        
        if (ir_tr_rec_is_has_signal == 1 && is_buzzer_on == 0)
        {
            fire_buzzer();
            is_buzzer_on = 1;
        }
        else if (ir_tr_rec_is_has_signal == 0 && is_buzzer_on == 1)
        {
            shut_buzzer();
            is_buzzer_on = 0;
        }
    }
    
    return (EXIT_SUCCESS);
}



