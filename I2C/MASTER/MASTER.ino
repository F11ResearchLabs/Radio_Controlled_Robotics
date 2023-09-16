#include <Wire.h>

#define SLAVE_ADDRESS 0x04 // Address of the slave device

int ir1Value; // Stores the value of the first IR sensor
int ir2Value; // Stores the value of the second IR sensor

void setup() {
  Serial.begin(9600); // Open serial communication for debugging
  Wire.begin(); // Join I2C bus
}

void loop() {
  // Send a request to the slave to read the IR sensor data
  Wire.requestFrom(SLAVE_ADDRESS, 2 * sizeof(int));
  while (Wire.available() < 2 * sizeof(int)) {
    // Wait for data to be available
  }
  Wire.readBytes((byte*)&ir1Value, sizeof(int));
  Wire.readBytes((byte*)&ir2Value, sizeof(int));

  // Print the values for debugging
  Serial.print("IR sensor 1: ");
  Serial.println(ir1Value);
  Serial.print("IR sensor 2: ");
  Serial.println(ir2Value);
}