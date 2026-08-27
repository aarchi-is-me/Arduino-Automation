const int pinA = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinA, HIGH);
  delay(1000);
  digitalWrite(pinA, LOW);
  delay(1000);
}