/*
	Author: Mobile Inc.
*/

#include "SevenSegment.h"

SevenSegment::SevenSegment(int _dataPin, int _latchPin, int _clockPin): dataPin(_dataPin), latchPin(_latchPin), clockPin(_clockPin){
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
}

void SevenSegment::setNumberOn(int number, bool isDecimalOn){
	byte bits;
	
	switch (number) {
		case 0:
			bits = B11111100; // 0
			break;
		case 1:
			bits = B10100000; // 1
			break;
		case 2:
			bits = B11011010; // 2
			break;
		case 3:
			bits = B11110010; // 3
			break;
		case 4:
			bits = B10100110; // 4
			break;
		case 5:
			bits = B01110110; // 5
			break;
		case 6:
			bits = B01111110; // 6
			break;
		case 7:
			bits = B11100000; // 7
			break;
		case 8:
			bits = B11111110; // 8
			break;
		case 9:
			bits = B11110110; // 9
			break;
	}
  
	if(isDecimalOn){
		bits = bits | B00000001;
	}
	
	bits = bits ^ B11111111;

	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, bits);
	digitalWrite(latchPin, HIGH); 
}