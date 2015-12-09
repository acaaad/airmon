#include "SoftwareSerial.h"

SoftwareSerial mySerial(11,10);

String val="";
double co2=0;

double multiplier = 10;

uint8_t buffer[25];
uint8_t ind =0;

void setup(){
  Serial.begin(9600);
  Serial.println("CO2Meter Cozir");
  mySerial.begin(9600);
}

void loop(){
  while(buffer[ind‐1] != 0x0A){
    if(mySerial.available()){
      buffer[ind] = mySerial.read();
      ind++;
    }
  }
  report();
}

void report(){
  for(int i=0; i < ind+1; i++){
    if(buffer[i] == 'z') break;
    if((buffer[i] != 0x5A)&&(buffer[i] != 0x20)){
      val += buffer[i]‐48;
    }
  }
  co2 = (multiplier * val.toInt());
  Serial.print( "Co2 = ");
  Serial.print(co2);
  Serial.println(" ppm");
  ind=0;
  val="";
}

