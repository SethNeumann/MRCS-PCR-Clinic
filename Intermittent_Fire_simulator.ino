/* LED Fire Effect
   Uses two amber and one red LED to simulate fire
   From the instructables.com web site
   
   Included a WHILE loop, so that the effect turns on and off.
*/

int ledPin1 =  9;
int ledPin2 = 10;
int ledPin3 = 11;
int OnTime;
int OffTime;
int i;

void setup()
{
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
}

void loop() 
{
OnTime = random( 1000, 5000 );
while( OnTime > 0 )
  {
  analogWrite(ledPin1, random(120)+135);
  analogWrite(ledPin2, random(120)+135);
  analogWrite(ledPin3, random(120)+135);
  i = random(1, 100);
  delay( i );
  OnTime = OnTime - i;
  }
  
  // off time, ensure the LEDs are turned off
  analogWrite(ledPin1, 255 );
  analogWrite(ledPin2, 255 );
  analogWrite(ledPin3, 255 );
  OffTime = random ( 1000, 3000 );
  delay ( OffTime );
}
