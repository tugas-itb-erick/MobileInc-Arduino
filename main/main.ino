#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>
#include <LED.h>

//Mobile, Inc
//Group: Chlordane

#define I2C_ADDR 0x3F
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
#define BACKLIGHT 3

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
long debounce = 40;

//weather status
int weatherStatus = 1;

/*********** INSTANCES ***********/
LED greenLED(13);
LED redLED(10);
DHT11 sensor(8);
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

/*********** CONTROLLER ***********/
//LED Status Controller
void indicatorLEDSwitch();
void controlWeatherLEDStatus();
void initLCD();
void displayLCD(char* message);

/*********** PIN DECLARATION ***********/
void setup() {
  initLCD();
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(9600);
}

/*********** MAIN PROGRAM ***********/
void loop() {
  int check = sensor.read();

//  Serial.print("Humidity (%): ");
//  Serial.println((float)sensor.getHumidity(), 2);
//
//  Serial.print("Temperature (°C): ");
//  Serial.println((float)sensor.getTemperature(), 2);
//
//  delay(1000);
  
  
  
  float temperature = (float)sensor.getTemperature();
  float humidity = (float)sensor.getHumidity();
  if(humidity >= 85 || temperature < 25){
    weatherStatus = 0;
    displayLCD("weather : rainy");  
  }else{
    weatherStatus = 1;
    displayLCD("weather : good");  
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

void initLCD(){
  lcd.begin (20,4); // initialize the lcd
  
  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT,POSITIVE);
  lcd.setBacklight(HIGH);  
}

void displayLCD(char* message){
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(message);
  delay(100);
}
