#define BLYNK_TEMPLATE_ID "TMPL4T_ONkGz2"
#define BLYNK_TEMPLATE_NAME "IOT HOME Lights"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

SoftwareSerial EspSerial(2, 3); // RX, TX

#define ESP8266_BAUD 38400
ESP8266 wifi(&EspSerial);

// LED pin definitions
const int redPin = 8;
const int yellowPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup()
{
  // Debug console
  Serial.begin(115200);
  delay(1000);  // Додатковий час для стабілізації

  Serial.println("Setting up ESP8266...");
  
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(1000);  // Додатковий час для стабілізації

  Serial.println("Initializing Blynk...");
  
  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);

  Serial.println("Blynk initialized");

  // Set LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  Blynk.run();
}
