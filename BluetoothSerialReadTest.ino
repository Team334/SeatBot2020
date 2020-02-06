#include <SoftwareSerial.h>

SoftwareSerial mySerial(19, 18);
char character;
String data;
bool allowedToReadData;
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
  allowedToReadData = false;
  data = "";
  character = 'a';
}

void loop() {
  //  character = Serial.read();
  //  if (character == '7') {
  //    allowedToReadData = false;
  //    Serial.print(data);
  //    data = "";
  //  }
  //  if (allowedToReadData) {
  //    data.concat(Serial.read());
  //    Serial.print("concat");
  //  }
  //  if (character == '6') {
  //    allowedToReadData = true;
  //    Serial.print("it is six, true");
  //  }
  //  Serial.print(data);
  Serial.println(Serial.read());
  delay(1000);
  Serial.println(Serial.read());
  delay(1000);
  Serial.println(Serial.read());
  delay(1000);
  Serial.println(((int)Serial.read()) + 5);
}
