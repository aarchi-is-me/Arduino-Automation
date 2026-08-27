int in1=7;
int in2=8;
int in3=2;
int in4=4;
int ena=9;
int enb=10;

int ecoPin=12;
int trigPin=13;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT); 
 pinMode(ena,OUTPUT);
 pinMode(enb,OUTPUT);
 Serial.begin(115200);

 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500);

  for(int i=40;i<240;i+=10)
  {
    analogWrite(ena,i);
    analogWrite(enb,i);
    Serial.println(i);
    delay(1000);
  }
}
