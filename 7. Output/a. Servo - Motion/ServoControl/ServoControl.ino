
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

}


void loop()
{
for(servoPos = 0; servoPos < 180; servoPos += 20)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    myServo.write(servoPos);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
  for(servoPos = 180; servoPos>=1; servoPos-=20)     // goes from 180 degrees to 0 degrees
  {
    myServo.write(servoPos);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
}
