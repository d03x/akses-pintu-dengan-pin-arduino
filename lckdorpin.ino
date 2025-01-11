#include "lcd_utils.h"
#include "utils.h"
#include "wifi_utils.h"
#include <ESP8266HTTPClient.h>
#include "http_client.h"
#include <Keypad_I2C.h>
#include <Wire.h>
unsigned long lastTime = 0;
unsigned long timeDelay = 5000;
#define RELAY_LOCKDOR D7;
//keypad setup

// Alamat I2C PCF8574T
#define I2C_ADDR 0x20  // Pastikan ini sesuai dengan hasil I2C Scanner

// Ukuran keypad
const byte ROW_NUM = 4;     // Jumlah baris
const byte COLUMN_NUM = 4;  // Jumlah kolom

// Definisi tombol keypad
char keys[ROW_NUM][COLUMN_NUM] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// Pemetaan pin PCF8574 ke baris dan kolom
byte pin_rows[ROW_NUM] = { 0, 1, 2, 3 };        // Pin 0-3 untuk baris
byte pin_columns[COLUMN_NUM] = { 4, 5, 6, 7 };  // Pin 4-7 untuk kolom

// Inisialisasi keypad
Keypad_I2C keypad = Keypad_I2C(makeKeymap(keys), pin_rows, pin_columns, ROW_NUM, COLUMN_NUM, I2C_ADDR);
String keyboard = "";


void setup() {
  Serial.begin(115200);
  Wire.begin();
  /*** BEGIN KEYPAD ***/
  keypad.begin();
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

  char key = keypad.getKey();
  lcd_display_text(0, 0, "Masukan PIN:");
  if (key) {
    if (key == '*') {
      if (keyboard.length() > 0) {
        keyboard.remove(keyboard.length() - 1);
      }
    } else if (key != '#') {
      keyboard += String(key);
    }
  }

  lcd_display_text(0, 1, "                ");
  lcd_display_text(0, 1, String(keyboard));
  if (key == '#') {
    if (wifi_connected_status()) {
      //clear dulu semua display
      String url = "http://192.168.43.50/kelompok1_arduino/arduino.php?type=keypad&pin=" + keyboard;
      String payload = fetch_server_data(url);
      lcd_clear();
      if (payload == "ERROR") {
        lcd_display_text(1, 0, "Gagal Koneksi ke url");
      } else {
        if (payload == "VALID") {
          lcd_display_text(0, 0, "PIN BENAR");
          lcd_display_text(0, 1, "Hello DADAN");
        } else if (payload == "SALAH") {
          lcd_display_text(0, 0, "PIN SALAH");
          lcd_display_text(0, 1, "COBA LAGI :)");
        }
      }
      keyboard = "";
      delay(5000);
    }
  }
  //wifi dulu haus konek
}
