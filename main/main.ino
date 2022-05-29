#include "joystick.h"
#include <PWM.h>


Joystick joystick(A0, A1);
int dir = 4;
int step = 3;
int ena = 5;


void setup() {
  Serial.begin(115200);
  joystick.begin();
  InitTimersSafe(); 
  pinMode(dir, OUTPUT);
  pinMode(step, OUTPUT);
  pinMode(ena, OUTPUT);

  digitalWrite(ena, 0);
}

void loop() {
  float freq = joystick.getX();
  Serial.println(freq);

  if (freq > 10) {
    digitalWrite(dir, 1);
    pwmWrite(step, 125);
    SetPinFrequencySafe(step, (int)abs(freq));
  }
  else if (freq < -10) {
    digitalWrite(dir, 0);
    pwmWrite(step, 125);
    SetPinFrequencySafe(step, (int)abs(freq));
  } else {
    pwmWrite(step, 0);
  }
}
