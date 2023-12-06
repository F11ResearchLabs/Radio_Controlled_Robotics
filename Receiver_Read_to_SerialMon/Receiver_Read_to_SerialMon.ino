
int receiver_pin = 6; // receiver pin

int pulseDuration; // variable to hold the pulse duration in microseconds


void setup() {
  pinMode(receiver_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the pulse duration from the receiver channel
  pulseDuration = pulseIn(receiver_pin, HIGH);


  // print the pulse duration to the serial monitor
  Serial.print("Pulse duration: ");
  Serial.println(pulseDuration);

}