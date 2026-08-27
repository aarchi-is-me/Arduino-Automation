#define PIR 8
#define LED 7

void setup() {
  // put your setup code here, to run once:
  pinMode(PIR,INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int motion = digitalRead(PIR);
  if(motion == HIGH){
    Serial.println("Motion Detected! Lights ON!!");
    digitalWrite(LED,HIGH);
  } else{
    Serial.println(" NO Motion Detected! Lights OFF - Zzzzz");
    digitalWrite(LED,LOW);
  }
}
