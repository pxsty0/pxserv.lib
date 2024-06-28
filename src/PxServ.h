
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
  PxServ(String apiKey);
  int set(String key, String value);

private:
  String _apiKey;
};

#endif