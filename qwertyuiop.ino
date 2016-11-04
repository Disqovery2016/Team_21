float val = analogRead(A0);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

#include <ESP8266WiFi.h>
float prevTemp = 0;
const char* server = "api.thingspeak.com";
String apiKey ="UT8GZQDKE9Q63YIB";
const char* MY_SSID = "h@ck@th0N_v2"; 
const char* MY_PWD = "codE@314";
int sent = 0;
void setup() { 
  Serial.begin(115200);
  connectWifi();
  Serial.begin (9600);
 }
 void loop(){
    float value = analogRead(A0);
   value = (value/1024.0)*5000;
float cel = value/10.0;
   sendTemperature(cel);
Serial.print("temperature = ");
Serial.println(cel);
  delay(500);
}

void connectWifi()
{
  Serial.print("Connecting to "+*MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Connected");
  Serial.println("");  
}//end connect

void sendTemperature(long temp)
{  
   WiFiClient client;
  
   if (client.connect(server, 80)) {
   Serial.println("WiFi Client connected ");
   
   String postStr = apiKey;
   postStr += "&field1=";
   postStr += String(temp);
   postStr += "\r\n\r\n";
   
   client.print("POST /update HTTP/1.1\n");
   client.print("Host: api.thingspeak.com\n");
   client.print("Connection: close\n");
   client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
   client.print("Content-Type: application/x-www-form-urlencoded\n");
   client.print("Content-Length: ");
   client.print(postStr.length());
   client.print("\n\n");
   client.print(postStr);
   delay(1000);
   
   }//end if
   sent++;
 client.stop();
}
