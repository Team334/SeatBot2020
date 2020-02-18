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
int state;
int acceleration;

bool receivedData;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);

  leftSide.attach(13);
  rightSide.attach(12);

  SPEED = 25;
  ZERO = 90;
  state = -1;
  acceleration = .95;
  
  leftCurrentSpeed = 90;
  rightCurrentSpeed = 90;

  leftSetSpeed = 90;
  rightSetSpeed = 90;

  receivedData = false;
  leftSide.write(ZERO);
  rightSide.write(ZERO);
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    receivedData = true;
  }
  if (state == 48) {
    // forward
    leftSetSpeed = ZERO + SPEED;
    rightSetSpeed = ZERO - SPEED;
  }
  else if (state == 49) {
    // backward
    leftSetSpeed = ZERO - SPEED;
    rightSetSpeed = ZERO + SPEED;
  }
  else if (state == 50) {
    // left

    leftSetSpeed = ZERO + SPEED;
    rightSetSpeed = ZERO + SPEED;
  }
  else if (state == 51) {
    // right

    leftSetSpeed = ZERO - SPEED;
    rightSetSpeed = ZERO - SPEED;
  }
  else if (state == 52) {
    // stop
    leftSetSpeed = ZERO;
    rightSetSpeed = ZERO;
  }
  if (receivedData) {
    receivedData = false;
  }
  if (leftCurrentSpeed > leftSetSpeed) {
    leftCurrentSpeed = leftCurrentSpeed - acceleration;
  } else if (leftCurrentSpeed < leftSetSpeed) {
    leftCurrentSpeed = leftCurrentSpeed + acceleration;
  }

  if (rightCurrentSpeed > rightSetSpeed) {
    rightCurrentSpeed = rightCurrentSpeed - acceleration;
  } else if (rightCurrentSpeed < rightSetSpeed) {
    rightCurrentSpeed = rightCurrentSpeed + acceleration;
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
