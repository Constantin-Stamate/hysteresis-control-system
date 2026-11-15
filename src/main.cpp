#include <Arduino.h>
#include "sensor/sensor.h"
#include "control/control.h"
#include "ui_lcd/ui_lcd.h"
#include "buttons/buttons.h"

unsigned long lastTempRead = 0;
unsigned long lastLcdUpdate = 0;
unsigned long lastSerial = 0;

void setup() {
    initPins();
    lcdInit();
    sensorInit();
    buttonsInit();

    Serial.begin(9600);

    lcdWelcome();
}

void loop() {
    unsigned long now = millis();

    handleButtons(now);

    if (now - lastTempRead >= 100) {
        lastTempRead = now;

        readTemperature();
        controlLoop();
    }

    if (now - lastLcdUpdate >= 150) {
        lastLcdUpdate = now;

        lcdUpdate(temperature, setPoint);
    }

    if (now - lastSerial >= 500) {
        lastSerial = now;

        Serial.print("Temperature:");
        Serial.print(temperature);
        Serial.print(", SetPoint:");
        Serial.println(setPoint);
    }
}