



int receiver_pin = 6;

int led1Pin = 15;
int led2Pin = 18;
int led3Pin = 14;


const int main_wait = 2000;
const int flicker_rate = 100;


void setup() {
  pinMode(receiver_pin, INPUT);
  pinMode (led1Pin, OUTPUT);
  pinMode (led2Pin, OUTPUT);
  pinMode (led3Pin, OUTPUT);
  Serial.begin(9600);
}



void loop(){


int pulseDuration = pulseIn(receiver_pin, HIGH);

if (pulseDuration < 1000) 
{
  // Turn off all LEDs
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
} 

else if (pulseDuration >= 1050 && pulseDuration < 1100) 
{
  // LED 1 is turned on
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
}

else if (pulseDuration >= 1150 && pulseDuration < 1200) 
{
  // LED 1 is turned on
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(led3Pin, LOW);
}


else if (pulseDuration >= 1250 && pulseDuration < 1300) 
{
  // LED 1 is turned on
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(led3Pin, HIGH);
}


else if (pulseDuration >= 1350 && pulseDuration < 1600) 
{
flashy();
}

else if (pulseDuration >= 1650 && pulseDuration < 1800) 
{
flashy2();
}


}





void flashy(){


digitalWrite (led1Pin, HIGH);
digitalWrite (led2Pin, LOW);
digitalWrite (led3Pin, HIGH);
delay (flicker_rate);
digitalWrite (led1Pin, LOW);
digitalWrite (led2Pin, LOW);
digitalWrite (led3Pin, LOW);
delay (flicker_rate);



}




void flashy2(){


digitalWrite (led1Pin, LOW);
digitalWrite (led2Pin, HIGH);
digitalWrite (led3Pin, LOW);
delay (flicker_rate);
digitalWrite (led1Pin, LOW);
digitalWrite (led2Pin, LOW);
digitalWrite (led3Pin, LOW);
delay (flicker_rate);



}





void loop2() {

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

