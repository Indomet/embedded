#include <Adafruit_NeoPixel.h>


const int neopixelPin = 8; // pin for neopixel ring
const int numOfPixel = 12; // number of pixels in the ring we are using

const int ledPin = 9; // pin for the middle red led
const int lightPin = A0; // pin for the light sensor

float light = 0.0; // variable for storing light value
int lightRead = 0; // variable for storing analog reading from light sensor
int ringState = 0; // variable for storing the state of the ring, ie how many leds should be on.

Adafruit_NeoPixel pixels(numOfPixel, neopixelPin, NEO_GRB + NEO_KHZ800); // Define the neopixel ring using the Adafruit_NeoPixel library

void setup() {
    pinMode(ledPin, OUTPUT); // set ledPin to output mode
    pinMode(lightPin, INPUT); // set lightPin to input mode
    pixels.begin(); // initialize the neopixel ring

    // Reset Timer 1 control registers
    TCCR1A = 0;
    TCCR1B = 0;
    // set timer counter to start at 0
    TCNT1 = 0;

    // set timer1 prescaler to 1024, 16MHz / 1024 = 15625/s, which fits in 16bit timer1.
    // to set 1024 prescaler we need 101 for first 3 bits
    TCCR1B |= (1 << CS12);
    TCCR1B |= (1 << CS10);

    // https://onlinedocs.microchip.com/pr/GUID-80B1922D-872B-40C8-A8A5-0CBE009FD908-en-US-3/index.html?GUID-3351FE1C-8FA4-406F-8D15-20130CB1F745
    // Set timer/counter interrupt mask register. OCIE1A = Compare match interrupt
    TIMSK1 |= (1 << OCIE1A);
    // Set compare match value for 1 second
    OCR1A = 15625;
    sei(); // Enable global interrupts

    TCCR1B |= (1 << WGM12); // Enables CTC (clears timer counter on compare)

    Serial.begin(9600); // begin serial communication
}

void loop() {
    int temp; // temp varaible
    for (int i = 0; i < numOfPixel; i++) {
        temp = map(i + 1, 0, numOfPixel, 0, 255); // map the value of the number of pixels to the range 0-255 rgb values.
        if (ringState >= i) { // if the ringState is greater than or equal to i, turn on the pixel
            // if statement for changing the color of the pixels based on the temperature
            if (temp < 128) { // first half of the ring ranges from blue to green
                // color range from blue to green for 0 to half the pixels
                pixels.setPixelColor(i, pixels.Color(0, 2 * temp, 255 - 2 * temp)); // blue decreases, green increases
            } else { // second half ranges from green to red
                // color range from green to red for half to last pixel
                pixels.setPixelColor(i, pixels.Color(2 * (temp - 128), 255 - (2 * (temp - 128)), 0)); // green decreases, red increases
            }
        } else {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Turn off pixel if ringState is less than i
        }
    }
    delay(50); // delay to use less resources
    pixels.show(); // show the pixels
}

ISR(TIMER1_COMPA_vect) { // Runs when the OCR1A compare value is reached.
    pixelDisplay(); // function that reads the light sensor and updates the neopixel ring
}

// Fill the dots one after the other with a color
void pixelDisplay() {
    lightRead = analogRead(lightPin); // analog read from the light sensor
    light = map(lightRead, 0, 104, 0, 12); // Map analog read value to range 0-12
    Serial.print(light);
    Serial.print('\n');

    ringState = (int)light % (numOfPixel + 1); // gives range from 0 to 12
    if (light >= 12) { // if all leds are on, turn on the middle red led
        digitalWrite(ledPin, HIGH); // turn on the middle red led
    }
}