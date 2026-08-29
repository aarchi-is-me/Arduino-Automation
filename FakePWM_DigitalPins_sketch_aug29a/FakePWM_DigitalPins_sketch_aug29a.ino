long period = 2048;
long duty = 10;
int redled = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(redled, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redled, HIGH);
  delayMicroseconds(duty);
  digitalWrite(redled, LOW);
  delayMicroseconds(period - duty);
}