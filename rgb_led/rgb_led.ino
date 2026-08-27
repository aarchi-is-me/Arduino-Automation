// Define the PWM pins for the LED
int redPin = 3;
int greenPin =5;
int bluePin = 6;

void setup() {
  // Set all three color pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Violet
  setColor(139, 0, 255);
  delay(3000);
  
  // Indigo
  setColor(102, 0, 255);
  delay(3000);
  
  // Turn Off completely
  setColor(0, 0, 0);
  delay(1000);
}

// Custom function to set the color
void setColor(int red, int green, int blue) {
  // Common Cathode logic: No math inversion needed
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}