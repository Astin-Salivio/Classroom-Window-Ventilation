#include "FanController.h"

FanController::FanController(int relayPin) {

  pin = relayPin;

  fanState = false;
}

void FanController::begin() {

  pinMode(pin, OUTPUT);

  digitalWrite(pin, LOW);
}

void FanController::turnOn() {

  digitalWrite(pin, HIGH);

  fanState = true;

  Serial.println("FAN ON");
}

void FanController::turnOff() {

  digitalWrite(pin, LOW);

  fanState = false;

  Serial.println("FAN OFF");
}

void FanController::toggle() {

  fanState = !fanState;

  digitalWrite(pin, fanState);
}

bool FanController::getState() {

  return fanState;
}