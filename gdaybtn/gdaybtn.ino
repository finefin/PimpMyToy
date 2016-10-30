
/*
  Girl's Day - Toy Hacking Workshop!

  Dieser Sketch ist das Standard-Programm für unsere Arduinos.

  Funktionen:
  - Status eines Buttons auslesen
  - Sounds abspielen
  - LEDs blinken lassen

  Wir können unsere Komponenten mit unterschiedlichen Pins verbinden um unterschiedliche Effekte zu erzielen.
  So können wir das Spielzeug erstmal "programmieren", ohne uns um den Code kümmern zu müssen.

  Standard-Pin-Belegung:

  PIN Dn      Funktion

  D2            Button 1
  D3            Button 2
  D4            Button 3
  D5            Button 4
  D6            Button 5

  D8            Sound 1
  D9            Sound 2
  D10           Sound 3
  D11           Sound 4
  D12           Sound 5

  A1            LED 1
  A2            LED 2
  A3            LED 3
  A4            LED 4

  A5            Potentiometer

  Button 1 spielt Sound auf Lautsprecher 1, Button 2 spielt Sound auf Lautsprecher 2 usw.
  Die LEDs blinken immer alle (aber unterschiedlich schnell) mit jedem Sound.

  Buttons anschließen:
  Verbinde einen Kontakt mit GND und den anderen mit einem der Button-Pins (D2-D6).

  Lautsprecher anschließen:
  Verbinde einen Kontakt mit GND und den anderen mit einem der Sound-Pins (D8-D12).

  LED anschließen:
  Verbinde das lange Bein (Anode) mit einem Widerstand (ca. 300 Ohm) und den Widerstand mit einem 
  LED-Pin (A1-A4). Das kurze Bein (Kathode) wird mit GND verbunden.

  Wenn die Schaltung steht, kann auch der Code angepasst werden.
  Für die Soundeffekte, schaue dir die Datei sfx.h an, hier werden auch die LEDs angesteuert.

*/

// Zunächst definieren wir die Namen unserer Pins
// Wir können dann im Hauptprogramm einfach die lesbaren Bezeichner benutzen
// und die dazugehörigen Pins an dieser Stelle neu definieren,
// So müssen wir das Programm nicht nochmal anpassen.

// Button Pins
#define BTN_PIN1 2
#define BTN_PIN2 3
#define BTN_PIN3 4
#define BTN_PIN4 5
#define BTN_PIN5 6

// Speaker Pins
#define SPK_PIN1 8
#define SPK_PIN2 9
#define SPK_PIN3 10
#define SPK_PIN4 11
#define SPK_PIN5 12

// LED Pins
#define LED_PIN1 A1
#define LED_PIN2 A2
#define LED_PIN3 A3
#define LED_PIN4 A4

// Poti Pin
#define POT_PIN1 A5

#include <NewTone.h> // NewTone ist eine Bibliothek, die es uns ermöglicht, mit einfachen Befehlen Töne zu generieren

int potiRead = 0;    // Wir können einen Potenziometer (Drehknopf) auslesen und den Wert in potiRead speichern

#include "leds.h"   // Die Lichteffekte können in der leds.h angepasst werden
#include "sfx.h"    // Die Soundeffekte können in der sfx.h angepasst werden


void setup() {
  // setup wird EINMAL ausgeführt, wenn der Arduino startet!

  // Mit Serial.begin() stellen wir eine serielle Verbindung zum PC her
  // Der Arduino kann dann an den Computer Nachrichten schicken und umgekehrt.
  // Das ist besonders dann wichtig, wenn etwas nicht funktioniert.
  Serial.begin(9600);


  // Jetzt werden die Buttons eingerichtet.
  pinMode(BTN_PIN1, INPUT);
  pinMode(BTN_PIN2, INPUT);
  pinMode(BTN_PIN3, INPUT);
  pinMode(BTN_PIN4, INPUT);
  pinMode(BTN_PIN5, INPUT);
  // Da wir möglichst wenige Kabel benutzen wollen,
  // aktivieren wir nun die internen Pullup-Widerstände des Arduinos.
  // Das bewirkt, dass wir den Stromkreis "umdrehen"
  // und ihn unterbrechen, wenn wir den Button drücken.
  // Das spart Kabel, Widerstände und Stress ;)
  digitalWrite (BTN_PIN1, HIGH);
  digitalWrite (BTN_PIN2, HIGH);
  digitalWrite (BTN_PIN3, HIGH);
  digitalWrite (BTN_PIN4, HIGH);
  digitalWrite (BTN_PIN5, HIGH);

  // Jetzt kommen die Pins für den/die Lautsprecher dran.
  // Diese definieren wir einfach als Outputs:
  pinMode(SPK_PIN1, OUTPUT);
  pinMode(SPK_PIN2, OUTPUT);
  pinMode(SPK_PIN3, OUTPUT);
  pinMode(SPK_PIN4, OUTPUT);
  pinMode(SPK_PIN5, OUTPUT);

  // ... und dies sind die Pins für unsere LEDs
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);

  // ... und für den Fall, dass ein Potenziometer angeschlossen werden soll...
  // pinMode(POT_PIN1, INPUT);

  // Wie oben beschrieben, müssen nicht an alle Pins auch tatsächlich Komponenten angeschlossen werden.
  // Wir entscheiden, welche Ein- und Ausgänge wir nutzen wollen und lassen die anderen einfach offen.

}

// In der Funktion loop() spielt sich das eigentliche Programm ab.
// Alles, was zwischen void loop() {   und   } steht, wird so schnell
// wiederholt, wie der Arduino kann bzw. wie es unser Programm zulässt.
void loop() {

  // mit jeder Wiederholung lesen wir den Status der Buttons aus
  int button1 = digitalRead (BTN_PIN1);
  int button2 = digitalRead (BTN_PIN2);
  int button3 = digitalRead (BTN_PIN3);
  int button4 = digitalRead (BTN_PIN4);
  int button5 = digitalRead (BTN_PIN5);
  // Da wir den Pullup-Widerstand benutzen,
  // wird bei den Buttons "1" bzw. "HIGH" ausgelesen, wenn sie NICHT gedrückt werden
  // und "0" bzw "LOW", wenn wir sie drücken.
  // Genau das fragen wir jetzt nacheinander ab:
  if (button1 == LOW) {
    // button1 wird gedrückt

    animalSound (SPK_PIN1, "kuh");

    // sfxRandomSine(SPK_PIN1);                    // eine zufällig oszillierende "Sinus-Tonfolge"
    // playMOLL(SPK_PIN1, random (4, 16), 950);    // Zufällige Melodie in C-Moll
    // playDUR(SPK_PIN1, random (4, 16), 950);     // Zufällige Melodie in C-Dur
    // sndfxSine(SPK_PIN1, 0.1, 1000, 50);         // Vogel
    // sndfxSine(SPK_PIN1, 0.01, 1000, 500, 550);  // Crazy Sirene
    // sndfxSine(SPK_PIN1, 0.1, 100, 100);         // Motor springt nicht an
    // sndfxUP(SPK_PIN1, 100, 1000, 10);           // ein schnell ansteigender Ton
    // sndfxDWN(SPK_PIN1,1000, 100, 1);            // ein langsam fallender Ton
    // playRandomSound(SPK_PIN1);                  // ein zufälliger Sound

  }

  if (button2 == LOW) {
    // button2 wird gedrückt
    sndfxUP(SPK_PIN2, 100, 1000, 10); // ein schnell ansteigender Ton
  }

  if (button3 == LOW) {
    // button3 wird gedrückt
    sndfxDWN(SPK_PIN3, 1000, 100, 1); // ein langsam fallender Ton
  }

  if (button4 == LOW) {
    // button4 wird gedrückt
     animalSound (SPK_PIN1, "vogel");
  }

  if (button5 == LOW) {
    // button5 wird gedrückt
    playMOLL(SPK_PIN5, random (4, 16), random(128, 1024)); // eine zufällige Melodie in C-Moll
  }

  // Wenn KEIN Button mehr gedrückt wird, sollen alle LEDs aus gehen
  // hierfür benutzen wir das "logische UND" (&&)
  // das bewirkt, dass der Code in den geschweiften Klammern nur dann ausgeführt wird,
  // wenn alle Bedingungen zutreffen, hier: alle Buttons auf HIGH stehen
  if (button1 == HIGH && button2 == HIGH && button3 == HIGH && button4 == HIGH && button5 == HIGH) {
    // mit "digitalWrite" können wir einen Pin ein- und ausschalten,
    // indem wir ihn auf HIGH oder LOW setzen. Hier machen wir alle LEDs aus:
    digitalWrite (LED_PIN1, LOW);
    digitalWrite (LED_PIN2, LOW);
    digitalWrite (LED_PIN3, LOW);
    digitalWrite (LED_PIN4, LOW);
  }

  // Wenn wir einen Potentiometer-Drehknopf einbauen,
  // können wir mit analogRead dessen Wert auslesen und in potiRead speichern
  // potiRead = analogRead (A1) * 2;

} // hier endet die loop()-Funktion und der Arduino fängt wieder oben an




