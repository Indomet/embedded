//Names: Ali Mousa Baqer Al-Muslim, Mehmet Asim Altinisik, Zepei Zhao
//Group number: 27
//Submssion code: A8L6BV

//Defining encoder pinA
#define ENCODER_A 2
//Defining encoder pinB
#define ENCODER_B 3
//defing first pin that drives the motor
#define POWER_1 5
//defing seecond pin that drives the motor
#define POWER_2 6

int a=0; // a-encoder signal
int b=0; // b-encoder signal

int pos = 0; // pistion counter in ticks
float degree = 0; // current degree on the dc motor
int degtarget = 0; // the desired degree entered by the user
int e = 0; //error
int kp = 15; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of the controller
int speed = 0; // speed of the motor

void setup()
{  //begin serial communcation
  Serial.begin(9600);
  //set encoders to input and ativate the pull up resistor
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  //assinging pin modes to output for the motor to drive it
  pinMode(POWER_1, OUTPUT);
  pinMode(POWER_2, OUTPUT);
  
  //attaching interrrupt to encoder A where it triggers when A rises
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), ISR_encoder, RISING);

 
  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(POWER_2, 10);
  //delay 200ms
  delay(200);
  //start the motor for the other pin too
  analogWrite(POWER_1, 10);
}

void loop()
{
  //check position bounds
 if(pos < -2299 || pos > 2299){
   //if outside reset it
    pos = 0;
  }  
  Serial.print("\n");
  Serial.print("\nDegrees: ");
  
  //Check if the dc motor made a full rotation
  //degrees within 360 degrees instead of 400, 420 degrees etc
  if (degree > 359) {
    //reset degrees if it goes over and keep the extra degrees when it goes over
    degree = degree - 360;
  }
  //print current position in degrees
  Serial.print(degree);
  Serial.print("\n");
  //200ms delay
  delay(200); 
  
  //the degree target is the input + the current degrees
  degtarget = getInput()+ degree ;
  Serial.print(degtarget);
  Serial.print("\n");
  
  
  // Calculate initial error
  e = degtarget - degree;
   
  // Loop until error is zero
  while(e){
    
    // Map current position into degrees
    degree = map(pos,0,2299,0,360);
       
  	// Get necessary speed signal
  	speed = getAction(e);
    
  	// Send speed signal to motor
    // Rotating clockwise
    if(speed >= 0){
    	if (speed < 100) // motor does not react with too low inputs
      	speed = 100;
      analogWrite(POWER_2, 0);
      analogWrite(POWER_1, speed);
  	}
  
    // Rotating counter-clockwise
  	else{
    	if (-speed < 100) // motor does not react with too low inputs
      	speed = -100; 
      	analogWrite(POWER_1, 0);
      	analogWrite(POWER_2, -speed); 
    }
	
    // Calculate new error
  	e = degtarget - degree;
  }
  if (e == 0) {
    //thinkercad bug
    //stop the motor from continously rotating
  	analogWrite(POWER_1, 10);
    delay(200);
    analogWrite(POWER_2, 10);	
  }
}


int getAction(int error){
  /* 
  Calculate u_out as function of the error and the kp (tuning parameter). 
  */
  u_out = kp*e;
  
  if (u_out > 254){ //u_out cannot be more than 255...
  	return 255;
  }
  else if (u_out < -254){ //...or less than -254
    return -255;
  }  
  else
     return u_out;
}


int getInput() {
  Serial.println("Please enter the desired position: ");
  // Wait for input
  while (!Serial.available()) {
    
  }
  //parse the input and convert it to int
  int input = Serial.parseInt();
  Serial.print("Input: ");
  Serial.println(input);

  // Clear the serial buffer from the new line
  while (Serial.available()) {
    //read the buffer to getr rid of it
    Serial.read();
  }
  //retrun the input integer
  return input;
}

void ISR_encoder(){
  /*
  READ THE ENCODER SIGNAL HERE.
  Read the encoder signals and increase or decrease pos accordingly.
  */
  a = digitalRead(ENCODER_A);
  b = digitalRead(ENCODER_B);

  // if signal at encoder a is on, increase the position counter
  if(a > b) {
    pos++;
  } else {
    //if signal at encoder b is on, decrease the position counter
    pos--;
  }
}