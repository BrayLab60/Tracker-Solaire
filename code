// Variables globales
int iPhotoValue1 = 0;        // Valeur du capteur photo-résistant droit
int iPhotoValue2 = 0;        // Valeur du capteur photo-résistant gauche
int diff = 0;                // Différence entre les deux capteurs

int myPinD = A1;             // Pin pour le capteur droit
int myPinG = A3;             // Pin pour le capteur gauche
int dep_D = 9;               // Pin pour le moteur droit
int dep_G = 10;              // Pin pour le moteur gauche

int val_dep = 80;            // Seuil de déclenchement du moteur
int luminosityThreshold = 800; // Seuil de luminosité pour déterminer la nuit

int hallPin = 11;            // Pin pour le capteur Hall
int hallState = 0;           // État du capteur Hall

// Initialisation
void setup() {
  pinMode(dep_D, OUTPUT);       // Moteur droit
  pinMode(dep_G, OUTPUT);       // Moteur gauche
  pinMode(hallPin, INPUT);      // Capteur Hall
  Serial.begin(9600);           // Initialisation de la communication série
}

// Boucle principale
void loop() {
  // Lecture des capteurs photo-résistants
  iPhotoValue1 = analogRead(myPinD);  // Lecture du capteur droit
  iPhotoValue2 = analogRead(myPinG);  // Lecture du capteur gauche
  
  // Calcul de la différence
  diff = iPhotoValue1 - iPhotoValue2;

  // Affichage des valeurs pour diagnostic
  Serial.print((String)"Valeurs : Diff " + diff + "    G " + iPhotoValue2 + " D " + iPhotoValue1 + " ");
  
  // Lecture de l'état du capteur Hall
  hallState = digitalRead(hallPin); 

  // Logique pour contrôler les moteurs
  if (isNight()) {
    // Si c'est la nuit, arrêt des moteurs
    digitalWrite(dep_D, LOW);
    digitalWrite(dep_G, LOW);
    Serial.println("Nuit: Moteur arrêté");
  } else if (hallState == LOW) {
    // Si aucun champ magnétique détecté, inversion de la logique du moteur
    if (diff > val_dep) {
      digitalWrite(dep_D, HIGH);
      digitalWrite(dep_G, LOW);
      Serial.println("Inversion: Tourne à droite");
    } else if (diff < -val_dep) {
      digitalWrite(dep_G, HIGH);
      digitalWrite(dep_D, LOW);
      Serial.println("Inversion: Tourne à gauche");
    } else {
      digitalWrite(dep_D, LOW);
      digitalWrite(dep_G, LOW);
      Serial.println("Inversion: Tourne pas");
    }
  } else {
    // Logique normale des moteurs si un champ magnétique est détecté
    if (diff > val_dep) {
      digitalWrite(dep_G, HIGH);
      digitalWrite(dep_D, LOW);
      Serial.println("Tourne à gauche");
    } else if (diff < -val_dep) {
      digitalWrite(dep_D, HIGH);
      digitalWrite(dep_G, LOW);
      Serial.println("Tourne à droite");
    } else {
      digitalWrite(dep_D, LOW);
      digitalWrite(dep_G, LOW);
      Serial.println("Tourne pas");
    }
  }

  delay(100); // Pause pour éviter une boucle trop rapide
}

// Fonction pour détecter si c'est la nuit
bool isNight() {
  return (iPhotoValue1 > luminosityThreshold && iPhotoValue2 > luminosityThreshold);
}
