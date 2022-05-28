#include "joystick.h"

Joystick::Joystick(int xPin, int yPin)
{
    this->_xPin = xPin;
    this->_yPin = yPin;
}

/* This function sets the home position of the 
* X an Y analog inputs
*/
void Joystick::begin(void)
{
    _xHome = this->_getAverageReading(_xPin);
    Serial.print("xHome: ");
    Serial.println(_xHome);
    _x_curve[1][0] = _xHome - 10;
    _x_curve[2][0] = _xHome + 10;

    _yHome = this->_getAverageReading(_yPin);
    Serial.print("yHome: ");
    Serial.println(_yHome);
    _y_curve[1][0] = _yHome - 10;
    _y_curve[2][0] = _yHome + 10;
}

int Joystick::getX(void)
{
    int raw_x = analogRead(this->_xPin);
    return _interpolate(raw_x, _x_curve);
}
    
int Joystick::getY(void)
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

int Joystick::_interpolate(int value, int (*curve)[2])
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
    return (int)(slope * (float)value) + offest;
}

// int Joystick::_interpolateY(int value)
// {
//     float x0, y0, x1, y1;
//     for(int i = 1; i < 4; i++)
//     {
//         x0 = (float)_y_curve[i - 1][0];
//         y0 = (float)_y_curve[i - 1][1];
//         x1 = (float)_y_curve[i][0];
//         y1 =(float) _y_curve[i][1];
//         if(value <= _y_curve[i][0])
//         {
//             break;
//         }
//     }
//     float slope = ((y1 - y0) / (x1 - x0));
//     float offest = y0 - (slope * x0);
//     return (int)(slope * (float)value) + offest;
// }