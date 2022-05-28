#include "joystick.h"

Joystick::Joystick(int xPin, int yPin)
{
    this->_xPin = xPin;
    this->_yPin = yPin;
}

/* This function sets the deadband in the curve
* for both inputs 
*/
void Joystick::begin(void)
{
    int _xHome = this->_getAverageReading(_xPin);
    _x_curve[1][0] = _xHome - 10;
    _x_curve[2][0] = _xHome + 10;

    int _yHome = this->_getAverageReading(_yPin);
    _y_curve[1][0] = _yHome - 10;
    _y_curve[2][0] = _yHome + 10;
}

/* Returns the interpolated value for X
*/
float Joystick::getX(void)
{
    int raw_x = analogRead(this->_xPin);
    return _interpolate(raw_x, _x_curve);
}

/* Returns the interpolated value for Y
*/
float Joystick::getY(void)
{
    int raw_value = analogRead(this->_yPin);
    return _interpolate(raw_value, _y_curve);
}

/* This function takes a number of readings
* from an analog pin and returns the average
* value 
*/
int Joystick::_getAverageReading(int pin)
{
    int num_samples = 50;
    long unsigned int sum_total = 0;
    for(int i = 0; i < num_samples; i++)
        sum_total += analogRead(pin);

    return sum_total / num_samples;
}

/* This function takes an input value and performs 
* a linear interpolation with the provided curve points. 
*/
float Joystick::_interpolate(float value, int (*curve)[2])
{
    float x0, y0, x1, y1;
    for(int i = 1; i < 4; i++)
    {

        x0 = (float)curve[i - 1][0];
        y0 = (float)curve[i - 1][1];
        x1 = (float)curve[i][0];
        y1 =(float) curve[i][1];
        if(value <= x1)
        {
            break;
        }
    }

    float slope = ((y1 - y0) / (x1 - x0));
    float offest = y0 - (slope * x0);
    return (slope * value) + offest;
}
