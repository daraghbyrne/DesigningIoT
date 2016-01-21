// We will be using D1 to control our LED
int ledPin = D1;

// Our button wired to D0
int buttonPin = D0;

// store the current state of the light
int ledState = LOW;

void setup()
{

  // For input, we define the
  // pushbutton as an input-pullup
  // this uses an internal pullup resistor
  // to manage consistent reads from the device

  pinMode( buttonPin , INPUT_PULLUP); // sets pin as input

  // We also want to use the LED

  pinMode( ledPin , OUTPUT ); // sets pin as output

  // Share the LED state
  Particle.variable( "ledState", &ledState, INT );

}

void loop()
{
   // find out if the button is pushed
   // or not by reading from it.
   int buttonState = digitalRead( buttonPin );

  // remember that we have wired the pushbutton to
  // ground and are using a pulldown resistor
  // that means, when the button is pushed,
  // we will get a LOW signal
  // when the button is not pushed we'll get a HIGH

  // let's use that to set our LED on or off

  // Now let's toggle this

  // if the button is pushed...
  if( buttonState == LOW )
  {
      // if the lED is currently off
      if( ledState == LOW ){
        // turn it on
        digitalWrite( ledPin, HIGH);
        // and set the state
        ledState = HIGH;
      }else{
        // otherwise
        // turn it off
        digitalWrite( ledPin, LOW);
        // and set the state
        ledState = LOW;

      }

  }

}
