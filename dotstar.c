// dotstar.c

#include "driver_init.h"

// During early testing (16:38z 28 July) D13 is
// substituted for D7 to verify gpio technique.

// This perforce displaces correct D13 operation,
// already established.  Correct use commented out.

// This (incorrect) use of D13 currently in operation.

#define PINN D13 // D7

void init_dotstar_gpio(void) {
    gpio_set_pin_direction(PINN, GPIO_DIRECTION_OUT);
}

void raise_DS_CLOCK(void) {
	// GPIO on PA21 - D7 - Dotstar Clock

	// Set pin direction to output
	// gpio_set_pin_direction(D7,  GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PINN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// gpio_set_pin_function(D7,  GPIO_PIN_FUNCTION_OFF);
}

void lower_DS_CLOCK(void) {
	// GPIO on PA21 - D7 - Dotstar Clock

	// Set pin direction to output
	// gpio_set_pin_direction(D7,  GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PINN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// gpio_set_pin_function(D7,  GPIO_PIN_FUNCTION_OFF);
}

