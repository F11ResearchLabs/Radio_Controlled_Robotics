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


/*

// while (Wire.available() < 2 * sizeof(int))


The `Wire.available()` function returns the number of bytes available to read from an I2C device. In this case, it is being used to check if there are enough bytes available to read from the device to ensure that a complete data transmission has been received.

The expression `2 * sizeof(int)` calculates the total number of bytes that should be received for the data transmission. `sizeof(int)` returns the size, in bytes, of an integer, which is typically 2 or 4 bytes depending on the platform and compiler.

Multiplying this by 2 gives us the total number of bytes required for two integers.

The `while` loop will continue to execute until enough bytes are available to read, as specified by the condition inside the parentheses. Once the condition is met, the loop will exit and the program will continue to execute the next line of code.

So, `while (Wire.available() < 2 * sizeof(int))` is a way to wait until all of the expected data has been received before proceeding with the next step in the communication protocol.

*/
