//Pin setup: Assigns pins for joystick axes and buzzer.
//Optional serial communication: Enabled for debugging and monitoring.
//Frequency calculation: Determines the frequency based on joystick position (modify the logic as desired).
//Sound generation: Uses tone() function to produce sound at the calculated frequency.
//Delay: Added for smoother response and potential sound effects.

int xPin = 12; // Pin connected to X axis of joystick
int yPin = 14; // Pin connected to Y axis of joystick
int buzzerPin = 13; // Pin connected to the buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Optional for serial communication
}

void loop() {
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  // Calculate frequency based on joystick position (adjust logic as needed)
  int finalFrequency = map(xVal, 0, 4095, 100, 4000); // Example: Map X-axis to frequency

  // Generate sound using the calculated frequency
  tone(buzzerPin, finalFrequency);

  // Optional: Print values to serial monitor for debugging
  Serial.print("X-axis: ");
  Serial.print(xVal);
  Serial.print(", Y-axis: ");
  Serial.print(yVal);
  Serial.print(", Frequency: ");
  Serial.println(finalFrequency);

  // Delay for smoother response and sound effects
  delay(10);
}
