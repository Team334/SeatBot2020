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

int interPolationSpeed;
bool receivedData;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);

  leftSide.attach(13);
  rightSide.attach(12);

  SPEED = 50;
  ZERO = 90;
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
    leftSetSpeed = Serial.read() * ZERO;
    leftSetSpeed = clampValue(ZERO - SPEED, ZERO + SPEED, leftSetSpeed);
    Serial.print("SetSpeedleft:");
    Serial.println(leftSetSpeed);
    Serial.flush();
    rightSetSpeed = Serial.read() * ZERO;
    rightSetSpeed = clampValue(ZERO - SPEED, ZERO + SPEED, rightSetSpeed);
    Serial.print("SetSpeedright:");
    Serial.println(rightSetSpeed);
    Serial.flush();
    receivedData = true;
  }
  if (leftCurrentSpeed > leftSetSpeed) {
    leftCurrentSpeed = leftCurrentSpeed - interPolationSpeed;
  } else if (leftCurrentSpeed < leftSetSpeed) {
    leftCurrentSpeed = leftCurrentSpeed + interPolationSpeed;
  }
  if (rightCurrentSpeed > rightSetSpeed) {
    rightCurrentSpeed = rightCurrentSpeed - interPolationSpeed;
  } else if (rightCurrentSpeed < rightSetSpeed) {
    rightCurrentSpeed = rightCurrentSpeed + interPolationSpeed;
  }
  leftSide.write(leftCurrentSpeed);
  rightSide.write(rightCurrentSpeed);
  if (receivedData) {
    Serial.print("LEFT Motor:");
    Serial.println(leftSide.read());

    Serial.print("RIGHT Motor:");
    Serial.println(rightSide.read());
    receivedData = false;
  }
}
int clampValue(int clampLower, int clampHigher, int valueSent) {
  if (valueSent > clampHigher) {
    return clampHigher;
  } else if (valueSent < clampLower) {
    return clampLower;
  }
  return valueSent;
}
