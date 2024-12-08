#include "curiosity_leds_module.h"

// Module Only Port D leds
#define BLUE_D5_ON 0b10000000
#define GREEN_D6_ON 0b01000000
#define RED_D7_ON 0b00100000
#define CYAN_D6D7_ON 0b11000000
#define YELLOW_D5D6_ON 0b01100000
#define MAGENTA_D5D7_ON 0b10100000
#define WHITE_D5D6D7_ON 0b11100000

#define ALL_D_LEDS_OFF 0b00011111

// Setup leds
void curiosity_leds_setup (void)
{
    TRISA = TRISA & 0x0F;
    ANSELA = ANSELA & 0x0F;
    PORTA = PORTA & 0x0F;
}

void colored_leds_setup (void) // Test Ok
{
    TRISD = TRISD & 0b00011111;
    ANSELD = ANSELD & 0b00011111;
    PORTD = PORTD & 0x1F;
}

// Power on Green
void turn_on_green_d7 (void)
{
    PORTD = PORTD | 0b01000000;
    PORTD = PORTD & 0b01011111;
}

// Power on Red
void turn_on_red_d7 (void)
{
    PORTD = PORTD | 0b00100000;
    PORTD = PORTD & 0b00111111;
}

// Power on led functions
void turn_on_led_D2 (void) // Port A4
{
    PORTA = PORTA | LED_D2_ON;
}

void turn_on_led_D3 (void) // Port A5
{
    PORTA = PORTA | LED_D3_ON;
}
void turn_on_led_D4 (void) // Port A6
{
    PORTA = PORTA | LED_D4_ON;
}

void turn_on_led_D5 (void) // Port A7
{
    PORTA = PORTA | LED_D5_ON;
}

// - Colored Purposed D5-D7
void turn_on_led_red_D7 (void)
{
    PORTD = PORTD | RED_D7_ON;
}

void turn_on_led_green_D6 (void)
{
    PORTD = PORTD | GREEN_D6_ON;
}

void turn_on_led_blue_D5 (void)
{
    PORTD = PORTD | BLUE_D5_ON;
}

void turn_on_led_cyan_D6D7 (void)
{
    PORTD = PORTD | CYAN_D6D7_ON;
}

void turn_on_led_yellow_D5D6 (void)
{
    PORTD = PORTD | YELLOW_D5D6_ON;
}

void turn_on_led_magenta_D5D7 (void)
{
    PORTD = PORTD | MAGENTA_D5D7_ON;
}

void turn_on_led_white_D5D6D7 (void)
{
    PORTD = PORTD | WHITE_D5D6D7_ON;
}

// Power off led functions
void turn_off_led_D2 (void) // Port A4
{
    PORTA = PORTA & ~LED_D2_ON;
}

void turn_off_led_D3 (void) // Port A5
{
    PORTA = PORTA & ~LED_D3_ON;
}

void turn_off_led_D4 (void) // Port A6
{
    PORTA = PORTA & ~LED_D4_ON;
}

void turn_off_led_D5 (void) // Port A7
{
    PORTA = PORTA & ~LED_D5_ON;
}

// - Colored Purposed D5-D7
void turn_off_led_red_D7 (void)
{
    PORTD = PORTD & ~RED_D7_ON;
}

void turn_off_led_green_D6 (void)
{
    PORTD = PORTD & ~GREEN_D6_ON;
}

void turn_off_led_blue_D5 (void)
{
    PORTD = PORTD & ~BLUE_D5_ON;
}

void turn_off_leds_D (void)
{
    PORTD = PORTD & ALL_D_LEDS_OFF;
}

void turn_off_led_cyan_D6D7 (void)
{
    PORTD = PORTD & ~CYAN_D6D7_ON;
}