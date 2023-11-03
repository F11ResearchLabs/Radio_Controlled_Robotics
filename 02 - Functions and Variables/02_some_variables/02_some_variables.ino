

void setup() {
  // put your setup code here, to run once:
pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// flash pattern 1
    digitalWrite(4, HIGH); // Turn on LED
    delay(300); // Wait for 500ms
    digitalWrite(4, LOW); // Turn off LED
    delay(300); // Wait for 500ms
    digitalWrite(4, HIGH); // Turn on LED
    delay(300); // Wait for 500ms
    digitalWrite(4, LOW); // Turn off LED
    delay(300); // Wait for 500ms


//on hold
    digitalWrite(4, HIGH); // Turn on LED
    delay(5000);


// flash pattern 2
    digitalWrite(4, HIGH); // Turn on LED
    delay(300); // Wait for 500ms
    digitalWrite(4, LOW); // Turn off LED
    delay(300); // Wait for 500ms
    digitalWrite(4, HIGH); // Turn on LED
    delay(300); // Wait for 500ms
    digitalWrite(4, LOW); // Turn off LED
    delay(300); // Wait for 500ms
    digitalWrite(4, HIGH); // Turn on LED
    delay(300); // Wait for 500ms
    digitalWrite(4, LOW); // Turn off LED
    delay(300); // Wait for 500ms
    digitalWrite(4, HIGH); // Turn on LED
    delay(300); // Wait for 500ms
    digitalWrite(4, LOW); // Turn off LED
    delay(300); // Wait for 500ms

//off
    digitalWrite(4, LOW); // Turn on LED
    delay(5000);



}
