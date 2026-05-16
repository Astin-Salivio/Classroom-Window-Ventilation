#include "ManualButton.h"

ManualButton::ManualButton(int buttonPin) {

  pin = buttonPin;
}

void ManualButton::begin() {

  pinMode(pin, INPUT_PULLUP);
}

bool ManualButton::isPressed() {

  return digitalRead(pin) == LOW;
}