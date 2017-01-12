#include "pitches.h"

int speakerPin = D1;

int buttonPin = D0;
int val;

// notes in the melody:
// include the pitches.h
// or use the mappings below
//int melody[] = { NOTE_A4, NOTE_B4,NOTE_C3 };
int melody[] = { 440, 494, 131 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = { 4,8,8 };

// Track if the doorbell is playing
boolean isPlaying = false;

void setup() {

  pinMode( buttonPin , INPUT_PULLUP); // sets pin as input

  // Register to receive the doorbellpushed notification
  // Make sure you use a relatively unique name
  // Anyone in the class can use this to build a connected doorbell.
  Particle.subscribe(  "db2017/doorbell-pushed" , handleDoorbellPush );  // From all devices!
  // or...
  //Particle.subscribe(  "db2017/doorbell-pushed" , handleDoorbellPush , MY_DEVICES);  // From your devices
  //Particle.subscribe(  "db2017/doorbell-pushed" , handleDoorbellPush , "53ff71066667574831282367");  // From a specific device

  // uncomment to play at startup
  //doDingDong();


}

void loop()
{
  // read the value from the button pin
  val = digitalRead( buttonPin );

  // if the button is pushed
  if( val == LOW )
  {
      // The doorbell is pushed
      announceDoorbell();

      // Wait for 2.5 seconds before letting
      // another event happen
      delay( 2500 );

    // this is good practice because the API
    // has a rate limit of 1 event per second
    // don't go nuts and send loads!

  }

}

void handleDoorbellPush(const char *event, const char *data)
{
  if( isPlaying == false ){
    // set is playing to true
    isPlaying = true;
    // play the chime
    doDingDong();
  }

  // We're done. Allow another chime to play.
  isPlaying = false;

}


// Publish an event saying that the
// Doorbell has been pushed
void announceDoorbell()
{
  Particle.publish( "db2015/doorbell-pushed" );
}


void doDingDong()
{
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 3; thisNote++) {

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
}
