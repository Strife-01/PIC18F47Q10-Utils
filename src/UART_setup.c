#include "UART_setup.h"
#include "interrupt_setup.h"

#define TX1STA_EN 0b00100000
#define TX1PIN 0b00001001
#define RX1PIN 0b00010111
#define TX1ASYNC 0b11101111
#define BIT_TRANS_8 0b10111111
#define RX1STA_EN 0b00010000
#define RX1SERIAL_ENABLE 0b10000000
#define BIT_REC_8 0b10111111
#define BAUD_RATE_16_BIT 0b00001000
#define TXBRGH 0b00000100
#define RCBRGH 0b00000100
#define TX1OUTPUT_PORT 0b10111111
#define DISABLE_ANSEL_FUNCTOPN_C7 0b01111111
#define DISABLE_ANSEL_FUNCTOPN_C6 0b10111111
#define BOUD_RATE_9600 0b0000011010000001;
#define START_SENDING_BUFFER_INDEX 0


// RX setup
void RX_setup (void)
{
    // Select pin C6 for receive
    RX1PPS = RX1PIN;
    
    // Disable to Analogic function
    ANSELC = ANSELC & DISABLE_ANSEL_FUNCTOPN_C7;
    
    // Enable serial port
    RC1STA = RC1STA | RX1SERIAL_ENABLE;
    
    // Set 8 bit payload
    RC1STA = RC1STA & BIT_REC_8;
    
    // Enable listening
    RX1_enable();
}

void RX1_enable (void)
{
    RC1STA = RC1STA | RX1STA_EN;
}

void RX1_disable (void)
{
    RC1STA = RC1STA & ~RX1STA_EN;
}

// TX setup
void TX_setup (void)
{
    // Select pin C7 for transmission
    RC6PPS = TX1PIN;
    
    // Disable to Analogic function
    ANSELC = ANSELC & DISABLE_ANSEL_FUNCTOPN_C6;
    
    // Make the pin of output
    TRISC = TRISC & TX1OUTPUT_PORT;
    
    // Make the transmission assincronous
    TX1STA = TX1STA & TX1ASYNC;
    
    // Set 8 bits payload
    TX1STA = TX1STA & BIT_TRANS_8;
    
    // Enable High Boud Rate Select bit
    TX1STA = TX1STA | TXBRGH;
    
    // Enable transmission
    // TX1_enable();
}

void TX1_enable (void)
{
    TX1STA = TX1STA | TX1STA_EN;
}

void TX1_disable (void)
{
    TX1STA = TX1STA & ~TX1STA_EN;
}

void boud_rate_setup (void)
{
    BAUD1CON = BAUD1CON | BAUD_RATE_16_BIT;
    baud_9600();
}

void baud_9600 (void)
{
    // SP1BRGH = 0b00000110;
    // SP1BRGL = 0b10000001;
    SP1BRG = BOUD_RATE_9600;
}

void start_sending (unsigned char* source_buffer, unsigned long source_buffer_length)
{
    if (sending_in_progress == 0)
    {
        local_sending_buffer_index = START_SENDING_BUFFER_INDEX;
        local_sending_buffer = source_buffer;
        local_sending_buffer_length = source_buffer_length;
        TX1_enable();
        sending_in_progress = 1;
        TX_1_interrupt_enable();
    }
    else
    {
        // DO NOTHING
    }
}