# atst_aa_rev03a

testing-ee-aa- current.  (Friday, 15 Nov 2019 at 00:07 UTC)

Current target: Adafruit Metro M0 Express w/Pimoroni Blinkt attached.
D6 D7 to talk to the DotStar (see the files, atmel_start_pins.h and
dotstar.c for details).

A glance at config/peripheral_clk_config.h (in November 2019) indicates
a CPU freq of 1 mHz:

 #define CONF_CPU_FREQUENCY 1000000

was: testing-ee current.  (Sunday, 29 July at 02:20 UTC)

This branch (testing-ee-aa-) has a functional Pimoroni Blinkt
demonstration program.  The Blinkt uses APA102 ('dotstar')
RGB led technology.

See: http://adafru.it/3341 - APA102
See: http://adafru.it/3195 - Pimoroni Blinkt!

Technique used is to bitbang the Blinkt, using GPIO, just as
one would for a shift register.

Simple.  And it works.

older news:

Branch master has a functioning LED blinkie.

Moving forward, branch testing-dd is retired.  New program
development will be on branch testing-ee.

Current program is good for the Adafruit Feather M0 Express,
their CPX and Metro M0 Express (most likely will function
with any ATSAMD21G18-AU board that has a traditional D13 LED
mapped onto PA17).

Sun Jul 29 02:19:44 UTC 2018
