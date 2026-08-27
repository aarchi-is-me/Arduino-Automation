#include <LiquidCrystal.h>
const int rs=8,enabler=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs, enabler, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0); // Lcd Setup Command
  lcd.print("Pikachu"); // Data send
  lcd.setCursor(0,1); 
  lcd.print("Charizard");
}
