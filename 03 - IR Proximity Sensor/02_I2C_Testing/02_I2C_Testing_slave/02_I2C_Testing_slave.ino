#include <Wire.h>

#define SLAVE_ADDRESS 0x04

struct SensorData {
  int sensor01;
  //int sensor02; // This line is commented out until we add more sensors
};

SensorData sdata; // Declaring sensor data variable at global scope

void setup() {
  Serial.begin(9600);
  pinMode(14, INPUT);
  //pinMode(18, INPUT); // This line can be commented out if you're not using sensor02 
  pinMode(6, OUTPUT);
  Wire.begin(SLAVE_ADDRESS); // join i2c bus as slave with address 0x04
  Wire.onRequest(requestEvent); // Register the requestEvent function
}

void loop() {
  if (sdata.sensor01 == 0){
    analogWrite(6, 140);
  } else {
    analogWrite(6, 0);
  }
}

void requestEvent() {
  sdata.sensor01 = digitalRead(14);
  //sdata.sensor02 = digitalRead(18); // This line can be commented out if you're not using sensor02
  Serial.println(sdata.sensor01);
  Wire.write((byte*)&sdata, sizeof(sdata));
}