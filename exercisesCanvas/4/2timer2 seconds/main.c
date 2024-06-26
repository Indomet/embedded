#include <Servo.h> // Include the servo library
// Create a servo object
Servo myservo;
// Set the initial degree to 180 so that it can go clocwise
int degree = 180;
void setup() {
    Serial.begin(9600); // Initialize serial communication at 9600 baud
    // Set up servo to pin A0 and set range to 0-180 since max is 180 degrees
    myservo.attach(A0, 0, 180);
    // Set up timer interrupt 2A
    TCCR2A = 0; // Reset Timer 2 control registers
    // Set up timer interrupt 2B
    TCCR2B = 0;

    // Prescaler = 1024 
    TCCR2B |= B00000111;
    // Set the timer to CTC mode
    TIMSK2 |= (1 << OCIE2A); // OCIE1B should work the same i think

    // https://deepbluembedded.com/arduino-timer-calculator-code-generator/
    // Set the compare register to 156 to get 10 ms interrupt
    OCR2A = 156;
    //enable global interrupts
    sei();
}

void loop() {
}
 // Runs when the OCR2A compare value is reached
ISR(TIMER2_COMPA_vect) {
    // Set timer counter to start at 0 for the next tick
    TCNT2 = 0; 
    // declare as static to retain value between ISR calls
    static int counter = 0; 
    // increment counter by 10 in each ISR call(156 ticks)
    counter = 10 + counter;
    // if counter reaches 1000, it means that it is one second
    if (counter >= 1000) {
        //reset the counter
        counter = 0;
        // declare as static to retain value between ISR calls
        static int second = 0;
        // increment second by 1
        second++;
        Serial.println(second);
        //in each second rotate the servo by 1 degree
        myservo.write(degree--);
        // if degree is 0 set it to 180 to start from the beginning
        if (degree == 0) {
            //set degree back to 180
            degree = 180;
        }
    }
}