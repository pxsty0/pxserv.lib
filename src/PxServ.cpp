#include "PxServ.h"

void PxServ::login(String token)
{
  PxServ::token = token;
}

bool set(String key, String value)
{
  WiFiClientSecure *client = new WiFiClientSecure;
  bool ok = false;

  // Eğer WiFiClientSecure nesnesi başarıyla oluşturulduysa devam et
  if (client)
  {
    client->setInsecure();

    HTTPClient https;

    if (https.begin(*client, "https://api.pxserv.net/api/set"))
    {
      StaticJsonDocument<500> json;
      String jsonData = "";

      json["token"] = PxServ::token;
      json["key"] = key;
      json["value"] = value;

      serializeJson(json, jsonData);
      https.addHeader("Content-Type", "application/json");

      int httpCode = https.POST(jsonData);

      // Eğer HTTP yanıt kodu alındıysa
      if (httpCode > 0)
      {
        // Başarılı bir yanıt kodu mu kontrol et
        if (httpCode == HTTP_CODE_OK ||
            httpCode == HTTP_CODE_MOVED_PERMANENTLY ||
            httpCode == HTTP_CODE_NO_CONTENT)
        {
          // İşlem başarılı oldu
          ok = true;
        }
        else
        {
          // İşlem başarısız oldu
          ok = false;
        }

        // İsteği sonlandır
        https.end();
      }
      else
      {
        // HTTP isteği başarısız oldu
        ok = false;
      }
    }
    else
    {
      // HTTPS bağlantısı başlatılamadı
      ok = false;
    }
  }
  else
  {
    // WiFiClientSecure nesnesi oluşturulamadı
    ok = false;
  }
}
String get(String key){};
String getAll(){};
String delete(String key){};