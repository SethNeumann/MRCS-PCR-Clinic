/* LED Fire Effect
   Uses two amber and one red LED to simulate fire
   From the instructables.com web site, slightly modified
*/

int ledPin1 =  9;
int ledPin2 = 10;
int ledPin3 = 11;

void setup()
{
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
}

void loop() 
{
analogWrite(ledPin1, random(135, 255));
analogWrite(ledPin2, random(135, 255));
analogWrite(ledPin3, random(135, 255));
delay(random(1, 100));
}
