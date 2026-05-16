#ifndef DHTHANDLER_H
#define DHTHANDLER_H

#include <Arduino.h>
#include <DHT.h>

class DHTHandler {

  private:
    DHT dht;

  public:
    DHTHandler(uint8_t pin, uint8_t type);

    void begin();

    float getTemperature();

    float getHumidity();
};

#endif