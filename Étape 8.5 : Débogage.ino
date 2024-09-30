int iPhotoValue1 = 0; // Valeur du capteur de luminosité 1
int iPhotoValue2 = 0; // Valeur du capteur de luminosité 2
int diff = 0; // Différence entre les deux valeurs

int myPinD = A1; // Pin pour la photo-résistance 1
int myPinG = A3; // Pin pour la photo-résistance 2
int hallPin = 11; // Pin pour le capteur Hall
int hallState = 0; // Variable pour stocker l'état du capteur Hall

void setup() {
  Serial.begin(9600); // Initialisation de la communication série
  pinMode(hallPin, INPUT); // Configurer le capteur Hall en tant qu'entrée

  // Vous pouvez également ajouter les autres broches, si vous en avez besoin
  // pour les tests, mais elles ne sont pas nécessaires pour la lecture des capteurs.
}

void loop() {
  // Lire les valeurs des photo-résistances
  iPhotoValue1 = analogRead(myPinD); // Lire la valeur de la photo-résistance 1
  iPhotoValue2 = analogRead(myPinG); // Lire la valeur de la photo-résistance 2
  diff = iPhotoValue1 - iPhotoValue2; // Calculer la différence entre les deux capteurs

  // Lire l'état du capteur Hall
  hallState = digitalRead(hallPin);

  // Afficher les valeurs dans le moniteur série
  Serial.print("Photo-résistance D (A1) : ");
  Serial.print(iPhotoValue1);
  Serial.print("  | Photo-résistance G (A3) : ");
  Serial.print(iPhotoValue2);
  Serial.print("  | Différence : ");
  Serial.print(diff);
  Serial.print("  | État du capteur Hall : ");
  if (hallState == HIGH) {
    Serial.println("Champ magnétique détecté");
  } else {
    Serial.println("Aucun champ magnétique");
  }

  // Délai pour éviter que la boucle soit trop rapide
  delay(500); // Attendre 500 ms avant la prochaine lecture
}
