// In this program, I have written this code to control the output of four LEDs. Each LED produces a HIGH output, 
// that is it stays on and goes off at different time intervals for each respective LED

//The first LED is indentified as LED_1 and is assigned the GPIO 2 port
#define PIN_LED1 2
//The second LED is indentified as LED_2 and is assigned the GPIO 13 port
#define PIN_LED2 13
//The third LED is indentified as LED_3 and is assigned the GPIO 12 port
#define PIN_LED3 12
//The fourth LED is indentified as LED_4 and is assigned the GPIO 4 port
#define PIN_LED4 4

//The setup function runs once when you press reset or power the board 
void setup() {
  //Initialize each digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  //The pinMode function configures the specified pin to behave either as an input or an output
}

//The loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_LED1, 1);  //turns LED1 on (HIGH is the voltage level)
  delay(300);  //stays on for 0.3secs
  digitalWrite(PIN_LED1, 0);  //turns LED1 off (LOW is the voltage level)
  delay(10);  //stays off for 0.01secs           

  digitalWrite(PIN_LED2, HIGH);  //turns LED2 on (HIGH is the voltage level)
  delay(300);  //stays on for 0.3secs
  digitalWrite(PIN_LED2, LOW);  //turns LED2 off (LOW is the voltage level)
  delay(20);  //stays off for 0.02secs

  digitalWrite(PIN_LED3, HIGH);  //turns LED3 on (HIGH is the voltage level)
  delay(300);  //stays on for 0.3secs
  digitalWrite(PIN_LED3, LOW);  //turns LED3 off (LOW is the voltage level)
  delay(30);  //stays off for 0.03secs

  digitalWrite(PIN_LED4, HIGH);  //turns LED4 on (HIGH is the voltage level)
  delay(300);  //stays on for 0.3secs
  digitalWrite(PIN_LED4, LOW);  //turns LED4 off (LOW is the voltage level)
  delay(40);  //stays off for 0.04secs

}

//The digitalWrite function writes the value HIGH or LOW (1 or 0) to the given pin
//Writing 1 or HIGH, or, 0 or LOW, can be used interchangeablly in the code

//The delay() function is used to make control board wait for a moment before executing the next statement
//The parameter indicates the number of milliseconds to wait for



