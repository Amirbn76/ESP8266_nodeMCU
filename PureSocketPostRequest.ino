#include <ESP8266WiFi.h>
#include <WiFiClient.h>
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin( /*SSID*/ , /*PASSWORD*/ );
  while((WiFi.status() != WL_CONNECTED)) {
    Serial.println("trying to connect to Wifi");
    delay(500);
  }
server.begin();
}
void loop() {
  WiFiClient client;
  if(client.connect( /*Host*/ ,80)){Serial.println("client connected");}
        Serial.println("sending post request");
        Serial.println();
        String payload = "ESP_Test";
        client.println("POST /*URI*/ HTTP/1.1");
        client.println("Host: /*Host*/");
        client.println("Content-Length: "+String(payload.length()));
        client.println();  
        client.print(payload);
        delay(2000);
        while(client.available()){
          Serial.println("Client available");
          String line = client.readString();
          Serial.println("line:");
          Serial.println(line);
          client.flush();
        }    
        delay(2000);
        client.stop();
}
