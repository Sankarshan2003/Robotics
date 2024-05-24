#include <Wire.h>
#include <string>
#define SDA_PIN 21
#define SCL_PIN 22
void i2cSetup();
void sendCommand(int cmd);
// Command "abcdefg" -  a - Direction , bcd - Duty Cycle (L), efg - Duty Cycle(R)  
//Direction
/*
    0-balance
    1-forward
    2-reverse
    3-left
    4-right

*/
