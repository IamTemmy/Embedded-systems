//same with the first program but a different format

int xPin = 13;
int yPin = 12;
int buttonPin = 14;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);
  int buttonVal = digitalRead(buttonPin);

  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.print(yVal);
  Serial.print(" | Button: ");
  Serial.println(buttonVal);

  delay(500);
}
