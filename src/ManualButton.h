
#ifndef MANUALBUTTON_H
#define MANUALBUTTON_H

#include <Arduino.h>

class ManualButton {

  private:
    int pin;

  public:
    ManualButton(int buttonPin);

    void begin();

    bool isPressed();
};

#endif