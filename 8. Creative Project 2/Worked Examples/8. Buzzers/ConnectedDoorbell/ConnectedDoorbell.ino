#include "pitches.h"

int speakerPin = A0;

int buttonPin = D0;
int val;

// notes in the melody:
int melody[] = { NOTE_A4, NOTE_B4,NOTE_C3 }; //330, 349, 370, 392, 415, 440 };
//{ NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = { 4,8,8 };

boolean isPlaying = false;

void setup() {

  pinMode( buttonPin , INPUT_PULLUP); // sets pin as input

  // Register to receive the doorbellpushed notification
  //
  //Spark.subscribe( eventName, handleDoorbellPush); // From all devices
  Spark.subscribe(  "db-e-doorbell-pushed" , handleDoorbellPush );  // From all devices!
  //Spark.subscribe(  "db-e-doorbell-pushed" , handleDoorbellPush , MY_DEVICES);  // From your devices
  //Spark.subscribe(  "db-e-doorbell-pushed" , handleDoorbellPush , "53ff71066667574831282367");  // From a specific device

  // play once
  doDingDong();


}

void loop()
{

  val = digitalRead( buttonPin );

  if( val == LOW )
  {
      // The doorbell is pushed
      announceDoorbell();
      delay( 2500 );

  }


}

void handleDoorbellPush(const char *event, const char *data)
{
  if( isPlaying == false ){
    doDingDong();
  }
}


// Publish an event saying that the
// Doorbell has been pushed
void announceDoorbell()
{
  Spark.publish( "db-e-doorbell-pushed" );
}


void doDingDong()
{
  isPlaying = true;
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }
  isPlaying = false;
}
