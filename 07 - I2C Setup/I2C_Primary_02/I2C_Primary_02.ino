
#include <Wire.h>

#define SLAVE_ADDRESS 0x04 // This is the address of the slave Arduino
int myVariable; // Variable to store the value received from the slave

const int bright01 = 10;
const int bright02 = 130;
const int pin2 = 9;
const int pin1 = A8;
const int glow01_on = 10;
const int glow01_off = 10;


const int flash_01 = 2;
const int led_off = 5;

const unsigned long flashInterval = 500; // Interval for LED flashing in milliseconds
unsigned long previousMillis = 0; // Time of the last LED flash
bool ledState = LOW; // LED state variable

void setup() {
  // put your setup code here, to run once:

Wire.begin(); // join i2c bus

Serial.begin(9600);

pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Wire.beginTransmission(SLAVE_ADDRESS); // Start communication with slave Arduino

   // Request data from the slave
  Wire.requestFrom(SLAVE_ADDRESS, sizeof(int));

  // Read the integer value from the slave
  if (Wire.available()) {
    myVariable = Wire.read();
  //Serial.print("Received value: ");
  //Serial.println(myVariable);
  }

//Wire.endTransmission(); // Stop communication with slave Arduino
  // Delay to prevent excessive reads
  //delay(0);

if (myVariable == 1){
    analogWrite(pin1,bright02);
    analogWrite(pin2,0);
}
if (myVariable == 2){
    analogWrite(pin1,0);
    analogWrite(pin2,bright01);
}


unsigned long currentMillis = millis(); // Get the current time

  if (currentMillis - previousMillis >= flashInterval) { // Check if it's time to toggle the LED
    previousMillis = currentMillis; // Remember the time of the last LED toggle

    // Toggle the LED state
    ledState = !ledState; // Invert the LED state

    // Send the LED state to the slave using the talk() function
    talk(ledState);
  }

//Serial.println(ledState);






}

void talk(bool ledState){

//Serial.println(x);
Wire.beginTransmission(SLAVE_ADDRESS); // Start communication with slave Arduino
Wire.write(ledState); // Send command to turn on LED
// Wire.endTransmission(); // OLD LINE without error checking - Stop communication with slave Arduino
 int error = Wire.endTransmission(); // reads wire.end into the variable "error" - This stops communication with slave Arduino

/*
I2C Error Codes

- `0`: Success
- `1`: Data too long to fit in transmit buffer
- `2`: Received NACK on transmit of address
- `3`: Received NACK on transmit of data
- `4`: Other error
*/

// This section checks for errors and writes them to the serial monitor.
// You could also create an SD card logger, which could be helpful if you were tracking many things
// Even dedicating a "logging Arduino" that you send to over I2C
  if(error == 0){
    Serial.println("I2C communication successful.");
  }
  else if(error == 1){
    Serial.println("I2C communication error: data too long to fit in transmit buffer.");
  }
  else if(error == 2){
    Serial.println("I2C communication error: received NACK on transmit of address.");
  }
  else if(error == 3){
    Serial.println("I2C communication error: received NACK on transmit of data.");
  }
  else if(error == 4){
    Serial.println("I2C communication error: other error.");
  }
  else{
    Serial.println("Unknown I2C communication error.");
  }



}


void led_test(){

analogWrite(pin1,bright02);
analogWrite(pin2,bright01);
delay(glow01_on);
analogWrite(pin2,0);
analogWrite(pin1,0);
delay(glow01_off);


}







void talk2(bool ledState) {
  static unsigned long previousMillis = 0; // Previous time of LED toggle
  const unsigned long interval = 500; // Interval between LED toggles in milliseconds

  unsigned long currentMillis = millis(); // Get the current time

  if (currentMillis - previousMillis >= interval) { // Check if it's time to toggle the LED
    // Send the LED state to the slave
    Wire.beginTransmission(SLAVE_ADDRESS);
    Wire.write(ledState);
    Wire.endTransmission();

    // Update previousMillis with the current time for the next LED toggle
    previousMillis = currentMillis;
  }
}


/*

AI Tips
AI01

Sure, I'd be happy to look over your code. From what I can see, the code appears well-structured and organized, with comments used to explain the purpose and operation of the different code sections.

Here are a few suggestions for further improvement:

1. The variable names `pin1` and `pin2` are not very descriptive, and it's not immediately clear what they refer to. Consider using more descriptive names that reflect the purpose or function of the pins they are associated with.

2. While the use of `delay()` function is okay for this code, it does affect the responsiveness of the code and can cause timing issues if additional features are added in the future. Consider using the `millis()` function instead, which allows for non-blocking delay and more precise timing control.

3. Make sure to add a `Wire.available()` check before reading data from the slave Arduino, to prevent potential data misalignment or corruption.

Overall, the code appears to be functional and well-designed to control and exchange data with the slave Arduino via I2C communication. Nicely done!


AI02

Here are some suggestions for improvements to your code:

1. It's generally a good idea to add comments to explain what each section of your code is doing. While it's clear that this code is communicating between two Arduinos over I2C, it would be helpful to have comments explaining what the different variables are used for and how the LED flashing sequence works.

2. Your `talk()` function is currently sending a boolean value over I2C to the slave Arduino to turn the LED on or off. It might be more clear to use an integer value (e.g. `0` for off, `1` for on), or to send a more descriptive command to the slave Arduino.

3. You have two different functions defined (`talk()` and `talk2()`) for sending data over I2C to the slave Arduino. It's not clear why you need both of these functions or how they are intended to be used. If you only need to send data to the slave Arduino in one way (i.e. from the master to the slave), you may only need a single function for this.

4. When you read data from the slave Arduino using the `Wire.requestFrom()` function, it's a good idea to check how many bytes were actually received before trying to read the variable. The `Wire.requestFrom()` function returns the number of bytes read, which you can check using the `Wire.available()` function. For example:

   ```
   // Request data from the slave
   int bytesRead = Wire.requestFrom(SLAVE_ADDRESS, sizeof(int));

   // Check if any data was received
   if (bytesRead > 0) {
     // Read the integer value from the slave
     myVariable = Wire.read();
   }
   ```

5. You have a variable called `ledState` which is used to keep track of the current state of the LED on the master Arduino. However, this variable is not currently being used to control the LED on the master Arduino - it's only being sent to the slave Arduino using the `talk()` function. If you want to use this variable to control the LED, you could add some code to the `loop()` function to toggle the LED based on the value of `ledState`.

6. You have a function called `led_test()` which appears to be used for testing the brightness of the LEDs. It might be a good idea to document this function more clearly and explain how it's intended to be used.

Overall, the code looks well-organized and functional, but adding more detailed comments and documentation would make it easier for other people (or yourself in the future) to understand how the code works and how it can be modified or extended.




*/


