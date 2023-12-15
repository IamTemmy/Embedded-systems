// In this program, I have written this code to control the output of four LEDs.
// Each LED produces a HIGH output, that is it stays on and goes off at different time intervals for each respective LED

// The first LED is identified as LED_1 and is assigned the GPIO 2 port
#define PIN_LED1 2
// The second LED is identified as LED_2 and is assigned the GPIO 13 port
#define PIN_LED2 13
// The third LED is identified as LED_3 and is assigned the GPIO 12 port
#define PIN_LED3 12
// The fourth LED is identified as LED_4 and is assigned the GPIO 4 port
#define PIN_LED4 4

// Define the GPIO pin for the button
#define PIN_BUTTON 25

bool loopActive = false; // Variable to control the loop

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
  if (loopActive) {
    // Execute the loop only when loopActive is true
    digitalWrite(PIN_LED1, HIGH);
    delay(300);
    digitalWrite(PIN_LED1, LOW);
    delay(10);

    digitalWrite(PIN_LED2, HIGH);
    delay(300);
    digitalWrite(PIN_LED2, LOW);
    delay(20);

    digitalWrite(PIN_LED3, HIGH);
    delay(300);
    digitalWrite(PIN_LED3, LOW);
    delay(30);

    digitalWrite(PIN_LED4, HIGH);
    delay(300);
    digitalWrite(PIN_LED4, LOW);
    delay(40);
  }

  // Read the button state
  if (digitalRead(PIN_BUTTON) == LOW) {
    delay(20);
    if (digitalRead(PIN_BUTTON) == LOW) {
      loopActive = !loopActive; // Toggle loop state
    }
    while (digitalRead(PIN_BUTTON) == LOW);
    delay(20);
    while (digitalRead(PIN_BUTTON) == LOW);
  }
}
