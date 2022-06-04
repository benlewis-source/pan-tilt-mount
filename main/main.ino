#include "joystick.h"
#include "stepper_motor.h"
#include <PWM.h>

Joystick joystick(A6, A7);

StepperMotor tiltMotor(9, 8);
StepperMotor panMotor(3, 11);


void setup() {
  Serial.begin(115200);
  InitTimersSafe(); 
  joystick.begin();
  tiltMotor.begin();
  panMotor.begin();
}

void loop() {
  float xValue = joystick.getX();
  float yValue = joystick.getY();

  Serial.print("X :");
  Serial.print(xValue);
  Serial.print(", Y :");
  Serial.println(yValue);

   panMotor.update(xValue);
   tiltMotor.update(yValue);
}
