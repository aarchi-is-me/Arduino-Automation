#include <TFT.h> // Pre-installed standard Arduino TFT library
#include <SPI.h>

// Define custom pins
#define CS_PIN   10
#define DC_PIN   9
#define RST_PIN  8

// Initialize the display object
TFT myScreen = TFT(CS_PIN, DC_PIN, RST_PIN);

void setup() {
  // Initialize the screen
  myScreen.begin();
  
  // Set background to black
  myScreen.background(0, 0, 0);

  // Draw a red bounding frame (X, Y, Width, Height)
  myScreen.stroke(255, 0, 0); // Red outline
  myScreen.noFill();
  myScreen.rect(0, 0, myScreen.width(), myScreen.height());

  // Print Text Header
  myScreen.stroke(0, 255, 0); // Green text
  myScreen.setTextSize(2);
  myScreen.text("ST7735 TFT", 15, 20);

  // Print Static Value Subtext
  myScreen.stroke(255, 255, 255); // White text
  myScreen.setTextSize(1);
  myScreen.text("System Status: OK", 15, 50);
}

void loop() {
  // Flash a cyan/blue pixel block to prove the loop is active
  
  // Cyan rectangle
  myScreen.fill(0, 255, 255);
  myScreen.stroke(0, 255, 255);
  myScreen.rect(15, 80, 30, 20);
  delay(500);

  // Blue rectangle
  myScreen.fill(0, 0, 255);
  myScreen.stroke(0, 0, 255);
  myScreen.rect(15, 80, 30, 20);
  delay(500);
}