//In this program, the LEDs will loop on and off when the button is pressed, 
//and they will stop when the button is pressed again

// The first LED is identified as LED_1 and is assigned the GPIO 2 port
#define PIN_LED1 2
// The second LED is identified as LED_2 and is assigned the GPIO 13 port
#define PIN_LED2 13
// The third LED is identified as LED_3 and is assigned the GPIO 12 port
#define PIN_LED3 12
// The fourth LED is identified as LED_4 and is assigned the GPIO 4 port
#define PIN_LED4 4
// This represents the button and is assigned the GPIO 25 port
#define PIN_BUTTON 25

//A boolean variable loopActive is introduced to control whether the loop that controls the LEDs is active
bool loopActive = false; // Variable to control the loop
//If loopActive is true, the LED control code executes, and the LEDs loop on and off as before

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
  //Inside the loop() function, a check is made using if (loopActive) to determine 
  //whether the LEDs should be controlled
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

//the loopActive variable is toggled when the button is pressed and released

//This project was stressful trying to understand the mechanics of the button
//The button does not respond quick enough to turn of the loop due to the mechanical vibrations (bounce)



