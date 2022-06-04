#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>

class StepperMotor {
    private:
        int _stepPin;
        int _dirPin;

    public:
        StepperMotor(int stepPin, int dirPin);
        void begin(void);
        void update(float value);
};

#endif
