#ifndef LED_H
#define LED_H

#include "Arduino.h"

class LED{
	public:
		LED(int _pin);
		void breathFade();
		void turnOn();
		void turnOff();
		bool isOn();
	private:
		int pin;
		int state;
};

#endif