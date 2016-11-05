#include "UbidotsMicroESP8266.h"
#define TOKEN  "d3eda0afe4ca46860ecf553ed2f243deccb073c6"  // Put here your Ubidots TOKEN
#define WIFISSID "h@ck@th0N_v2"
#define PASSWORD "codE@314"

Ubidots client(TOKEN);
int tds[]={232,324,544,43,242,64,1122,67,98};
int tds1[]={123,234,345,456,567,678,789,900,543,880};
float ph[]={6.6,6.5,7.6,7.9,9.8,12,8.4,4.3,6.7,8.3};
float ph1[]={9.8,8.9,7.8,8.7,6.7,7.6,5.4,4.5,4.7,8.2};
void setup(){
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
}
void loop(){
  for(int i=0;i<10;i++)
  { float value = tds[i];
    float value2 = ph[i];
    client.add("Total Dissolved Salts", value);
    client.add("pH", value2);
    client.sendAll(true);
    }
    float value3=analogRead(A0);
    client.add("Temperature",value3);
    client.sendAll(true);
}

