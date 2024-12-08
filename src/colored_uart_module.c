#include "colored_uart_module.h"

#define RED "red"
#define BLUE "blue"
#define GREEN "green"
#define CYAN "cyan"
#define YELLOW "yellow"
#define MAGENTA "magenta"
#define WHITE "white"
#define CLEAR "clear"

#define RED_OK_MESSAGE "The led has been turned RED\n"
#define BLUE_OK_MESSAGE "The led has been turned BLUE\n"
#define GREEN_OK_MESSAGE "The led has been turned GREEN\n"
#define CYAN_OK_MESSAGE "The led has been turned CYAN\n"
#define YELLOW_OK_MESSAGE "The led has been turned YELLOW\n"
#define MAGENTA_OK_MESSAGE "The led has been turned MAGENTA\n"
#define WHITE_OK_MESSAGE "The led has been turned WHITE\n"

#define CLEAR_LEDS "The leds have been turned off\n"
#define ERROR_MESSAGE "ERROR:\n Commands:\nred\ngreen\nblue\ncyan\nclear\n"

#define RED_LENGTH 29
#define BLUE_LENGTH 30
#define GREEN_LENGTH 31
#define CYAN_LENGTH 30
#define YELLOW_LENGTH 32
#define MAGENTA_LENGTH 33
#define WHITE_LENGTH 31

#define CLEAR_LENGTH 31
#define ERROR_LENGTH 45


void check_command_uart_1_rx (void)
{
    if (strcmp(rx_copy_buffer, RED) == 0)
    {
        turn_off_leds_D();
        turn_on_led_red_D7();
        led_on = 1;
        start_sending(RED_OK_MESSAGE, RED_LENGTH);
    }
    else if (strcmp(rx_copy_buffer, BLUE) == 0)
    {
        turn_off_leds_D();
        turn_on_led_blue_D5();
        led_on = 1;
        start_sending(BLUE_OK_MESSAGE, BLUE_LENGTH);
    }
    else if (strcmp(rx_copy_buffer, GREEN) == 0)
    {
        turn_off_leds_D();
        turn_on_led_green_D6();
        led_on = 1;
        start_sending(GREEN_OK_MESSAGE, GREEN_LENGTH);
    }
    else if (strcmp(rx_copy_buffer, CYAN) == 0)
    {
        turn_off_leds_D();
        turn_on_led_cyan_D6D7();
        led_on = 1;
        start_sending(CYAN_OK_MESSAGE, CYAN_LENGTH);
    }
    else if (strcmp(rx_copy_buffer, YELLOW) == 0)
    {
        turn_off_leds_D();
        turn_on_led_yellow_D5D6();
        led_on = 1;
        start_sending(YELLOW_OK_MESSAGE, YELLOW_LENGTH);
    }
    else if (strcmp(rx_copy_buffer, MAGENTA) == 0)
    {
        turn_off_leds_D();
        turn_on_led_magenta_D5D7();
        led_on = 1;
        start_sending(MAGENTA_OK_MESSAGE, MAGENTA_LENGTH);
    }
    else if (strcmp(rx_copy_buffer, WHITE) == 0)
    {
        turn_off_leds_D();
        turn_on_led_white_D5D6D7();
        led_on = 1;
        start_sending(WHITE_OK_MESSAGE, WHITE_LENGTH);
    }
    else if (strcmp(rx_copy_buffer, CLEAR) == 0)
    {
        turn_off_leds_D();
        led_on = 0;
        start_sending(CLEAR_LEDS, CLEAR_LENGTH);
    }
    else
    {
        start_sending(ERROR_MESSAGE, ERROR_LENGTH);
    }
    
    clear_command_copy_buffer();
    
    finished_received_buffer = 0;
    }
