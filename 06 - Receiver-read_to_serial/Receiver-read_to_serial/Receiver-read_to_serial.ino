
int receiver_pin = 6; // receiver pin




int pulseDuration; // variable to hold the pulse duration in microseconds


void setup() {
  pinMode(receiver_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the pulse duration from the receiver channel
  pulseDuration_pan = pulseIn(rec_pan, HIGH);


  // print the pulse duration to the serial monitor
  Serial.print("Pulse duration_pan: ");
  Serial.println(pulseDuration_pan);

  // set the servo to the pulse duration value in microseconds
  myservo1.writeMicroseconds(pulseDuration_pan);
  myservo2.writeMicroseconds(pulseDuration_tilt);
}