#ifndef KEYPAD_UTILS_H

#define KEYPAD_UTILS_H
#include <Keypad_I2C.h>
#include <Wire.h>

// Inisialisasi keypad
extern Keypad_I2C keypad;
void keypad_setup();
char keypad_get_key();
#endif