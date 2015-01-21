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

  // Set all pins to off
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);

}


void loop()
{

  // Create Red only
  // We mix as follows:
  // Turn Red all the way on, Green off, Blue off
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);

  delay(1000); // wait one second


  // Create Green only
  // We mix as follows:
  // Turn Red all the way off, Green on, Blue off
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);

  delay(1000); // wait one second

  // Create Blue only
  // We mix as follows:
  // Turn Red all the way off, Green on, Blue off
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);

  delay(1000); // wait one second


  // Create Pink only
  // We mix as follows:
  // Turn Red all the way on,
  // Turn Green off,
  // Turn Blue on
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);

  delay(1000); // wait one second

  // Create Yellow only
  // We mix as follows:
  // Turn Red all the way on,
  // Turn Green off,
  // Turn Blue on
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);

  delay(1000); // wait one second


  // Create Cyan only
  // We mix as follows:
  // Turn Red all the way off,
  // Turn Green on,
  // Turn Blue on
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);

  delay(1000); // wait one second

  // Create White only
  // We mix as follows:
  // Turn Red all the way on,
  // Turn Green on,
  // Turn Blue on
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);

  delay(1000); // wait one second



}
