#include<ESP8266WiFi.h>
#include<ThingSpeak.h>

int channel=2454779;
char *apikey="SDN34SVMFBS1Q432";

char *ssid="VASIREDDY RAMBABU";
char *password="vasireddy@123";
WiFiClient client;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.print("Wifi Connected");
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){

      String data=Serial.readString();
      
      String field1, field2, field3, field4, field5;
      int commaIndex1 = data.indexOf(',');
      int commaIndex2 = data.indexOf(',', commaIndex1 + 1);
      int commaIndex3 = data.indexOf(',', commaIndex2 + 1);
      int commaIndex4 = data.indexOf(',', commaIndex3 + 1);
      field1 = data.substring(5, commaIndex1);
      field2 = data.substring(commaIndex1 + 10, commaIndex2);
      field3 = data.substring(commaIndex2 + 13, commaIndex3);
      field4 = data.substring(commaIndex3 + 10, commaIndex4);
      field5 = data.substring(commaIndex4 + 18);

      Serial.println(field1);
      Serial.println(field2);
      Serial.println(field3);
      Serial.println(field4);
      Serial.println(field5);
      ThingSpeak.setField(1,field1);
      ThingSpeak.setField(2,field2);
      ThingSpeak.setField(3,field3);
      ThingSpeak.setField(4,field4);
      ThingSpeak.setField(5,field5);
      int status=ThingSpeak.writeFields(channel,apikey);
      if(status=200){
        Serial.print("Data Stored");
      }
  }

}
