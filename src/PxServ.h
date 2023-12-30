
#ifndef PxServ_h
#define PxServ_h

#include <Arduino.h>

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

  bool set(String name, String value);
  bool get(String name);

private:
  String token;
};

#endif