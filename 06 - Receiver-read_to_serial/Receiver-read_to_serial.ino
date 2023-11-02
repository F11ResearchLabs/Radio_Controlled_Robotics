#include <Servo.h> // include the Servo library

int rec_pan = 21; // receiver - Channel 4
int rec_tilt = 20; // receiver - Channel 3



int pulseDuration_pan; // variable to hold the pulse duration in microseconds
int pulseDuration_tilt;
Servo myservo1; // create servo object to control a servo
Servo myservo2;


void setup() {
  pinMode(rec_pan, INPUT);
  Serial.begin(9600);
  myservo1.attach(9); // attach servo signal wire to pin 6
  myservo2.attach(10); // attach servo signal wire to pin 6
}

void loop() {
  // read the pulse duration from the receiver channel
  pulseDuration_pan = pulseIn(rec_pan, HIGH);
  pulseDuration_tilt = pulseIn(rec_tilt, HIGH);

  // print the pulse duration to the serial monitor
  Serial.print("Pulse duration_pan: ");
  Serial.println(pulseDuration_pan);

  // set the servo to the pulse duration value in microseconds
  myservo1.writeMicroseconds(pulseDuration_pan);
  myservo2.writeMicroseconds(pulseDuration_tilt);
}