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
}

void readSensors() {
  // read right sensor voltage:
  int RVal = analogRead(RIGHT_SENSE);
  // read left sensor voltage:
  int LVal = analogRead(LEFT_SENSE);

  // no idea how to do this part
  // print to serial as a tuple
  //char buffer;
  //sprintf(buffer, ;
  //Serial.println(buffer);
}
