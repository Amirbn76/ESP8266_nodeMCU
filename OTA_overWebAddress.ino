//I placed a .bin file in my webpage which makes D0 pin start blinking

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>

ESP8266WiFiMulti WiFiMulti;
const char* ssid = "your ssid";
const char* password = "your password";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid,password);
  while((WiFiMulti.run() != WL_CONNECTED)) {
    Serial.println("trying to connect to Wifi");
    delay(500);
  }
  /*************uncomment this part to test net, there is a test.txt in my page****************/
  //HTTPClient httpclient;
  // httpclient.begin("http://ee.sharif.edu/~amirhossein.binesh/test.txt");
  // int httpCode = httpclient.GET();
  // if( httpCode == 200 ) {
  //   String teststring = httpclient.getString();
  //   Serial.println(teststring);
  // }
  // httpclient.end();
  /****************--------------------------------------------------------********************/
}
void loop() {

    WiFiClient client;

    t_httpUpdate_return ret = ESPhttpUpdate.update("http://ee.sharif.edu/~amirhossein.binesh/Firmware/‌Blink_D0_ESP8266.bin");
    Serial.println("Something went wrong");       //code should never get here
    switch (ret) {
      case HTTP_UPDATE_FAILED:
        Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
        break;

      case HTTP_UPDATE_NO_UPDATES:
        Serial.println("HTTP_UPDATE_NO_UPDATES");
        break;

      case HTTP_UPDATE_OK:
        Serial.println("HTTP_UPDATE_OK");
        break;
      default:
        Serial.println("HTTP_UPDATE_DEFAULT");
        break;
    }
}
