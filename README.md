# PimpMyToy
Girl's Day - Toy Hacking Workshop!

Es werden Arduino Nano (Klone) mit CH340-Chipsatz verwendet. 
http://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html

Zur Tonerzeugung wird die NewTone()-Library verwendet.
https://forum.arduino.cc/index.php?topic=143940.0

Im Ordner /gdaybtn liegt das Beispiel-Programm gdaybtn.ino

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
  Für die Soundeffekte, schaue dir die Datei sfx.h an, hier werden auch die LEDs angesteuert.
