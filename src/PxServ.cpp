#include "PxServ.h"

PxServ::PxServ(String apiKey)
{
  _apiKey = apiKey;
}

int PxServ::set(String key, String value)
{
  WiFiClientSecure *client = new WiFiClientSecure;
  int status = -1;

  if (client)
  {
    client->setInsecure();

    HTTPClient https;

    if (https.begin(*client, "https://api.pxserv.net/database/setData"))
    {
      https.addHeader("Content-Type", "application/json");

      int httpCode = https.POST("{\"key\":\"" + key +
                                "\",\"value\":\"" + value + "\",\"apiKey\":\"" + _apiKey + "\"}");
      if (httpCode > 0)
      {

        String payload = https.getString();
        JSONVar result = JSON.parse(payload);

        if (JSON.typeof(result) != "object")
        {
          status = 400;
        }
        else
        {

          status = result["status"]
        }

        https.end();
      }
    }
  }

  delete client;
  return status;
}