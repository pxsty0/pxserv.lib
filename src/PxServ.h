
#ifndef PxServ_h
#define PxServ_h

#include <Arduino.h>
#include <ArduinoJson.h>

#if defined(ESP32)
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#else
#warning "Kütüphane Sadece Deneyap Kartlar İle Çalışmaktadır"
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#endif

class PxServ
{
public:
  void login(String token);

  bool set(String key, String value);
  String get(String key);
  String getAll();
  String delete(String key);

private:
  String token;
};

#endif