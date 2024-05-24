#include "timer.h"
#include "ultrasound.h"
#include <Arduino.h>
#include "soc/rtc_wdt.h"
#include <esp_task_wdt.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
float fd=0;
float ld=0;
float rd=0; 
float sensorbuff[3];
#define STACK_SIZE_READ 10000
#define LED 2
#define SAMPLES 3
void read(void * parameter){
  
  static int count =0;
  float favg,lavg,ravg;
  favg=0;
  lavg=0;
  ravg=0;
  while(true){
  unsigned long startTime = millis();
  digitalWrite(LED, !digitalRead(LED));
   fd = getDistance(FTrigPin, FEchoPin);
   ld = getDistance(LTrigPin, LEchoPin);
   rd = getDistance(RTrigPin, REchoPin);
   if(count==SAMPLES){
    sensorbuff[0]=favg;
    sensorbuff[1]=lavg;
    sensorbuff[2]=ravg;
    count =0;
    favg=0;
    lavg=0;
    ravg=0;
    
   }else{
   count++;
   favg=favg+fd/SAMPLES;
   lavg=lavg+ld/SAMPLES;
   ravg=ravg+rd/SAMPLES;
   }
  vTaskDelay(100/portTICK_PERIOD_MS);
  unsigned long endTime = millis();  // End time
    //Serial.print("Execution time: ");
    //Serial.println(endTime - startTime);
}
}
void print(void * parameter)
{
  while(true)
  {
  Serial.print("Front:");
  Serial.println(sensorbuff[0]);
  Serial.print(" Left: ");
  Serial.println(sensorbuff[1]);
  Serial.print(" Right: ");
  Serial.println(sensorbuff[2]);
  Serial.print(" Tick Rate: ");
  Serial.println(portTICK_PERIOD_MS);
  

  vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
void setup() {
  // put your setup code here, to run once:'yo mama
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  initUltrasound();
  //Creating Reading Ultrasonic sensor task
  TaskHandle_t readTaskHandle;
  xTaskCreate(read,"Read Task",STACK_SIZE_READ,NULL,6,&readTaskHandle);
  //Creating printing Task
  TaskHandle_t printSensorValues;
  xTaskCreate(print,"Serial Print",STACK_SIZE_READ,NULL,1,&printSensorValues);
  //Creating Control Task
  TaskHandle_t control;
  //xTaskCreate(cont,"Control Task",STACK_SIZE_READ,NULL,7,&control);
 
}

void loop() {
  // put your main code here, to run repeatedly:

  

}
