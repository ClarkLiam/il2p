/*Project: illumination2PRO*/
/*Device: Arduino_Mega.B*/
/*Author: Liam Clark */
/*Version: 2.0.0 pre-alpha*/

#include <Wire.h>

const int SLAVE_MASTER = 1;
const int SLAVE_MegaA = 2;
const int SLAVE_MegaB = 3;
const int SLAVE_Display = 4;

/*Definations*/
    /*Wing B*/
    #define wingB_fader7 A0
    #define wingB_fader8 A1
    #define wingB_fader9 A2
    #define wingB_fader10 A3
    #define wingB_fader11 A4
    #define wingB_fader12 A5
    #define wingB_fader19 A6
    #define wingB_fader20 A7
    #define wingB_fader21 A8
    #define wingB_fader22 A9
    #define wingB_fader23 A10
    #define wingB_fader24 A11

    #define wingB_faderLED7 2
    #define wingB_faderLED8 3
    #define wingB_faderLED9 4
    #define wingB_faderLED10 5
    #define wingB_faderLED11 6
    #define wingB_faderLED12 7
    #define wingB_faderLED19 8
    #define wingB_faderLED20 9
    #define wingB_faderLED21 10
    #define wingB_faderLED22 11
    #define wingB_faderLED23 12
    #define wingB_faderLED24 13

    #define wingCMD_fader_A A12
    #define wingCMD_fader_B A13
    #define wingCMD_fader_Sequencer A14
    #define wingCMD_fader_Aux A15

    #define wingB_button7 14
    #define wingB_button8 15
    #define wingB_button9 16
    #define wingB_button10 17
    #define wingB_button11 18
    #define wingB_button12 19

    #define wingB_button_A 22
    #define wingB_button_B 23
    #define wingB_button_Sequencer 24
    #define wingB_button_Aux 25

    #define wingB_button_ChaserMode 26
    #define wingB_button_ChaserModeUp 27
    #define wingB_button_ChaserModeDown 28
    #define wingB_button_ChaserModeStop 29
    #define wingB_button_ChaserModeStart 30

/*Variables*/
    int valf7 = 0;
    int valf8 = 0;
    int valf9 = 0;
    int valf10 = 0;
    int valf11 = 0;
    int valf12 = 0;
    int valf19 = 0;
    int valf20 = 0;
    int valf21 = 0;
    int valf22 = 0;
    int valf23 = 0;
    int valf24 = 0;

    int valfA = 0;
    int valfB = 0;
    int valfSequencer = 0;
    int valfAux = 0;
    
    int lastf7 = 0;
    int lastf8 = 0;
    int lastf9 = 0;
    int lastf10 = 0;
    int lastf11 = 0;
    int lastf12 = 0;
    int lastf19 = 0;
    int lastf20 = 0;
    int lastf21 = 0;
    int lastf22 = 0;
    int lastf23 = 0;
    int lastf24 = 0;
    
    int lastfA = 0;
    int lastfB = 0;
    int lastfSequencer = 0;
    int lastfAux = 0;

    int valb7 = 0;
    int valb8 = 0;
    int valb9 = 0;
    int valb10 = 0;
    int valb11 = 0;
    int valb12 = 0;

    int valbA = 0;
    int valbB = 0;
    int valbSequencer = 0;
    int valbAux = 0;

    int valbChaserMode = 0;
    int valbChaserModeUp = 0;
    int valbChaserModeDown = 0;
    int valbChaserModeStop = 0;
    int valbChaserModeGo = 0;
    
    int lastb7 = 0;
    int lastb8 = 0;
    int lastb9 = 0;
    int lastb10 = 0;
    int lastb11 = 0;
    int lastb12 = 0;
    int lastbA = 0;
    int lastbB = 0;
    int lastbSequencer = 0;
    int lastbAux = 0;
    int lastbChaserMode = 0;
    int lastbChaserModeUp = 0;
    int lastbChaserModeDown = 0;
    int lastbChaserModeStop = 0;
    int lastbChaserModeGo = 0;

/*Send Count*/
    int sendcount = 0;

/*Unions*/
    union midiData_MegaB_A
    {
    struct
    {
        int midi_wingB_fader7;
        int midi_wingB_fader8;
        int midi_wingB_fader9;
        int midi_wingB_fader10;
        int midi_wingB_fader11;
        int midi_wingB_fader12;
        int midi_wingB_fader19;
        int midi_wingB_fader20;
        int midi_wingB_fader21;
        int midi_wingB_fader22;
        int midi_wingB_fader23;
        int midi_wingB_fader24;

        int midi_wingCMD_faderA;
        int midi_wingCMD_faderB;
    }
    byte bytes[28];
    };
    midiData_MegaB_A DataA;

    union midiData_MegaB_B
    {
    struct
    {
        int midi_wingCMD_faderSequencer;
        int midi_wingCMD_faderAux;

        int midi_wingB_button7;
        int midi_wingB_button8;
        int midi_wingB_button9;
        int midi_wingB_button10;
        int midi_wingB_button11;
        int midi_wingB_button12;

        int midi_wingB_buttonA;
        int midi_wingB_buttonB;
        int midi_wingB_buttonSequencer;
        int midi_wingB_buttonAux;

        int midi_wingB_buttonChaserMode;
        int midi_wingB_buttonChaserModeUp;
        int midi_wingB_buttonChaserModeDown;
    }
    byte bytes[30];
    };
    midiData_MegaB_B DataB;

    union midiData_MegaB_C
    {
    struct
    {
        int midi_wingB_buttonChaserModeStop;
        int midi_wingB_buttonChaserModeGo;
    }
    byte bytes[4];
    };
    midiData_MegaB_C DataC;

void setup()
{
    Serial.begin(115200);
    Wire.begin(SLAVE_MegaB);
    Wire.setClock(400000);
    Wire.onRequest(sendData);

    pinMode(wingB_button7, INPUT_PULLUP);
    pinMode(wingB_button8, INPUT_PULLUP);
    pinMode(wingB_button9, INPUT_PULLUP);
    pinMode(wingB_button10, INPUT_PULLUP);
    pinMode(wingB_button11, INPUT_PULLUP);
    pinMode(wingB_button12, INPUT_PULLUP);

    pinMode(wingB_button_A, INPUT_PULLUP);
    pinMode(wingB_button_B, INPUT_PULLUP);
    pinMode(wingB_button_Sequencer, INPUT_PULLUP);
    pinMode(wingB_button_Aux, INPUT_PULLUP);

    pinMode(wingB_button_ChaserMode, INPUT_PULLUP);
    pinMode(wingB_button_ChaserModeUp, INPUT_PULLUP);
    pinMode(wingB_button_ChaserModeDown, INPUT_PULLUP);
    pinMode(wingB_button_ChaserModeStop, INPUT_PULLUP);
    pinMode(wingB_button_ChaserModeStart, INPUT_PULLUP);

    pinMode(wingB_faderLED24, OUTPUT);
    pinMode(wingB_faderLED23, OUTPUT);
    pinMode(wingB_faderLED22, OUTPUT);
    pinMode(wingB_faderLED21, OUTPUT);
    pinMode(wingB_faderLED20, OUTPUT);
    pinMode(wingB_faderLED19, OUTPUT);
    pinMode(wingB_faderLED12, OUTPUT);
    pinMode(wingB_faderLED11, OUTPUT);
    pinMode(wingB_faderLED10, OUTPUT);
    pinMode(wingB_faderLED9, OUTPUT);
    pinMode(wingB_faderLED8, OUTPUT);
    pinMode(wingB_faderLED7, OUTPUT);
}

void loop()
{
    valb7 = digitalRead(wingB_button7);
    valb8 = digitalRead(wingB_button8);
    valb9 = digitalRead(wingB_button9);
    valb10 = digitalRead(wingB_button10);
    valb11 = digitalRead(wingB_button11);
    valb12 = digitalRead(wingB_button12);

    if(valb7 != lastb7){
        DataB.midi_wingB_button7 = map(valb7, 0, 1, 127, 0);
        lastb7 = valb7;
    }
    if(valb8 != lastb8){
        DataB.midi_wingB_button8 = map(valb8, 0, 1, 127, 0);
        lastb8 = valb8;
    }
    if(valb9 != lastb9){
        DataB.midi_wingB_button9 = map(valb9, 0, 1, 127, 0);
        lastb9 = valb9;
    }
    if(valb10 != lastb10){
        DataB.midi_wingB_button10 = map(valb10, 0, 1, 127, 0);
        lastb10 = valb10;
    }
}