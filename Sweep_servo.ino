/*
Servo Sweep

This program slowly sweeps a servo back and forth from 0 to a presettable maximum number of degrees.
*/

#include <Servo.h>

Servo Servo1;

int pos;
int MaxPos = 90;
int DelayTime = 90;

void setup()
{
  //tell the Arduino & the servo driver that the servo is connected to pin 7
  Servo1.attach(7);  
}

void loop()
{
  //sweep the servo back and forth
  for( pos = 1; pos <=MaxPos; pos++ ) //sweep from 0 to MaxPos in 1 degree steps
  {
    Servo1.write(pos);
    delay(DelayTime);
  }
  delay( 1000 );
  
  //now sweep it back
  for( pos = MaxPos; pos >=1; pos--)  //sweep from MaxPos to 0 in 1 degree steps
  {
    Servo1.write(pos);
    delay(DelayTime);
  }
  delay( 1000 );
}
