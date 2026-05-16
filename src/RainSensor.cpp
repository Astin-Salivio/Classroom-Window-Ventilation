#include "RainSensor.h"

RainSensor::RainSensor(int sensorPin, int rainThreshold) {

  pin = sensorPin;
  threshold = rainThreshold;
}

void RainSensor::begin() {

  pinMode(pin, INPUT);
}

bool RainSensor::isRaining() {

  int sensorValue = analogRead(pin);

  Serial.print("Rain Sensor Value: ");
  Serial.println(sensorValue);

  return sensorValue < threshold;
}