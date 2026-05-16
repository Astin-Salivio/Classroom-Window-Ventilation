#include <Arduino.h>

#include "RainSensor.h"
#include "DHTHandler.h"
#include "WindowServo.h"
#include "LCDDisplay.h"

// ==========================================================
// PIN CONFIGURATION
// ==========================================================
#define DHT_PIN            4
#define DHT_TYPE           DHT22

#define WATER_SENSOR_PIN   34
#define SERVO_PIN          18

// ==========================================================
// TEMPERATURE THRESHOLDS
// ==========================================================
#define MEDIUM_TEMP        30
#define HIGH_TEMP          35
#define FAN_PIN            26
#define WINDOW_BUTTON_PIN  14
#define FAN_BUTTON_PIN     27

// ==========================================================
// OBJECTS
// ==========================================================
RainSensor rainSensor(WATER_SENSOR_PIN, 2000);
DHTHandler dhtSensor(DHT_PIN, DHT_TYPE);
WindowServo classroomWindow(SERVO_PIN);
LCDDisplay lcdDisplay(LCDPIN);
FanController fan(FAN_PIN);
ManualButton windowButton(WINDOW_BUTTON_PIN);
ManualButton fanButton(FAN_BUTTON_PIN);

// ==========================================================
// SETUP
// ==========================================================
void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("==================================");
  Serial.println("SMART CLASSROOM SYSTEM STARTING");
  Serial.println("==================================");

  rainSensor.begin();

  dhtSensor.begin();

  classroomWindow.begin();

  lcdDisplay.begin();

  fan.begin();

  windowButton.begin();

  fanButton.begin();

  bool manualWindowState = false;
}

// ==========================================================
// LOOP
// ==========================================================
void loop() {

  bool raining = rainSensor.isRaining();

  float temperature = dhtSensor.getTemperature();

  float humidity = dhtSensor.getHumidity();

  Serial.println("----------------------------------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // ==========================================
  // RAIN PRIORITY
  // ==========================================
  if (raining) {

    Serial.println("RAIN DETECTED!");

    classroomWindow.closeWindow();
  }

  // ==========================================
  // TEMPERATURE CONTROL
  // ==========================================
  else {

    if (temperature >= HIGH_TEMP) {

      Serial.println("HIGH TEMPERATURE DETECTED");

      classroomWindow.fullyOpenWindow();
    }

    else if (temperature >= MEDIUM_TEMP) {

      Serial.println("MEDIUM TEMPERATURE DETECTED");

      classroomWindow.halfOpenWindow();
    }

    else {

      Serial.println("NORMAL TEMPERATURE");

      classroomWindow.closeWindow();
    }

    if (temperature >= HIGH_TEMP) {

  classroomWindow.fullyOpenWindow();

  fan.turnOn();
}
else {

  fan.turnOff();
}
  }

  if (windowButton.isPressed()) {

  manualWindowState = !manualWindowState;

  if (manualWindowState) {

    classroomWindow.fullyOpenWindow();
  }

  else {

    classroomWindow.closeWindow();
  }

  delay(300);
}

if (fanButton.isPressed()) {

  fan.toggle();

  delay(300);
}

  Serial.println("----------------------------------");

  delay(2000);
}