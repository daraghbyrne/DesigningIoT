
// name the pins
int led = D0;

// This routine runs only once upon reset
void setup()
{
   // Set up Pin for output
   pinMode(led, OUTPUT);
}


// This routine loops forever
void loop()
{
  // loop from 0 to 255
  for( int i = 0 ; i < 256; i++)
  {
    // Use analogWrite to set the brightness
    // of the LED
    // This works in a range from 0-255
    analogWrite( led, i );
    delay( 20 ); // wait 20ms
  }

  // loop from 255 to .
  for( int i = 255 ; i >= 0; i--)
  {
    // Use analogWrite to set the brightness
    analogWrite( led, i );
    delay( 20 ); // wait 20ms
  }

  // wait 0.5s
  delay( 500 );

}
