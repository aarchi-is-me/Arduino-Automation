int IrSensor=7;
int ledPin=8;

void setup() {
  // put your setup code here, to run once:
  pinMode(IrSensor,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:'
  int val = digitalRead(IrSensor);

  digitalWrite(ledPin,!val); //LOW or HIGH


}
