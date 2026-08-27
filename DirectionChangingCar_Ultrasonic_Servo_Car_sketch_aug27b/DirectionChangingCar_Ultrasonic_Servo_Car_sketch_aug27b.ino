#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoOut = 8;
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int enA = 6;
const int enB = 11;

Servo servoS;


long duration;
float distance;

void setup() {

  Serial.begin(9600);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(servoOut, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enA, 120);
  analogWrite(enB, 120);

  servoS.attach(servoOut);
  servoS.write(90); // 90+ = left side || // > 90 = right side
}
void backward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void left(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void right(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void dist(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH, 25000);
  
  
  distance = duration * (0.034 / 2);
  
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
void loop() {
  dist();
  if(distance != 0.00 && distance <= 50){
    stop();
    delay(100);
    backward();
    delay(400);
    stop();

    for(int i=90; i<=150; i++){
      servoS.write(i);
      delay(7);
    }

    int leftSide;
   
    do{
      dist();
  }while(distance==0.00);
    leftSide = distance;
    delay(100);

    for(int i = 150; i>=30; i--){
      servoS.write(i);
      delay(7);
    }

    int rightSide;

   do{
    dist();
   }while(distance==0.00);
    rightSide = distance;
    delay(100);
    for(int i=30; i <= 90; i++){
      servoS.write(i);
      delay(7);
    }
    if(leftSide > rightSide){
      left();
      delay(300);
      stop();
    }
    else{
      left();
      delay(300);
      stop();
    }
  
  }
  forward();
  
}