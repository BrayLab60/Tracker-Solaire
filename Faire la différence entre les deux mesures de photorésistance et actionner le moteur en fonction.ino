int val_dep = 80;  // Valeur de seuil pour déterminer si la différence est significative
int diff = 0;  // Variable pour stocker la différence de luminosité

void loop() {
  iPhotoValue1 = analogRead(myPinD);
  iPhotoValue2 = analogRead(myPinG);

  diff = iPhotoValue1 - iPhotoValue2;  // Calcul de la différence entre les deux photorésistances

  if (diff > val_dep) {
    digitalWrite(dep_D, HIGH);  // Tourner à droite
    digitalWrite(dep_G, LOW);
    Serial.println("Tourne à droite");
  }
  else if (diff < -val_dep) {
    digitalWrite(dep_G, HIGH);  // Tourner à gauche
    digitalWrite(dep_D, LOW);
    Serial.println("Tourne à gauche");
  }
  else {
    digitalWrite(dep_D, LOW);  // Arrêter le moteur
    digitalWrite(dep_G, LOW);
    Serial.println("Arrêt");
  }

  delay(100);  // Pause pour éviter un bouclage trop rapide
}
