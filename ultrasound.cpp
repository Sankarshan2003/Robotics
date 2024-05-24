#include "ultrasound.h"


int flag=0;
void initUltrasound() {
    pinMode(LTrigPin, OUTPUT);
    pinMode(LEchoPin, INPUT);
    pinMode(RTrigPin, OUTPUT);
    pinMode(REchoPin, INPUT);
    pinMode(FTrigPin, OUTPUT);
    pinMode(FEchoPin, INPUT);
}
float  getDistance( int trigPin, int echoPin) {
  
    static float distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    distance = pulseIn(echoPin, HIGH,26000) * 0.034 / 2;
    return distance;
}
