#include <math.h>
const int thresholdvalue=10;
float RSensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(0);
   RSensor=(float)(1023-sensorValue)*10/sensorValue;
   Serial.println("the analog read data is ");
   Serial.println(sensorValue);
   Serial.println("the sensor resistance is ");
   Serial.println(RSensor,DEC);
   delay(1000);
}
