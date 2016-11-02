# PimpMyToy
Girl's Day - Toy Hacking Workshop im Game Science Center Berlin!

Um einen Arduino mit einem Programm ("Sketch") zu bespielen, muss zunächst die Arduino-Software installiert werden.
https://www.arduino.cc/en/Main/Software

Werden Arduino Nano (Klone) mit CH340-Chipsatz verwendet, muss unter Windows und Mac OS X der Chiptreiber installiert werden. Aktuelle Linux-Distributionen haben den Treiber bereits installiert, CH340-Arduinos sollten ohne zusätzliche Software erkannt werden (noch nicht getestet).
http://sparks.gogo.co.nz/ch340.html

Zur Tonerzeugung wird die NewTone()-Library verwendet und muss zur Arduino-Software hinzugefügt werden.
https://forum.arduino.cc/index.php?topic=143940.0

Wie man eine Bibliothek hinzufügt, kann man hier lesen
https://www.arduino.cc/en/Guide/Libraries

Im Ordner /gdaybtn liegt das Beispiel-Programm gdaybtn.ino, das mit der Arduino-Software geöffnet werden kann

pitches.h, leds.h und sfx.h beinhalten Programmteile für Sounds und LEDs

  Funktionen:
  - Status eines Buttons auslesen
  - Sounds abspielen
  - LEDs blinken lassen
  
  Wir können unsere Komponenten mit unterschiedlichen Pins verbinden um unterschiedliche Effekte zu erzielen.
  So können wir das Spielzeug erstmal "programmieren", ohne uns um den Code kümmern zu müssen.
  Standard-Pin-Belegung:
  
  PIN / Funktion
  
  D2 / Button 1
  
  D3 / Button 2
  
  D4 / Button 3
  
  D5 / Button 4
  
  D6 / Button 5
  
  D8 / Sound 1
  
  D9 / Sound 2
  
  D10 / Sound 3
  
  D11 / Sound 4
  
  D12 / Sound 5
  
  A1 / LED 1
  
  A2 / LED 2
  
  A3 / LED 3
  
  A4 / LED 4
  
  (A5 / Potentiometer)
  
  Button 1 spielt Sound auf Lautsprecher 1, Button 2 spielt Sound auf Lautsprecher 2 usw.
  Die LEDs blinken immer alle (aber unterschiedlich schnell) mit jedem Sound.
  
  Wenn die Schaltung steht, kann auch der Code angepasst werden.
  In der Datei sfx.h finden wir die Programmteile, die den Sound verursachen.<br>
  Und in der Datei leds.h liegt der Code, der die LEDs steuert.
  
