int ledPin = 4;  // LED connected to digital pin 13
int inPin = 5;    // pushbutton connected to digital pin 7
int MyVar = 0;      // variable to store the read value

void setup() {
  pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
  pinMode(inPin, INPUT);    // sets the digital pin 7 as input
  Serial.begin(9600);
}

void loop() {
  MyVar = digitalRead(inPin);   // read the input pin
  digitalWrite(ledPin, MyVar);  // sets the LED to the button's value
  Serial.println(MyVar);


}