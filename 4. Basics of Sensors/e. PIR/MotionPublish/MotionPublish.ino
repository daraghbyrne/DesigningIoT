int inputPin = D0;              // choose the input pin (for PIR sensor)
int ledPin = D1;                // LED Pin
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int calibrateTime = 10000;      // wait for the thingy to calibrate

void setup()
{
  pinMode( ledPin, OUTPUT );
  pinMode(inputPin, INPUT);     // declare sensor as input
}

void loop()
{

  // if the sensor is calibrated
  if ( calibrated() )
  {
  // get the data from the sensor
    readTheSensor();

    // report it out, if the state has changed
    reportTheData();
  }
}

void readTheSensor() {
  val = digitalRead(inputPin);
}

bool calibrated() {
  return millis() - calibrateTime > 0;
}

void reportTheData() {

  // if the sensor reads high
  // or there is now motion
  if (val == HIGH) {

    // the current state is no motion
    // i.e. it's just changed
    // announce this change by publishing an eent
    if (pirState == LOW) {
      // we have just turned on
      Particle.publish("designingiot/s15/motion");
      // Update the current state
      pirState = HIGH;
      setLED( pirState );
    }
  } else {
    if (pirState == HIGH) {
      // we have just turned of
      // Update the current state
      pirState = LOW;
      setLED( pirState );
    }
  }
}

void setLED( int state )
{
  digitalWrite( ledPin, state );
}

/*

 To check what events your device is publishing
 use Curl on Mac OSX

 curl 'https://api.spark.io/v1/events/designingiot?access_token=[your_access_token]'

 */
