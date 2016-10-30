/*
   sfx.h
     Soundeffekte für den Girl's Day-Workshop

  Hier finden wir alle Funktionen, die Sounds auf den angeschlossenen Lautsprechern ausgeben.
  Folgende Funktionen können vom Hauptprogramm aus aufgerufen werden:


    sndfxSine(int derPin, float zwitscherFaktor, int basisHoehe, int dauer)
            Spielt auf dem angegeben Pin einen Ton, der konstant auf- und absteigt.
            "Sine" bezieht sich auf die Sinus-Funktion, die hier verwendet wird

    sfxRandomSine(pin)
            Spielt einen zufälligen Zwitscher-Sound

    sndfxUP(pin)
            Spielt einen konstant ansteigenden Ton

    sndfxDWN(pin)
            Spielt einen konstant abfallenden Ton

    playMOLL(pin, anzahlNoten, tempo)
            Spielt eine zufällige Melodie in C-Moll

    playDUR(pin, anzahlNoten, tempo)
            Spielt eine zufällige Melodie in C-Dur

    playRandomSound (pin)
            Spielt zufällig einen der gelisteten Sounds


*/

#include <Arduino.h> // ohne das hier funktioniert nichts
#include "pitches.h" // hier sind die Frequenzen für die Klaviernoten gespeichert

// mit der Frequenzen-Sammlung in der pitches.h können wir Melodien aufschreiben und abspielen lassen
// in dieser Liste hier habe ich mal ein paar Akkorde
int chords[4][6] = {
  { NOTE_C2, NOTE_DS3, NOTE_F4, NOTE_GS3, NOTE_B3, 0 }, // C-Moll
  { NOTE_C2, NOTE_E3, NOTE_G3, NOTE_A2, NOTE_C3, 0},   // C-Dur
  { NOTE_C2, NOTE_DS2, NOTE_FS2, NOTE_A2, NOTE_C3, 0},  //
  {}  //
};


// Je nach Tonhöhe und zwitscherFaktor kann diese Funktion
// wie ein Vogel zwitschern oder wie ein Motor brummen
void sndfxSine(int derPin, float zwitscherFaktor, int amplitude, int basisHoehe, int dauer) {

  // Hier tut ein for-Loop seine Arbeit.:
  // Er wiederholt den Code so lange, wie "i" kleiner als "dauer" ist
  for (unsigned long i = 0; i <= dauer; i += 1) {
    // In ix wird der Wert für die neue Frequenz gespeichert, die gepielt werden soll
    int ix = int( sin(i * zwitscherFaktor) * amplitude ) + basisHoehe * 1.1;

    // Hier werden die LEDs entsprechend der Sounds an und ausgeschaltet
    // Wenn ix eine gerade Zahl ist, werden LED_PINs 1 und 3 angeschaltet, die anderen ausgeschaltet.
    // Ist ix ungerade, werden LED_PINs 1 und 3 ausgeschaltet, die anderen angeschaltet.
    if (ix % 2 > 0) {
      digitalWrite (LED_PIN1, HIGH);
      digitalWrite (LED_PIN2, LOW);
      digitalWrite (LED_PIN3, HIGH);
      digitalWrite (LED_PIN4, LOW);
    } else {
      digitalWrite (LED_PIN1, LOW);
      digitalWrite (LED_PIN2, HIGH);
      digitalWrite (LED_PIN3, LOW);
      digitalWrite (LED_PIN4, HIGH);
    }

    // NewTone hier spielt den neuen Ton ab
    NewTone(derPin, ix + potiRead);
    // es wird sehr kurz gewartet (2 Millisekunden)
    delay(2);
  }
  // und am Ende wird der Ton gestoppt
  noNewTone(derPin);
}

// Diese Funktion startet sndfxSine mit zufälligen Werten
void sfxRandomSine (int derPin) {
  float randomWhistle = random (5, 30) * .01;
  int randomPitch = random (150, 2200);
  int randomAmp = random (50, randomPitch);
  int randomDur = random (50, 150);
  sndfxSine(derPin, randomWhistle, randomAmp, randomPitch, randomDur);
}


// Hier wird ein for-Loop verwendet, um einen ansteigenden Ton zu generieren
void sndfxUP(int derPin, int startFrequenz, int endFrequenz, int geschwindigkeit) {
  for (unsigned long freq = startFrequenz; freq <= endFrequenz; freq += geschwindigkeit) {
    NewTone(derPin, freq + potiRead);
    if (freq % 2 > 0) {
      digitalWrite (LED_PIN1, HIGH);
    } else {
      digitalWrite (LED_PIN1, LOW);
    }
    delay(1);
  }
  noNewTone(derPin);
}

// Hier wird ein for-Loop verwendet, um einen absteigenden Ton zu generieren
void sndfxDWN(int derPin, int startFrequenz, int endFrequenz, int geschwindigkeit)  {
  for (unsigned long freq = startFrequenz; freq > endFrequenz; freq -= geschwindigkeit) {
    NewTone(derPin, freq + potiRead);
    if (freq % 5 > 0) {
      digitalWrite (LED_PIN1, HIGH);
    } else {
      digitalWrite (LED_PIN1, LOW);
    }
    delay(1);
  }
  noNewTone(derPin);
}

// Spielt eine zufällige Tonfolge aus der C-Moll-Liste
void playMOLL(int derPin, int anzahlNoten, int tempo) {
  int tDelay = 1024 - tempo;
  if (tDelay < 0) tDelay = 0;
  for (int steps = 0; steps < anzahlNoten; steps++) {
    int zufallsNote = random (0, 5);
    int zufallsPause = random (0, tempo * 0.25);
    int dieNote = chords [0] [zufallsNote];
    NewTone(derPin, dieNote + potiRead);
    delay(tDelay);
    noNewTone(derPin);
    delay (zufallsPause);
  }
}

// Spielt eine zufällige Tonfolge aus der C-Dur-Liste
void playDUR(int derPin, int anzahlNoten, int tempo) {
  int tDelay = 1024 - tempo;
  if (tDelay < 0) tDelay = 0;
  for (int steps = 0; steps < anzahlNoten; steps++) {
    int zufallsNote = random (0, 5);
    int zufallsPause = random (0, tempo * 0.25);
    int dieNote = chords [1] [zufallsNote];
    NewTone(derPin, dieNote + potiRead);
    delay(tDelay);
    noNewTone(derPin);
    delay (zufallsPause);
  }
}


void animalSound (int derPin, String theAnimal) {

  if (theAnimal == "vogel") {
    int rndLaenge = random (2, 6);
    for (int steps = 0; steps < rndLaenge; steps++) {
      sfxRandomSine(derPin);
    }
    sndfxDWN(derPin, 650, 100, 2);
  }

  if (theAnimal == "kuh") {
      sndfxSine(derPin, 0.01, 10, 20, 300);
      sndfxUP(derPin, 10, 200, 1);
      sndfxSine(derPin, 0.01, 50, 200, 300);
      sndfxDWN(derPin, 200, 10,  1);
  }


}

// Würfelt einmal rndSnd und spielt dann einen zufälligen Sound ab
void playRandomSound (int derPin) {
  //Serial.println ("PLAY RND SND");
  int rndSnd = random (0, 6);
  if (rndSnd < 3) {
    sfxRandomSine(derPin);
  } else if (rndSnd == 4) {
    playMOLL(derPin, random (4, 8), random(900, 1024));
  } else if (rndSnd == 5) {
    sndfxUP(derPin, 100, 1000, 10);
  } else {
    sndfxDWN(derPin, 1000, 100, 10);
  }
}
