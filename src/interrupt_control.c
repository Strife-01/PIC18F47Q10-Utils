#include "interrupt_control.h"
#include "interrupt_setup.h"
#include "UART_setup.h"
#include "timer_module.h"
#include "curiosity_leds_module.h"
#include "buzzer.h"

void clean_rx_1_buffer (void);
void copy_rx_1_buffer (void);

const unsigned char polling_time_busy_wait = 20000;
unsigned char rx_1_rec_character;

void __interrupt() ISR (void)
{
    // Uart1 TX interrupt strategy
    if ((PIR3 & TX1IF_M) == TX1IF_M)
    {
        if (local_sending_buffer_index < local_sending_buffer_length)
        {
            TX1REG = local_sending_buffer[local_sending_buffer_index];
            local_sending_buffer_index++;
        }
        else
        {
            sending_in_progress = 0;
            TX_1_interrupt_disable();
        }
    }
    
    // Tiemr 0 Interrupt strategy
    if ((PIR0 & TMR0IF_M) == TMR0IF_M)
    {
        PIR0 = PIR0 & ~TMR0IF_M;
        timer_0_stop();
        copy_rx_1_buffer();
        finished_received_buffer = 1;
        rx_1_copy_buffer_size = rx_1_index;
        clean_rx_1_buffer();
        rx_1_index = 0;
    }
    else
    {
        // DO NOTHING
    }
    
    // Uart1 RX interrupt strategy
    if ((PIR3 & RX1IF_M) == RX1IF_M)
    {
        // Check for Buffer Overflow
        if (rx_1_index >= UART_1_RECEIVE_BUFFER_LENGTH)
        {
            rx_1_index = 0;
        }
        else
        {
            // DO NOTHING
        }
        
        rx_1_rec_character = RC1REG;
        rx_1_buffer_receive[rx_1_index] = rx_1_rec_character;
        rx_1_index++;
        rx_1_buffer_size++;
        timer_0_reset();
    }
    else
    {
        // Do NOTHING
    }
    
    // IR_sensor_tr_rec with polling
    if ((PIR0 & PHERIPHERAL_0_IF) == PHERIPHERAL_0_IF)
    {
        // check for redundancy
        busy_wait(polling_time_busy_wait);
        
        if ((PIR0 & PHERIPHERAL_0_IF) == PHERIPHERAL_0_IF)
        {
            if (ir_tr_rec_is_has_signal == 0)
            {
                // fire_buzzer();
                ir_tr_rec_is_has_signal = 1;
            }
            else
            {
                ir_tr_rec_is_has_signal = 0;
            }
            PIR0 = PIR0 & ~PHERIPHERAL_0_IF;
        }
        else
        {
            // DO NOTHING
        }
    }
    else
    {
        // DO NOTHING
    }

}

void clean_rx_1_buffer (void)
{
    unsigned char index = 0;
    
    for (index = 0; index < UART_1_RECEIVE_BUFFER_LENGTH; index++)
    {
        rx_1_buffer_receive[index] = 0;
    }
}

void copy_rx_1_buffer (void)
{
    unsigned char index = 0;
    
    for (index = 0; index < rx_1_index; index++)
    {
        rx_copy_buffer[index] = rx_1_buffer_receive[index];
    }
}

void clear_command_copy_buffer (void)
{
    unsigned char index = 0;
    
    for (index = 0; index < rx_1_copy_buffer_size; index++)
    {
        rx_copy_buffer[index] = 0;
    }
}

void busy_wait (unsigned long time)
{
    unsigned long index = 0;
    
    for (index = 0; index < time; index++)
    {
        // Increment
    }
}
