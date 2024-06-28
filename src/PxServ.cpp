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
  callback.data = "";

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
PxServ::Callback PxServ::get(String key)
{
  WiFiClientSecure *client = new WiFiClientSecure;
  Callback callback;

  callback.status = -1;
  callback.message = "failed to send request";
  callback.data = "";

  if (client)
  {
    client->setInsecure();

    HTTPClient https;

    if (https.begin(*client, "https://api.pxserv.net/database/getData"))
    {
      https.addHeader("Content-Type", "application/json");

      JSONVar body;

      body["key"] = key;
      body["apiKey"] = PxServ::_apiKey;

      int httpCode = https.POST(JSON.stringify(body));
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

          if (status == 200)
          {
            String value = result["data"]["value"];
            callback.data = value;
          }

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
PxServ::Callback PxServ::remove(String key)
{
  WiFiClientSecure *client = new WiFiClientSecure;
  Callback callback;

  callback.status = -1;
  callback.message = "failed to send request";
  callback.data = "";

  if (client)
  {
    client->setInsecure();

    HTTPClient https;

    if (https.begin(*client, "https://api.pxserv.net/database/removeData"))
    {
      https.addHeader("Content-Type", "application/json");

      JSONVar body;

      body["key"] = key;
      body["apiKey"] = PxServ::_apiKey;

      int httpCode = https.POST(JSON.stringify(body));
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
