
// name the pins
int ledPin = D0;

// create a variable to store the
// current brightness of the LED
int ledValue = 0;

// This routine runs only once upon reset
void setup()
{ 
   //Register our Particle Core function to allow
   // Control of the LED
   Particle.function("led", ledControl);

   // Make the variable 'ledValue' available through
   // the Particle Core cloud as 'brightness'
   Particle.variable("brightness", &ledValue, INT);

   // Set up pin for output
   pinMode(ledPin, OUTPUT);
}


// This routine loops forever
void loop()
{
  // do nothing
}


// This function gets called whenever there is a matching API request
// the command string format is simply a passed integer value
// e.g. 1,125 etc. in the range of 0-255

int ledControl(String command)
{
    // Convert the passed variable to an integer
   ledValue = command.toInt();

   // Check it is a valid number
   if( ledValue > 255 ) return -1;
   if( ledValue < 0 ) return -1;

   // Use PWM to set the brightness
   // of the LED
   analogWrite(ledPin, ledValue);

   // Return 1 to say completed successfully
   return 1;
}


/*
POST /v1/devices/{DEVICE_ID}/led

# EXAMPLE REQUEST IN TERMINAL
# Core ID is 0123456789abcdef
# Your access token is 123412341234
curl https://api.spark.io/v1/devices/0123456789abcdef/led \
  -d access_token=123412341234 \
  -d params=155
*/

/*
curl "https://api.spark.io/v1/devices/0123456789abcdef/ledvalue?access_token=123412341234"


*/
