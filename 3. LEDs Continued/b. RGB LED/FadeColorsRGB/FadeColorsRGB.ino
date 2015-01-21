int redPin = A0;    // RED pin of the LED to PWM pin **A0**
int greenPin = D0;  // GREEN pin of the LED to PWM pin **D0**
int bluePin = D1;   // BLUE pin of the LED to PWM pin **D1**
int brightness = 255; // Full brightness for an Cathode RGB LED is 0, and off 255

void setup()
{
  // Set up our pins for output
  pinMode( redPin, OUTPUT);
  pinMode( greenPin, OUTPUT);
  pinMode( bluePin, OUTPUT);

}


void loop()
{

  // Set all pins to off
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);


  // Fade up red
  for( int i = 255; i > -1 ; i = i - 5 )
  {
    analogWrite(redPin, i);
    delay(25);
  }

  // Set all pins to off
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);

  // Fade up green

  for( int i = 255; i > -1 ; i = i - 5 )
  {
    analogWrite(greenPin, i);
    delay(25);
  }

  // Set all pins to off
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);

  // Fade up blue
  for( int i = 255; i > -1 ; i = i - 5 )
  {
    analogWrite(bluePin, i);
    delay(25);
  }

  // Set all pins to off
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);

  // Fade all up
  for( int i = 255; i > -1 ; i = i - 5 )
  {
    analogWrite(redPin, i);
    analogWrite(greenPin, i);
    analogWrite(bluePin, i);
    delay(25);
  }


}
