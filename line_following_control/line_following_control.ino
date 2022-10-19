
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// motor 0 is right side, motor 1 is left side 
Adafruit_DCMotor *motorR = AFMS.getMotor(3);
Adafruit_DCMotor *motorL = AFMS.getMotor(1); 

// sensor pins
lSensorPin = A0;
rSensorPin = A1;

void setup() {
    AFMS.begin();
    Serial.begin(9600);

    // Set default speed 
    motorR->setSpeed(30);
    motorL->setSpeed(30);

}

void loop() {
  int lSensor = analogRead(lSensorPin);
  int rSensor = analogRead(rSensorPin);

  Serial.print(sensorValue1);
  Serial.print("|");
  Serial.println(sensorValue2);

  if (lSensor<850)&&(rSensor<850){
    //turn right
    motorR->run(FORWARD);
    motorL->run(RELEASE);
  } if (lSensor<850)&&(rSensor>850){
    //turn right
    motorR->run(FORWARD);
    motorL->run(RELEASE);
  } if (lSensor>850)&&(rSensor<850){
    //turn left
    motorR->run(RELEASE);
    motorL->run(FORWARD);
  } if (lSensor>850)&&(rSensor>850){
    //go straight
    motorR->run(FORWARD);
    motorL->run(FORWARD);
  }

  delay(500);

  
  
}
