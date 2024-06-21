
# IoT Lighting Control System with Arduino, ESP8266, and Blynk

## Опис проекту

Цей проект реалізує систему керування освітленням за допомогою Arduino Uno, ESP8266 (ESP-01) та платформи Blynk. Система дозволяє дистанційно вмикати та вимикати світлодіоди через мобільний додаток Blynk, використовуючи Wi-Fi з’єднання.

## Архітектура системи

### Компоненти

1. **Arduino Uno** - мікроконтролер для керування світлодіодами.
2. **ESP-01 (ESP8266)** - Wi-Fi модуль для підключення Arduino до Інтернету.
3. **Blynk** - платформа для створення мобільних додатків для керування IoT пристроями.
4. **Світлодіоди** - вихідні пристрої, які ми будемо керувати.

### Схема підключення

1. Підключіть ESP-01 до Arduino через порти RX і TX.
2. Підключіть світлодіоди до відповідних цифрових виходів Arduino.
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
#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);

void setup()
{
  Serial.begin(9600);
  delay(10);

  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
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
