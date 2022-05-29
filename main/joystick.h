#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>


class Joystick {
    private:
        int _xPin;
        int _yPin;

        int _xHome = 512;
        int _yHome = 512;

        int _getAverageReading(int pin);
        float _cubic(float x, float centre);

    public:
        Joystick(int xPin, int yPin);
        void begin(void);
        float getX(void);
        float getY(void);
};

#endif