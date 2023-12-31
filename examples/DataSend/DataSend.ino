#include <WiFi.h>
#include <PxServ.h>

PxServ pxserv;

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
  pxserv.login(""); // PxServ API Key
}

void loop()
{

  int status1 = pxserv.set("msg", "Hello Earth");

  String msg = pxserv.get("msg");

  int status2 = pxserv.del("msg");

  Serial.println("Status 1 : " + String(status1));
  Serial.println("Status 2 : " + String(status2));
  Serial.println("Mesaj : " + String(msg));

  delay(1000);
}
