void loop() {
  iPhotoValue1 = analogRead(myPinD);
  iPhotoValue2 = analogRead(myPinG);
  hallState = digitalRead(hallPin);  // Lire l'état du capteur Hall

  if (hallState == HIGH) {
    // Si le capteur à effet Hall détecte un champ magnétique, arrêter le moteur
    digitalWrite(dep_D, LOW);
    digitalWrite(dep_G, LOW);
    Serial.println("Limite atteinte, moteur arrêté");
  }
  else {
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
  }

  delay(100);
}
