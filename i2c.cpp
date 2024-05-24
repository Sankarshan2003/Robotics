#include "i2c.h"
void i2cSetup(){
     Wire.begin(SDA_PIN, SCL_PIN); 
}
void sendCommand(String cmd)
{
    Wire.beginTransmission(8); // Start transmission to device with address 8
    Wire.write(cmd); // Send the string "Hello"
    Wire.endTransmission(); // End transmission
}