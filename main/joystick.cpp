#include "joystick.h"

Joystick::Joystick(int xPin, int yPin) {
    this->_xPin = xPin;
    this->_yPin = yPin;
}

/* This function sets the deadband in the curve
* for both inputs 
*/
void Joystick::begin(void) {
    _xHome = this->_getAverageReading(_xPin);
    _yHome = this->_getAverageReading(_yPin);
}

/* Returns the interpolated value for X
*/
float Joystick::getX(void) {
    int raw_x = analogRead(this->_xPin);
    return _cubic(raw_x, _xHome);
}

/* Returns the interpolated value for Y
*/
float Joystick::getY(void) {
    int raw_value = analogRead(this->_yPin);
    return _cubic(raw_value, _yHome);
}

/* This function takes a number of readings
* from an analog pin and returns the average
* value 
*/
int Joystick::_getAverageReading(int pin) {
    int num_samples = 50;
    long unsigned int sum_total = 0;
    for(int i = 0; i < num_samples; i++)
        sum_total += analogRead(pin);

    return sum_total / num_samples;
}


float Joystick::_cubic(float x, float centre) {
    float y = pow((x - centre), 3) / 20000;
    return y;
}
