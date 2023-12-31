#include <WiFi.h>
#include <PxServ.h>

PxServ db;

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
  db.login(""); // APIKEY
}

void loop()
{

  db.set("msg", "Hello World");

  String msg = db.get("msg");

  Serial.println("Mesaj : " + String(msg));

  delay(1000);
}
