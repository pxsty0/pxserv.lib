#include <WiFi.h>
#include <PxServ.h>
#include <Deneyap_OLED.h> 

#define WIFI_SSID "" // wifi ad
#define WIFI_PASS "" // wifi şifre

PxServ client(""); // pxserv proje apikey
OLED oled;

void setup()
{
  Serial.begin(57600);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Wi-Fi Baglanıyor...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
  }
  Serial.println("Baglandi");
  oled.begin(0x7A);
  oled.clearDisplay();
}

void loop()
{

  PxServ::Callback temp = client.getData("temp");
  PxServ::Callback hum = client.getData("hum");
  PxServ::Callback gesture = client.getData("gesture");


  if(temp.status != 200 || hum.status != 200 || gesture.status != 200) return;

  oled.setTextXY(0,0);
  oled.putString("   PXSERV IOT    ");
  oled.setTextXY(2,0);
  oled.putString("Sicaklik:  "+String(temp.data));
  oled.setTextXY(4,0);
  oled.putString("Nem:       "+String(hum.data));
  oled.setTextXY(6,0);
  String x = gesture.data == "0" ? "YOK" : "VAR";
  oled.putString("Hareket:     "+x);
  
}
