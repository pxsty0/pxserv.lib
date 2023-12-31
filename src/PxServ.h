
#ifndef PxServ_h
#define PxServ_h

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
  void login(String token);

  int set(String key, String value);
  String get(String key);
  String getAll();
  int del(String key);

private:
  String token;
};

#endif