
// Timer interrupt temperature sensor

// https://www.youtube.com/watch?v=Uv9UeYUsA8A
// Compare match interrupt
// Overflow interrupt
// Input capture interrupt

// Control registers: TCCR1A, TCCR1B, TCCR2A, TCCR2B, TCCR3A, TCCR3B
// Timer 2 is 16 bit, and can be used for input capture
// TCNT1 - Timer value
// OCR1A - Compare match value
// Others - register bits for different configurations.

// Define pins
int tempPin = A0; // pin for temperature sensor
int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int led5 = 12;

const int ledPins[] = { led1, led2, led3, led4, led5 }; // define an array storing the pin numbers
const int threshold[] = { 0, 20, 40, 60, 80 }; // define an array storing the temperature thresholds for lighting the corresponding led.

int tempRead = 0; // variable for storing analog reading
float temperature = 0.0; // varaible for storing calculated temperature.

void setup() {
    // Setting each led pin to output mode
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);

    // Setting the temperature sensor pin to input mode
    pinMode(tempPin, INPUT);

    // Reset Timer 1 control registers
    TCCR1A = 0;
    TCCR1B = 0;
    // set timer counter to start at 0
    TCNT1 = 0;

    // set timer1 prescaler to 1024, 16MHz / 1024 = 15625/s, which fits in 16bit timer1.
    // to set 1024 prescaler we need 101 for first 3 bits
    TCCR1B |= (1 << CS12); // CS12 is the bit number of the bit that we want to flip on
    TCCR1B |= (1 << CS10); // CS10 is the bit number of the bit that we want to flip on

    // https://onlinedocs.microchip.com/pr/GUID-80B1922D-872B-40C8-A8A5-0CBE009FD908-en-US-3/index.html?GUID-3351FE1C-8FA4-406F-8D15-20130CB1F745
    // Set timer/counter interrupt mask register. OCIE1A = Compare match interrupt
    TIMSK1 |= (1 << OCIE1A);
    // Set compare match value for 1 second
    OCR1A = 15625;
    sei(); // Enable global interrupts

    TCCR1B |= (1 << WGM12); // Enables CTC (clears timer counter on compare)

    Serial.begin(9600); // begin serial communication
}

void loop() { // empty loop since we are using timer interrupts to periodically check the
    // temperature and updating the led display.
}

ISR(TIMER1_COMPA_vect) { // Runs when the OCR1A compare value is reached.
    refreshLED(); // Function that reads the temperature and updates the leds
}

void refreshLED() {
    tempRead = analogRead(tempPin); // Analog read from the temperature sensor
    temperature = map(((tempRead - 20.0) * 3.04), 0, 1023, -40, 125); // convert the analog reading to temperature in Celsius, 20 offset, 3.04 constant scaling factor, then mapping the voltage to temperature range.
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print('\n');

    for (int i = 0; i < 5; i++) { // for each led
        if (temperature >= threshold[i]) { // if temperature is higher than threshold
            digitalWrite(ledPins[i], HIGH); // turn on the led
        } else {
            digitalWrite(ledPins[i], LOW); // turn off the led
        }
    }
}