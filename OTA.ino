#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPUpdateServer.h>

ESP8266HTTPUpdateServer httpupdater;
ESP8266WebServer httpserver(80) ;

void setup(){
  WiFi.begin("SSID","PASSWORD");
  while(WiFi.status() != WL_CONNECTED){ delay(1000);}
  httpupdater.setup(&httpserver,"/update","test","1234"); //creates a update server at local address/update with username "test" and password "1234"
  httpserver.begin();
}
void loop(){
httpserver.handleClient();
}
