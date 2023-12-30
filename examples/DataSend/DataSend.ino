#include <WiFi.h>
#include <PxServ.h>

PxServ client;

#define WIFI_SSID "" // Wifi Adı
#define WIFI_PASS "" // Wifi Şifresi

void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Wi-Fi Baglanıyor...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
  }
  Serial.println("Baglandi");
  client.login("");
}

void loop()
{
}