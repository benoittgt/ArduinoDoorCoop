#include <SimpleTimer.h>

int ledPinTest = 13;
int lightSensorPin = 0;
int motorDownSensor = A1;
int motorUpSensor = A2;
int motorDown = 11;
int motorUp = 12;
int lightSensor;
int lightState;

SimpleTimer chickenCoopTimer;

void setup(){
  pinMode(lightSensorPin, INPUT);
  pinMode(motorDownSensor, INPUT);
  pinMode(motorUpSensor, INPUT);
  pinMode(motorDown, OUTPUT);
  pinMode(motorUp, OUTPUT);
  pinMode(ledPinTest, OUTPUT);
  Serial.begin(9600);
  chickenCoopTimer.setInterval(6000, howIsLight);      // read the lightSensor every
}

void loop(){
  chickenCoopTimer.run();
  //howIsLight();
  if(lightState == 1){
    Serial.println("motor goes up!");
    digitalWrite(motorDown, LOW);
    motorGoUp();
    Serial.println("motor is up!");
  } else {
    Serial.println("motor goes down!");
    digitalWrite(motorUp, LOW);
    motorGoDown();
    Serial.println("motor is down!");
  }
}

void motorGoUp(){
  Serial.print("\nI'm in motorUp: motorUpSensor = ");
  Serial.println(analogRead(motorUpSensor));
  if (analogRead(motorUpSensor) <= 60) {
    digitalWrite(motorUp, LOW);
    Serial.println("Motor is up !");
    delay(100);
  } else {
    digitalWrite(motorUp, HIGH);
    Serial.println("Motor go up!");
    delay(100);
  }
}

void motorGoDown(){
  Serial.print("\nI'm in motorDown: motorDownSensor = ");
  Serial.println(analogRead(motorDownSensor));
  if (analogRead(motorDownSensor) <= 60) {
    digitalWrite(motorDown, LOW);
    Serial.println("Motor is down !");
    delay(100);
  } else {
    digitalWrite(motorDown, HIGH);
    Serial.println("Motor go down!");
    delay(100);
  }
}

void howIsLight(){
  lightSensor = analogRead(lightSensorPin);
  if(lightSensor >= 100){
    lightState = 1;
  } else {
    lightState = 0;
  }
  Serial.print("lighState is ");
  Serial.println(lightState);
}
