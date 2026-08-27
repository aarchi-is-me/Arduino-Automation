#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(39,16,2); // 39 or 0x27


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0); // Lcd Setup Command
  lcd.print("Pikachu"); // Data send
  lcd.setCursor(0,1); 
  lcd.print("Charizard");
}
