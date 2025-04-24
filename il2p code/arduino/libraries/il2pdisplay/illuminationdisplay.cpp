/*
  illuminationdisplay.cpp - Library for CommandWing Display Section on the Illumination2PRO Consoles
  Created by Liam A. Clark, April 24, 2025.
  Updated by Liam A. Clark, April 24, 2025.
  Version: 1.0.1 pre-alpha
*/

#include "illuminationdisplay.h"
#include <Arduino.h>

IlDisplay::IlDisplay(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7) {
    _pin1 = pin1;
    _pin2 = pin2;
    _pin3 = pin3;
    _pin4 = pin4;
    _pin5 = pin5;
    _pin6 = pin6;
    _pin7 = pin7;
}
void IlDisplay::begin() {
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    pinMode(_pin3, OUTPUT);
    pinMode(_pin4, OUTPUT);
    pinMode(_pin5, OUTPUT);
    pinMode(_pin6, OUTPUT);
    pinMode(_pin7, OUTPUT);
}

void IlDisplay::show(int element){
    
}

void IlDisplay::clearElement(int element){
}

void IlDisplay::clearAll(){
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
    digitalWrite(_pin3, LOW);
    digitalWrite(_pin4, LOW);
    digitalWrite(_pin5, LOW);
    digitalWrite(_pin6, LOW);
    digitalWrite(_pin7, LOW);
}

