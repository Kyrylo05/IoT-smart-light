
# IoT Lighting Control System with Arduino, ESP8266, and Blynk

## Опис проекту

Цей проект реалізує систему керування освітленням за допомогою Arduino Uno, ESP8266 (ESP-01) та платформи Blynk. Система дозволяє дистанційно вмикати та вимикати світлодіоди через мобільний додаток Blynk, використовуючи Wi-Fi з’єднання.

## Архітектура системи

### Компоненти

1. **Arduino Uno** - мікроконтролер для керування світлодіодами.
2. **ESP-01 (ESP8266)** - Wi-Fi модуль для підключення Arduino до Інтернету.
3. **Blynk** - платформа для створення мобільних додатків для керування IoT пристроями.
4. **Світлодіоди** - вихідні пристрої, які ми будемо керувати.
5. **Резистори 220 Ом** - для обмеження струму через світлодіоди.

### Схема підключення

1. Підключіть ESP-01 до Arduino через порти RX і TX.
2. Підключіть світлодіоди до відповідних цифрових виходів Arduino через резистори на 220 Ом.
3. Підключіть живлення до всіх компонентів.

## Налаштування середовища

### 1. Налаштування Arduino IDE

1. Встановіть [Arduino IDE](https://www.arduino.cc/en/software).
2. Додайте ESP8266 до менеджера плат:
   - Відкрийте `Файл -> Налаштування`.
   - В полі `Additional Board Manager URLs` додайте: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`.
   - Перейдіть до `Інструменти -> Board -> Board Manager` і встановіть `esp8266`.

### 2. Встановлення бібліотек

Встановіть наступні бібліотеки через Arduino Library Manager:
- **Blynk**: `Sketch -> Include Library -> Manage Libraries -> Blynk`
- **ESP8266**: `Sketch -> Include Library -> Manage Libraries -> esp8266`

### 3. Завантаження коду на Arduino

1. Підключіть Arduino до комп’ютера через USB.
2. Завантажте код з цього репозиторію на Arduino.

### Код

```cpp
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
```

### 4. Налаштування Blynk

1. Завантажте додаток Blynk з [App Store](https://apps.apple.com) або [Google Play](https://play.google.com).
2. Створіть новий проект та отримайте AUTH TOKEN.
3. Додайте віджети для керування світлодіодами (наприклад, кнопки).

## Пояснення роботи системи

1. **Arduino Uno**: контролює світлодіоди, отримуючи команди від ESP-01 через послідовний інтерфейс.
2. **ESP-01**: підключається до Wi-Fi і обробляє команди з Blynk сервера.
3. **Blynk**: надає інтерфейс для користувача у вигляді мобільного додатка, що дозволяє керувати освітленням через інтернет.

## Висновок

Ця система надає зручний спосіб керування освітленням за допомогою IoT технологій. Завдяки використанню Arduino, ESP8266 та платформи Blynk, можна легко створити систему, яка дозволяє керувати освітленням через Інтернет з будь-якої точки світу.
