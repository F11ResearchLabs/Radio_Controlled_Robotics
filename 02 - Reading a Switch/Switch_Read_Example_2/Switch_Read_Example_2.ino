// Example 1
const int buttonPin = 6; // Define pin number for button
const int ledPin = 4; // Define pin number for LED

void setup() {
pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor
pinMode(ledPin, OUTPUT); // Set LED pin as output
Serial.begin(9600); // Initialize serial communication
}

void loop() {
int buttonState = digitalRead(buttonPin); // Read state of button
digitalWrite(ledPin, buttonState); // Set LED state to button state
Serial.println(buttonState); // Print button state to serial monitor
delay(10); // Wait for 10ms
}