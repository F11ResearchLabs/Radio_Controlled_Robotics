int buttonPin = 7; // Define pin number for button
int ledPin = 4; // Define pin number for LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor
}

void loop() {
  while (digitalRead(buttonPin) == LOW) { // While button is not pressed
    digitalWrite(ledPin, HIGH); // Turn on LED
    delay(40); // Wait for 500ms
    digitalWrite(ledPin, LOW); // Turn off LED
    delay(40); // Wait for 500ms
  }

    digitalWrite(ledPin, HIGH); // Turn on LED
    delay(1000); // Wait for 500ms
    digitalWrite(ledPin, LOW); // Turn off LED
    delay(1000); // Wait for 500ms

}


