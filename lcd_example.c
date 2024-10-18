#define F_CPU 3333333UL
#include <avr/io.h>
#include <stdlib.h>
#include "attinyLCDlib/lcd.h"
#include "attinyLCDlib/lcd.c"
int count =0;
char buffer[10];
int main(void) {
	lcd_init();  // Initialize the LCD

	// Set cursor to Row 0, Column 5 and print "Hello"
	lcd_set_cursor(0, 5);
	lcd_print("Hello");

	// Set cursor to Row 1, Column 3 and print "World!"
	lcd_set_cursor(1, 5);
	lcd_print("World!");
	_delay_ms(5000);
	lcd_clear();
	lcd_set_cursor(0,0);
	lcd_print("value =");

	while (1) {
		lcd_set_cursor(0,8);
		count += 1;
		itoa(count, buffer, 10);
		lcd_print(buffer);
		_delay_ms(1000);
		
		
		
		
		// Main loop
	}
}
