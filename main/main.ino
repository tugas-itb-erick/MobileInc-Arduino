#include <LED.h>
//Mobile, Inc
//Group: Chlordane

/*********** WARNING *************/
//do not use pin 13 !!!
/*********** GLOBAL VARIABLES ***********/
//Pin number constant
const int switchPin = 12; //Tactile switch

//Indicator LED on/off status
int indicatorLEDState = 0;

//tactile switch previous status
int prevStatus = LOW;

//time
long prevMilis = 0;
long debounce = 50;

/*********** INSTANCES ***********/
LED greenLED(9);

/*********** CONTROLLER ***********/
//LED Status Controller
void indicatorLEDSwitch();

/*********** PIN DECLARATION ***********/
void setup() {
  pinMode(switchPin, INPUT_PULLUP); 
}

/*********** MAIN PROGRAM ***********/
void loop() {
  // put your main code here, to run repeatedly:
  indicatorLEDSwitch();
}

//
void indicatorLEDSwitch(){
  int switchStatus;
  
  switchStatus = digitalRead(switchPin);
  if(switchStatus == HIGH && prevStatus == LOW && millis() - prevMilis > debounce) {
    if(greenLED.isOn()){
      greenLED.turnOff();
    }else{
      greenLED.breathFade();
    }  
    prevMilis = millis();
  }

  if(greenLED.isOn()){
    greenLED.breathFade();
  }else{
    greenLED.turnOff();
  }
  //digitalWrite(ledPin,indicatorLEDState); 
  prevStatus = switchStatus;
}
