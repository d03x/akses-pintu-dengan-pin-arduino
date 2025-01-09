#include "lcd_utils.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcd_setup() {
  lcd.init();
  lcd.backlight();
  lcd_clear();
}

void lcd_display_text(uint8_t column, uint8_t rows, String text) {
  lcd.setCursor(column, rows);
  lcd.print(text);
}

void lcd_clear() {
  lcd.clear();
}
