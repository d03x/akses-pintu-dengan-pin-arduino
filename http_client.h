#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>


String fetch_server_data(const String& url);

#endif