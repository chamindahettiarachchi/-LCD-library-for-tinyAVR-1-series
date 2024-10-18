
#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>  // Include standard AVR IO library

// LCD pin definitions (customize based on your setup)
#define LCD_RS PIN2_bm  // Register Select (RS) pin on PA2
#define LCD_E  PIN3_bm  // Enable (E) pin on PA3
#define LCD_D4 PIN4_bm  // Data pin D4 on PA4
#define LCD_D5 PIN5_bm  // Data pin D5 on PA5
#define LCD_D6 PIN6_bm  // Data pin D6 on PA6
#define LCD_D7 PIN7_bm  // Data pin D7 on PA7

// Function prototypes
void lcd_init(void);               // Initialize LCD
void lcd_clear(void);              // Clear LCD
void lcd_print(const char* str);   // Print a string on the LCD
void lcd_command(uint8_t cmd);     // Send a command to the LCD
void lcd_data(uint8_t data);       // Send data to the LCD
void lcd_set_cursor(uint8_t row, uint8_t column); // Set cursor to specific row and column

#endif 
