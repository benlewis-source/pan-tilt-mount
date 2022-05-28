#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>


class Joystick {
    private:
        int _xPin;
        int _yPin;

        int _x_curve[4][2] = {{0, -100}, {502, 0}, {512, 0}, {1023, 100}};
        int _y_curve[4][2] = {{0, -100}, {502, 0}, {512, 0}, {1023, 100}};

        int _getAverageReading(int pin);
        float _interpolate(float value, int (*curve)[2]);

    public:
        Joystick(int xPin, int yPin);
        void begin(void);
        float getX(void);
        float getY(void);
};

#endif