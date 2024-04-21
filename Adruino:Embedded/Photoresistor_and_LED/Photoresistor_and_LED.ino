//A photoresistor, also known as a light-dependent resistor (LDR) or photoconductive cell, 
//is a passive electronic component that exhibits a change in resistance in response to light intensity. 
//In simpler terms, the more light that shines on a photoresistor, the lower its resistance becomes. 
//Conversely, in darkness, a photoresistor's resistance is very high.

//Photoresistors are typically made from semiconductor materials like cadmium sulfide (CdS) or lead sulfide (PbS). 
//When light strikes the photoresistor, it excites electrons in the material, allowing them to flow more easily. 
//This increased flow of electrons corresponds to a decrease in resistance.

// Define the photoresistor and LED pins
const int photoresistorPin = 4;
const int ledPin = 12;

// Define the threshold variable
float threshold = 70.0f;
//Sets a brightness threshold (initially 50) to control LED behavior.

// Set the LED pin as an output
void setup() {
  pinMode(ledPin, OUTPUT);
  //Configures ledPin as an output pin, enabling LED control.
  Serial.begin(115200);
  //Initializes serial communication for potential user input (threshold adjustment).
}

// Loop forever
void loop() {

  // Read the photoresistor value
  int photoresistorValue = analogRead(photoresistorPin);
  //Reads the analog voltage value from the photoresistor, ranging from 0 (dark) to 4095 (bright).

  // Map the photoresistor value to a value between 0 and 100
  float mappedPhotoresistorValue = map(photoresistorValue, 0, 4095, 0.0f, 100.0f);
  //Rescales the photoresistorValue to a more intuitive percentage-like range (0 to 100), representing brightness levels.

Serial.print("Photoresistor Value (raw): ");
Serial.print(photoresistorValue);
Serial.print(", Mapped Value (%): ");
Serial.println(mappedPhotoresistorValue);

  // Compare the mapped photoresistor value to the threshold value
  if (mappedPhotoresistorValue > threshold) {
    // Turn the LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn the LED off
    digitalWrite(ledPin, LOW);
  }

  // Read the threshold value from the Serial Monitor
  if (Serial.available()) {
  //Checks for available serial input from a user.  
    threshold = Serial.parseFloat();
    //Reads a new threshold value from the serial monitor.
    Serial.println(threshold);
    //Prints the new threshold value to the serial monitor for confirmation.
  }

  // Delay for 100 milliseconds
  delay(100);
}