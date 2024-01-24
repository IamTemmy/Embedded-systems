//The code continuously reads analog values from X and Y pins on the joystick
//It also reads the digital value of the Z pin, representing a button press or release.
//The measured values are printed to the serial monitor for observation or further processing.

int xyzPins[] = {13, 12, 14};   //x,y,z pins

void setup() {
  Serial.begin(115200);
  pinMode(xyzPins[2], INPUT_PULLUP);  //z axis is a button.
//pinMode(xyzPins[2], INPUT_PULLUP); sets pin 14 (the Z-axis pin) as an input with internal pull-up resistor, making it suitable for button input.
}

void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.printf("X,Y,Z: %d,\t%d,\t%d\n", xVal, yVal, zVal);
  delay(500);
}
