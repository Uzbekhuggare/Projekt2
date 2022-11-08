#include "header.h"

ISR(INT0_vect) {	//återställer direkt tillståndsmaskinen vid nedtryckning av reset_knappen
	
	fsm_reset();
	return;
}

ISR(INT1_vect)
{
	fsm_update();
	return;
}

ISR(PCINT0_vect) {	//om någon av knapparna pin 11 - 13 trycks ned så uppdateras tillståndsmaskinens tillstånd
	
	if (BUTTON1_PRESSED || BUTTON2_PRESSED || BUTTON3_PRESSED) {
		fsm_update();
	}
	return;
}