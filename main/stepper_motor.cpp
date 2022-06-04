#include "stepper_motor.h"
#include <PWM.h>

StepperMotor::StepperMotor(int stepPin, int dirPin) {
    this->_stepPin = stepPin;
    this->_dirPin = dirPin;
}

void StepperMotor::begin(void) {
//    InitTimersSafe(); 
    pinMode(_stepPin, OUTPUT);
    pinMode(_dirPin, OUTPUT);
    pwmWrite(_stepPin, 0);
}

void StepperMotor::update(float value) {
    int freq = (int)abs(value);

    if (value > 0) {
        digitalWrite(_dirPin, 1);
    } else {
        digitalWrite(_dirPin, 0);
    } 
    if (freq > 10) {
        pwmWrite(_stepPin, 125);
        SetPinFrequencySafe(_stepPin, freq);
    } else {
        SetPinFrequencySafe(_stepPin, 1);
        pwmWrite(_stepPin, 0);
    }
}
