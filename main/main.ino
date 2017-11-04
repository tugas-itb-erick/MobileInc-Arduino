//Mobile, Inc
//Group: Chlordane

/*********** GLOBAL VARIABLES ***********/
//Pin number constant
const int ledPin = 13; //LED indicator
const int switchPin = 12; //Tactile switch

//Indicator LED on/off status
int indicatorLEDState = LOW;

//tactile switch previous status
int prevStatus = LOW;

//time
long prevMilis = 0;
long debounce = 200;

/*********** CONTROLLER ***********/
//LED Status Controller
void indicatorLEDSwitch();

/*********** PIN DECLARATION ***********/
void setup() {
  pinMode(ledPin, OUTPUT); 
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
    if(indicatorLEDState == LOW){
      indicatorLEDState = HIGH;
    }else{
      indicatorLEDState = LOW;
    }  
    prevMilis = millis();
  }
  digitalWrite(ledPin,indicatorLEDState); 
  prevStatus = switchStatus;
}
