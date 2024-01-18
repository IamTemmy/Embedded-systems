//This code continuously reads an analog voltage from pin 2, maps it to a digital value suitable for a DAC, and outputs the corresponding voltage using the DAC.
//It also prints the ADC value, DAC value, and calculated voltage to the serial monitor for observation and debugging.

#define PIN_ANALOG_IN  2

void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);
  //Reads the analog voltage value from the specified pin (pin 2) and stores it in the adcVal variable. The value will be between 0 and 4095, representing a 10-bit analog-to-digital conversion.
  int dacVal = map(adcVal, 0, 4095, 0, 255);
  //Maps the adcVal (0-4095) to a range of 0-255, suitable for output to a digital-to-analog converter (DAC). This creates a corresponding digital value for the analog input.
  double voltage = adcVal / 4095.0 * 3.3;
  //Calculates the actual voltage represented by the adcVal, assuming a reference voltage of 3.3 volts. This converts the raw ADC value to a meaningful voltage measurement.
  dacWrite(DAC1, dacVal);
  //Writes the mapped dacVal (0-255) to a DAC output, likely labeled as DAC1 on the microcontroller. This sends the digital representation of the analog input to the DAC to produce an analog output voltage.
  Serial.printf("ADC Val: %d, \t DAC Val: %d, \t Voltage: %.2fV\n", adcVal, dacVal, voltage);
  //Prints formatted output to the serial monitor, displaying the raw ADC value, mapped DAC value, and calculated voltage for each cycle of the loop.
  delay(200);
}
