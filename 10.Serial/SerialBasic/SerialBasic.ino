
// Place an LED on D0
int LED = D0;


void setup() {

    // Set the LED for output
    pinMode(LED, OUTPUT);

    // Begin serial communication
    Serial.begin(9600);

    // Print a message
    Serial.println("started!");
}

void loop() {

    // Print a message
    Serial.println("On!");
    // Turn the LED on
    digitalWrite(LED, HIGH);
    // wait 2.5 seconds
    delay(2500);

    // Print a message
    Serial.println("Off!");
    // Turn the LED on
    digitalWrite(LED, LOW);
    // wait 2.5 seconds
    delay(2500);
}
