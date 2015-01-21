// Lets set up three variable to store
// our r,g,b values
// In the case ofthe inbuilt RGB 0 is off, 255 is on.
int redValue = 255;
int greenValue = 255;
int blueValue = 255;


void setup()
{
  //Register our Spark function here
  Spark.function("led", ledControl);

  // We need to say we'll be controlling the RGB led
  RGB.control(true);

  // set it to white
  RGB.color( 255,255,255);

  // We can undo this and go back to normal
  // using the following command
  RGB.control(false);


}

void loop()
{
  // do nothing
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


    // We need to say we'll be controlling the RGB led
    RGB.control(true);

    // set it to white
    RGB.color( redValue,greenValue,blueValue);

    // wait 3 seconds
    delay( 3000 );

    // return control of the RGB led to spark
    RGB.control(false);


   return 1;
}
