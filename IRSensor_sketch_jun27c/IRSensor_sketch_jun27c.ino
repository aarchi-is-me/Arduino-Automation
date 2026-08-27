int IrSensor=7;

void setup() {
  // put your setup code here, to run once:
  pinMode(IrSensor,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:'
  int val = digitalRead(IrSensor);
  Serial.println(val);
  delay(500);

}
