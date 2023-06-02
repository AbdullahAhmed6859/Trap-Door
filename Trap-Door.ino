#include <Servo.h>
const int trig = 4;
const int echo = 5;

const int trigDist = 10;

Servo myServo;

float getDist(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  float duration = pulseIn(echoPin, HIGH);
  return  duration * 0.034 / 2;
}

void setup() {
  Serial.begin(9600);
  myServo.attach(3);
  myServo.write(180);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  float dist = getDist(trig, echo);
  delay(100);
  Serial.println(dist);
  if ( dist < trigDist ) {
    myServo.write(0);
    Serial.println("object detected");
    delay(1000);
  }
}
