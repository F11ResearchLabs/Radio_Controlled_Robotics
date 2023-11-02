// Example 3
const int buttonPin = 6; // Define pin number for button
const int ledPin = 4; // Define pin number for LED

void setup() {
pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor
pinMode(ledPin, OUTPUT); // Set LED pin as output
Serial.begin(9600); // Initialize serial communication
}

void loop() {
int buttonState = digitalRead(buttonPin); // Read state of button
int buttonPressed = 0; // Initialize variable to 0
if (buttonState == LOW) { // If the button is pressed
buttonPressed = 1; // Set variable to 1
}
digitalWrite(ledPin, buttonPressed); // Set LED state to buttonPressed variable
Serial.println(buttonState); // Print button state to serial monitor
delay(10); // Wait for 10ms
}