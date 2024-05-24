#ifndef ULTRASOUND_H
#define ULTRASOUND_H
#endif
#define LTrigPin 25
#define LEchoPin 26
#define RTrigPin 27
#define REchoPin 14
#define FTrigPin 12
#define FEchoPin 13
#include <Arduino.h>
#include "timer.h"
#include <esp_task_wdt.h>
#include "soc/rtc_wdt.h"
class UltrasonicSensor {
    private:
    const int trigPin;
    const int echoPin;
    enum { S_LOW, S_HIGH, S_MEASURE } state;
    unsigned long lastMicros;
    float distance;
public:
    UltrasonicSensor(int trigPin, int echoPin) : trigPin(trigPin), echoPin(echoPin), state(S_LOW), lastMicros(0), distance(0.0) {}

    void update() {
        unsigned long now = micros();
        switch (state) {
            case S_LOW:
                if (now - lastMicros >= 2) {
                    digitalWrite(trigPin, HIGH);
                    state = S_HIGH;
                    lastMicros = now;
                }
                break;
            case S_HIGH:
                if (now - lastMicros >= 10) {
                    digitalWrite(trigPin, LOW);
                    state = S_MEASURE;
                }
                break;
            case S_MEASURE:
                distance = pulseIn(echoPin, HIGH, 26000) * 0.034 / 2;
                state = S_LOW;
                break;
        }
    }

    float getDistance() const {
        return distance;
    }


};
void initUltrasound();
float getDistance(int trigPin,int echoPin);
