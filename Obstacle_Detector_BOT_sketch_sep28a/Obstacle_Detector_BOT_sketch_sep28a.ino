const int ledPin = 13;
const int IRout = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(IRout, INPUT);
  Serial.begin(9600); // Baud Rate
}

void loop() {
  // put your main code here, to run repeatedly:
  int OutVal = digitalRead(IRout);
  digitalWrite(ledPin, !OutVal);

  if (OutVal == LOW) {
    Serial.println("Obstacle Detected!");
  } else {
    Serial.println("Clear");
  }

  delay(100); // Brief delay to keep Serial output readable
}
