const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  setColor(135,0,255);
  delay(1000);
  setColor(135,255,155);
  delay(1000);
  setColor(165,0,255);
  delay(1000);
}

void setColor(int red, int green, int blue){
  analogWrite(redPin, 255-red);
  analogWrite(greenPin, 255-green);
  analogWrite(bluePin, 255-blue);
}
