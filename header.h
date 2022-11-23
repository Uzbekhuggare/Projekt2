#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 36000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define LED1 PORTB0
#define LED2 PORTB1
#define LED3 PORTB2

#define BUTTON1 PORTB3
#define BUTTON2 PORTB4
#define BUTTON3 PORTB5
#define BUTTON4 PORTD3
#define RESET_BUTTON PORTD2

#define LED1_ON PORTB |= (1 << LED1)
#define LED1_OFF PORTB &= ~(1 << LED1)
#define LED2_ON PORTB |= (1 << LED2)
#define LED2_OFF PORTB &= ~(1 << LED2)
#define LED3_ON PORTB |= (1 << LED3)
#define lED3_OFF PORTB &= ~(1 << LED3)

#define BUTTON1_PRESSED (PINB &(1 << BUTTON1))
#define BUTTON2_PRESSED (PINB &(1 << BUTTON2))
#define BUTTON3_PRESSED (PINB &(1 << BUTTON3))
#define BUTTON4_PRESSED (PIND &(1 << BUTTON4))
#define RESET_BUTTON_PRESSED (PIND &(1 << RESET_BUTTON))

#define ALL_LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)
#define ALL_LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3))

typedef enum {
	STATE_OFF,
	STATE_SLOW,
	STATE_MEDIUM,
	STATE_FAST,
	STATE_ON	
}LED_STATE_t;

void setup();
void fsm_reset();
void fsm_update();
void fsm_set_output();
void led_blink(volatile uint16_t* blink_speed_ms);

#endif