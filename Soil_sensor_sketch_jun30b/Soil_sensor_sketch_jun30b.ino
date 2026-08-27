const int sensorPin=A3;
const int redLED=7;
const int blueLED=4;

const int dryThreshold=500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(redLED,OUTPUT);
  pinMode(blueLED,OUTPUT);

  Serial.println("System Initialised...");
}

void loop() {
  // put your main code here, to run repeatedly:
  int SensorValue= analogRead(sensorPin);

  Serial.print("Moisture Value: ");
  Serial.println(SensorValue);

  if(SensorValue > dryThreshold){
    digitalWrite(redLED,HIGH);
    digitalWrite(blueLED,LOW);
    Serial.println("Status: DRY - RED is ON");
  }
  else{
    digitalWrite(redLED,LOW);
    digitalWrite(blueLED,HIGH);
    Serial.println("Status: DRY - BLUE is ON");
  }
  delay(2000);
}
