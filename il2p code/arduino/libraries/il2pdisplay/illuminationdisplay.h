/*
  illuminationdisplay.h - Library for CommandWing Display Section on the Illumination2PRO Consoles
  Created by Liam A. Clark, April 24, 2025.
  Updated by Liam A. Clark, April 24, 2025.
  Version: 1.0.2 alpha
*/

#ifndef ILLUMINATIONDISPLAY_H
#define ILLUMINATIONDISPLAY_H

#include <Arduino.h>

/*
Pin1:   Channel
Pin2:   Flash
Pin3:   Solo
Pin4:   Preview
Pin5:   Chaser
Pin6:   Next
Pin7:   Prog
Pin8:   Universe1
Pin9:   Universe2
Pin10:  Universe3
Pin11:  Universe4
Pin12:  GroupON
*/

//If the element is connected to a different board, the library will expect a 100 on the pin
class IlDisplay {
    public:
        IlDisplay(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8, int pin9, int pin10, int pin11, int pin12);
        void begin();
        void Channel(int state);
        void Flash(int state);
        void Solo(int state);
        void Preview(int state);
        void Chaser(int state);
        void Next(int state);
        void Prog(int state);
        void DMX(int universe1, int universe2, int universe3, int universe4);
        void group(int state);

    private:
        int _pin1, _pin2, _pin3, _pin4, _pin5, _pin6, _pin7, _pin8, _pin9, _pin10, _pin11, _pin12;
};

#endif