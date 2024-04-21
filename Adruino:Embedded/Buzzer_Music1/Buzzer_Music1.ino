int buzzerPin = 13; // Pin connected to the buzzer

int melody[] = {
  262, 196, 196, 220, 196, 0, 247, 262, // C4, G3, G3, A3, G3, rest, B3, C4
  294, 330, 349, 392, 392, 392, 330, 294, // D4, E4, F4, G4, G4, G4, E4, D4
  262, 262, 294, 330, 349, 392, 392, 392, // C4, C4, D4, E4, F4, G4, G4, G4
  330, 294, 262, 392, 392, 349, 330, 294, // E4, D4, C4, G4, G4, F4, E4, D4
  262, 262, 196, 196, 220, 196, 0, 247, // C4, C4, G3, G3, A3, G3, rest, B3
  262, 330, 349, 392, 392, 330, 294, 247, // C4, E4, F4, G4, G4, E4, D4, B3
  262 // C4 (final note)
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4,
  4, 8, 8, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 8, 8, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 8, 8, 4, 4, 4, 4, 4,
  2 // Final note (held longer)
};

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 1000 / noteDurations[i]; // Calculate note duration in milliseconds
    tone(buzzerPin, melody[i], noteDuration);

    // Delay between notes for a slight pause
    int pauseBetweenNotes = noteDuration * 1.30; // Adjust for desired tempo
    delay(pauseBetweenNotes);
    noTone(buzzerPin); // Stop the tone before the next note
  }
}
