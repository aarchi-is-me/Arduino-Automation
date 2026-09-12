const int led = 13;
int data;
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int enA = 6;
const int enB = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enA, 120);
  analogWrite(enB, 120);
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

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    data = Serial.read();

    Serial.println(data); // prints the data send

    if (data == 'L') {
      left();
    }
    else if (data == 'R') {
      right();
    }
    else if (data == 'F') {
      forward();
    }
    else if (data == 'B') {
      backward();
    }
    else if (data == 'S') {
      stop();
    }
    else {
      // Optional: Handle unrecognized commands without stopping the motors
      Serial.println("Invalid Command Received");
    }
  }
}
