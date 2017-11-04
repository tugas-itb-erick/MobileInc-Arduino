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

//weather status
int weatherStatus = 1;

/*********** INSTANCES ***********/
LED greenLED(13);
LED redLED(10);

/*********** CONTROLLER ***********/
//LED Status Controller
void indicatorLEDSwitch();
void controlWeatherLEDStatus();

/*********** PIN DECLARATION ***********/
void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(9600);
}

/*********** MAIN PROGRAM ***********/
void loop() {
  // STUB, nanti diganti jadi dapet data dari hasil bacaan suhu + kelembapan
  if(Serial.available()>0){
    weatherStatus = Serial.read()-'0';
  }
  Serial.print(weatherStatus); 
  indicatorLEDSwitch();
}

//Procedure Implementation
void indicatorLEDSwitch(){
  int switchStatus;
  
  switchStatus = digitalRead(switchPin);
  if(switchStatus == HIGH && prevStatus == LOW && millis() - prevMilis > debounce) {
    if(indicatorLEDState == 1){
      greenLED.turnOff();
      redLED.turnOff();
      indicatorLEDState = 0;
    }else{
      indicatorLEDState = 1;
      controlWeatherLEDStatus();
    }  
    prevMilis = millis();
  }

  if(indicatorLEDState == 1){
    controlWeatherLEDStatus();
  }else{
    greenLED.turnOff();
    redLED.turnOff();
  }
   
  prevStatus = switchStatus;
}

void controlWeatherLEDStatus(){
  if(weatherStatus == 0){
    greenLED.turnOff();
    redLED.breathFade();
  }else{
    greenLED.turnOn();
  }
}
