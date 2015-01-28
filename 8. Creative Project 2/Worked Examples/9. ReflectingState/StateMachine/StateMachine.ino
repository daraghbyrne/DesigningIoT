
int servoPin = A7;
Servo myServo;
int servoPos = 0;

int potPin = A0;
int potVal;


void setup() {

  pinMode( potPin , INPUT_PULLUP); // sets pin as input

  myServo.attach( servoPin );
  myServo.write(0); // start with servo fully clockwise (down pushup)

  Spark.variable(  "pot" , &potVal , INT );  // From all devices!
  Spark.variable(  "servoPosition" , &servoPos , INT );  // From all devices!


  Spark.subscribe(  "db2015/servo-changed" , handleServoChange );  // From all devices!
  //Spark.subscribe(  "db2015/servo-changed" , handleServoChange , MY_DEVICES);  // From your devices
  //Spark.subscribe(  "db2015/servo-changed" , handleServoChange , "53ff71066667574831282367");  // From a specific device


}

void loop()
{
  // read the value
  int val = analogRead( potPin );

  // convert to a servo positio
  // 0 - 180
  int converted = map( potVal, 0, 4094, 1 , 180 );

  // if the position has changed
  if( val < potVal - 100 || val > potVal + 100 )
  {
      // then announce it
      //publishServoChange( converted );
      // wait 500 ms
      delay( 500 );
  }

  servoPos = converted;
  potVal = val;

  // wait a few seconds
  delay( 100 );
}

void handleServoChange(const char *event, const char *data)
{
  // if there isn't data do nothing
  if (!data) return;

  int val = atoi( data ) ;
  val = constrain( val, 0, 180 );
  // move the servo to the new position
  myServo.write( val );
  servoPos = val;
}


// Publish an event saying that the
// Doorbell has been pushed
void publishServoChange( int position )
{
  if( position == servoPos ) return ;

  String data = "" ;
  data = data + position;

  Spark.publish( "db2015/servo-changed", "" + data );
}
