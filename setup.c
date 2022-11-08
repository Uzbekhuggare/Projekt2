#include "header.h"

static inline void init_ports();
static inline void init_interrupts();

void setup() {
	init_ports();
	init_interrupts();
	fsm_reset();
	return;
}

static inline void init_ports() {
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3);
	PORTD = (1 << RESET_BUTTON) | (1 << BUTTON4);
	return;
}

static inline void init_interrupts() {
	sei();
	PCICR = (1 << PCIE0);	
	PCMSK0	= (1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3);
	
	EICRA = (1 << ISC11) | (1 << ISC10) | (1 << ISC01); // Pin 3 stigande, pin 2 fallande.
	EIMSK = (1 << INT0) | (1 << INT1); // Sätter på avbrott på pin 2 - 3.
	return;
}