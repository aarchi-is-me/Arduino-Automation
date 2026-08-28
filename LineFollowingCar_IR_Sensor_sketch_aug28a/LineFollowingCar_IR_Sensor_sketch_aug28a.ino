const int sensorPins[8] = { 6, 7, 8, 9, 10, A5, 12, 13 };
int sensor[8];
const int in1 = 2;
const int in2 = A0;
const int in3 = 4;
const int in4 = A1;
const int enA = 3;
const int enB = 5;

const int baseSpeed = 120;

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // analogWrite(enA, 100);
  // analogWrite(enB, 100);

  for (int i = 0; i < 8; i++) {
    pinMode(sensorPins[i], INPUT);
  }
  pinMode(11,INPUT);
  Serial.begin(9600);
}

void forward(int speed,boolean b) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  delay(15);
  stop();
  if(b)
  return forward(speed,false);
}
void left(int baseSpeed,boolean b) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, baseSpeed);
  analogWrite(enB, baseSpeed);
  delay(15);
  stop();
  if(b)
  return left(baseSpeed,false);
}
void right(int baseSpeed,boolean b) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, baseSpeed);
  analogWrite(enB, baseSpeed);
  delay(15);
  stop();
  if(b)
  return right(baseSpeed,false);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  int index;
  for(int i=0;i<8;i++)
  if(digitalRead(sensorPins[i]))
  index=i;
if(index>4)
left(90,1);
else if(index<4)
right(90,1);
else
forward(100,1);
}
