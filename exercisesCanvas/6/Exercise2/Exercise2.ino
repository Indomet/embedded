//Names: Ali Mousa Baqer Al-Muslim, Mehmet Asim Altinisik, Zepei Zhao
//Group number: 27
//Submssion code: A8L6BV

// define untrosonic pin
byte triggerPin = 7;
// define echopin
byte echoPin = 6; // put 7 as well if the sensor has 3 pins
// define buzzer pin
byte buzzerPin = 9;
// define led pins
int ledPins[] = { 13, 4, 3, 2 };

void setup() {
    // initialize serial communication
    Serial.begin(9600);
    // initialize the buzzer pin as output
    pinMode(buzzerPin, OUTPUT);
    // loop through the led pins
    for (int i = 0; i < 4; i++) {
        // inittialize the led pins as output
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
    // get the meaured distance
    int distance = measureUltrasonicDistance();
    Serial.println(distance);

    // if the distance is less than 25 cm blink led and play tone
    if (distance < 25) {
        // call the blink led function
        blinkLed();
        // call the play tone function
        playTone(2000, 100);

        // if the distance is less than 200 cm turn on led and play tone
    } else if (distance < 200) {
        // turnon led function has the check for tresholds for ranges between 30 and 300 cm
        turnOnLed(distance);
        // call the playtone function, distance is mapped to the frequency so that the sound can automatically
        // increase as the distance decreases
        playTone(map(distance, 25, 200, 1000, 200), 100);
        // oyherwise turn off the led and the tone
    } else {
        // call the turn off led function
        turnOffLed();
        // make the buzzer silent
        noTone(buzzerPin);
    }
}

// function to turn on the led
void turnOnLed(int distance) {
    // loop through the led pins
    for (int i = 0; i < 4; i++) {
        // if the distance is less than the treshold turn on the led
        if (distance < (200 - i * 56.33)) {
            // turn on the i-th led
            digitalWrite(ledPins[i], HIGH);

            // otherwise turn off the led
        } else {
            // turn off the i-th led
            digitalWrite(ledPins[i], LOW);
        }
    }
}
// function to measure the ultrasonic distance
long measureUltrasonicDistance() {
    // Sets the ultrasonicPin as an Output
    pinMode(triggerPin, OUTPUT); // Clear the trigger
    // Sets the ultrasonicPin on HIGH state
    digitalWrite(triggerPin, LOW);
    // delay for 2 milliseconds
    delay(2);
    // Sets the ultrasonicPin pin to HIGH state
    digitalWrite(triggerPin, HIGH);
    // delay for 10 milliseconds
    delay(10);
    // Sets the ultrasonicPin pin to LOW state
    digitalWrite(triggerPin, LOW);
    // Sets the ultrasonicPin as an Input
    pinMode(echoPin, INPUT);
    // define cm
    int cm = 0;
    // Reads the echo pin, and returns the sound wave travel time in microseconds
    // cm = pulseIn(ultrasonicPin, HIGH) / 29 / 2;

    // 0.01723 is the speed of sound in cm per millisecond
    // and pulseIn returns the time in miliseconds
    cm = 0.01723 * pulseIn(echoPin, HIGH);

    // delay for 100 milliseconds
     delay(100);

    // cm = 0.01723 *  pulseIn(ultrasonicPin, HIGH);
    // measure the ping time in cm
    // cm = 0.01723 * readUltrasonicDistance(7, 7);
    return cm;
}
// function to blink the led
void blinkLed() {
    // define the previousMillis
    static unsigned long previousMillis = 0;
    // define the led state
    static boolean ledState = false;
    // get the current millis
    unsigned long currentMillis = millis();

    // blink the led every 150 milliseconds
    // if the difference between the current time and last time you blinked the led is bigger than the interval
    if (currentMillis - previousMillis >= 150) {
        // save the last time you blinked the led
        previousMillis = currentMillis;
        // if the led state is true make it false and vice versa
        ledState = !ledState;
        // loop through the led pins
        for (int i = 0; i < 4; i++) {
            // set the led on according to the led state
            digitalWrite(ledPins[i], ledState ? HIGH : LOW);
        }
    }
}
// function to turn off the led
void turnOffLed() {
    // loop through all led pins
    for (int i = 0; i < 4; i++) {
        // turn off the i-th led
        digitalWrite(ledPins[i], LOW);
    }
}
// function to play a tone
void playTone(int freq, int duration) {
    // play the tone on the buzzer pin
    tone(buzzerPin, freq, duration);
}
