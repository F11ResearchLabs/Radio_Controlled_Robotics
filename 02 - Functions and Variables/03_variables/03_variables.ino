#define led1 4

#define on_time 200
#define off_time 200
#define on_hold 5000

void setup() {
  // put your setup code here, to run once:
pinMode();
}

void loop() {
  // put your main code here, to run repeatedly:
// flash
digitalWrite(ledPin, HIGH); // Turn on LED
delay(on_time); // Wait for 500ms
digitalWrite(ledPin, LOW); // Turn off LED
delay(off_time); // Wait for 500ms

//on hold
digitalWrite(ledPin, HIGH); // Turn on LED
delay(on_hold)