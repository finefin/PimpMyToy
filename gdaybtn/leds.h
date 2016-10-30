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
