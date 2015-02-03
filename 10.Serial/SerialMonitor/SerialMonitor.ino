// Create a variable
// To store an integer
int count = 0;

void setup()                    // run once, when the sketch starts
{
  Serial.begin( 9600 );         // Setups Serial Communications
}

void loop()                     // run over and over again
{
  Serial.print( "Looped " );    // Output a String
  Serial.print( count );        // Output the number of loops
  Serial.println( " times" );   // Output the end of line
  count++;                      // Increment the value
  delay(1000);                  // waits for a second
}
