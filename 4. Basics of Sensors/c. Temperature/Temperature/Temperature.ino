// -----------------
// Read temperature
// -----------------

// Define the Pin the Temperature sensor is on
int tempPin = A0;

// Create a variable that will store the temperature value
double temperature = 0.0;
double temperatureF = 0.0;

void setup()
{
  // Register a Spark variable here
  Spark.variable("temperature", &temperature, DOUBLE);
  Spark.variable("temperatureF", &temperatureF, DOUBLE);

  // Connect the temperature sensor to A0 and configure it
  // to be an input
  pinMode(tempPin, INPUT);
}

void loop()
{
  // Keep reading the sensor value so when we make an API
  // call to read its value, we have the latest one
  int reading = analogRead(tempPin);

  // The returned value from the Core is going to be in the range from 0 to 4095
  // Calculate the voltage from the sensor reading
  double voltage = (reading * 3.3) / 4095.0;

  // Calculate the temperature and update our static variable
  temperature = (voltage - 0.5) * 100;

  // Now convert to Farenheight
  temperatureF = ((temperature * 9.0) / 5.0) + 32.0;
}

/*
The API request will look something like this:
GET /v1/devices/{DEVICE_ID}/temperature

# EXAMPLE REQUEST IN TERMINAL
# Core ID is 0123456789abcdef
# Your access token is 123412341234
curl -G https://api.spark.io/v1/devices/0123456789abcdef/temperature \
  -d access_token=123412341234
*/
