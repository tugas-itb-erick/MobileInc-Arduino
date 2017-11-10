/*
	Author: Mobile Inc.
*/

#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include "Arduino.h"

class SevenSegment{
	public:
		SevenSegment(int _dataPin, int _latchPin, int _clockPin);
		void setNumberOn(int number, bool isDecimalOn);
		
	private:
		const int dataPin;
		const int latchPin;
		const int clockPin;
		const char common = 'a';
};

#endif