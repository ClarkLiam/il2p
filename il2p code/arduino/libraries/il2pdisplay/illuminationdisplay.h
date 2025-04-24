/*
  illuminationdisplay.h - Library for CommandWing Display Section on the Illumination2PRO Consoles
  Created by Liam A. Clark, April 24, 2025.
  Updated by Liam A. Clark, April 24, 2025.
  Version: 1.0.1 pre-alpha
*/

#ifndef ILLUMINATIONDISPLAY_H
#define ILLUMINATIONDISPLAY_H

#include <Arduino.h>

class IlDisplay {
    public:
        IlDisplay(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7); /*How many pin? -> What features?*/
        void begin();
        void show(int element)
        void clearElement(int element);
        void clearAll();
    private:
        int _pin1, _pin2, _pin3, _pin4, _pin5, _pin6, _pin7;
};

#endif