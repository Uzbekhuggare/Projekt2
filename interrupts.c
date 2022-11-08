#include "header.h"

ISR(INT0_vect) {	//�terst�ller direkt tillst�ndsmaskinen vid nedtryckning av reset_knappen
	
	fsm_reset();
	return;
}

ISR(INT1_vect)
{
	fsm_update();
	return;
}

ISR(PCINT0_vect) {	//om n�gon av knapparna pin 11 - 13 trycks ned s� uppdateras tillst�ndsmaskinens tillst�nd
	
	if (BUTTON1_PRESSED || BUTTON2_PRESSED || BUTTON3_PRESSED) {
		fsm_update();
	}
	return;
}