/*
  Version modifiée pour afficher au port série et l'écran OLED la valeur lue au potentiomètre.
*/
#include "Ecran.h"

Ecran monEcran;

int potValue = 0;
const int delais = 250;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  delay(100);
  monEcran.begin();
  
  Serial.println("Initialisation terminée - je suis prêt!");

}

// the loop function runs over and over again forever
void loop() {
  potValue = analogRead(15);
  Serial.println(potValue);
  monEcran.effacer();
  monEcran.ecrire(String(potValue),2,3);
  monEcran.refresh();
  delay(delais);                    // wait for a second
}
