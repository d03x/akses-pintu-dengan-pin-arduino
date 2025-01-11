#include "lcd_utils.h"
#include "utils.h"
#include "wifi_utils.h"
#include <ESP8266HTTPClient.h>
#include "http_client.h"
unsigned long lastTime = 0;
unsigned long timeDelay = 5000;
#define RELAY_LOCKDOR D7;

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
  WiFiClient client;
  HTTPClient http;
  //wifi dulu haus konek
  if ((millis() - lastTime) > timeDelay) {
    if (wifi_connected_status()) {
      //clear dulu semua display
      String url = "http://192.168.43.50/kelompok1_arduino/arduino.php?type=keypad";
      String payload = fetch_server_data(url);
      lcd_clear();
      if (payload == "ERROR") {
        lcd_display_text(1, 0, "Gagal Koneksi ke url");
      } else {
        lcd_display_text(1, 0, payload);
      }
      delay(5000);
    }
    lastTime = millis();
  }
}
