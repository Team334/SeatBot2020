#include <Servo.h>

float Vrx;
float Vry;

float Vrx2;
float Vry2;

int VRX_ANALOG_PIN;
int VRY_ANALOG_PIN;

int VRX_ANALOG_PIN2;
int VRY_ANALOG_PIN2;

float MOTOR_ZERO;
float MOTOR_MULTIPLIER;
float MOTOR_MAX:

Servo leftSide;
Servo rightSide;

void setup() {
  Serial.begin(38400);

  VRX_ANALOG_PIN = A0;
  VRY_ANALOG_PIN = A1;

  VRX_ANALOG_PIN2 = A2;
  VRY_ANALOG_PIN2 = A3;

  MOTOR_ZERO = 90.0;
  MOTOR_MAX = 180.0f;
  MOTOR_MULTIPLIER = 0.3f;

  leftSide.attach(13);
  rightSide.attach(12);

  leftSide.write(MOTOR_ZERO);
  rightSide.write(MOTOR_ZERO);
}

void loop() {
  // max of joystick is 1023, min is 0
  // clamp 1023 - 0 to 1 - 0
  Vrx = (float)analogRead(VRX_ANALOG_PIN) / 1023.0;
  Vry = (float)analogRead(VRY_ANALOG_PIN) / 1023.0;
  Vrx2 = (float)analogRead(VRX_ANALOG_PIN2) / 1023.0;
  Vry2 = (float)analogRead(VRY_ANALOG_PIN2) / 1023.0;
  // now the values are from 0.5,0,-0.5
  // corresponding to max, zero, min
  Vrx = Vrx - 0.5f;
  Vry = Vry - 0.5f;
  Vrx2 = Vrx2 - 0.5f;
  Vry2 = Vry2 - 0.5f;

  // map the values to the acceptable motor values
  // max,zero,min = 180,90,0
  // 0.5 * 180 * 1 + 90 = 180, max
  // 0 * 180 * 1 + 90 = 90, zero
  // -0.5 * 180 * 1 + 90 = 0, min
  Vrx = Vrx * MOTOR_MAX * MOTOR_MULTIPLIER + MOTOR_ZERO;
  Vry = Vry * MOTOR_MAX * MOTOR_MULTIPLIER + MOTOR_ZERO;

  Vrx2 = Vrx2 * MOTOR_MAX * MOTOR_MULTIPLIER + MOTOR_ZERO;
  Vry2 = Vry2 * MOTOR_MAX * MOTOR_MULTIPLIER + MOTOR_ZERO;

  //  Serial.print("VRX:");
  //  Serial.println(Vrx);
  //  Serial.print("VRY:");
  //  Serial.println(Vry);

  leftSide.write(Vry);
  rightSide.write(Vry2);
}
