#include "wifi_utils.h"

const char* ssid = "Deni Sumargo";
const char* password = "bismilahpakearab";

bool wifi_connected_status() {
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }
  return false;
}

void wifi_connect() {
  lcd_display_text(0, 0, "Setup WiFi...");
  WiFi.begin(ssid, password);
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lcd_display_text(i, 1, "*");
    i++;
    if (i >= 16) {
      i = 0;
      lcd_clear();
      lcd_display_text(0, 0, "Setup Wifi");
    }
  }
  wifi_connected_message();
}