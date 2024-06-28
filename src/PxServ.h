
#ifndef PxServ_h
#define PxServ_h
#include <Arduino_JSON.h>

#include <Arduino.h>

#if defined(ESP32)
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#else
#warning "Kütüphane Sadece Deneyap Geliştirme Kartları ve ESP32 ler ile Çalışmaktadır"
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#endif

class PxServ
{
public:
  struct Callback
  {
    int status;
    String message;
  };

  PxServ(String apiKey);
  Callback set(String key, String value);

private:
  String _apiKey;
};

#endif