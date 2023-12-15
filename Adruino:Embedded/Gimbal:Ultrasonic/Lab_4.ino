#include <ESP32Servo.h>

// Ultrasonic Sensor Pins
#define trigPin 27
#define echoPin 26
#define MAX_DISTANCE 700
float timeOut = MAX_DISTANCE * 60;
int soundVelocity = 340;

// Joystick Pins
int xyzPins[] = {13, 12, 14}; // x, y, z pins

// Servo Configuration
Servo servoX, servoY;
int posValX = 90;
int posValY = 90;
int servoPinX = 15;
int servoPinY = 2;

bool joystickControlEnabled = true;
bool sonarEnabled = true; // By default, display sonar readings
bool lastButtonState = false;
float lastDistance = 0.0;

int currentDelayX = 90;
int currentDelayY = 90;

unsigned long previousMillisX = 0;
unsigned long previousMillisY = 0;
const int servoStep = 1; // This is a fixed step for servo movement

void setup() {
  Serial.begin(115200);

  // Pin Configurations
  pinMode(xyzPins[2], INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo Initialization
  servoX.setPeriodHertz(50);
  servoX.attach(servoPinX, 500, 2500);
  servoX.write(posValX);

  servoY.setPeriodHertz(50);
  servoY.attach(servoPinY, 500, 2500);
  servoY.write(posValY);
}

void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);

  // Joystick Button Handling
  if (zVal == LOW && lastButtonState == HIGH) {
    joystickControlEnabled = !joystickControlEnabled;
    lastDistance = getSonar();
    Serial.printf("Distance: %.2f cm\n", lastDistance);
    delay(500); // Debounce delay
  }
  lastButtonState = zVal;

  // Toggle Sonar Display
  if (zVal == LOW && lastButtonState == HIGH) {
    sonarEnabled = !sonarEnabled;
  }

  // Joystick Control
  if (joystickControlEnabled) {
    int adjustedX = xVal - 2047;
    int adjustedY = yVal - 2047;
    currentDelayX = map(abs(adjustedX), 0, 2047, 50, 10);
    currentDelayY = map(abs(adjustedY), 0, 2047, 50, 10);
    unsigned long currentMillis = millis();

    // Handling X servo independently
    handleServo(adjustedX, posValX, servoX, previousMillisX, currentDelayX);

    // Handling Y servo independently
    handleServo(adjustedY, posValY, servoY, previousMillisY, currentDelayY);

    Serial.printf("Adjusted X: %d, ServoX Pos: %d, Adjusted Y: %d, ServoY Pos: %d\n",
                  adjustedX, posValX, adjustedY, posValY);
  }
}

// Function to handle servo movement
void handleServo(int adjustedValue, int &posVal, Servo &servo, unsigned long &previousMillis, int currentDelay) {
  unsigned long currentMillis = millis();

  if ((adjustedValue > 180 || adjustedValue < -180) && currentMillis - previousMillis >= currentDelay) {
    if (adjustedValue > 180) {
      posVal += servoStep;
      if (posVal > 180) posVal = 180;
    } else {
      posVal -= servoStep;
      if (posVal < 0) posVal = 0;
    }
    servo.write(posVal);
    previousMillis = currentMillis;
  }
}

// Function to get sonar distance
float getSonar() {
  unsigned long pingTime;
  float distance;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pingTime = pulseIn(echoPin, HIGH, timeOut);
  distance = (float)pingTime * soundVelocity / 2 / 10000;
  return distance;
}
