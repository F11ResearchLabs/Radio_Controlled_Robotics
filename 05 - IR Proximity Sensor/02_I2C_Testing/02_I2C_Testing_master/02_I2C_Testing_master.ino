
#include <Wire.h>
#define SLAVE_ADDRESS 0x04



struct SensorData {
  int sensor01;
  int sensor02;
};

SensorData sdata; // Declare sensor data variable at global scope


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Wire.begin(); // join i2c bus as master

}

void loop() {
  // put your main code here, to run repeatedly:

  // Request sensor data from slave
  Wire.requestFrom(SLAVE_ADDRESS, sizeof(sdata));

Wire.readBytes((byte*)&sdata, sizeof(sdata));
  Serial.print("Sensor 1: ");
  Serial.println(sdata.sensor01);
//delay (100); //this is for latency testing - enable this and watch what happens

if (sdata.sensor01 == 0){
  analogWrite(9,150);
}
else{
  analogWrite(9,0);
}


}


void talk(){
\\ This will eventually be to hold the I2C reading process so it can be called with a simple format in the loop 
}






