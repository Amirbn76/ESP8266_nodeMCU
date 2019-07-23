#include <Arduino.h>              //
#include <ESP8266HTTPClient.h>    //these two are only used for the internet test part & can be removed
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <PubSubClient.h>

ESP8266WiFiMulti WiFiMulti;
WiFiClient wificlient;
PubSubClient client(wificlient);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("Amir","amiramir");
  while((WiFiMulti.run() != WL_CONNECTED)) {
    Serial.println("trying to connect to Wifi");
    delay(500);
  }
  /********************************internet test********************************************************************/
  HTTPClient httpclient;
  httpclient.begin("http://ee.sharif.edu/~amirhossein.binesh/test.txt");
  int httpCode = httpclient.GET();
  if( httpCode == 200 ) {
    String teststring = httpclient.getString();
    Serial.println(teststring);
  }
  httpclient.end();
/**********************************this should print the word "test" in Serial monitor******************************/
/**********************************if it didn't happen, you're having internet connection issue ********************/

    client.setServer( /*MQTT_server*/ , /*MQTT_port*/ );
     while (!client.connected()) {
        Serial.println("Connecting to MQTT...");
 
        if (client.connect( /*clientName*/ , /*userName*/ , /*password*/ )) {
          Serial.println("connected");  
        }
        else {
          Serial.print("failed with state ");
          Serial.print(client.state());
          delay(2000);
        }
 
     }   
    client.publish( /*topic*/, /*payload*/ );
    client.subscribe( /*topic*/ );

}
void loop() {
 client.loop();
}
