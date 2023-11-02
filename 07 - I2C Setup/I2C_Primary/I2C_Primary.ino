
#include <Wire.h>

#define SLAVE_ADDRESS 0x04 // This is the address of the slave Arduino

const int bright01 = 10;
const int bright02 = 130;
const int pin2 = 9;
const int pin1 = A8;
const int glow01_on = 10;
const int glow01_off = 10;

void setup() {
  // put your setup code here, to run once:

Wire.begin(); // join i2c bus

pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


Wire.beginTransmission(SLAVE_ADDRESS); // Start communication with slave Arduino
Wire.write(0x01); // Send command to turn on LED
Wire.endTransmission(); // Stop communication with slave Arduino
delay(500); // Wait for 500 ms

Wire.beginTransmission(SLAVE_ADDRESS); // Start communication with slave Arduino
Wire.write(0x00); // Send command to turn on LED
Wire.endTransmission(); // Stop communication with slave Arduino
delay(500); // Wait for 500 ms

}


void led_test(){

analogWrite(pin1,bright02);
analogWrite(pin2,bright01);
delay(glow01_on);
analogWrite(pin2,0);
analogWrite(pin1,0);
delay(glow01_off);


}
