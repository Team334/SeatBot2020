#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(19, 18);
Servo leftSide;
Servo rightSide;

int leftSpeed;
int rightSpeed;
int SPEED;
int ZERO;
int state;

bool receivedData;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);

  leftSide.attach(13);
  rightSide.attach(12);

  SPEED = 50;
  ZERO = 90;
  state = -1;
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
    leftSpeed = ZERO + SPEED;
    rightSpeed = ZERO - SPEED;
    //    Serial.print("LEFT:");
    //    Serial.println(leftSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSpeed);
  }
  else if (state == 49) {
    // backward
    leftSpeed = ZERO - SPEED;
    rightSpeed = ZERO + SPEED;
    //    Serial.print("LEFT:");
    //    Serial.println(leftSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSpeed);
  }
  else if (state == 50) {
    // left

    leftSpeed = ZERO + SPEED;
    rightSpeed = ZERO + SPEED;

    //    Serial.print("LEFT:");
    //    Serial.println(leftSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSpeed);
  }
  else if (state == 51) {
    // right

    leftSpeed = ZERO - SPEED;
    rightSpeed = ZERO - SPEED;

    //    Serial.print("LEFT:");
    //    Serial.println(leftSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSpeed);
  }
  else if (state == 52) {
    // stop
    leftSpeed = ZERO;
    rightSpeed = ZERO;

    //    Serial.print("LEFT:");
    //    Serial.println(leftSpeed);
    //
    //    Serial.print("RIGHT:");
    //    Serial.println(rightSpeed);
  }
  leftSide.write(leftSpeed);
  rightSide.write(rightSpeed);
  if (receivedData) {
    state = -1;
    receivedData = false;
    //    Serial.print("LEFT Motor:");
    //    Serial.println(leftSide.read());
    //
    //    Serial.print("RIGHT Motor:");
    //    Serial.println(rightSide.read());
  }
}
