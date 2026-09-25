#include <Servo.h>

const int trigPin = 10;  // Triggers the sound wave
const int echoPin = 9;   // Recieves the sound wave to calculate distance
const int servoOut = 7;  // Provides instruction to Servo-SG90 to Move

S`ervo servoS;  //Servo Lib Obj to control Servo

long duration;   // Time taken for the Sound wave to return to Echo
float distance;  // Distance Stored from HC-SR04 sensor

void setup() {
  Serial.begin(9600);  // baud rate for serial transmission

  pinMode(trigPin, OUTPUT);  // Trigger Pin, Output signal
  pinMode(echoPin, INPUT);   // Echo Pin, Input signal

  servoS.attach(servoOut);  // Attaching Servo Control Pin to the imported Lib
  servoS.write(90);         // Center positioning the Servo
  delay(500);               // Delay for positioning
}

void dist() {
  digitalWrite(trigPin, LOW);   // Clearing Noise
  delayMicroseconds(2);         // Short reset pulse
  digitalWrite(trigPin, HIGH);  // Trigger Pulse Sent
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  // Trigger Pulse Halted

  // 25000us timeout (~400cm max range)
  duration = pulseIn(echoPin, HIGH, 25000);

  distance = duration * (0.034 / 2);
  /* Distance = Time * Speed (Speed = speed of sound in air, divided by 2, to cancel the dual trip of back and forth) */

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void loop() {
  dist();

  // ONLY sweep if an object is actually detected (distance > 0) AND closer than 50cm
  if (distance > 0.00 && distance < 50.00) {

    // Sweep left (90 to 150)
    for (int i = 90; i <= 150; i++) {
      servoS.write(i);
      delay(7);
    }

    delay(200);  // Brief pause at left limit

    // Sweep back to center (150 down to 90)
    for (int i = 150; i >= 90; i--) {
      servoS.write(i);
      delay(7);
    }
  } else {
    // Keep servo idle at center position when no obstacle is detected
    servoS.write(90);
  }

  delay(50);  // Short stability delay between distance checks
}