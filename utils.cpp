#include "utils.h"
void show_startup_message() {

  lcd_display_text(0, 0, " KEAMANAN PINTU ");
  lcd_display_text(0, 1, "   KELOMPOK 1  ");
  delay(2000);
  lcd_clear();
}

void wifi_connected_message() {
  lcd_display_text(0, 0, "WiFi Connected");
  lcd_display_text(0, 1, "Tunggu Bentar...");
  delay(3000);
  lcd_clear();
}