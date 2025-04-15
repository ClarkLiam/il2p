/*Project: IL2P*/
/*Device: Mega (1)*/
/*Author: Liam Clark */
/*Version: 1.8.3 pre-alpha*/

#include <Wire.h>    
const int SLAVE_UNO = 1;
const int SLAVE_Mega1 = 2;
const int SLAVE_Mega2 = 3;

/*Definations*/
    /*Pins*/
    #define fader1 A0
    #define fader2 A1
    #define fader3 A2
    #define fader4 A3
    #define fader5 A4
    #define fader6 A5

    #define fader13 A6
    #define fader14 A7
    #define fader15 A8
    #define fader16 A9
    #define fader17 A10
    #define fader18 A11

    #define faderfade A12
    #define faderspeed A13

    #define button1 14
    #define button2 15
    #define button3 16
    #define button4 17
    #define button5 18
    #define button6 19

    #define buttondelete 22
    #define buttonstore 23
    #define buttonmodify 24

    #define buttonsoundup 25
    #define buttonsounddown 26

    #define buttonflashmode 27
    #define buttonflashup 28
    #define buttonflashdown 29

    #define SDALink 20
    #define SCLLink 21

    #define ledfader1 2
    #define ledfader2 3
    #define ledfader3 4
    #define ledfader4 5
    #define ledfader5 6
    #define ledfader6 7

    #define ledfader13 8
    #define ledfader14 9
    #define ledfader15 10
    #define ledfader16 11
    #define ledfader17 12
    #define ledfader18 13

/*Variables*/
    /*Button States*/
    int stateb1 = 0;
    int stateb2 = 0;
    int stateb3 = 0;
    int stateb4 = 0;
    int stateb5 = 0;
    int stateb6 = 0;

    int statebdelete = 0;
    int statebstore = 0;
    int statebmodify = 0;

    int statebsoundup = 0;
    int statebsounddown = 0;

    int statebflashmode = 0;
    int statebflashup = 0;
    int statebflashdown = 0;

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

    int lastb1 = 0;
    int lastb2 = 0;
    int lastb3 = 0;
    int lastb4 = 0;
    int lastb5 = 0;
    int lastb6 = 0;

    int lastbdelete = 0;
    int lastbstore = 0;
    int lastbmodify = 0;

    int lastbsoundup = 0;
    int lastbsounddown = 0;

    int lastbflashmode = 0;
    int lastbflashup = 0;
    int lastbflashdown = 0;

    /*Fader Values*/
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

    /*LEDs*/
    int ledstate1 = 0;
    int ledstate2 = 0;
    int ledstate3 = 0;
    int ledstate4 = 0;
    int ledstate5 = 0;
    int ledstate6 = 0;

    int ledstate13 = 0;
    int ledstate14 = 0;
    int ledstate15 = 0;
    int ledstate16 = 0;
    int ledstate17 = 0;
    int ledstate18 = 0;

    /*SendCount*/
    int sendcount = 0;

/*Unions*/
    union data_FaderA
    {
    struct
    {
        int typeFader;

        int midif1;
        int midif2;
        int midif3;
        int midif4;
        int midif5;
        int midif6;

        int midif13;
        int midif14;
        int midif15;
        int midif16;
        int midif17;
        int midif18;

        int midiffade;
        int midifspeed;
    };
    byte bytes[30];
    };
    data_FaderA megaafader;

    union data_OtherA
    {
    struct
    {
        int typeOther;


        int midib1;
        int midib2;
        int midib3;
        int midib4;
        int midib5;
        int midib6;

        int midibdelete;
        int midibstore;
        int midibmodify;

        int midibsoundup;
        int midibsounddown;

        int midibflashmode;
        int midibflashup;
        int midibflashdown;

        int waste;

    };
    byte bytes[32];
    };
    data_OtherA megaaother;

void setup()
{
    /*Serial*/
        Serial.begin(115200);
    /*Wire*/
        Wire.begin(SLAVE_Mega1);    // Join I2C bus with address #2
        Wire.setClock(400000); // Set I2C clock speed to 400kHz
        Wire.onRequest(sendData);
    /*pinMode*/
        pinMode(button1, INPUT_PULLUP);
        pinMode(button2, INPUT_PULLUP);
        pinMode(button3, INPUT_PULLUP);
        pinMode(button4, INPUT_PULLUP);
        pinMode(button5, INPUT_PULLUP);
        pinMode(button6, INPUT_PULLUP);

        pinMode(buttondelete, INPUT_PULLUP);
        pinMode(buttonstore, INPUT_PULLUP);
        pinMode(buttonmodify, INPUT_PULLUP);

        pinMode(buttonsoundup, INPUT_PULLUP);
        pinMode(buttonsounddown, INPUT_PULLUP);

        pinMode(buttonflashmode, INPUT_PULLUP);
        pinMode(buttonflashup, INPUT_PULLUP);
        pinMode(buttonflashdown, INPUT_PULLUP);

        pinMode(ledfader1, OUTPUT);
        pinMode(ledfader2, OUTPUT);
        pinMode(ledfader3, OUTPUT);
        pinMode(ledfader4, OUTPUT);
        pinMode(ledfader5, OUTPUT);
        pinMode(ledfader6, OUTPUT);

        pinMode(ledfader13, OUTPUT);
        pinMode(ledfader14, OUTPUT);
        pinMode(ledfader15, OUTPUT);
        pinMode(ledfader16, OUTPUT);
        pinMode(ledfader17, OUTPUT);
        pinMode(ledfader18, OUTPUT);

        /*Union Management*/
            megaafader.typeFader = 1;
            megaaother.typeOther = 2;
}

void loop()
{
    for(int i=0; i<100; i++){
        megaaother.midib1 = i;
        megaaother.midib2 = i+1;
        megaaother.midib3 = i+2;
        megaaother.midib4 = i+3;
        megaaother.midib5 = i+4;
        megaaother.midib6 = i+5;
        megaaother.midibdelete = i+6;
        megaaother.midibstore = i+7;
        megaaother.midibmodify = i+8;
        megaaother.midibsoundup = i+9;
        megaaother.midibsounddown = i+10;
        megaaother.midibflashmode = i+11;
        megaaother.midibflashup = i+12;
        megaaother.midibflashdown = i+13;
        megaaother.waste = i+14;
        megaafader.midif1 = i+15;
        megaafader.midif2 = i+16;
        megaafader.midif3 = i+17;
        megaafader.midif4 = i+18;
        megaafader.midif5 = i+19;
        megaafader.midif6 = i+20;
        megaafader.midif13 = i+21;
        megaafader.midif14 = i+22;
        megaafader.midif15 = i+23;
        megaafader.midif16 = i+24;
        megaafader.midif17 = i+25;
        megaafader.midif18 = i+26;
        megaafader.midiffade = i+27;
        megaafader.midifspeed = i+28;
        delay(100); 
    }
}

void sendData()
{
    if(sendcount == 0)
    {
        Wire.write(megaafader.bytes, sizeof(megaafader));
        sendcount = 1;
    }else{
        Wire.write(megaaother.bytes, sizeof(megaaother));
        sendcount = 0;
    }
}

void getData()
{

}