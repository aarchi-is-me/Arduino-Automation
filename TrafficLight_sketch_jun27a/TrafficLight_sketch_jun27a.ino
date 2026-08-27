int redled = 3;
int yellowled = 4;
int greenled = 5;
void setup() {
  // put your setup code here, to run once:
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(greenled,HIGH);
delay(5000);
digitalWrite(greenled,LOW);
digitalWrite(yellowled,HIGH);
delay(1000);
digitalWrite(yellowled,LOW);
digitalWrite(redled,HIGH);
delay(2000);
digitalWrite(redled,LOW);
}
