int dep_D = 9;  // Broche pour le relais qui contrôle le moteur dans une direction
int dep_G = 10;  // Broche pour le relais dans l'autre direction

void setup() {
  pinMode(dep_D, OUTPUT);  // Configurer les broches des relais comme des sorties
  pinMode(dep_G, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Activer le relais pour tourner à droite
  digitalWrite(dep_D, HIGH);
  digitalWrite(dep_G, LOW);
  Serial.println("Tourne à droite");
  delay(1000);  // Attendre 1 seconde

  // Activer le relais pour tourner à gauche
  digitalWrite(dep_D, LOW);
  digitalWrite(dep_G, HIGH);
  Serial.println("Tourne à gauche");
  delay(1000);  // Attendre 1 seconde
}
