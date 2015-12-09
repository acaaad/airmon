#include <SoftwareSerial.h>
#include "cozir.h"

SoftwareSerial nss(3,2);
COZIR czr(nss);

void setup()
{
 Serial.begin(9600);
 delay(3000);
 //czr.SetOperatingMode(CZR_POLLING);
 //czr.SetOperatingMode(CZR_STREAMING);
}

void loop()
{
 float t = czr.Celsius();
 float f = czr.Fahrenheit();
 float h = czr.Humidity();
 int c = czr.CO2();
 int digi = czr.GetDigiFilter();

 Serial.print("Celcius : ");Serial.println(t);
 Serial.print("Fahrenheit : ");Serial.println(f);
 Serial.print("Humidity : ");Serial.println(h);
 Serial.print("CO2 : ");Serial.println(c);
 Serial.print("Digital Filter : ");Serial.println(digi);
}
