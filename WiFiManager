#include <ESP8266WiFi.h>        
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "WiFiManager.h"        

//////////////////ESP loads in STA mode, if connection fails, this function will be called//////////////////////it can be concluded
void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

void setup() {
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.setAPCallback(configModeCallback);
  if(!wifiManager.autoConnect("ESPTest","password")) {      /////////////////////will use "ESPTest" and  "password" for access point///both optional
    Serial.println("failed to connect");                    ////////////connect to AP and request ip printed in monitor to configure wifi
    ESP.reset();
    delay(1000);
  }  
}
//if it gets to loop,device has connected
void loop() {
  Serial.println("connected.)");
}
