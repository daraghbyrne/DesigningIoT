
// The Pin the LED is on
int ledPin = D1;

// The pin we'll read the Tilt sensor from
int tiltPin = D0;

// Hold the state
int currentState = HIGH;

void setup()
{
  pinMode( ledPin, OUTPUT );
  pinMode( tiltPin, INPUT_PULLUP );


}

void loop()
{
    // Read the state from the tilt sensor
    int val = digitalRead( tiltPin );

    // we use the state to figure out what to do.
    // first let's see if the state has chaneged
    if( currentState != val)
    {
        // Why do we do this?
        // Well we don't want to keep publishing events
        // all the time. This means that we only
        // take actions when the state has changed.

        // If its tilted
        if( val == LOW )
        {
          // Display it on the LED
          digitalWrite( ledPin, HIGH );
          // Send an event
          Particle.publish( "tilt-sensor", "tilt detected" );
        }else{
          // Turn th LED off
          digitalWrite( ledPin, LOW );
        }
    }//end currentState if

    // finally update the state
    currentState = val;
}

/*

 To check what events your device is publishing
 use Curl on Mac OSX

 curl 'https://api.spark.io/v1/devices/[your_device_id/events?access_token=[your_access_token]'

 */
