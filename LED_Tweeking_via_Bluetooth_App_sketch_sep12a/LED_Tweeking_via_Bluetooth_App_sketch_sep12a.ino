const int led = 13;
int data;

long period = 2048;
long duty = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    data = Serial.read();

    Serial.println(data); // prints the data send

    if (data == 'L') {
      digitalWrite(led, HIGH);
    }
    else if (data == 'D') { // To Dim the light
      digitalWrite(led, HIGH);
      delayMicroseconds(duty);
      digitalWrite(led, LOW);
      delayMicroseconds(period - duty);
    }
    else {
      digitalWrite(led, LOW);
    }
  }
}
