#ifndef RAINSENSOR_H
#define RAINESENSOR_H

#include <Arduino.h>

class RainSensor {

  private:
    int pin;
    int threshold;

  public:
    RainSensor(int sensorPin, int rainThreshold);

    void begin();

    bool isRaining();
};

#endif