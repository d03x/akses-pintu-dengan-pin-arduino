#include "keypad_utils.h"
// Alamat I2C PCF8574T
#define I2C_ADDR 0x20       // Pastikan ini sesuai dengan hasil I2C Scanner
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

void keypad_setup() {
  Wire.begin();
  keypad.begin();
}
char keypad_get_key() {
  return keypad.getKey();
}