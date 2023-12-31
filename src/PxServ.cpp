#include "PxServ.h"

void PxServ::login(String token)
{
  PxServ::token = token;
}

int PxServ::set(String key, String value)
{
  WiFiClientSecure *client = new WiFiClientSecure;
  int status = 200;
  if (client)
  {
    client->setInsecure();

    HTTPClient https;

    String token = PxServ::token;
    if (https.begin(*client, "http://api.pxserv.net/api/plain/set"))
    {
      https.addHeader("Content-Type", "application/json");

      int httpCode = https.POST("{\"token\":\"" + token +
                                "\",\"key\":\"" + key + "\",\"value\":\"" + value + "\"}");
      if (httpCode > 0)
      {
        if (httpCode == HTTP_CODE_OK ||
            httpCode == HTTP_CODE_MOVED_PERMANENTLY ||
            httpCode == HTTP_CODE_NO_CONTENT)
        {

          status = 200;
        }
        else
        {
          status = 1;
        }
        https.end();
      }
      else
      {
        status = 1;
      }
    }
    else
    {
      status = 2;
    }
  }
  else
  {
    status = 3;
  }
  delete client;
  return status;
}
String PxServ::get(String key)
{
  WiFiClientSecure *client = new WiFiClientSecure;

  int status = 200;
  String data = "!";

  if (client)
  {
    client->setInsecure();

    HTTPClient https;

    String token = PxServ::token;
    if (https.begin(*client, "https://cdn.anicordapp.net/api/plain/get"))
    {
      https.addHeader("Content-Type", "application/json");

      int httpCode = https.POST("{\"token\":\"" + token +
                                "\",\"key\":\"" + key + "\"}");
      if (httpCode > 0)
      {
        if (httpCode == HTTP_CODE_OK ||
            httpCode == HTTP_CODE_MOVED_PERMANENTLY ||
            httpCode == HTTP_CODE_NO_CONTENT)
        {
          data = https.getString();
          status = 200;
        }
        else
        {
          status = 1;
        }
        https.end();
      }
      else
      {
        status = 1;
      }
    }
    else
    {
      status = 2;
    }
  }
  else
  {
    status = 3;
  }
  delete client;
  return data;
}
int PxServ::del(String key){};