#include <Arduino.h>
#include "buttons.h"
#include "control/control.h"

#define BTN_UP 2
#define BTN_DOWN 3

static unsigned long lastBtnCheck = 0;

void buttonsInit() {
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
}

void handleButtons(unsigned long now) {
    if (now - lastBtnCheck < 50) {
        return;
    }

    lastBtnCheck = now;

    if (digitalRead(BTN_UP) == LOW) {
        setPoint += 0.2;
    }

    if (digitalRead(BTN_DOWN) == LOW) {
        setPoint -= 0.2;
    }
}