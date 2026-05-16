#include "LCDDisplay.h"

LCDDisplay::LCDDisplay()
  : lcd(0x27, 16, 2) {}

void LCDDisplay::begin() {

  lcd.init();

  lcd.backlight();

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("SMART CLASSROOM");

  delay(2000);

  lcd.clear();
}

void LCDDisplay::showTemperature(float temp) {

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temp: ");

  lcd.print(temp);

  lcd.print(" C");
}

void LCDDisplay::showRain() {

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("RAIN DETECTED");

  lcd.setCursor(0,1);
  lcd.print("WINDOW CLOSED");
}

void LCDDisplay::showWindowStatus(String status) {

  lcd.setCursor(0,1);

  lcd.print("Window: ");

  lcd.print(status);
}