int receiverPin = 4; // the pin the receiver signal is connected to
int pulseDuration; // variable to hold the pulse duration
const int array_num = 5;
int pulseArray[array_num]; // an array to hold 10 pulse duration values
int pulseCount = 0; // counter to keep track of values added to array
long int pulseSum = 0; // variable to hold the sum of pulse duration values

void setup() {
  pinMode(receiverPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the pulse duration from the receiver channel
  pulseDuration = pulseIn(receiverPin, HIGH);

  // add the pulse duration to the pulseArray and increment the pulseCount
  pulseArray[pulseCount] = pulseDuration;
  pulseCount++;

  // if the pulseCount has reached 10, calculate the average and reset the pulseCount and pulseSum
  if (pulseCount == array_num) {
    for (int i = 0; i < array_num; i++) {
      pulseSum += pulseArray[i];
    }
    int pulseAverage = pulseSum / array_num;
    Serial.print("Average pulse duration: ");
    Serial.println(pulseAverage);
    pulseCount = 0;
    pulseSum = 0;
  }

}