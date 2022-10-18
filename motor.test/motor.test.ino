
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// motor 0 is right side, motor 1 is left side 
Adafruit_DCMotor *motorR = AFMS.getMotor(3);
Adafruit_DCMotor *motorL = AFMS.getMotor(1); 

void setup() {
    AFMS.begin();
    Serial.begin(9600);

    // Set default speed 
    motorR->setSpeed(30);
    motorL->setSpeed(30);
}

void loop() {
    // Do your control loop stuff, changing speeds of motors
    // based on IR sensor readings

    // Argument to run could be FORWARD, BACKWARD, or RELEASE
    motorR->run(FORWARD);
    motorL->run(FORWARD);
    delay(5000);
    motorR->run(RELEASE);
    motorL->run(RELEASE);
    delay(5000);

}
