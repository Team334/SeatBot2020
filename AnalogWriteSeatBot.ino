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
  Serial.println("Going forward");
  analogWrite(motorPin, 234);
  Serial.println(analogRead(motorPin));
} 
