#include <SoftwareSerial.h>
#include <Servo.h> 
SoftwareSerial mySerial(19, 18);
Servo leftSide;
Servo rightSide;

int leftSpeed;
int rightSpeed;
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);

  leftSide.attach(12);
  rightSide.attach(13);
}

void loop() {
//  Serial.print(Serial.available());
  leftSpeed = ((int)Serial.read()) - 47;
  rightSpeed = ((int)Serial.read()) - 47;

//  Serial.println(leftSpeed - 1);
//  Serial.println(rightSpeed - 1);
  leftSpeed = leftSpeed - 1;
  rightSpeed = rightSpeed - 1;
  
  leftSide.write(leftSpeed * 90);
  rightSide.write(rightSpeed * 90);

//  Serial.println(leftSide.read());
//  Serial.print(rightSide.read());
}
