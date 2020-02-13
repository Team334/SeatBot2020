#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(19, 18);
Servo leftSide;
Servo rightSide;

int leftSetSpeed;
int rightSetSpeed;

int leftCurrentSpeed;
int rightCurrentSpeed;

int SPEED;
int ZERO;
<<<<<<< HEAD
int state;
int acceleration;

=======

int interPolationSpeed;
>>>>>>> 6a01b0813ac033d84cc263c14d057900b03a0070
bool receivedData;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);

  leftSide.attach(13);
  rightSide.attach(12);

  SPEED = 30;
  ZERO = 90;
  state = -1;
  acceleration = 1;
  
  leftCurrentSpeed = 90;
  rightCurrentSpeed = 90;

  leftSetSpeed = 90;
  rightSetSpeed = 90;
  
  interPolationSpeed = 2;
  
  receivedData = false;
  leftSide.write(ZERO);
  rightSide.write(ZERO);
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    //    Serial.println(state);
    receivedData = true;
  }
  if (state == 48) {
    // forward
    leftSetSpeed = ZERO + SPEED;
    rightSetSpeed = ZERO - SPEED;
    //    Serial.print("LEFT:");
    //    Serial.println(leftSetSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSetSpeed);
  }
  else if (state == 49) {
    // backward
    leftSetSpeed = ZERO - SPEED;
    rightSetSpeed = ZERO + SPEED;
    //    Serial.print("LEFT:");
    //    Serial.println(leftSetSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSetSpeed);
  }
  else if (state == 50) {
    // left

    leftSetSpeed = ZERO + SPEED;
    rightSetSpeed = ZERO + SPEED;

    //    Serial.print("LEFT:");
    //    Serial.println(leftSetSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSetSpeed);
  }
  else if (state == 51) {
    // right

    leftSetSpeed = ZERO - SPEED;
    rightSetSpeed = ZERO - SPEED;

    //    Serial.print("LEFT:");
    //    Serial.println(leftSetSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSetSpeed);
  }
  else if (state == 52) {
    // stop
    leftSetSpeed = ZERO;
    rightSetSpeed = ZERO;

    //    Serial.print("LEFT:");
    //    Serial.println(leftSetSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSetSpeed);
  }
  if (receivedData) {
    state = -1;
    receivedData = false;
    //    Serial.print("LEFT Motor:");
    //    Serial.println(leftSide.read());
    //
    //    Serial.print("RIGHT Motor:");
    //    Serial.println(rightSide.read());
  }
  if (leftCurrentSpeed > leftSetSpeed) {
<<<<<<< HEAD
    leftCurrentSpeed = leftCurrentSpeed - acceleration;
  } else if (leftCurrentSpeed < leftSetSpeed) {
    leftCurrentSpeed = leftCurrentSpeed + acceleration;
  } else if (leftCurrentSpeed == leftSetSpeed) {
    //    Serial.print("On Setpoint Set");
    //    Serial.println(leftCurrentSpeed);
=======
    leftCurrentSpeed = leftCurrentSpeed - interPolationSpeed;
  } else if (leftCurrentSpeed < leftSetSpeed) {
    leftCurrentSpeed = leftCurrentSpeed + interPolationSpeed;
>>>>>>> 6a01b0813ac033d84cc263c14d057900b03a0070
  }

  if (rightCurrentSpeed > rightSetSpeed) {
<<<<<<< HEAD
    rightCurrentSpeed = rightCurrentSpeed - acceleration;
  } else if (rightCurrentSpeed < rightSetSpeed) {
    rightCurrentSpeed = rightCurrentSpeed + acceleration;
  } else if (rightCurrentSpeed == rightSetSpeed) {
    //    Serial.print("On Setpoint Right");
    //    Serial.println(rightCurrentSpeed);
=======
    rightCurrentSpeed = rightCurrentSpeed - interPolationSpeed;
  } else if (rightCurrentSpeed < rightSetSpeed) {
    rightCurrentSpeed = rightCurrentSpeed + interPolationSpeed;
>>>>>>> 6a01b0813ac033d84cc263c14d057900b03a0070
  }
  leftSide.write(leftCurrentSpeed);
  rightSide.write(rightCurrentSpeed);
  //  Serial.print("LEFT Motor:");
  //  Serial.println(leftSide.read());
  //
  //  Serial.print("RIGHT Motor:");
  //  Serial.println(rightSide.read());
  //  delay(500);
}
