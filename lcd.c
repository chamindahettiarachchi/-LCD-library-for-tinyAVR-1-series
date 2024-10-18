
#include "lcd.h"
#include <util/delay.h>  // For delay functions

// Send a nibble (4 bits) to the LCD
void lcd_send_nibble(uint8_t nibble) {
	if (nibble & (1 << 0)) VPORTA.OUT |= LCD_D4; else VPORTA.OUT &= ~LCD_D4;
	if (nibble & (1 << 1)) VPORTA.OUT |= LCD_D5; else VPORTA.OUT &= ~LCD_D5;
	if (nibble & (1 << 2)) VPORTA.OUT |= LCD_D6; else VPORTA.OUT &= ~LCD_D6;
	if (nibble & (1 << 3)) VPORTA.OUT |= LCD_D7; else VPORTA.OUT &= ~LCD_D7;

	// Pulse the Enable pin
	VPORTA.OUT |= LCD_E;
	_delay_us(1);
	VPORTA.OUT &= ~LCD_E;
	_delay_us(100);
}

// Send a byte (two nibbles) to the LCD
void lcd_send_byte(uint8_t byte) {
	lcd_send_nibble(byte >> 4);  // Upper nibble
	lcd_send_nibble(byte & 0x0F);  // Lower nibble
}

// Send a command to the LCD
void lcd_command(uint8_t cmd) {
	VPORTA.OUT &= ~LCD_RS;  // RS = 0 for command
	lcd_send_byte(cmd);
	_delay_ms(2);  // Command processing delay
}

// Send data (a character) to the LCD
void lcd_data(uint8_t data) {
	VPORTA.OUT |= LCD_RS;  // RS = 1 for data
	lcd_send_byte(data);
	_delay_us(100);  // Data processing delay
}

// Initialize the LCD
void lcd_init(void) {
	VPORTA.DIR |= LCD_RS | LCD_E | LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7;  // Set LCD pins as output

	_delay_ms(50);  // Wait for LCD to power up

	lcd_send_nibble(0x03);
	_delay_ms(5);
	lcd_send_nibble(0x03);
	_delay_us(100);
	lcd_send_nibble(0x03);
	_delay_ms(1);
	lcd_send_nibble(0x02);  // Set 4-bit mode

	lcd_command(0x28);  // Function set: 4-bit mode, 2 lines, 5x8 dots
	lcd_command(0x0C);  // Display control: display on, cursor off, no blink
	lcd_command(0x06);  // Entry mode: increment cursor
	lcd_clear();        // Clear display
}

// Clear the LCD
void lcd_clear(void) {
	lcd_command(0x01);  // Clear display
	_delay_ms(2);       // Wait for clear to complete
}

// Print a string on the LCD
void lcd_print(const char* str) {
	while (*str) {
		lcd_data(*str++);
	}
}

// Set cursor position on the LCD (row and column)
void lcd_set_cursor(uint8_t row, uint8_t column) {
	uint8_t address;

	// Calculate the address based on row and column
	if (row == 0) {
		address = 0x00 + column;  // Row 0
		} else if (row == 1) {
		address = 0x40 + column;  // Row 1
		} else {
		return;  // Invalid row, do nothing
	}

	// Send the command to set the DDRAM address
	lcd_command(0x80 | address);
}
