const int rows = 4;
const int columns = 4;
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

void setup() {
    for (int i = 0; i < columns; i++) {
        pinMode(colPins[i], OUTPUT);
        digitalWrite(colPins[i], HIGH); // Initialize column pins to high so later we can check which one gets pulled low.
    }

    // initialize row pins to input_pullup mode to detect when a row gets pulled low.
    for (int i = 0; i < rows; i++) {
        pinMode(rowPins[i], INPUT_PULLUP); // Pull up mode is to set the pin to a known state when no external signals are present.
        // Should be pulled up to 5V in this case.
    }

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
    for (int col = 0; col < columns; col++) { // Scan one column at a time
        // Set the current column to LOW
        digitalWrite(colPins[col], LOW); // Starting with high and setting one column low at a time prevents cross talking between adjacent keys.

        // Check each row for a LOW reading
        for (int row = 0; row < rows; row++) { // Scan each row of current column
            if (digitalRead(rowPins[row]) == LOW) { // Since rows are in pullup mode, and the current column is low, if a key is pressed then the voltage from the row will be pulled low from contacting the low column.
                // Key is pressed, print the corresponding character
                *key = keys[row][col]; // Set value of key pressed to the right char in the keypad based on row and col
            }
        }

        // Set the current column back to high as we are done scanning this one
        digitalWrite(colPins[col], HIGH);
    }
    return *key;
}