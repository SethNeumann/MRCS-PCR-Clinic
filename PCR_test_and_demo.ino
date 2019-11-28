/*

    servo Sweep is by BARRAGAN <http://barraganstudio.com> 
    This example code is in the public domain.

     modified 8 Nov 2013
     by Scott Fitzgerald
     http://arduino.cc/en/Tutorial/Sweep

*/ 

#include <Servo.h> 



// LED setup
#define LED2 2     // LED no PWM
#define LED3 3     // LEDs PWM 
#define LED5 5     // LEDs PWM 
#define LED6 6     // LEDs PWM 
#define LED9  9
#define LED10 10
#define LED11 11
// push button for LED 9
#define BUTTON 12

#define SERVO_PIN  7


#define MAX 255 // PWM maximum
#define MID  96 // PWM mid point, not really but more visible
#define MIN   0 // PWM minimum
#define TICK 10 // clock tick
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 

int buttonval = 0; // for push button test -- lites LED 9
int pot0val = 0; // for pot 0, lites LED 10
int pot1val = 0; // for pot 1, lites LED 11


void setup() { 
    myservo.attach(SERVO_PIN);  // attaches the servo on pin 7 to the servo object 

    pinMode(LED9, OUTPUT);
    pinMode(LED10, OUTPUT);
    pinMode(LED11, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}
 
void loop() {
    for (byte i = 0; i < 255; i++){
	analogWrite(LED2, i);
	analogWrite(LED3, i); 
	analogWrite(LED5, i); 
	analogWrite(LED6, i); 
	 
	delay (TICK);
    }
    delay (1000);

    // analogWrite(LED2, MAX);   // turns the LED on
    // analogWrite(LED3, MAX);   // turns the LED on
    // analogWrite(LED5, MAX);   // turns the LED on
    // analogWrite(LED6, MAX);   // turns the LED on

    // delay(TICK);             // waits for a second
    // analogWrite(LED2, MID);   // turns the LED on halfway
    // analogWrite(LED3, MID);   // turns the LED on halfway
    // analogWrite(LED5, MID);   // turns the LED on halfway
    // analogWrite(LED6, MID);   // turns the LED on halfway

    // delay(TICK);             // waits for a second

    // analogWrite(LED2, MIN);   // turns the LED off
    // analogWrite(LED3, MIN);   // turns the LED off
    // analogWrite(LED5, MIN);   // turns the LED off
    // analogWrite(LED6, MIN);   // turns the LED off

    //delay(TICK);             // waits for a second

    // push button

    buttonval = digitalRead(BUTTON); // push button, only reads once through cycle
    if (buttonval == LOW){
	digitalWrite (LED9,LOW);
    } else {
	digitalWrite (LED9,HIGH);
    }
      
    pot0val = analogRead (0); // first pot
    analogWrite (LED10, pot0val/4); // scale the 1024 bit input to 256 bit output
    pot1val = analogRead (1); // first pot
    analogWrite (LED11, pot1val/4); // scale the 1024 bit input to 256 bit output

    delay (10);

    // from Banzi example 6B
    for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
	myservo.write(pos);              // tell servo to go to position in variable 'pos' 
	delay(15);                       // waits 15ms for the servo to reach the position 
    } 
  
    for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
	myservo.write(pos);              // tell servo to go to position in variable 'pos' 
	delay(15);                       // waits 15ms for the servo to reach the position 
    }
}

