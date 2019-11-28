/* Blink

This program blinks an LED on and off

*/

const int LED2 = 2;  //D2

void setup()
{
  pinMode( LED2, OUTPUT );
  
}

void loop()
{
  digitalWrite( LED2, HIGH );
  delay( 1000);
  digitalWrite( LED2, LOW );
  delay ( 1000 );

}

