

const int bright01 = 130;
const int ard1_red = 6;
const int ard1_blue = 19;
const int glow01_on = 10;
const int glow01_off = 300;

void setup() {
  // put your setup code here, to run once:


pinMode(ard1_red, OUTPUT);
pinMode(ard1_blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

analogWrite(ard1_red,bright01);
delay(glow01_on);
analogWrite(ard1_red,0);
delay(glow01_off);

digitalWrite(ard1_blue,HIGH);
delay(glow01_on);
digitalWrite(ard1_blue,LOW);
delay(glow01_off);

}