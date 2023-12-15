
//Filename    : FlowingLight
//Description : Using ledbar to demonstrate flowing lamp.

byte ledPins[] = {15, 2, 0, 4, 5, 18, 19, 21, 22, 23};
//the array in this code is used to easily define the 10 GPIO ports conneccted to the LED Bar
int ledCounts;

//In setup(), use sizeof() to get the number of arrau, which is the number of LEDs,
//then configure the GPIO port to output mode
void setup() {
  ledCounts = sizeof(ledPins);
  for (int i = 0; i < ledCounts; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

//Then, in loop(), use two "for" loop to realize flowing water light from left to right 
//and from right to left
void loop() {
  for (int i = 0; i < ledCounts; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = ledCounts - 1; i > -1; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}
