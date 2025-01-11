#include "http_client.h"



String fetch_server_data(const String& url) {
  WiFiClient client;
  HTTPClient http;
  String response = "";
  if (http.begin(client, url)) {
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      if (httpResponseCode == HTTP_CODE_OK) {
        response = http.getString();  // Ambil respons
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpResponseCode).c_str());
        response = "ERROR";
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpResponseCode).c_str());
      response = "ERROR";
    }
    http.end();
  }
  return response;
}