
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
    // Do your control loop stuff, changing speeds of motors
    // based on IR sensor readings

    // Argument to run could be FORWARD, BACKWARD, or RELEASE
    motor0->run(BACKWARD);
    motor1->run(BACKWARD);
    delay(5000);
    motor0->run(RELEASE);
    motor1->run(RELEASE);
    delay(5000);

}
