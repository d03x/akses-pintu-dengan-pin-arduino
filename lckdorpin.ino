#include "lcd_utils.h"
#include "utils.h"
#include "wifi_utils.h"
#include "http_client.h"
#include "keypad_utils.h"
#define RELAY_LOCKDOR D0
String pindata = "";
void setup() {
  Serial.begin(115200);
  /*** KEYPAD SETUP ***/
  keypad_setup();
  /*** SETUP LCD ***/
  lcd_setup();
  /*** STARTUP MESSAGE ***/
  show_startup_message();
  /*** WIFI KONEKSI KE WIFI ***/
  wifi_connect();

  pinMode(RELAY_LOCKDOR, OUTPUT);
  digitalWrite(RELAY_LOCKDOR, HIGH);
}
//looping
void loop() {
  char key = keypad_get_key();
  lcd_display_text(0, 0, "Masukan PIN:");
  if (key) {
    if (key == '*') {
      if (pindata.length() > 0) {
        pindata.remove(pindata.length() - 1);
      }
    } else if (key != '#') {
      pindata += String(key);
    }
    lcd_display_text(0, 1, "                ");
    lcd_display_text(0, 1, String(pindata));
  }


  if (key == '#') {
    if (wifi_connected_status()) {
      //clear dulu semua display
      String url = "http://192.168.43.50/kelompok1_arduino/arduino.php?type=keypad&pin=" + pindata;
      String payload = fetch_server_data(url);
      lcd_clear();
      if (payload == "ERROR") {
        lcd_display_text(1, 0, "Gagal Koneksi ke url");
      } else {
        //jika pin salah
        if (payload == "SALAH") {
          lcd_display_text(0, 0, "PIN SALAH");
          lcd_display_text(0, 1, "COBA LAGI :)");
        } else if (payload == "PIN_KOSONG") {
          lcd_display_text(0, 0, "PIN KOSONG");
          lcd_display_text(0, 1, "COBA LAGI :)");
        } else {
          //jika response dari server tidak SALAH
          //parsing dulu karena responya bukan json tapi string pake separator|
          int separatorIndex = payload.indexOf("|");
          if (separatorIndex != -1) {
            String status = payload.substring(0, separatorIndex);
            String nama = payload.substring(separatorIndex + 1);
            if (status == "BENAR") {
              lcd_display_text(0, 0, "PIN BENAR");
              lcd_display_text(0, 1, nama);
              delay(1000);
              lcd_clear();
              digitalWrite(RELAY_LOCKDOR, LOW);
              lcd_display_text(0, 0, "PINTU DIBUKA");
              delay(3000);
              digitalWrite(RELAY_LOCKDOR, HIGH);
              lcd_display_text(0, 0, "PINTU DITUTUP");
              delay(2000);
            }
          } else {
            lcd_display_text(0, 0, "Ada Kesalahan");
            lcd_display_text(0, 1, payload);
          }
        }
      }
      pindata = "";
      delay(2000);
      lcd_clear();
    }
  }
  //wifi dulu haus konek
}
