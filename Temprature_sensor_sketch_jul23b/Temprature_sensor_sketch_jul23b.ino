#include <LiquidCrystal_I2C.h>
#include <DHT11.h>
#define DHTPIN 8

DHT11 dht(DHTPIN);
LiquidCrystal_I2C lcd(0x27,16,2);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("DHT11 Sensor");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // dht.readTemperatureHumidity(int &temperature, int &humidity)
  if(isnan(h) || isnan(t)){
    Serial.println("failed to Read from DHT11 Sensor!");
    lcd.setCursor(0,0);
    lcd.print("Sensor Error!");
    return;
  }
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" c");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" \t");
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.println(" *c");
}
