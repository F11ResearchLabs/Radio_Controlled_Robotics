void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(14, INPUT);
pinMode(6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

int sensor01 = digitalRead(14);
Serial.println(sensor01);

if (sensor01 == 0)
{
analogWrite(6, 120);
}
else{
analogWrite(6, 0);

}



}
