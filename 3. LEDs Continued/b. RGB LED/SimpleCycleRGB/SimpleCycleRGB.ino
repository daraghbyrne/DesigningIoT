int redPin = A4;    // RED pin of the LED to PWM pin **A4**
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

  analogWrite(redPin, brightness);
  delay(500);  // wait for 500 milliseconds

  analogWrite(greenPin, brightness);
  delay(500);  // wait for 500 milliseconds

  analogWrite(bluePin, brightness);
  delay(500);  // wait for 500 milliseconds

  brightness = 255 - brightness;

}
