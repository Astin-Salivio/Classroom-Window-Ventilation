#ifndef FANCONTROLLER_H
#define FANCONTROLLER_H

#include <Arduino.h>

class FanController {

  private:
    int pin;
    bool fanState;

  public:
    FanController(int relayPin);

    void begin();

    void turnOn();

    void turnOff();

    void toggle();

    bool getState();
};

#endif