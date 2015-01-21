

void setup()
{

}

void loop()
{
  RGB.control(true);

  for( int i = 0 ; i < 256; i++){
    RGB.color( i, 0,0 );
    delay( 50 );
  }

  for( int i = 0 ; i < 256; i++){
    RGB.color( 0,i,0 );
    delay( 50 );
  }


  for( int i = 0 ; i < 256; i++){
    RGB.color( 0,0,i );
    delay( 50 );
  }


  RGB.control(false);
}
