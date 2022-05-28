#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>


class Joystick {
    private:
        int _xPin;
        int _yPin;

        int _xHome = 512;
        int _yHome = 512;
        int _xMin = 0;
        int _yMin = 0;
        int _xMax = 1023;
        int _yMax = 1023;

        int _x_curve[4][2] = {{_xMin, -100}, {_xHome - 10, 0}, {_xHome + 10, 0}, {_xMax, 100}};
        int _y_curve[4][2] = {{_yMin, -100}, {_yHome - 10, 0}, {_yHome + 10, 0}, {_yMax, 100}};

        int _getAverageReading(int pin);
        int _interpolate(int value, int (*curve)[2]);

    public:
        Joystick(int xPin, int yPin);
        void begin(void);
        int getX(void);
        int getY(void);
};

#endif