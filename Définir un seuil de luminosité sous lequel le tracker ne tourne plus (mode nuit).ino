int luminosityThreshold = 800;  // Seuil de luminosité pour déterminer la nuit

bool isNight() {
  // Vérifier si les deux valeurs des photorésistances sont en dessous du seuil
  return (iPhotoValue1 < luminosityThreshold && iPhotoValue2 < luminosityThreshold);
}

void loop() {
  iPhotoValue1 = analogRead(myPinD);
  iPhotoValue2 = analogRead(myPinG);
  hallState = digitalRead(hallPin);  // Lire l'état du capteur Hall

  if (isNight()) {
    // Si c'est la nuit, arrêter le moteur
    digitalWrite(dep_D, LOW);
    digitalWrite(dep_G, LOW);
    Serial.println("Nuit : Moteur arrêté");
  } 
  else if (hallState == HIGH) {
    // Si le capteur à effet Hall détecte un champ magnétique, arrêter le moteur
    digitalWrite(dep_D, LOW);
    digitalWrite(dep_G, LOW);
    Serial.println("Limite atteinte, moteur arrêté");
  }
  else {
    diff = iPhotoValue1 - iPhotoValue2;
    if (diff > val_dep + tampon) {
      digitalWrite(dep_D, HIGH);  //
