const int ledPin=7;
const int buzzerPin=8;

void setup() {
  // put your setup code here, to run once:
  digitalWrite(ledPin,OUTPUT);
  digitalWrite(buzzerPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(2000);
  digitalWrite(buzzerPin, LOW);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
