#include<DHT.h>
const int dhtpin=6;
int in1=2;
int in2=3;
#define DHTTYPE DHT11
DHT dht(dhtpin,DHTTYPE);
float temp=25.0;
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
float t= dht.readTemperature();
float h=dht.readHumidity();
if (isnan(h)||isnan(t))
{
  Serial.println("failed to read the value");
  return;
}
Serial.print("Humidity");
Serial.println(h);
Serial.print("Temperature");
Serial.println(t);
delay(1000);
if(t<temp)
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  delay(1000);
}
else
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  delay(1000);

}


}



