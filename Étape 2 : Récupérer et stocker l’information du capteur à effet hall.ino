int hallPin = 11;  // Broche numérique pour le capteur à effet Hall
int hallState = 0;  // Variable pour stocker l'état du capteur Hall

void setup() {
  pinMode(hallPin, INPUT);  // Configurer la broche du capteur Hall comme une entrée
  Serial.begin(9600);  // Démarrer la communication série
}

void loop() {
  hallState = digitalRead(hallPin);  // Lire l'état du capteur Hall

  // Afficher l'état du capteur dans le moniteur série
  if (hallState == HIGH) {
    Serial.println("Champ magnétique détecté");
  } else {
    Serial.println("Pas de champ magnétique détecté");
  }

  delay(500);  // Pause de 500ms avant la prochaine lecture
}
