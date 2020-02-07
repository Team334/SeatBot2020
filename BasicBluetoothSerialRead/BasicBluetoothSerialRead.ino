#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(19, 18);
Servo leftSide;
Servo rightSide;

int leftSpeed;
int rightSpeed;
int SPEED;
int ZERO;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);

  leftSide.attach(12);
  rightSide.attach(13);

  SPEED = 5;
  ZERO = 60;
}

void loop() {
  while (Serial.available() < 0) { Serial.println("ERROR: NO COMM TO BLUETOOTH"); }
  if (Serial.read() == '0') {
    // forward
    leftSpeed = ZERO + SPEED;
    rightSpeed = ZERO - SPEED;
  }
  else if (Serial.read() == '1') {
    // backward
    leftSpeed = ZERO - SPEED;
    rightSpeed = ZERO + SPEED;
  }
  else if (Serial.read() == '2') {
    // left
    leftSpeed = ZERO + SPEED;
    rightSpeed = ZERO + SPEED;
  }
  else if (Serial.read() == '3') {
    // right
    leftSpeed = ZERO - SPEED;
    rightSpeed = ZERO - SPEED;
  }
  else if (Serial.read() == '4') {
    // stop
    leftSpeed = ZERO;
    rightSpeed = ZERO;
  }
  leftSide.write(leftSpeed);
  rightSide.write(rightSpeed);
  Serial.print("LEFT:");
  Serial.println(leftSide.read());

  Serial.print("RIGHT:");
  Serial.println(rightSide.read());
}
