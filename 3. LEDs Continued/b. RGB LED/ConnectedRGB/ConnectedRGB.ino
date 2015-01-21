int redPin = A0;    // RED pin of the LED to PWM pin **A0**
int greenPin = D0;  // GREEN pin of the LED to PWM pin **D0**
int bluePin = D1;   // BLUE pin of the LED to PWM pin **D1**
int redValue = 255; // Full brightness for an Cathode RGB LED is 0, and off 255
int greenValue = 255; // Full brightness for an Cathode RGB LED is 0, and off 255
int blueValue = 255; // Full brightness for an Cathode RGB LED is 0, and off 255

void setup()
{
  // Set up our pins for output
  pinMode( redPin, OUTPUT);
  pinMode( greenPin, OUTPUT);
  pinMode( bluePin, OUTPUT);

  //Register our Spark function here
  Spark.function("led", ledControl);

  // turn them all off...
  analogWrite( redPin, redValue);
  analogWrite( greenPin, greenValue);
  analogWrite( bluePin, blueValue);

}


// This routine loops forever
void loop()
{
   // Nothing to do here
}



// This function gets called whenever there is a matching API request
// the command string format is <red>,<green>,<blue>
// for example: 255,0,128 or 128,0,0

int ledControl(String command)
{

    String colors[3];
    colors[0]="";
    colors[1]="";
    colors[2]="";

    int index = 0;
    for( int i = 0; i < command.length(); i++ )
    {
      if( index < 3 ){
        char c = command.charAt(i);
        colors[index] += c;

        if( c == ',') index++;
      }
    }

    // get the red component...
    redValue = colors[0].toInt();
    // now green
    greenValue = colors[1].toInt();
    // now blue
    blueValue = colors[2].toInt();

   // write the mixed color
   analogWrite( redPin, redValue);
   analogWrite( greenPin, greenValue);
   analogWrite( bluePin, blueValue);

   return 1;
}
