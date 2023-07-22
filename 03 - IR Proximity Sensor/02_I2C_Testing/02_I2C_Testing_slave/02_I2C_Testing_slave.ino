
#include <Wire.h>


#define SLAVE_ADDRESS 0x04



struct SensorData {
  int sensor01;
  //int sensor02;
};

SensorData sdata; // Declare sensor data variable at global scope

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(14, INPUT);
pinMode(18, INPUT);
pinMode(6, OUTPUT);
Wire.begin(SLAVE_ADDRESS); // join i2c bus as slave with address 0x04
Wire.onReceive(receiveEvent); // When data is received, call function receiveEvent
Wire.onRequest(requestEvent); // Register the requestEvent function
}

void loop() {
  // put your main code here, to run repeatedly:

// this section is to vaidate the sensor struct read function
if (sdata.sensor01 == 0){
  analogWrite (6, 140);
}
  else{
  analogWrite (6, 0);
  }


}





void receiveEvent(int bytesReceived)
{
  while (Wire.available()) // While there is data available
  {
    int command = Wire.read(); // Read the command sent by master
    

  }
}


void requestEvent() {
  // Send the variable value to the master
  // This may be better thought of as ""REQUESTED event" - it isn't requesting anything on the slave

sdata.sensor01 = digitalRead(14);
sdata.sensor02 = digitalRead(2);
Serial.println(sdata.sensor01); // this prints the value of the specified sensor in the serial monitor
  Wire.write((byte*)&sdata, sizeof(sdata));
}

