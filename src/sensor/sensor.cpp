#include <Arduino.h>
#include "sensor.h"

#define SENSOR_PIN A0

float temperature = 0.0;

void sensorInit() {
    pinMode(SENSOR_PIN, INPUT);
}

void readTemperature() {
    int val = analogRead(SENSOR_PIN);

    temperature = map(val, 0, 1023, 0, 100);
}