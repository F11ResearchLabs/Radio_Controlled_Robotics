
#include <Wire.h>

#define SLAVE_ADDRESS 0x04 // This is the address of this Arduino
int myVariable = 2; // The variable to send to the master

const int bright01 = 10;
const int bright02 = 130;
const int Ard2_Blue = 19;
const int Ard2_Red = 6;
const int glow01_on = 10;
const int glow01_off = 10;


const int flash_01 = 2;
const int led_off = 5;

const int flash_rate = 30;


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Wire.begin(SLAVE_ADDRESS); // join i2c bus as slave with address 0x04
Wire.onReceive(receiveEvent); // When data is received, call function receiveEvent
Wire.onRequest(requestEvent); // Register the requestEvent function
pinMode(Ard2_Blue, OUTPUT);
pinMode(Ard2_Red, OUTPUT);
pinMode(14, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

myVariable = 1;
delay(flash_rate);

myVariable = 2;
delay(flash_rate);



}


void receiveEvent(int bytesReceived)
{
  while (Wire.available()) // While there is data available
  {
    int command = Wire.read(); // Read the command sent by master
    
    if (command == 1) // If command is to turn on LED
    {
      analogWrite(Ard2_Red, 50); // Turn on LED
      analogWrite(Ard2_Blue, 0);
    }
    if (command == 0)
    {
      analogWrite(Ard2_Red, 0); // Turn off LED
      analogWrite(Ard2_Blue, 150);
    }
  }
}


void requestEvent() {
  // Send the variable value to the master
  //Serial.println(myVariable);
  Wire.write((byte*)&myVariable, sizeof(int));
}


void led_test(){

  
analogWrite(Ard2_Blue,bright02);
analogWrite(Ard2_Red,bright01);
delay(glow01_on);
analogWrite(Ard2_Red,0);
analogWrite(Ard2_Blue,0);
delay(glow01_off);
  
  }


/*
AI Tips

Here are some suggestions for improvements to your code:

1. As with the master device code, it's a good idea to add comments to explain what each section of your code is doing. This will make it easier for other people (or yourself in the future) to understand how the code works.

2. It's not clear what the purpose of the `myVariable` variable is in the slave device code, or why you're setting it to different values and then delaying for a certain amount of time. If you're using this variable to test the communication between the two devices, you could add more comments explaining how this testing is being performed.

3. In the `receiveEvent()` function, you're currently reading a single byte from the master device and using it to control the LED on the slave device. It might be more clear to use an integer value (e.g. `0` for off, `1` for on), or to send a more descriptive command to the slave Arduino.

4. When sending data back to the master device in the `requestEvent()` function, you're currently sending the `myVariable` value as an integer. It might be better to send this value as a byte array or as a more compact data structure to reduce the amount of data being transmitted over the I2C bus.

5. The `led_test()` function appears to be similar to the `led_test()` function in the master device code, and is used to test the brightness of the LEDs. It might be a good idea to document this function more clearly and explain how it's intended to be used.

Overall, the code looks well-organized and functional, but adding more detailed comments and documentation would make it easier for other people (or yourself in the future) to understand how the code works and how it can be modified or extended.


No, I meant that instead of sending the `myVariable` value as an integer, you could send it as a byte array or a more compact data structure to reduce the amount of data being transmitted over the I2C bus. 

For example, you could define a custom data structure that includes information about the state of both LEDs, like this:

```
struct LedState {
  byte red;
  byte blue;
};
```

Then, you could create an instance of this data structure in your slave code and populate its fields with the appropriate LED brightness values:

```
LedState myState;
myState.red = bright01;
myState.blue = 0;
```

Finally, when you receive a request from the master to send the LED state, you could write the contents of the `myState` data structure to the I2C bus using the `Wire.write()` function:

```
void requestEvent() {
  // Send the LED state to the master
  Wire.write((byte*)&myState, sizeof(LedState));
}
```

On the master side, you would need to define a similar data structure and read its contents from the I2C bus using the `Wire.read()` function.

Using a custom data structure like this can be more efficient than sending each LED state as a separate integer value, since it reduces the number of bytes being transmitted over the I2C bus.



*/



