#include "joystick.h"


Joystick joystick(A0, A1);


void setup() {
  Serial.begin(115200);
  joystick.begin();
}

void loop() {
  Serial.print(joystick.getX());
  Serial.print(", ");
  Serial.println(joystick.getY());
  delay(50);
}
