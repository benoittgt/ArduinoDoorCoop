int ledPinTest = 13;
int lightSensorPin = 0;
int motorDownSensor = 1;
int motorUpSensor = 2;
int motorDown = 11;
int motorUp = 12;
int lightSensor;
int lightState;

void setup(){
  pinMode(lightSensorPin, INPUT);
  pinMode(motorDownSensor, INPUT);
  pinMode(motorUpSensor, INPUT);
  pinMode(motorDown, OUTPUT);
  pinMode(motorUp, OUTPUT);
  pinMode(ledPinTest, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  howIsLight();
  if(lightState == 1){
    Serial.println("motor goes up!");
    motorGoUp();
    Serial.println("motor is up!");
  } else {
    Serial.println("motor goes down!");
    motorGoDown();
    Serial.println("motor is down!");
  }
}

void motorGoUp(){
  delay(1000);
  Serial.print("i'm in motorUp: motorUpSensor = ");
  Serial.println(motorUpSensor);
  delay(1000);
}

void motorGoDown(){
  delay(1000);
  Serial.print("i'm in motorDown, motorDownSensor = ");
  Serial.println(motorDownSensor);
  delay(1000);
}

void howIsLight(){
  lightSensor = analogRead(lightSensorPin);

  if(lightSensor >= 1000){
    lightState = 1;
  } else {
    lightState = 0;
  }
  Serial.print("LighState is ");
  Serial.println(lightState);
}
