byte led1= 8;
//setting second led to pin 7
byte led2= 7;

void setup()
{
  // setting pin mode to output
  pinMode(led1, OUTPUT);
  // setting pin mode to output
  pinMode(led2, OUTPUT);
}

void loop()
{// turning on the light by setting it to high
  digitalWrite(led1, HIGH);
  // delaying one second
  delay(1000);
  //turning off the by setting digitalwrite to low
  digitalWrite(led1, LOW);
  //delaying one second again
  delay(1000);
  
  // setting the second light to on since we can control on and off by button
  digitalWrite(led2,HIGH);
}