#define PIN_ANALOG_IN   4
void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcValue = analogRead(PIN_ANALOG_IN);                       //read ADC pin
  double voltage = (float)adcValue / 4095.0 * 3.3;                // calculate voltage
  double Rt = 10000 * voltage / (3.3 - voltage);                     //calculate resistance value of thermistor
  double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10000) / 3950.0); //calculate temperature (Kelvin)
  double tempC = tempK - 273.15;                                  //calculate temperature (Celsius)
  double tempF = (tempC * 9/5) + 32;                              //calculate temperature (Fahrenheit)
  Serial.printf("ADC value : %d,\tVoltage : %.2fV, \tTemperature(Celcius) : %.2fC, \tTemperature(Fahrenheit) : %.2fF\n", adcValue, voltage, tempC, tempF);
  delay(1000);
}
