#include "header.h"

static LED_STATE_t state = STATE_OFF;
uint16_t speed_ms = 0;

void fsm_reset() {
	state = STATE_OFF;
	speed_ms = 0;
	return;	
}

void fsm_update() {
	
	switch (state) {
		
		case STATE_OFF: {
			if (BUTTON1_PRESSED) {
				state = STATE_ON;
				speed_ms = 0;
			}
			else if (BUTTON2_PRESSED) {
				state = STATE_SLOW;
				speed_ms = 500;
			}
			else if (BUTTON3_PRESSED) {
				state = STATE_MEDIUM;
				speed_ms = 250;
			}
			else if (BUTTON4_PRESSED) {
				state = STATE_FAST;
				speed_ms = 50;
			}
			break;
		}
		case STATE_ON: {
			if (BUTTON1_PRESSED) {
				state = STATE_FAST;
				speed_ms = 50;
			}
			else if (BUTTON2_PRESSED) {
				state = STATE_OFF;
				speed_ms = 0;
			}
			else if (BUTTON3_PRESSED) {
				state = STATE_MEDIUM;
				speed_ms = 250;
			}
			else if (BUTTON4_PRESSED) {
				state = STATE_SLOW;
				speed_ms = 500;
			}
			break;	
		}
		case STATE_FAST: {
			if (BUTTON1_PRESSED) {
				state = STATE_MEDIUM;
				speed_ms = 250;
			}
			else if (BUTTON2_PRESSED) {
				state = STATE_ON;
				speed_ms = 0;
			}
			else if (BUTTON3_PRESSED) {
				state = STATE_OFF;
				speed_ms = 0;
			}
			else if (BUTTON4_PRESSED) {
				state = STATE_SLOW;
				speed_ms = 500;
			}
			break;
		}
		case STATE_MEDIUM: {
			if (BUTTON1_PRESSED) {
				state = STATE_SLOW;
				speed_ms = 500;
			}
			else if (BUTTON2_PRESSED) {
				state = STATE_FAST;
				speed_ms = 50;
			}
			else if (BUTTON3_PRESSED) {
				state = STATE_OFF;
				speed_ms = 0;
			}
			else if (BUTTON4_PRESSED) {
				state = STATE_ON;
				speed_ms = 0;
			}
			break;
		}
		case STATE_SLOW: {
			if (BUTTON1_PRESSED) {
				state = STATE_OFF;
				speed_ms = 0;
			}
			else if (BUTTON2_PRESSED) {
				state = STATE_MEDIUM;
				speed_ms = 250;
			}
			else if (BUTTON3_PRESSED) {
				state = STATE_FAST;
				speed_ms = 50;
			}
			else if (BUTTON4_PRESSED) {
				state = STATE_ON;
				speed_ms = 0;
			}
			break;
		}
		default: {
			fsm_reset();
			break;
		}
	}	
	
	fsm_set_output();
	return;
}


void fsm_set_output() {
	ALL_LEDS_OFF;
	
	if (state == STATE_ON) ALL_LEDS_ON;
	else if (state == STATE_OFF) ALL_LEDS_OFF;
	else if (state == STATE_FAST || state == STATE_MEDIUM || state == STATE_SLOW) led_blink(&speed_ms);
	return;
}

