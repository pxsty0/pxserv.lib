# PxServ
## Usage / Example
```cpp
#include <WiFi.h>
#include <PxServ.h>

#define WIFI_SSID "" // Wi-Fi Adı
#define WIFI_PASS "" // Wi-Fi Şifresi

PxServ client("y5WWh16PKRkqBepq0R6wwF3aEkoQPg15"); // PxServ Proje API Key

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
}

void loop()
{

  PxServ::Callback setResult = client.setData("msg", "value"); // veri eklendi
  Serial.println("set result -> status : " + String(setResult.status) + " | message : " + String(setResult.message) + " | data : " + String(setResult.data));

  delay(2000);

  PxServ::Callback getResult = client.getData("msg"); // veri getirildi
  Serial.println("get result -> status : " + String(getResult.status) + " | message : " + String(getResult.message) + " | data : " + String(getResult.data));

  delay(2000);

  PxServ::Callback removeResult = client.removeData("msg"); // veri kaldırıldı
  Serial.println("remove result -> status : " + String(removeResult.status) + " | message : " + String(removeResult.message) + " | data : " + String(removeResult.data));

  delay(2000);
}```
