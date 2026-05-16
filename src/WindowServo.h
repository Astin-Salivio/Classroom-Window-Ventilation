#ifndef WINDOWSERVO_H
#define WINDOWSERVO_H

#include <Arduino.h>
#include <ESP32Servo.h>

class WindowServo {

  private:
    Servo servo;
    int pin;

  public:
    WindowServo(int servoPin);

    void begin();

    void closeWindow();

    void halfOpenWindow();

    void fullyOpenWindow();
};

#endif