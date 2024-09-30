int iPhotoValue1 = 0;  // Variable pour stocker la valeur de la photorésistance 1
int iPhotoValue2 = 0;  // Variable pour stocker la valeur de la photorésistance 2

int myPinD = A1;  // Broche analogique pour la photorésistance 1
int myPinG = A3;  // Broche analogique pour la photorésistance 2

void setup() {
  Serial.begin(9600);  // Initialise la communication série pour afficher les valeurs
}

void loop() {
  iPhotoValue1 = analogRead(myPinD);  // Lire la valeur de la photorésistance 1
  iPhotoValue2 = analogRead(myPinG);  // Lire la valeur de la photorésistance 2

  // Afficher les valeurs des photorésistances dans le moniteur série
  Serial.print("Valeur photorésistance D: ");
  Serial.println(iPhotoValue1);
  Serial.print("Valeur photorésistance G: ");
  Serial.println(iPhotoValue2);

  delay(500);  // Pause de 500ms avant la prochaine lecture
}
