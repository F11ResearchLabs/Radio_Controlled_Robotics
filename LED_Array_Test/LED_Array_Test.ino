

int LED_C1 = 14;
int LED_C2 = 15;
int LED_C3 = 16;

void setup() {
  // put your setup code here, to run once:

pinMode(LED_C1, OUTPUT);
pinMode(LED_C2, OUTPUT);
pinMode(LED_C3, OUTPUT);


}

void loop() {


// This is to test each column - remark out the columns you're not testing
digitalWrite(LED_C1, HIGH);
//digitalWrite(LED_C2, HIGH);
//digitalWrite(LED_C3, HIGH);


}


void led_col_cycle() {

// This is to talk about functions in class - Nothing really important here yet
digitalWrite(LED_C1, HIGH);
delay(300);
digitalWrite(LED_C1, LOW);
delay(300);

digitalWrite(LED_C2, HIGH);
delay(300);
digitalWrite(LED_C2, LOW);
delay(300);

digitalWrite(LED_C3, HIGH);
delay(300);
digitalWrite(LED_C3, LOW);
delay(300);

}




