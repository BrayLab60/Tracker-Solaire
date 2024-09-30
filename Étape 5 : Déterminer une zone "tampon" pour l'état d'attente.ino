int val_dep = 80;  // Seuil pour la différence entre les photorésistances
int tampon = 20;  // Zone neutre où le moteur ne bouge pas

void loop() {
  iPhotoValue1 = analogRead(myPinD);
  iPhotoValue2 = analogRead(myPinG);

  diff = iPhotoValue1 - iPhotoValue2;

  if (diff > val_dep + tampon) {
    digitalWrite(dep_D, HIGH);  // Tourner à droite
    digitalWrite(dep_G, LOW);
    Serial.println("Tourne à droite");
  }
  else if (diff < -(val_dep + tampon)) {
    digitalWrite(dep_G, HIGH);  // Tourner à gauche
    digitalWrite(dep_D, LOW);
    Serial.println("Tourne à gauche");
  }
  else {
    digitalWrite(dep_D, LOW);  // Arrêter le moteur
    digitalWrite(dep_G, LOW);
    Serial.println("Arrêt");
  }

  delay(100);
}

