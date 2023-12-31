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
    if (https.begin(*client, "https://api.pxserv.net/api/plain/set"))
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
          String payload = https.getString();
          if (payload.startsWith("PXSERV+ERR="))
          {
            payload.replace("PXSERV+ERR=", "");
            String errCode = payload;

            if (errCode == "INVALID_AUTH")
              status = 401;
            else if (errCode == "INVALID_PARAMS")
              status = 204;
          }
          else if (payload.startsWith("PXSERV+DATA="))
          {
            payload.replace("PXSERV+DATA=", "");
            String dataCode = payload;

            if (dataCode == "OK")
              status = 200;
          }
          else
            status = 400;
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
      status = 1;
    }
  }
  else
  {
    status = 1;
  }
  delete client;
  return status;
}
String PxServ::get(String key)
{

  WiFiClientSecure *client = new WiFiClientSecure;

  int status = 200;
  String data = "PXSERV+DATA=NOT_READING";

  if (client)
  {
    client->setInsecure();

    HTTPClient https;

    String token = PxServ::token;
    if (https.begin(*client, "https://api.pxserv.net/api/plain/get"))
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
          String payload = https.getString();
          if (payload.startsWith("PXSERV+ERR="))
          {
            payload.replace("PXSERV+ERR=", "");
            String errCode = payload;

            if (errCode == "INVALID_AUTH")
              status = 401;
            else if (errCode == "INVALID_PARAMS")
              status = 204;
            else if (errCode == "INVALID_DATA_KEY")
              status = 206;
          }
          else if (payload.startsWith("PXSERV+DATA="))
          {
            payload.replace("PXSERV+DATA=", "");
            data = payload;

            status = 200;
          }
          else
            status = 400;
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
      status = 1;
    }
  }
  else
  {
    status = 1;
  }
  delete client;
  return data;
}
String PxServ::getAll() {}
int PxServ::del(String key)
{

  WiFiClientSecure *client = new WiFiClientSecure;
  int status = 200;
  if (client)
  {
    client->setInsecure();

    HTTPClient https;

    String token = PxServ::token;
    if (https.begin(*client, "https://api.pxserv.net/api/plain/delete"))
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
          String payload = https.getString();
          if (payload.startsWith("PXSERV+ERR="))
          {
            payload.replace("PXSERV+ERR=", "");
            String errCode = payload;

            if (errCode == "INVALID_AUTH")
              status = 401;
            else if (errCode == "INVALID_PARAMS")
              status = 204;
            else if (errCode == "INVALID_DATA_KEY")
              status = 206;
          }
          else if (payload.startsWith("PXSERV+DATA="))
          {
            payload.replace("PXSERV+DATA=", "");
            String dataCode = payload;

            if (dataCode == "OK")
              status = 200;
          }
          else
            status = 400;
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
      status = 1;
    }
  }
  else
  {
    status = 1;
  }
  delete client;
  return status;
};