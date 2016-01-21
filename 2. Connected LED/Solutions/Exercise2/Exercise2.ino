// -----------------------------------
// Controlling LEDs over the Internet
// -----------------------------------

// name the pins
int ledPin = D0;

// This routine runs only once upon reset
void setup()
{
   //Register our Particle Core function here
   Particle.function("led", ledControl);

   // Configure the pins to be outputs
   pinMode(ledPin, OUTPUT);

   // Initialize both the LEDs to be OFF
   digitalWrite(ledPin, LOW);
}


// This routine loops forever
void loop()
{
   // Nothing to do here
}


// This function gets called whenever there is a matching API request
// The parameter will be an integer value.
// We'll use the toInt() function on Strings
// see: http://arduino.cc/en/Reference/StringToInt

int ledControl(String command)
{
   // command is the number of times to blink
   // convert it to an integer
   int times = command.toInt();

   // this returns 0 if it couldn't convert
   // we also don't want to blink zero times. pointles.
   // if the times variable is less than one, return an error (-1)
   if( times < 1 ) return -1;

   // loop for as many times as required.
   for( int i = 0; i < times; i++ ){
     digitalWrite(ledPin, HIGH);
     delay( 500 );
     digitalWrite(ledPin, LOW);
     delay( 500 );
   }

   // send back OK!
   return 1;
}


/*
POST /v1/devices/{DEVICE_ID}/led

# EXAMPLE REQUEST IN TERMINAL
# Core ID is 0123456789abcdef
# Your access token is 123412341234
curl https://api.spark.io/v1/devices/0123456789abcdef/led \
  -d access_token=123412341234 \
  -d params=l1,HIGH
*/
