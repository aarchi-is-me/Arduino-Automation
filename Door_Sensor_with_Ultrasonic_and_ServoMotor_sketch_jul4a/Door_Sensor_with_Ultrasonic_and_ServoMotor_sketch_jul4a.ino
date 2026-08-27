#include <Servo.h>
const int trigPin=12;
const int echoPin=13;
const int servoPin=8;

Servo myServo;

long duration;
int distance;
int threshold=50;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  myServo.attach(servoPin);
  myServo.write(0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  distance = duration * 0.034/2;

  Serial.println(distance);

  if(distance > 0 && distance <threshold){
    Serial.println("Obj Detected! Opening Door...");
    myServo.write(90);
    // delay(3000);
  }
  else{
    myServo.write(0);
  }

  delay(100);
}
