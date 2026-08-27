#include <LiquidCrystal.h>
const int rs=8,enabler=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs, enabler, d4, d5, d6, d7);

const int trigPin=2, echo=4;
int distance, duration;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

  pinMode(trigPin, OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Ultrasonic Sensor
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echo,HIGH);

  distance=(duration * 0.034)/2; // what??????????

  // LCD Outlet
  if(distance < 10){
    lcd.setCursor(0,0); // Lcd Setup Command
    lcd.print("Distance= "); // Data send
    lcd.print(distance);
    lcd.print("cm"); // for : Distance= xx Cm
  }
  else{
    lcd.setCursor(0,1); // Lcd Setup Command
    lcd.print("Distance= "); // Data send
    lcd.print(distance);
    lcd.print("cm"); // for : Distance= xx Cm
  }
  
  // lcd.setCursor(0,1); 
  // lcd.print("Charizard");
}
