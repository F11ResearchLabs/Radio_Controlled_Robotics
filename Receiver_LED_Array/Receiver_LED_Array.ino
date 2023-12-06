int receiver_pin = 6;

int led1Pin = 14;
int led2Pin = 16;
int led3Pin = 15;

void setup() {
  pinMode(receiver_pin, INPUT);
  Serial.begin(9600);
}




void loop() {

int pulseDuration = pulseIn(receiver_pin, HIGH);

if (pulseDuration < 1200) {
  // Turn off all LEDs
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
} else if (pulseDuration >= 1200 && receiver_pin < 1400) {
  // LED 1 is turned on
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
} else if (pulseDuration >= 1400 && receiver_pin < 1600) {
  // LED 1 and LED 2 are turned on
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(led3Pin, LOW);
} else if (pulseDuration >= 1600 && receiver_pin < 1800) {
  // LED 1, LED 2, and LED 3 are turned on
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(led3Pin, HIGH);
} else if (pulseDuration >= 1800 && receiver_pin <= 2000) {
  // All LEDs flash
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(led3Pin, HIGH);
  delay(500); // Adjust the delay time to control the flashing speed
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
  delay(500); // Adjust the delay time to control the flashing speed
}

}

