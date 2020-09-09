//
// GENG 421 - Gus Brigantino
//
// Session 19 - Compact Embedded printf()
//

#include <stdio.h>

#include "geng421.h"
#include "clock.h"
#include "colors.h"
#include "eprintf.h"
#include "gpio.h"
#include "rgb.h"
#include "uart.h"
#include "nav.h"
#include "game.h"
#include "lcd.h"

int main(void)
{
	// Initialize hardware
	ClockInit();
	GpioInit();
	UartInit();
	NavInit();
	LcdInit();

	// Main loop
	while (TRUE)
	{
		// Wait for the 1msec tick timer
		ClockWaitForTick();

		NavClock();
		RocketReactions();

	} // End - main loop
}
