/*Project: illumination2PRO*/
/*Device: Arduino_Mega.A*/
/*Author: Liam Clark */
/*Version: 2.0.0 pre-alpha*/

#include <Wire.h>

const int SLAVE_MASTER = 1;
const int SLAVE_MegaA = 2;
const int SLAVE_MegaB = 3;
const int SLAVE_Display = 4;

/*Definations*/
    /*Wing A*/
    #define wingA_fader1 A0
    #define wingA_fader2 A1
    #define wingA_fader3 A2
    #define wingA_fader4 A3
    #define wingA_fader5 A4
    #define wingA_fader6 A5
    #define wingA_fader13 A6
    #define wingA_fader14 A7
    #define wingA_fader15 A8
    #define wingA_fader16 A9
    #define wingA_fader17 A10
    #define wingA_fader18 A11

    #define wingA_faderLED1 2
    #define wingA_faderLED2 3
    #define wingA_faderLED3 4
    #define wingA_faderLED4 5
    #define wingA_faderLED5 6
    #define wingA_faderLED6 7
    #define wingA_faderLED13 8
    #define wingA_faderLED14 9
    #define wingA_faderLED15 10
    #define wingA_faderLED16 11
    #define wingA_faderLED17 12
    #define wingA_faderLED18 13

    #define wingA_fader_fade A12
    #define wingA_fader_speed A13

    #define wingA_button1 14
    #define wingA_button2 15
    #define wingA_button3 16
    #define wingA_button4 17
    #define wingA_button5 18
    #define wingA_button6 19

    #define wingA_button_delete 22
    #define wingA_button_store 23
    #define wingA_button_modify 24

    #define wingA_button_sound_up 25
    #define wingA_button_sound_down 26

    #define wingA_button_flash_mode 27
    #define wingA_button_flash_up 28
    #define wingA_button_flash_down 29

/*Variables*/
    int valf1 = 0;
    int valf2 = 0;
    int valf3 = 0;
    int valf4 = 0;
    int valf5 = 0;
    int valf6 = 0;
    int valf13 = 0;
    int valf14 = 0;
    int valf15 = 0;
    int valf16 = 0;
    int valf17 = 0;
    int valf18 = 0;

    int valffade = 0;
    int valfspeed = 0;

    int lastf1 = 0;
    int lastf2 = 0;
    int lastf3 = 0;
    int lastf4 = 0;
    int lastf5 = 0;
    int lastf6 = 0;
    int lastf13 = 0;
    int lastf14 = 0;
    int lastf15 = 0;
    int lastf16 = 0;
    int lastf17 = 0;
    int lastf18 = 0;

    int lastffade = 0;
    int lastfspeed = 0;

    int valb1 = 0;
    int valb2 = 0;
    int valb3 = 0;
    int valb4 = 0;
    int valb5 = 0;
    int valb6 = 0;

    int valbdelete = 0;
    int valbstore = 0;
    int valbmodify = 0;

    int valbsoundup = 0;
    int valbsounddown = 0;

    int valbflashmode = 0;
    int valbflashup = 0;
    int valbflashdown = 0;

/*Send Count*/
    int sendcount = 0;

/*Unions*/
    union midiData_MegaA_A
    {
    struct
    {
        int midi_wingA_fader1;
        int midi_wingA_fader2;
        int midi_wingA_fader3;
        int midi_wingA_fader4;
        int midi_wingA_fader5;
        int midi_wingA_fader6;
        int midi_wingA_fader13;
        int midi_wingA_fader14;
        int midi_wingA_fader15;
        int midi_wingA_fader16;
        int midi_wingA_fader17;
        int midi_wingA_fader18;

        int midi_wingCMD_fade;
        int midi_wingCMD_speed;

        int midi_wingCMD_soundup;
        int midi_wingCMD_sounddown;
    }
    byte bytes[32];
    };

    union midiData_MegaA_B
    {
    struct
    {
        int midi_wingA_button1;
        int midi_wingA_button2;
        int midi_wingA_button3;
        int midi_wingA_button4;
        int midi_wingA_button5;
        int midi_wingA_button6;

        int midi_wingA_button_delete;
        int midi_wingA_button_store;
        int midi_wingA_button_modify;

        int midi_wingA_button_flashmode;
        int midi_wingA_button_flashup;
        int midi_wingA_button_flashdown;
    }
    byte bytes[24];
    };

void setup()
{
    Serial.begin(115200);
    Wire.begin(SLAVE_MegaA);
    Wire.setClock(400000);
    Wire.onRequest(sendData);

    pinMode(wingA_button1, INPUT_PULLUP);
    pinMode(wingA_button2, INPUT_PULLUP);
    pinMode(wingA_button3, INPUT_PULLUP);
    pinMode(wingA_button4, INPUT_PULLUP);
    pinMode(wingA_button5, INPUT_PULLUP);
    pinMode(wingA_button6, INPUT_PULLUP);

    pinMode(wingA_button_delete, INPUT_PULLUP);
    pinMode(wingA_button_store, INPUT_PULLUP);
    pinMode(wingA_button_modify, INPUT_PULLUP);

    pinMode(wingA_button_sound_up, INPUT_PULLUP);
    pinMode(wingA_button_sound_down, INPUT_PULLUP);

    pinMode(wingA_button_flash_mode, INPUT_PULLUP);
    pinMode(wingA_button_flash_up, INPUT_PULLUP);
    pinMode(wingA_button_flash_down, INPUT_PULLUP);

    pinMode(wingA_faderLED1, OUTPUT);
    pinMode(wingA_faderLED2, OUTPUT);
    pinMode(wingA_faderLED3, OUTPUT);
    pinMode(wingA_faderLED4, OUTPUT);
    pinMode(wingA_faderLED5, OUTPUT);
    pinMode(wingA_faderLED6, OUTPUT);

    pinMode(wingA_faderLED13, OUTPUT);
    pinMode(wingA_faderLED14, OUTPUT);
    pinMode(wingA_faderLED15, OUTPUT);
    pinMode(wingA_faderLED16, OUTPUT);
    pinMode(wingA_faderLED17, OUTPUT);
    pinMode(wingA_faderLED18, OUTPUT);
}

void loop()
{
    
}