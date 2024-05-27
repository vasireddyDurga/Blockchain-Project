#include<DHT.h>
DHT dht(2,DHT11);
int soil = A0;
int ldr = A1;
int rainfall = A2;

void setup()
{
 pinMode(soil,INPUT);
 pinMode(ldr,INPUT);
 pinMode(rainfall,INPUT);
 Serial.begin(9600);
 dht.begin();
}

void loop() 
{
 int s = analogRead(soil);
 int l = analogRead(ldr);
 int r = analogRead(rainfall);
 float h=dht.readHumidity();
 float t=dht.readTemperature();
 if(isnan(h)||isnan(t)){
 return;
 }
 Serial.print("Soil:");
 Serial.print(s);
 Serial.print(",Humidity:");
 Serial.print(h);
 Serial.print(",Temperature:");
 Serial.print(t);
 Serial.print(",Rainfall:");
 Serial.print(r);
 Serial.print(",Light Intensity:");
 Serial.println(l);
 delay(4000);
}
