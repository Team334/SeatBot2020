#include <SoftwareSerial.h>

SoftwareSerial mySerial(19, 18);
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    Serial.print("First number1:");
    Serial.println(Serial.read());
    Serial.flush();
    Serial.print("Second number2:");
    Serial.println(Serial.read());
    
  }
}
