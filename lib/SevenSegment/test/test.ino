/*
	Author: Mobile Inc.
*/

//Test 7 Segment
// Globals
const int dataPin = 5;
const int latchPin = 6;
const int clockPin = 7;

const char common = 'a';    // common anode
//const char common = 'c';    // common cathode

void setup() {
  // initialize I/O pins
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  byte bits = numToBits(1);
  myfnUpdateDisplay(bits);
}

void myfnUpdateDisplay(byte eightBits) {
  if (common == 'a') {
    eightBits = eightBits ^ B11111111;
  }
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, eightBits);
  digitalWrite(latchPin, HIGH); 
}

byte numToBits(int someNumber) {
  //desimal : ganti bit terakhir jadi 1
  switch (someNumber) {
    case 0:
      return B11111100; // 0
      break;
    case 1:
      return B10100000; // 1
      break;
    case 2:
      return B11011010; // 2
      break;
    case 3:
      return B11110010; // 3
      break;
    case 4:
      return B10100110; // 4
      break;
    case 5:
      return B01110110; // 5
      break;
    case 6:
      return B01111110; // 6
      break;
    case 7:
      return B11100000; // 7
      break;
    case 8:
      return B11111110; // 8
      break;
    case 9:
      return B11110110; // 9
      break;
  }
}
