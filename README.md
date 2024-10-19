lcd_init();
Description: Initializes the LCD in 4-bit mode, turns on the display without cursor or blinking, and sets the entry mode to increment the cursor after each character

lcd_clear();
Description: Clears all the characters from the LCD and returns the cursor to the home position (Row 0, Column 0).

lcd_print(const char* str);
Description: Sends the characters of a string to the LCD, printing them one by one starting at the current cursor position.
example: lcd_print("Hello World!");  // Print the string "Hello World!" to the LCD

lcd_set_cursor(uint8_t row, uint8_t column);
Description: Moves the cursor to a specific position on the LCD screen. The cursor will move to the specified row (0 or 1) and column (0–15 for a 16x2 display).
example:  lcd_set_cursor(0,0);

example for printing value:

#include <stdlib.h> // should be added
int count = 0;// declareing a int variable

lcd_set_cursor(0,0);
		count += 1;
		itoa(count, buffer, 10);
		lcd_print(buffer);
