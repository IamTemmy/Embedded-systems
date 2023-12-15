#include <WiFi.h>

//this assigns a d name to the WiFi and assigns a password to it
const char *ssid_AP     = "NigerianScammer"; //Enter the router name
const char *password_AP = "123456789"; //Enter the router password

IPAddress local_IP(192,168,1,100);//Set the IP address of ESP32 itself 
IPAddress gateway(192,168,1,10); //Set the gateway of ESP32 itself 
IPAddress subnet(255,255,255,0); //Set the subnet mask for ESP32 itself

void setup(){
  Serial.begin(115200);
  delay(2000);
  Serial.println("Setting soft-AP configuration ... ");
  WiFi.disconnect();
  //sets esp32 in AP mode
  WiFi.mode(WIFI_AP);
  //Configure IP address, gateway and subnet mask for ESP32
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!"); Serial.println("Setting soft-AP ... ");
  //Turn on an AP in ESP32, whose name is set by ssid_AP and password is set by password_AP
  boolean result = WiFi.softAP(ssid_AP, password_AP);
  //Check whether the AP is turned on successfully. If yes, print out IP and MAC address of AP established by ESP32. 
  //If no, print out the failure prompt
  if(result){
    Serial.println("Ready");
    Serial.println(String("Soft-AP IP address = ") + WiFi.softAPIP().toString()); 
    Serial.println(String("MAC address = ") + WiFi.softAPmacAddress().c_str());
  }else{
    Serial.println("Failed!");
  }
  Serial.println("Setup End");
}

void loop() {
}