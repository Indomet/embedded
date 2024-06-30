//Names: Ali Mousa Baqer Al-Muslim, Mehmet Asim Altinisik, Zepei Zhao
//Group number: 27
//Submssion code: 495RT6

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

//make a dht object and give it the pin
DHT dht(DHTPIN, DHTTYPE);
// Digital pins
const int normalLed = 9;
const int highLed = 8;
const int lowLed = 10;

// Analog pin for light sensorr
const int lightPin = A1;

//variables to sore temp and light
float temperature = 0.0;
float light = 0.0;
//delay
const int interval = 500; //milliseconds

void setup() {
    //begin the serial monitor
    Serial.begin(9600);
    //start the library to read temps
    dht.begin();
    //setting leds to output and the light sensor to input
    pinMode(normalLed, OUTPUT);
    pinMode(highLed, OUTPUT);
    pinMode(lowLed, OUTPUT);
    pinMode(lightPin, INPUT);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(500);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read light sensor
  int lightValue = analogRead(lightPin);

  // Check if any reads failed and exit early 
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  //Artificially decrease temperature
  //t -= 50;
  // Map light value to 0-100 where the max value is 450 and the min value is 0
  light = map(lightValue, 0, 450, 0, 100);
  //print data
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
  Serial.print('\n');
  Serial.print("Light: ");
  Serial.print(light);
  Serial.print("%");
  Serial.print('\n');

  if (light < 1) { // Light at 0%
        if (t < -12) { // temperature in normal range
            //turn on the normal led and turn off the other leds
            digitalWrite(normalLed, HIGH);
            digitalWrite(highLed, LOW);
            digitalWrite(lowLed, LOW);
        } else if (t >= -12) { // temperature too high
            //turn on the high led and turn off the other leds
            digitalWrite(normalLed, LOW);
            digitalWrite(highLed, HIGH);
            digitalWrite(lowLed, LOW);
        }
    } else if (light <= 20) { // Light 1% - 20%
        if (t >= -12 && t <= 0) { // temperature in normal range
        //turn on the normal led and turn off the other leds
            digitalWrite(normalLed, HIGH);
            digitalWrite(highLed, LOW);
            digitalWrite(lowLed, LOW);
        } else if (t < -12) { // temperature too low
        //turn on the low led and turn off the other leds
            digitalWrite(normalLed, LOW);
            digitalWrite(highLed, LOW);
            digitalWrite(lowLed, HIGH);
        } else if (t > 0) { // temperature too high
        //turn on the high led and turn off the other leds
            digitalWrite(normalLed, LOW);
            digitalWrite(highLed, HIGH);
            digitalWrite(lowLed, LOW);
        }
    } else if (light <= 60) { // Light 21% - 60%
        if (t >= 0 && t <= 20) { // temperature in normal range
        //turn on the normal led and turn off the other leds
            digitalWrite(normalLed, HIGH);
            digitalWrite(highLed, LOW);
            digitalWrite(lowLed, LOW);
        } else if (t < 0) { // temperature too low
        //turn on the low led and turn off the other leds
            digitalWrite(normalLed, LOW);
            digitalWrite(highLed, LOW);
            digitalWrite(lowLed, HIGH);
        } else if (t > 20) { // temperature too high
        //turn on the high led and turn off the other leds
            digitalWrite(normalLed, LOW);
            digitalWrite(highLed, HIGH);
            digitalWrite(lowLed, LOW);
        }
    } else if (light <= 100) { // Light 61% - 100%
        if (t >= 21) { // temperature in normal range
        //turn on the normal led and turn off the other leds
            digitalWrite(normalLed, HIGH);
            digitalWrite(highLed, LOW);
            digitalWrite(lowLed, LOW);
        } else if (t < 21) { // temperature too low
        //turn on the low led and turn off the other leds
            digitalWrite(normalLed, LOW);
            digitalWrite(highLed, LOW);
            digitalWrite(lowLed, HIGH);
        }
    }
  delay(interval);
}