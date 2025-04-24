/*
  illuminationdisplay.cpp - Library for CommandWing Display Section on the Illumination2PRO Consoles
  Created by Liam A. Clark, April 24, 2025.
  Updated by Liam A. Clark, April 24, 2025.
  Version: 1.0.1 pre-alpha
*/

#include "illuminationdisplay.h"
#include <Arduino.h>

IlDisplay::IlDisplay(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8, int pin9, int pin10, int pin11, int pin12) {
    _pin1 = pin1;
    _pin2 = pin2;
    _pin3 = pin3;
    _pin4 = pin4;
    _pin5 = pin5;
    _pin6 = pin6;
    _pin7 = pin7;
    _pin8 = pin8;
    _pin9 = pin9;
    _pin10 = pin10;
    _pin11 = pin11;
    _pin12 = pin12;
}
void IlDisplay::begin() {
    if(_pin1 != 100){
        pinMode(_pin1, OUTPUT);
    }
    if(_pin2 != 100){
        pinMode(_pin2, OUTPUT);
    }
    if(_pin3 != 100){
        pinMode(_pin3, OUTPUT);
    }
    if(_pin4 != 100){
        pinMode(_pin4, OUTPUT);
    }
    if(_pin5 != 100){
        pinMode(_pin5, OUTPUT);
    }
    if(_pin6 != 100){
        pinMode(_pin6, OUTPUT);
    }
    if(_pin7 != 100){
        pinMode(_pin7, OUTPUT);
    }
    if(_pin8 != 100){
        pinMode(_pin8, OUTPUT);
    }
    if(_pin9 != 100){
        pinMode(_pin9, OUTPUT);
    }
    if(_pin10 != 100){
        pinMode(_pin10, OUTPUT);
    }
    if(_pin11 != 100){
        pinMode(_pin11, OUTPUT);
    }
    if(_pin12 != 100){
        pinMode(_pin12, OUTPUT);
    }
}

void IlDisplay::Channel(int state) {
    if(state == 1){
        digitalWrite(_pin1, HIGH);
    }else{
        digitalWrite(_pin1, LOW);
    }
}
void IlDisplay::Flash(int state) {
    if(state == 1){
        digitalWrite(_pin2, HIGH);
    }else{
        digitalWrite(_pin2, LOW);
    }
}
void IlDisplay::Solo(int state) {
    if(state == 1){
        digitalWrite(_pin3, HIGH);
    }else{
        digitalWrite(_pin3, LOW);
    }
}
void IlDisplay::Preview(int state) {
    if(state == 1){
        digitalWrite(_pin4, HIGH);
    }else{
        digitalWrite(_pin4, LOW);
    }
}
void IlDisplay::Chaser(int state) {
    if(state == 1){
        digitalWrite(_pin5, HIGH);
    }else{
        digitalWrite(_pin5, LOW);
    }
}
void IlDisplay::Next(int state) {
    if(state == 1){
        digitalWrite(_pin6, HIGH);
    }else{
        digitalWrite(_pin6, LOW);
    }
}
void IlDisplay::Prog(int state) {
    if(state == 1){
        digitalWrite(_pin7, HIGH);
    }else{
        digitalWrite(_pin7, LOW);
    }
}
void IlDisplay::DMX(int universe1, int universe2, int universe3, int universe4) {
    if(universe1 == 1){
        digitalWrite(_pin8, HIGH);
    }else{
        digitalWrite(_pin8, LOW);
    }
    if(universe2 == 1){
        digitalWrite(_pin9, HIGH);
    }else{
        digitalWrite(_pin9, LOW);
    }
    if(universe3 == 1){
        digitalWrite(_pin10, HIGH);
    }else{
        digitalWrite(_pin10, LOW);
    }
    if(universe4 == 1){
        digitalWrite(_pin11, HIGH);
    }else{
        digitalWrite(_pin11, LOW);
    }
}
void IlDisplay::group(int state) {
    if(state == 1){
        digitalWrite(_pin12, HIGH);
    }else{
        digitalWrite(_pin12, LOW);
    }
}
