#include <LedControl.h>
LedControl lc(4,8,7,1); // DataIn(DIN), Clock(CLK), ChipSelect(CS), No. of Devices
byte smiley[8] = {
  0b10000001,
  0b01111110,
  0b00100100,
  0b00011000,
  0b00011000,
  0b00100100,
  0b01111110,
  0b10000001
};

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0,false); // device address, Mac Default Wake up call, via FALSE
  lc.setIntensity(0,8); // device address, Intensity of Matrix Brightness (0-15)
  lc.clearDisplay(0); // clearing of display for device via id mention
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<8; i++){
    lc.setRow(0,i,smiley[i]);
  }
}
