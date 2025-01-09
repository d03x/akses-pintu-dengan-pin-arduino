#include "lcd_utils.h"
#include "utils.h"
#include "wifi_utils.h"
void setup() {
  Serial.begin(115200);
  /*** SETUP LCD ***/
  lcd_setup();
  /*** STARTUP MESSAGE ***/
  show_startup_message();
  /*** WIFI KONEKSI KE WIFI ***/
  wifi_connect();
}
//looping
void loop() {
  if(WiFi.status() == WL_CONNECTED) {
    lcd_clear();
    lcd_display_text(1,0,"Oke Bray");
    delay(5000);
  }
}
