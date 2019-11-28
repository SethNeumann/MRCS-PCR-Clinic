/*
Grade Crossing

Ties together the blinking lights and servomotor sweep,
along with reading an input, to drive a grade crossing.
The servo simulates a crossing arm.

The sequence is a bit stylized to keep the code manageable
for the clinic.
*/

#include <Servo.h>
Servo Servo1;

int pos;
int MaxPos   = 90;   // max position in degrees
int ServoPos;        // where the servo is in it's sweep
int StepTime = 90;   // time between steps
int ServoTime;       // time since last step

const int TriggerPin = 12;  //Digitial input D12 
int Trigger;

int BlinkRate = 1000;  //rate at which the LED blinks 
int LEDTime;
int Delta = 90;    // number of msec for each loop iteration
int LEDPin = 2;
boolean LEDState;

void setup()
{
  pinMode( TriggerPin, INPUT_PULLUP);
  //tell the Arduino & the servo driver that the servo is connected to pin 7
  Servo1.attach(7);  
  Servo1.write( 0 );   // ensure the crossing gate is raised
  ServoPos = 0;
  LEDState = false;    // LED starts off
  pinMode ( LEDPin, OUTPUT );
  digitalWrite ( LEDPin, HIGH );
  } // end of setup

void loop()
{
  //poll, looking for a LOW to start the sequence
  do
  {
    Trigger = digitalRead( TriggerPin );
  }
  while( Trigger == HIGH );
 
  //start the sequence
  ServoTime  = StepTime;   // initialize the crossing arm timer
  LEDTime    = 0;          // go into the routine with the LED off, so it will turn on
  LEDState   = false;
  ServoPos   = 0;         // crossing arm raised position
  do
    {
    // see if we need to change the stat of the LED
    LEDTime = LEDTime - Delta;
    if( LEDTime <= 0 )
      {
        LEDState = !LEDState;  //LED to other state; on or off
        if (LEDState)
        {
          digitalWrite ( LEDPin, LOW );
        }
        else
        {
          digitalWrite ( LEDPin, HIGH );
        }
        LEDTime = BlinkRate;  //load up the next blink cycle
      }
   
    //see if we need to change the state of the crossing arm  
    ServoTime = ServoTime - Delta;
    if( ServoTime <= 0 )
      {
        //if arm not at down position, move it
        if( ServoPos < MaxPos )
          {
            ServoPos++;
            Servo1.write( ServoPos );
            // and reset the timer for the next step
            ServoTime = StepTime;
          }
      }
    delay ( Delta );
    Trigger = digitalRead( TriggerPin );
    }
  while ( Trigger == LOW );
  
  //switch has been released, turn off the light and raise the arm
  digitalWrite( LEDPin, HIGH );
  
  for( int pos = ServoPos; pos >=1; pos--)
  {
    Servo1.write(pos);
    delay( StepTime );
  }
   
  
} // end of loop
