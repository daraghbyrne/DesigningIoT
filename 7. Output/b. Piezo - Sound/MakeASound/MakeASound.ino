
int speakerPin = D0;

// create an array for the notes in the melody:
int melody[] = {1908,2551,2551,2273,2551,0,2024,1908}; //C4,G3,G3,A3,G3,0,B3,C4

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4,8,8,4,4,4,4,4 };

void setup() {

  pinMode( speakerPin, OUTPUT );
  playNotes();
}

void loop()
{

}

void playNotes()
{
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
}
