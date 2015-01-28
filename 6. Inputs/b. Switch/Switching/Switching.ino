// We will be using D1 to control our LED
int ledPin = D1;

// Our button wired to D0
// We wire D0 to the middle terminal on the switch
// And any of the two other terminals to ground
int switchPin = D0;

void setup()
{

  // For input, we define the
  // switch as an input-pullup
  // this uses an internal pullup resistor
  // to manage consistent reads from the device

  pinMode( switchPin , INPUT_PULLUP); // sets pin as input

  // We also want to use the LED

  pinMode( ledPin , OUTPUT ); // sets pin as output

}

void loop()
{
   // find out if the button is pushed
   // or not by reading from it.
   int buttonState = digitalRead( switchPin );

  // Using a pulldown resistor we get a LOW
  // Signal when its on
  
  if( buttonState == LOW )
  {
    // turn the LED On
    digitalWrite( ledPin, HIGH);
  }else{
    // otherwise
    // turn the LED Off
    digitalWrite( ledPin, LOW);

  }


}
