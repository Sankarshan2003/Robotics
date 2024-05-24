#include "timer.h"
void timDelay(int ms,void (* callback)(),int timer_num,bool periodic) {
    if(timer_num>3){
        return;
    }
    hw_timer_t *My_timer = NULL;
    My_timer = timerBegin(timer_num, 80, true);
    timerAttachInterrupt(My_timer, callback, true);
    timerAlarmWrite(My_timer, ms * 1000, periodic);
    timerAlarmEnable(My_timer);
}
void timDelayMicroseconds(int us,void (* callback)(),int timer_num,bool periodic) {
    if(timer_num>3){
        return;
    }
    hw_timer_t *My_timer = NULL;
    My_timer = timerBegin(timer_num, 80, true);
    timerAttachInterrupt(My_timer, callback, true);
    timerAlarmWrite(My_timer, us, periodic);
    timerAlarmEnable(My_timer);
}