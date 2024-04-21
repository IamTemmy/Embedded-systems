//Touch Reading: The code's primary purpose is to read touch sensor values using the touchRead(T0) function and display them on the serial monitor.
void setup()
{
  Serial.begin(115200);
  //Initializes serial communication with a baud rate of 115200. This enables the Arduino to send data to the serial monitor
}

void loop()
{
  Serial.printf("Touch value: %d \n",touchRead(T0));  // get value using T0（GPIO4）
  //touchRead(T0): Reads the touch sensor value connected to GPIO4 (designated as T0). This function is specific to ESP32 boards and returns a value between 0 (no touch) and 4095 (strong touch)
  //Serial.printf("Touch value: %d \n", touchValue): Prints the touch value to the serial monitor, followed by a newline character for readability.
  delay(1000);
}
