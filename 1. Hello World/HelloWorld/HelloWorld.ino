// First, we define the variables we want to use.
// Here we have a single LED, we create a variable to
// store a reference to the Pin its on.
// In this case, its D0 (look closely at the Core to find it, bottom right)
int ledPin = D0;
// You'll need to wire an LED to this Pin to see it blink.


// This routine runs only once at the beginning
// As the name suggests we use it to set everything up

void setup() {
  // We want to tell the Core that we'll use
  // D0 as an output pin.
  pinMode(ledPin, OUTPUT);

  // pinMode and other operations should happen here and not in the loop
  // it gets messy otherwise.
}

// This gets called over and over
void loop() {
  // Now let's make this LED blink

  // First... On
  digitalWrite(ledPin, HIGH);   // Turn ON the LED pins
  delay(1000);               // Wait for 1000mS = 1 second

  // Now... Off
  digitalWrite(ledPin, LOW);   // Turn OFF the LED pins
  delay(1000);               // Wait for 1000mS = 1 second

  // rinse + repeat
}
