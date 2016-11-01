/*
   leds.h
     Lichteffekte für den Girl's Day-Workshop

*/

#include <Arduino.h> // ohne das funktioniert hier nichts

void blinkModulo (int einWert) {

  // Hier werden die LEDs anhand eines beliebigen Wertes an und ausgeschaltet
  // Wenn "einWert" eine gerade Zahl ist, werden LED_PINs 1 und 3 angeschaltet, die anderen ausgeschaltet.
  // Ist einWert ungerade, werden LED_PINs 1 und 3 ausgeschaltet, die anderen angeschaltet.

  if (einWert % 2 > 0) {
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

}

void alleLEDsAn () {
  digitalWrite (LED_PIN1, HIGH);
  digitalWrite (LED_PIN2, HIGH);
  digitalWrite (LED_PIN3, HIGH);
  digitalWrite (LED_PIN4, HIGH);
}

void alleLEDsAus () {
  digitalWrite (LED_PIN1, LOW);
  digitalWrite (LED_PIN2, LOW);
  digitalWrite (LED_PIN3, LOW);
  digitalWrite (LED_PIN4, LOW);
}

// Verwendung:
// nummerLEDan (1); // LED 1 wird eingeschaltet
void nummerLEDAn (int ledNummer) {
  if (ledNummer == 1) {
    digitalWrite (LED_PIN1, HIGH);
  }

  if (ledNummer == 2) {
    digitalWrite (LED_PIN2, HIGH);
  }
  
  if (ledNummer == 3) {
    digitalWrite (LED_PIN3, HIGH);
  }
  
  if (ledNummer == 4) {
    digitalWrite (LED_PIN4, HIGH);
  }
}

// Verwendung im Programm:
// nummerLEDAus (3); // LED 3 wird ausgeschaltet
void nummerLEDAus (int ledNummer) {
  if (ledNummer == 1) {
    digitalWrite (LED_PIN1, LOW);
  }

  if (ledNummer == 2) {
    digitalWrite (LED_PIN2, LOW);
  }
  
  if (ledNummer == 3) {
    digitalWrite (LED_PIN3, LOW);
  }
  
  if (ledNummer == 4) {
    digitalWrite (LED_PIN4, LOW);
  }
}


