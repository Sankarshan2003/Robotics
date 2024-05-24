#ifndef TIMER_H
#define TIMER_H
#endif
#include <Arduino.h>
void initTimer();
void timDelay(int ms,void (* callback)(),int timer_num,bool periodic);
void timDelayMicroseconds(int us,void (* callback)(),int timer_num,bool periodic);
