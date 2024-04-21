//The code controls two LEDs independently using a joystick's X and Y axes.
//The brightness of each LED corresponds to the position of the joystick in its respective axis.
//Moving the joystick horizontally (X-axis) changes the brightness of the first LED.
//Moving the joystick vertically (Y-axis) changes the brightness of the second LED.

int xPin = 12; // Pin connected to X axis of joystick
int yPin = 14; // Pin connected to X axis of joystick
int ledPin1 = 2; // Pin connected to the LED1 (anode)
int ledPin2 = 13; // Pin connected to the LED2 (anode)

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(115200); // Initialize serial communication

  // Set initial brightness to 0
  analogWrite(ledPin1, 0);
  analogWrite(ledPin2, 0);
}

void loop() {
  // Read analog value from X axis
  int xVal = analogRead(xPin);
  // Read analog value from Y axis
  int yVal = analogRead(yPin);

  // Print analog values to serial monitor
  Serial.print("X-axis: ");
  Serial.print(xVal);
  Serial.print(", Y-axis: ");
  Serial.println(yVal);

  // Map analog values to brightness (adjusted for desired control)
  int brightness1 = map(xVal, 0, 4095, 0, 255); // Map X-axis to reverse brightness
  int brightness2 = map(yVal, 0, 4095, 0, 255); // Map Y-axis to increasing brightness

  // Set LED brightness
  analogWrite(ledPin1, brightness1);
  analogWrite(ledPin2, brightness2);

  // Delay for smoother response
  delay(10);
}

//The serial monitor shows the printed analog values for both axis
//So you can see while testing, when X is 0, LED1 is off and when it reaches max at 4095, the LED is at its brightest
//Also you can see while testing, when Y is 0, LED2 is off and when it reaches max at 4095, the LED is at its brightest