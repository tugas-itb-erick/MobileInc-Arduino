#include "LED.h"
#include "Arduino.h"

LED::LED(int _pin){
	pinMode(pin, OUTPUT);
	pin = _pin;
	turnOff();
}

void LED::breathFade(){
	int brightness = 0, fadeConstant = 5;
	while(brightness <255){
		brightness += fadeConstant;
		analogWrite(pin,brightness);
		delay(5);
	}
	
	while(brightness >0){
		brightness -= fadeConstant;
		analogWrite(pin,brightness);
		delay(5);
	}
	
	state = 1;
}

void LED::turnOn(){
	analogWrite(pin,255);
	state = 1;
}

void LED::turnOff(){
	analogWrite(pin,0);
	state = 0;
}

bool LED::isOn(){
	return (state == 1);
}

