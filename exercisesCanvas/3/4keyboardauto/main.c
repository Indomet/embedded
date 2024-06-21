#include <Keypad.h> //Keypad library

// https://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/
const byte rows = 4; // number of rows
const byte columns = 4; // number of columns
int rowPins[rows] = { 11,10,9,8}; // row pins
int colPins[columns] = { 6,5,4,3}; // column pins

// set the correct characters to print out.
char keys[rows][columns] = {
    { '1', '2', '3', 'A' },
    { '4', '5', '6', 'B' },
    { '7', '8', '9', 'C' },
    { 'E', '0', 'F', 'D' }
};

char keystroke; // Variable for storing which key was detected
// Using keypad library to create a Keypad object.
// arguments: Keypad(char*, byte*, byte*, byte, byte)
Keypad keypad1 = Keypad(makeKeymap(keys), rowPins, colPins, rows, columns);

void setup() {

    // Initialize serial communication
    Serial.begin(9600);
}

void loop() {
    // Scan the keypad
    if (scanKeypad(&keystroke) != NULL) { // If return value is not null, meaning a key has been pressed.
        Serial.println(keystroke);
        delay(1000); // delay 1 second after printing out a key to avoid unwanted doubletapping.
    }
    keystroke = NULL; // reset registered key press to null
}

char scanKeypad(char* key) {
    *key = keypad1.getKey(); // Get the key from the keypad
    // If a key is pressed, return the key
    return *key;
}