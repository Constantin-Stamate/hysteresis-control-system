#pragma once

extern float setPoint;
extern float hysteresis;
extern float temperature;
extern bool heaterState;

void initPins();
void controlLoop();