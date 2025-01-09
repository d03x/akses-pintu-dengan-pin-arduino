#ifndef LCD_UTILS_H
#define LCD_UTILS_H ;
#include <LiquidCrystal_I2C.h>
extern LiquidCrystal_I2C lcd;

void lcd_setup();
void lcd_display_text(uint8_t column, uint8_t rows, String text);
void lcd_clear();
#endif