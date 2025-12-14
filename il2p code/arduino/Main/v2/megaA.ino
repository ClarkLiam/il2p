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
    midiData_MegaA_A DataA;

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
    midiData_MegaA_B DataB;

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
    valb1 = digitalRead(wingA_button1);
    valb2 = digitalRead(wingA_button2);
    valb3 = digitalRead(wingA_button3);
    valb4 = digitalRead(wingA_button4);
    valb5 = digitalRead(wingA_button5);
    valb6 = digitalRead(wingA_button6);
    valbdelete = digitalRead(wingA_button_delete);
    valbstore = digitalRead(wingA_button_store);
    valbmodify = digitalRead(wingA_button_modify);
    valbsoundup = digitalRead(wingA_button_sound_up);
    valbsounddown = digitalRead(wingA_button_sound_down);
    valbflashmode = digitalRead(wingA_button_flash_mode);
    valbflashup = digitalRead(wingA_button_flash_up);
    valbflashdown = digitalRead(wingA_button_flash_down);

    if(valb1 != lastb1){
        DataA.midi_wingA_button1 = map(valb1, 0, 1, 127, 0);
        lastb1 = valb1;
    }
    if(valb2 != lastb2){
        DataA.midi_wingA_button2 = map(valb2, 0, 1, 127, 0);
        lastb2 = valb2;
    }
    if(valb3 != lastb3){
        DataA.midi_wingA_button3 = map(valb3, 0, 1, 127, 0);
        lastb3 = valb3;
    }
    if(valb4 != lastb4){
        DataA.midi_wingA_button4 = map(valb4, 0, 1, 127, 0);
        lastb4 = valb4;
    }
    if(valb5 != lastb5){
        DataA.midi_wingA_button5 = map(valb5, 0, 1, 127, 0);
        lastb5 = valb5;
    }
    if(valb6 != lastb6){
        DataA.midi_wingA_button6 = map(valb6, 0, 1, 127, 0);
        lastb6 = valb6;
    }
    if(valbdelete != lastbdelete){
        DataA.midi_wingA_button_delete = map(valbdelete, 0, 1, 127, 0);
        lastbdelete = valbdelete;
    }
    if(valbstore != lastbstore){
        DataA.midi_wingA_button_store = map(valbstore, 0, 1, 127, 0);
        lastbstore = valbstore;
    }
    if(valbmodify != lastbmodify){
        DataA.midi_wingA_button_modify = map(valbmodify, 0, 1, 127, 0);
        lastbmodify = valbmodify;
    }
    if(valbsoundup != lastbsoundup){
        DataA.midi_wingCMD_soundup = map(valbsoundup, 0, 1, 127, 0);
        lastbsoundup = valbsoundup;
    }
    if(valbsounddown != lastbsounddown){
        DataA.midi_wingCMD_sounddown = map(valbsounddown, 0, 1, 127, 0);
        lastbsounddown = valbsounddown;
    }
    if(valbflashmode != lastbflashmode){
        DataB.midi_wingA_button_flashmode = map(valbflashmode, 0, 1, 127, 0);
        lastbflashmode = valbflashmode;
    }
    if(valbflashup != lastbflashup){
        DataB.midi_wingA_button_flashup = map(valbflashup, 0, 1, 127, 0);
        lastbflashup = valbflashup;
    }
    if(valbflashdown != lastbflashdown){
        DataB.midi_wingA_button_flashdown = map(valbflashdown, 0, 1, 127, 0);
        lastbflashdown = valbflashdown;
    }

    valf1 = analogRead(wingA_fader1);
    if(valf1 != lastf1){
        DataA.midi_wingA_fader1 = map(valf1, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED1, DataA.midi_wingA_fader1 / 4);
        lastf1 = valf1;
    }
    valf2 = analogRead(wingA_fader2);
    if(valf2 != lastf2){
        DataA.midi_wingA_fader2 = map(valf2, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED2, DataA.midi_wingA_fader2 / 4);
        lastf2 = valf2;
    }
    valf3 = analogRead(wingA_fader3);
    if(valf3 != lastf3){
        DataA.midi_wingA_fader3 = map(valf3, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED3, DataA.midi_wingA_fader3 / 4);
        lastf3 = valf3;
    }
    valf4 = analogRead(wingA_fader4);
    if(valf4 != lastf4){
        DataA.midi_wingA_fader4 = map(valf4, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED4, DataA.midi_wingA_fader4 / 4);
        lastf4 = valf4;
    }
    valf5 = analogRead(wingA_fader5);
    if(valf5 != lastf5){
        DataA.midi_wingA_fader5 = map(valf5, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED5, DataA.midi_wingA_fader5 / 4);
        lastf5 = valf5;
    }
    valf6 = analogRead(wingA_fader6);
    if(valf6 != lastf6){
        DataA.midi_wingA_fader6 = map(valf6, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED6, DataA.midi_wingA_fader6 / 4);
        lastf6 = valf6;
    }
    valf13 = analogRead(wingA_fader13);
    if(valf13 != lastf13){
        DataA.midi_wingA_fader13 = map(valf13, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED13, DataA.midi_wingA_fader13 / 4);
        lastf13 = valf13;
    }
    valf14 = analogRead(wingA_fader14);
    if(valf14 != lastf14){
        DataA.midi_wingA_fader14 = map(valf14, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED14, DataA.midi_wingA_fader14 / 4);
        lastf14 = valf14;
    }
    valf15 = analogRead(wingA_fader15);
    if(valf15 != lastf15){
        DataA.midi_wingA_fader15 = map(valf15, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED15, DataA.midi_wingA_fader15 / 4);
        lastf15 = valf15;
    }
    valf16 = analogRead(wingA_fader16);
    if(valf16 != lastf16){
        DataA.midi_wingA_fader16 = map(valf16, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED16, DataA.midi_wingA_fader16 / 4);
        lastf16 = valf16;
    }
    valf17 = analogRead(wingA_fader17);
    if(valf17 != lastf17){
        DataA.midi_wingA_fader17 = map(valf17, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED17, DataA.midi_wingA_fader17 / 4);
        lastf17 = valf17;
    }
    valf18 = analogRead(wingA_fader18);
    if(valf18 != lastf18){
        DataA.midi_wingA_fader18 = map(valf18, 1023, 0, 0, 127);
        analogWrite(wingA_faderLED18, DataA.midi_wingA_fader18 / 4);
        lastf18 = valf18;
    }
    valffade = analogRead(wingA_fader_fade);
    if(valffade != lastffade){
        DataA.midi_wingCMD_fade = map(valffade, 1023, 0, 0, 127);
        lastffade = valffade;   
    }
    valfspeed = analogRead(wingA_fader_speed);
    if(valfspeed != lastfspeed){
        DataA.midi_wingCMD_speed = map(valfspeed, 1023, 0, 0, 127);
        lastfspeed = valfspeed;
    }
}

void sendDatat(){
    if sendcount == 0 {
        Wire.write(DataA.bytes, sizeof(DataA.bytes));
        sendcount = 1;
    } else {
        Wire.write(DataB.bytes, sizeof(DataB.bytes));
        sendcount = 0;
    }
}