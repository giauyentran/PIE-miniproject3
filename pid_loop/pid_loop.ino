
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// motor 0 is right side, motor 1 is left side 
Adafruit_DCMotor *motor0 = AFMS.getMotor(3);
Adafruit_DCMotor *motor1 = AFMS.getMotor(1); 

void setup() {
    AFMS.begin();
    Serial.begin(9600);

    // Set default speed 
    motor0->setSpeed(10);
    motor0->setSpeed(90);
    motor1->setSpeed(10);
    motor1->setSpeed(90);
}

void loop() {
  while (Serial.available() == 0) {
    // wait for data available in serial receive buffer
  }
  String command = Serial.readStringUntil('\n');  // read until timeout
  if (command.startsWith("motor0")) {
    // note: wheel will be in the form "setWheelDirection N" where N is speed
    // extract speed from command string
    uint8_t speed = command.substring(command.indexOf(" ")+1, command.length()).toInt();
    motor0->run(FORWARD);
    motor0->setSpeed(speed);
    Serial.println(speed);

  } else if (command.startsWith("motor1")) {
    uint8_t speed = command.substring(command.indexOf(" ")+1, command.length()).toInt();
    motor1->run(FORWARD);
    motor1->setSpeed(speed);
    Serial.println(speed);

  } else if (command.startsWith("-motor0")) {
    uint8_t speed = command.substring(command.indexOf(" ")+1, command.length()).toInt();
    motor0->run(BACKWARD);
    motor0->setSpeed(speed);
    Serial.println(speed);

  } else if (command.startsWith("-motor1")) {
    uint8_t speed = command.substring(command.indexOf(" ")+1, command.length()).toInt();
    motor1->run(BACKWARD);
    motor1->setSpeed(speed);
    Serial.println(speed);

  } else if (command.equals("readSensors")) {
    // send sensor readings over serial
    readSensors();
  } else if (command.equals("STOP")) {
    // stop motors
    rightWheel->run(RELEASE);
    leftWheel->run(RELEASE);
    Serial.println("0");
}
