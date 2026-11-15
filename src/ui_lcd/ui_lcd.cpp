#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "ui_lcd.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcdInit() {
    lcd.init();
    lcd.backlight();
}

void lcdWelcome() {
    lcd.setCursor(0, 0);
    lcd.print("Control Temp");

    delay(1000);

    lcd.clear();
}

void lcdUpdate(float temperature, float setPoint) {
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperature, 1);
    lcd.print("C   ");

    lcd.setCursor(0, 1);
    lcd.print("SP:");
    lcd.print(setPoint, 1);
    lcd.print("C   ");
}