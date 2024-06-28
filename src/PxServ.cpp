#include "PxServ.h"

PxServ::PxServ(String apiKey)
{
  _apiKey = apiKey;
}

PxServ::Callback PxServ::set(String key, String value)
{
  WiFiClientSecure *client = new WiFiClientSecure;
  Callback callback;

  callback.status = -1;
  callback.message = "failed to send request";

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
          callback.status = 400;
          callback.message = "Response format not appropriate";
        }
        else
        {
          int status = result["status"];
          String message = result["message"];

          callback.status = status;
          callback.message = message;
        }

        https.end();
      }
    }
  }

  delete client;
  return callback;
}