/*
  digitdisplay.h - Library for 7-digit-displays
  Created by Liam A. Clark, November 2, 2023.
  Updated by Liam A. Clark, April 15, 2025.
  Version: 2.1.1 beta
*/

#ifndef DIGITDISPLAY_H
#define DIGITDISPLAY_H

#include <Arduino.h>
#include <digitdisplay.cpp>

// Library Pin Specifications are for the Model "Hawlett-Paclard(HP) 5082-7653"

// Pins View from Top
//  1: Top          14: GND
//  2: TopLeft      13: TopRight
//  3: GND          12: NoPin
//  4: NoPin        11: Middle
//  5: NoPin        10: BottomRight
//  6:              9:  Dot Right
//  7: BottomLeft   8:  Bottom

// CodePins to ObjectPins          ---1---
// _pin1 = 1    Top               |       |
// _pin2 = 13   TopRight          6       2
// _pin3 = 10   BottomRight       |       |
// _pin4 = 8    Bottom             ---7---    
// _pin5 = 7    BottomLeft        |       |
// _pin6 = 2    TopLeft           5       3
// _pin7 = 11   Middle            |       |
//                                 ---4---


class DigitDisplay {
    public:
        DigitDisplay(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7);
        void begin();
        void displayNumber(int number);
        void displayOther(int element_id);
        void clearDisplay();
    private:
        int _pin1, _pin2, _pin3, _pin4, _pin5, _pin6, _pin7;
};

#endif