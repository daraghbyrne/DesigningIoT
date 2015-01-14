// -----------------------------------
// Controlling LEDs over the Internet
// -----------------------------------

// name the pins
int ledPin = D0;

// This routine runs only once upon reset
void setup()
{
   //Register our Spark function here
   Spark.function("led", ledControl);

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
   int state = LOW;

   // find out the state of the led
   if(command == "HIGH") state = HIGH;
   else if(command == "LOW") state = LOW;
   else return -1;

   // write to the appropriate pin
   digitalWrite(ledPin, state);
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
