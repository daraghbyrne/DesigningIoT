
/* WIRING is so simple
 * -----------------------------
 * SERVO             SPARK CORE
 * Brown or Black   - GND
 * Red / Orange     - VIN (3V+)
 * Yellow/White     - A7
 * -----------------------------
 */


int servoPin = A7;
Servo myServo;
int servoPos = 0;

void setup() {

  // attaches the servo on the A7 pin to the servo object
  myServo.attach( A7 );
  myServo.write(0); // start with servo fully clockwise (down pushup)

   //Register our Spark to control the servo
   Spark.function("servo", servoControl);

  // Keep a cloud variable for the current position
  Spark.variable(  "servoPosition" , &servoPos , INT );


}

void loop()
{
}


// This function gets called whenever there is a matching API request
// the command string format is 0-128

int servoControl(String command)
{
    // Convert
   int newPos = command.toInt();
   // Make sure it is in the right range
   // And set the position
   servoPos = constrain( newPos, 0 , 180);

   // Set the servo
   myServo.write( servoPos );

   // done
   return 1;
}
