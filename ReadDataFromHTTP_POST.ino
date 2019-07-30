#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

WiFiClient wificlient;
ESP8266WebServer webserver(80);

void callBack(){
    webserver.send(200, "text/html", "<h1>You are connected</h1>");    
}

void configMode(){
    if(webserver.hasArg("plain")==false){
        webserver.send(200,"text/html","<h1>Body not included!</h1>");
    }
    else {
        Serial.println("Body recieved:");
        Serial.println(webserver.arg("plain"));
        webserver.send(200,"text/html","<h1> Body recieved !</h1>");
    }
}

void setup(){
    Serial.begin(115200);
    WiFi.softAP("ESP_softAP");
    Serial.println("SoftAP created !");
    Serial.println(WiFi.softAPIP());
    webserver.on("/",callBack);
    webserver.on("/config",HTTP_POST,configMode);
    webserver.begin();
    delay(2000);
}
void loop(){
    webserver.handleClient(); 
}
