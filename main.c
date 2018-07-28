#include <atmel_start.h>
#include "thisproject.h" // local include for main.c
#include "gpio_local.h"
#include "dotstar.h"

/* Many changes: by wa1tnr, July 2018 */

// #include "sam.h"
// #include "local_board_init.h"
// #include "PinMap_local.h"
// #include "bsp_gpio.h"
// #include "bsp_neopix.h"

void uSec(void) {
    for (volatile int i = 1; i < 2; i++) { // needs calibration
        // nothing
    }
}

void short_timer(void) { // human blinkie timescale
    uint32_t on_time  = 2140111222; // it's 2147 something ;)
    for(on_time = 21401; on_time > 0; on_time--) {
        uSec();
    }
}

void vy_short_timer(void) { // human blinkie timescale
    uint32_t on_time  = 2140111222; // it's 2147 something ;)
    for(on_time = 344; on_time > 0; on_time--) {
        uSec();
    }
}

void long_timer(void) {
    for(int i =  9; i > 0; i--) {
        short_timer();
    }
}

void blink_LED(void) {
    raise_D13();
    short_timer();
    lower_D13();
    short_timer();
/*
 // gpio_write(int port, int pin, int val)
    gpio_write(PORTA, PIN_ACTIVITY_LED, 1); // PA17
    short_timer();
    gpio_write(PORTA, PIN_ACTIVITY_LED, 0); // PA17
    short_timer();
*/
}

void flicker_LED(void) {
    raise_D13();
    vy_short_timer();
    lower_D13();
    vy_short_timer();
}

void blinkLEDfast(void) {
    for(int i = 15; i > 0; i--) {
        blink_LED();
    }
}

void activity_LED_demo(void) {
    init_act_LED();
    blinkLEDfast();
}

void loop_vy_short_timer(void) {
    for(int i = 12; i > 0; i--) {
        vy_short_timer();
    }
}

void fleck_D7_clock_line(void) {
        raise_DS_CLOCK();
        loop_vy_short_timer();

        lower_DS_CLOCK();
        loop_vy_short_timer();
}

void pulse_D7_clock_twice(void) {
    fleck_D7_clock_line();
    loop_vy_short_timer();
    loop_vy_short_timer();
    fleck_D7_clock_line();
    loop_vy_short_timer();
    loop_vy_short_timer();
}

void loop_D7_clock(void) {
    for(int i = 33; i > 0; i--) {
        pulse_D7_clock_twice();
        short_timer();
    }
}

void demo_D7_clock(void) {
    init_dotstar_gpio();
    loop_D7_clock();
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
        // USB_0_PORT_init(); // redundant?

        // testing of D7 logic using physical D13 (the LED)
        // usual use of D13 commented out during those tests.
        // activity_LED_demo();

        // D7 logic good - using D13
        // demo_D7_clock();

        lower_D13();
        long_timer();

	/* Replace with your application code */
	while (1) {
            flicker_LED();
            long_timer();
	}
}
