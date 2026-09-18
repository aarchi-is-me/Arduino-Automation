#include<LiquidCrystal.h>
int rs=8;
int en=7;
int d2=2;
int d3=3;
int d4=4;
int d5=5;
int sw1=9;
int sw2=10;
int res=11;
int led=6;
int buz=12;
LiquidCrystal lcd(rs,en,d2,d3,d4,d5);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(led,OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(sw1,INPUT_PULLUP);
  pinMode(sw2,INPUT_PULLUP);
  pinMode(res,INPUT_PULLUP);
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:s
  lcd.setCursor(0,0);
  lcd.print("hi");


}