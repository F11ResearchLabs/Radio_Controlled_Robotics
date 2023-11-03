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



}




void pattern1(){

digitalWrite(ledPin, HIGH); // Turn on LED
delay(on_time); // Wait for 500ms
digitalWrite(ledPin, LOW); // Turn off LED
delay(off_time); // Wait for 500ms
digitalWrite(ledPin, HIGH); // Turn on LED
delay(on_time); // Wait for 500ms
digitalWrite(ledPin, LOW); // Turn off LED
delay(off_time); // Wait for 500ms
  
}



void pattern2(){

digitalWrite(ledPin, HIGH); // Turn on LED
delay(on_time); // Wait for 500ms
digitalWrite(ledPin, LOW); // Turn off LED
delay(off_time); // Wait for 500ms
digitalWrite(ledPin, HIGH); // Turn on LED
delay(on_time); // Wait for 500ms
digitalWrite(ledPin, LOW); // Turn off LED
delay(off_time); // Wait for 500ms
digitalWrite(ledPin, HIGH); // Turn on LED
delay(on_time); // Wait for 500ms
digitalWrite(ledPin, LOW); // Turn off LED
delay(off_time); // Wait for 500ms
digitalWrite(ledPin, HIGH); // Turn on LED
delay(on_time); // Wait for 500ms
digitalWrite(ledPin, LOW); // Turn off LED
delay(off_time); // Wait for 500ms

}


void led_off(){

digitalWrite(ledPin, LOW); // Turn off LED
delay(1000); // Wait for 500ms
  
}


void on_hold(){

digitalWrite(ledPin, HIGH); // Turn on LED
delay(1000); // Wait for 500ms
  
}




