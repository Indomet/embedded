//Names: Ali Mousa Baqer Al-Muslim, Mehmet Asim Altinisik, Zepei Zhao
//Group number: 27
//Submssion code: 495RT6
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11
//make a dht object and give it the pin
DHT dht(DHTPIN, DHTTYPE);
//define led pins

//led array to loop over and turn on
const int ledPins[] = { 8, 9, 10, 11, 12 };
// threshold array to check temperature
const int threshold[] = { 0, 20, 40, 60, 80 };

void setup() {
  //set each led to
  for(int i=0; i<5; i++){ //Loop through each LED pin in the array and set to OUTPUT mode
    pinMode(ledPins[i], OUTPUT);
  }
  //begin the serial monitor
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  //start the library to read temps
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // print data
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
  Serial.print("Number of LEDs On:");
  //artifically increase temp to see if leds would light up
  //t += 60;
 
  //loop over threshold array
  for (int i = 0; i < 5; i++) {
        //if the current temperature is bigger than the threshold
        if (t >= threshold[i]) {
            //light up the ith led that the tempetaure is above regarding the threshold
            digitalWrite(ledPins[i], HIGH);
            Serial.print(" x");
        } else {
          // otherwise make it low if its less than the threshold
            digitalWrite(ledPins[i], LOW);
        }
    }
   Serial.print('\n');
}