#ifndef WIFI_UTILS_H

#define WIFI_UTILS_H

#include <ESP8266WiFi.h>
#include "lcd_utils.h"
#include "utils.h"

extern const char* ssid;
extern const char* password;

void wifi_connect();

#endif