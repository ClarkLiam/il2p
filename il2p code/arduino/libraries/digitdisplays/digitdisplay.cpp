/*
  digitdisplay.cpp - Library for 7-digit-displays
  Created by Liam A. Clark, November 2, 2023.
  Updated by Liam A. Clark, April 15, 2025.
  Version: 2.1.1 beta
*/

#include "digitdisplay.h"
#include <Arduino.h>

DigitDisplay::DigitDisplay(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7) {
    _pin1 = pin1;
    _pin2 = pin2;
    _pin3 = pin3;
    _pin4 = pin4;
    _pin5 = pin5;
    _pin6 = pin6;
    _pin7 = pin7;
}
void DigitDisplay::begin() {
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    pinMode(_pin3, OUTPUT);
    pinMode(_pin4, OUTPUT);
    pinMode(_pin5, OUTPUT);
    pinMode(_pin6, OUTPUT);
    pinMode(_pin7, OUTPUT);
}

// Simple Numbers
// 0: 1-6
// 1: 2-3
// 2: 1,2,4,5,7
// 3: 1,2,3,4,7
// 4: 2,3,6,7
// 5: 1,3,4,5,7
// 6: 1,3,4,5,6,7
// 7: 1-3
// 8: 1-7
// 9: 1,2,3,4,6,7

void DigitDisplay::displayNumber(int number){
    if(number == 0){
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, HIGH);
        digitalWrite(_pin5, HIGH);
        digitalWrite(_pin6, HIGH);
        digitalWrite(_pin7, LOW);
    }
    if(number == 1){
        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, LOW);
        digitalWrite(_pin5, LOW);
        digitalWrite(_pin6, LOW);
        digitalWrite(_pin7, LOW);
    }
    if(number == 2){
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, LOW);
        digitalWrite(_pin4, HIGH);
        digitalWrite(_pin5, HIGH);
        digitalWrite(_pin6, LOW);
        digitalWrite(_pin7, HIGH);
    }
    if(number == 3){
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, HIGH);
        digitalWrite(_pin5, LOW);
        digitalWrite(_pin6, LOW);
        digitalWrite(_pin7, HIGH);
    }
    if(number == 4){
        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, LOW);
        digitalWrite(_pin5, LOW);
        digitalWrite(_pin6, HIGH);
        digitalWrite(_pin7, HIGH);
    }
    if(number == 5){
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, LOW);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, HIGH);
        digitalWrite(_pin5, HIGH);
        digitalWrite(_pin6, LOW);
        digitalWrite(_pin7, HIGH);
    }
    if(number == 6){
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, LOW);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, HIGH);
        digitalWrite(_pin5, HIGH);
        digitalWrite(_pin6, HIGH);
        digitalWrite(_pin7, HIGH);
    }
    if(number == 7){
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, LOW);
        digitalWrite(_pin5, LOW);
        digitalWrite(_pin6, LOW);
        digitalWrite(_pin7, LOW);
    }
    if(number == 8){
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, HIGH);
        digitalWrite(_pin5, HIGH);
        digitalWrite(_pin6, HIGH);
        digitalWrite(_pin7, HIGH);
    }
    if(number == 9){
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, HIGH);
        digitalWrite(_pin5, LOW);
        digitalWrite(_pin6, HIGH);
        digitalWrite(_pin7, HIGH);
    }
}

void DigitDisplay::displayOther(int element_id){
    if(element_id == 0){                // Element 0 -> "L"
        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, LOW);
        digitalWrite(_pin3, LOW);
        digitalWrite(_pin4, HIGH);
        digitalWrite(_pin5, HIGH);
        digitalWrite(_pin6, HIGH);
        digitalWrite(_pin7, LOW);
    }
    if(element_id == 1){                // Element 1 -> "S"
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, LOW);
        digitalWrite(_pin3, HIGH);
        digitalWrite(_pin4, HIGH);
        digitalWrite(_pin5, HIGH);
        digitalWrite(_pin6, LOW);
        digitalWrite(_pin7, HIGH);
    }
    if(element_id == 2){                // Element 2 -> "I"
        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, LOW);
        digitalWrite(_pin3, LOW);
        digitalWrite(_pin4, LOW);
        digitalWrite(_pin5, HIGH);
        digitalWrite(_pin6, HIGH);
        digitalWrite(_pin7, LOW);
    }
    if(element_id == 3){                // Element 3 -> "P"
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, HIGH);
        digitalWrite(_pin3, LOW);
        digitalWrite(_pin4, LOW);
        digitalWrite(_pin5, HIGH);
        digitalWrite(_pin6, HIGH);
        digitalWrite(_pin7, HIGH);
    }
}

void DigitDisplay::clearDisplay(){
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
    digitalWrite(_pin3, LOW);
    digitalWrite(_pin4, LOW);
    digitalWrite(_pin5, LOW);
    digitalWrite(_pin6, LOW);
    digitalWrite(_pin7, LOW);
}

