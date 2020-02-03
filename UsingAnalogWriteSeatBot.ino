#define motorPin 11
int speedMotor = HIGH;
void  setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  Serial.write(250);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{
  Serial.println(Serial.available());
  Serial.println("loop is working");
  analogWrite(motorPin, 75);
  Serial.println(analogRead(motorPin));
} 
