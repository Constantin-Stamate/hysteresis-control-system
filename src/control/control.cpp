#include <Arduino.h>
#include "control.h"

#define RELAY_PIN 8
#define LED_PIN 9

float setPoint = 30.0;
float hysteresis = 1.0;
bool heaterState = false;

void initPins() {
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
}

void controlLoop() {
    if (!heaterState && temperature < setPoint - hysteresis) {
        heaterState = true;

        digitalWrite(RELAY_PIN, HIGH);
        digitalWrite(LED_PIN, HIGH);
    } else if (heaterState && temperature > setPoint + hysteresis) {
        heaterState = false;

        digitalWrite(RELAY_PIN, LOW);
        digitalWrite(LED_PIN, LOW);
    }
}