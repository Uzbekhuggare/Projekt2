#include "header.h"

static void delay_ms(const volatile uint16_t* delay_time_ms) {
	for (int i = 0; i < *delay_time_ms; i++) {
		_delay_ms(1);
	}
}

void led_blink(volatile uint16_t* blink_speed_ms) {
	ALL_LEDS_OFF;
	LED1_ON;
	delay_ms(blink_speed_ms);
	LED1_OFF;
	LED2_ON;
	delay_ms(blink_speed_ms);
	LED2_OFF;
	LED3_ON;
	delay_ms(blink_speed_ms);
	lED3_OFF;
}

