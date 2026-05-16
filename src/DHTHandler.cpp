#include "DHTHandler.h"

DHTHandler::DHTHandler(uint8_t pin, uint8_t type)
  : dht(pin, type) {}

void DHTHandler::begin() {

  dht.begin();
}

float DHTHandler::getTemperature() {

  float temp = dht.readTemperature();

  if (isnan(temp)) {

    Serial.println("DHT22 Temperature Read Failed!");
    return -1;
  }

  return temp;
}

float DHTHandler::getHumidity() {

  float hum = dht.readHumidity();

  if (isnan(hum)) {

    Serial.println("DHT22 Humidity Read Failed!");
    return -1;
  }

  return hum;
}