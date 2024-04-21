/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL2gx6s-R3Z"
#define BLYNK_TEMPLATE_NAME "LED Control Switch"
#define BLYNK_AUTH_TOKEN "aUzqXk2t1WU_fk6_BArt9_xnsQYYgzYm"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials. Set password to "" for open networks.
char ssid[] = "Kamal's iPhone";
char pass[] = "mimi&lulu";

// Define the LED pin
int ledPin1 = 12;
int ledPin2 = 13;
int ledPin3 = 2;
int ledPin4 = 4;

void setup() {
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Setup virtual pin for brightness control
  Blynk.virtualWrite(V0, 225); // Default brightness
  
  // Initialize LED pin as output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  Blynk.run();
}

// Define a function to handle brightness changes
BLYNK_WRITE(V0) {
  int brightness = param.asInt();
  // Map the brightness value from the slider (0-255) to the LED brightness (0-255)
  int mappedBrightness = map(brightness, 0, 4095, 0, 225);
  //analogWrite(ledPin, mappedBrightness); // Set LED brightness
  analogWrite(ledPin1, mappedBrightness); // Set LED brightness
  analogWrite(ledPin2, mappedBrightness); // Set LED brightness
  analogWrite(ledPin3, mappedBrightness); // Set LED brightness
  analogWrite(ledPin4, mappedBrightness); // Set LED brightness
}
