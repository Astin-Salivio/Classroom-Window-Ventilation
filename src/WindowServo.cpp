#include "WindowServo.h"

WindowServo::WindowServo(int servoPin) {

  pin = servoPin;
}

void WindowServo::begin() {

  servo.attach(pin);

  servo.write(0);
}

void WindowServo::closeWindow() {

  servo.write(0);

  Serial.println("WINDOW CLOSED");
}

void WindowServo::halfOpenWindow() {

  servo.write(90);

  Serial.println("WINDOW HALF OPEN");
}

void WindowServo::fullyOpenWindow() {

  servo.write(180);

  Serial.println("WINDOW FULLY OPEN");
}