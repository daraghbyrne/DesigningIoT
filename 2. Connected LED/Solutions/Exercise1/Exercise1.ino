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
// the command string format is l<led number>,<state>
// for example: l1,HIGH or l1,LOW
//              l2,HIGH or l2,LOW

int ledControl(String command)
{
   // blink 3 times
   for( int i = 0; i < 3 ; i++ ){
     digitalWrite(ledPin, HIGH);
     delay( 500 );
     digitalWrite(ledPin, LOW);
     delay( 500 );
   }
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
