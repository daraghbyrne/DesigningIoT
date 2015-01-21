// First, we define the variables we want to use.
// Here we have a single LED, we create a variable to
// store a reference to the Pin its on.
// In this case, its D0 (look closely at the Core to find it, bottom right)
int led1Pin = D0; // Put the first LED on pin 0
int led2Pin = D1; // put the second LED on pin 1

// This routine runs only once at the beginning
// As the name suggests we use it to set everything up

void setup() {
  // We want to tell the Core that we'll use
  // D0 + D1 as output pins.

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);

  // pinMode and other operations should happen here and not in the loop
  // it gets messy otherwise.
}

// This gets called over and over
void loop() {

  // Turn LED 1 on, and LED 2 off
  digitalWrite( led1Pin, HIGH );
  digitalWrite( led2Pin, LOW );
  delay( 500 ); // wait 0.5s

  // Turn LED 2 on, and LED 1 off
  digitalWrite( led1Pin, LOW );
  digitalWrite( led2Pin, HIGH );
  delay( 500 ); // wait 0.5s
}
