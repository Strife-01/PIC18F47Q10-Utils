#ifndef CURIOSITY_LEDS_MODULE_H
#define	CURIOSITY_LEDS_MODULE_H

#include <xc.h>

#define LED_D2_ON 0b00010000;
#define LED_D3_ON 0b00100000;
#define LED_D4_ON 0b01000000;
#define LED_D5_ON 0b10000000;

// Setup leds
void curiosity_leds_setup (void); // TEST OK
void colored_leds_setup (void); // Test OK

// Power on led functions
void turn_on_led_D2 (void); // Port A4 - TEST OK
void turn_on_led_D3 (void); // Port A5 - TEST OK
void turn_on_led_D4 (void); // Port A6 - TEST OK
void turn_on_led_D5 (void); // Port A7 - TEST OK

// Power off led functions
void turn_off_led_D2 (void); // Port A4 - TEST OK
void turn_off_led_D3 (void); // Port A5 - TEST OK
void turn_off_led_D4 (void); // Port A6 - TEST OK
void turn_off_led_D5 (void); // Port A7 - TEST OK

// Power on Colored Leds
void turn_on_led_red_D7 (void); // Test OK
void turn_on_led_green_D6 (void); // Test OK
void turn_on_led_blue_D5 (void); // Test OK
void turn_on_led_cyan_D6D7 (void); // Test OK
void turn_on_led_yellow_D5D6 (void);
void turn_on_led_magenta_D5D7 (void);
void turn_on_led_white_D5D6D7 (void);

// Power off Colored Leds
void turn_off_led_red_D7 (void); // Test OK
void turn_off_led_green_D6 (void); // Test OK
void turn_off_led_blue_D5 (void); // Test OK
void turn_off_led_cyan_D6D7 (void);

void turn_off_leds_D (void); // Test OK

#endif	/* CURIOSITY_LEDS_MODULE_H */

