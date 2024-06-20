// set up the temperature pin to A0
int temp_sensor = A0;
// function to read the temperature
void setup() {
    // initialize serial communication
    Serial.begin(9600);
    // set the temperature sensor pin to input
    pinMode(temp_sensor, INPUT);
}

void loop() {
    // read the temperature and print it out
    float temp = read_temp();
    Serial.println(temp);
    // delay for 600ms
    delay(600);
}

float read_temp() {
    // read the analog value from the temperature sensor
    int reading = analogRead(temp_sensor);
    // convert to the voltage. 5 is the voltage supplied by the arduion and
    //  1024 is the max digital value that can be read
    // https://arduino.stackexchange.com/questions/44639/how-to-calculate-voltage-from-a0-pin#:~:text=The%20formula%20to%20calculate%20voltage,sens%20*%20(%205.0%20%2F%201023.0)%3B
    float voltage = reading * (5.0 / 1023.0);
    // convert voltage to temp in C and return it
    // conversion factor is 1c/10mv which is 1/0.01v = 100 i think the formula provided is wrong
    return (voltage - 0.5) * 100; //-0.5 is offset value
}