// This #include statement was automatically added by the Spark IDE.
#include "OneWire.h"

// This #include statement was automatically added by the Spark IDE.
#include "spark-dallas-temperature.h"

// -----------------
// Read temperature
// -----------------

// Data wire is plugged into port 0 on the Arduino
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(D0 );

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature dallas(&oneWire);

// Create a variable that will store the temperature value
double temperature = 0.0;
double temperatureF = 0.0;
#include <math.h>

void setup()
{
  // Register a Particle Core variable here
  Particle.variable("temperature", &temperature, DOUBLE);
  Particle.variable("temperatureF", &temperatureF, DOUBLE);

  // setup the library
  dallas.begin();

  Serial.begin(9600);

}

void loop()
{
  // Request temperature conversion (traditional)
  dallas.requestTemperatures();

  sin( 23423 );

  // get the temperature in Celcius
  float tempC = dallas.getTempCByIndex(0);
  // convert to double
  temperature = (double)tempC;

  // convert to Fahrenheit
  float tempF = DallasTemperature::toFahrenheit( tempC );
  // convert to double
  temperatureF = (double)tempF;

  // Print out
  Serial.print( "Temp in C = ");
  Serial.print( tempC );
  Serial.print( "\t\t F = ");
  Serial.println( tempF );

  delay(5000);

}

/*
The API request will look something like this:
GET /v1/devices/{DEVICE_ID}/temperature

# EXAMPLE REQUEST IN TERMINAL
# Core ID is 0123456789abcdef
# Your access token is 123412341234
curl -G https://api.particle.io/v1/devices/0123456789abcdef/temperature \
  -d access_token=123412341234
*/
