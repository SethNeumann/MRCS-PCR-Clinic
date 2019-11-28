
#include <Servo.h> // servo Sweep is by BARRAGAN <http://barraganstudio.com> This example code is in the public domain.
Servo myservo;     // create servo object to control a servo 
                   // twelve servo objects can be created on most boards
                
int pos;

//const int LED9 = 9; PWM functionality diabled by using servo library
//const int LED10 = 10; PWM functionality diabled by using servo library

int pot0val = 0; // value for pot read
int pot1val = 0; // value for pot read
int lowpos = 1;  // set it in the range of servo
int highpos = 127;// set it in the range of servo

void setup() {

myservo.attach(7);  // attaches the servo on pin 7 to the servo object 

//byte i;
}

void loop() {
  
 pot0val = analogRead (0); // first pot
 lowpos = pot0val/6; //scale to 1-~180, this is actually 170 degrees
 pot1val = analogRead (1); // second pot
 highpos = pot1val/6; //scale to 1-~180
 {for ( pos=lowpos; pos<=highpos; pos++){
 
    myservo.write(pos);              // tell servo to go to POSition 
    delay(20);                       // waits 15ms for the servo to reach the position 
  } 
 delay(500); // time to recyle
  }
 
 // from Banzi example 6B
}
