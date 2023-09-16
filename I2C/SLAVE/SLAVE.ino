#include <Wire.h>

#define SLAVE_ADDRESS 0x04 // This is the address of this Arduino

const int ir1Pin = A0; // Pin connected to the first IR sensor
const int ir2Pin = A1; // Pin connected to the second IR sensor

int ir1Value; // Stores the value read from the first IR sensor
int ir2Value; // Stores the value read from the second IR sensor

void setup() {
  Serial.begin(9600); // Open serial communication for debugging
  Wire.begin(SLAVE_ADDRESS); // Join I2C bus as slave with address 0x04
  Wire.onRequest(requestEvent); // Register the requestEvent function
}

void loop() {
  // Read data from the two IR sensors and store their values
  ir1Value = analogRead(ir1Pin);
  ir2Value = analogRead(ir2Pin);
}

void requestEvent() {
  // Send the IR sensor data to the master
  Wire.write((byte*)&ir1Value, sizeof(int));
  Wire.write((byte*)&ir2Value, sizeof(int));
}