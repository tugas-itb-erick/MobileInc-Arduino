/*
	Author: Mobile Inc.
*/

#ifndef DHT11_H
#define DHT11_H

#include <Arduino.h>

#define DHT11LIB_VERSION "0.4.1"

#define DHTLIB_OK				0
#define DHTLIB_ERROR_CHECKSUM	-1
#define DHTLIB_ERROR_TIMEOUT	-2

class DHT11{
	public:
		DHT11(int _pin);
		int read();
		int getHumidity();
		int getTemperature();
	private:
		int pin;
		int humidity;
		int temperature;
};

#endif
