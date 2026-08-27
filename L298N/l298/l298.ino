int in1=7;
int in2=8;
int ena=9;
void setup() {
  // put your setup code here, to run once:
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(ena,OUTPUT);
 Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  for(int i=40;i<240;i+=10)
  {
    analogWrite(ena,i);
    Serial.println(i);
    delay(1000);
  }
}
