
// Define a pin that we'll place the FSR on
// Remember to add a 10K Ohm pull-down resistor too.
int fsrPin = A0;

// Create a variable to hold the FSR reading
int fsrReading = 0;

// Define a pin we'll place an LED on
int ledPin = D0;

// Create a variable to store the LED brightness.
int ledBrightness = 0;

//
void setup(){

  // Set up the LED for output
  pinMode(ledPin, OUTPUT);

  // Create a cloud variable of type integer
  // called 'light' mapped to photoCellReading
  Particle.variable("force", &fsrReading, INT);
}

void loop() {

  // Use analogRead to read the photo cell reading
  // This gives us a value from 0 to 4095
  fsrReading = analogRead(fsrPin);

  // Map this value into the PWM range (0-255)
  // and store as the led brightness
  ledBrightness = map(fsrReading, 0, 4095, 0, 255);

  // fade the LED to the desired brightness
  analogWrite(ledPin, ledBrightness);

  // wait 1/10th of a second and then loop
  delay(100);
}
