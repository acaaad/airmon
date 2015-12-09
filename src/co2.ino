#include <SoftwareSerial.h>

SoftwareSerial nss(11,10);

void setup()
{
  Serial.begin(9600);
  nss.begin(9600);
  delay(3000);
}

void getStuff()
{
  if (nss.available())
  {
    Serial.write(nss.read());
  }
}
void loop()
{
  getStuff();
  delay(2000);
}
