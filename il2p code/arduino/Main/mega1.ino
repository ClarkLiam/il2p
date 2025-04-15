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
    /*Read Buttons*/
        valb1 = digitalRead(button1);
        valb2 = digitalRead(button2);
        valb3 = digitalRead(button3);
        valb4 = digitalRead(button4);
        valb5 = digitalRead(button5);
        valb6 = digitalRead(button6);
        valbdelete = digitalRead(buttondelete);
        valbstore = digitalRead(buttonstore);
        valbmodify = digitalRead(buttonmodify);
        valbsoundup = digitalRead(buttonsoundup);
        valbsounddown = digitalRead(buttonsounddown);
        valbflashmode = digitalRead(buttonflashmode);
        valbflashup = digitalRead(buttonflashup);
        valbflashdown = digitalRead(buttonflashdown);

        if(valb1 != lastb1){
            if(stateb1 != 0){
                stateb1 = 0;
            }else{
                stateb1 = 1;
            }
            megaaother.midib1 = map(stateb1, 0, 1, 0, 127);
            lastb1 = valb1;
        }
        if(valb2 != lastb2){
            if(stateb2 != 0){
                stateb2 = 0;
            }else{
                stateb2 = 1;
            }
            megaaother.midib2 = map(stateb2, 0, 1, 0, 127);
            lastb2 = valb2;
        }
        if(valb3 != lastb3){
            if(stateb3 != 0){
                stateb3 = 0;
            }else{
                stateb3 = 1;
            }
            megaaother.midib3 = map(stateb3, 0, 1, 0, 127);
            lastb3 = valb3;
        }
        if(valb4 != lastb4){
            if(stateb4 != 0){
                stateb4 = 0;
            }else{
                stateb4 = 1;
            }
            megaaother.midib4 = map(stateb4, 0, 1, 0, 127);
            lastb4 = valb4;
        }
        if(valb5 != lastb5){
            if(stateb5 != 0){
                stateb5 = 0;
            }else{
                stateb5 = 1;
            }
            megaaother.midib5 = map(stateb5, 0, 1, 0, 127);
            lastb5 = valb5;
        }
        if(valb6 != lastb6){
            if(stateb6 != 0){
                stateb6 = 0;
            }else{
                stateb6 = 1;
            }
            megaaother.midib6 = map(stateb6, 0, 1, 0, 127);
            lastb6 = valb6;
        }
        if(valbdelete != lastbdelete){
            if(statebdelete != 0){
                statebdelete = 0;
            }else{
                statebdelete = 1;
            }
            megaaother.midibdelete = map(statebdelete, 0, 1, 0, 127);
            lastbdelete = valbdelete;
        }
        if(valbstore != lastbstore){
            if(statebstore != 0){
                statebstore = 0;
            }else{
                statebstore = 1;
            }
            megaaother.midibstore = map(statebstore, 0, 1, 0, 127);
            lastbstore = valbstore;
        }
        if(valbmodify != lastbmodify){
            if(statebmodify != 0){
                statebmodify = 0;
            }else{
                statebmodify = 1;
            }
            megaaother.midibmodify = map(statebmodify, 0, 1, 0, 127);
            lastbmodify = valbmodify;
        }
        if(valbsoundup != lastbsoundup){
            if(statebsoundup != 0){
                statebsoundup = 0;
            }else{
                statebsoundup = 1;
            }
            megaaother.midibsoundup = map(statebsoundup, 0, 1, 0, 127);
            lastbsoundup = valbsoundup;
        }
        if(valbsounddown != lastbsounddown){
            if(statebsounddown != 0){
                statebsounddown = 0;
            }else{
                statebsounddown = 1;
            }
            megaaother.midibsounddown = map(statebsounddown, 0, 1, 0, 127);
            lastbsounddown = valbsounddown;
        }
        if(valbflashmode != lastbflashmode){
            if(statebflashmode != 0){
                statebflashmode = 0;
            }else{
                statebflashmode = 1;
            }
            megaaother.midibflashmode = map(statebflashmode, 0, 1, 0, 127);
            lastbflashmode = valbflashmode;
        }
        if(valbflashup != lastbflashup){
            if(statebflashup != 0){
                statebflashup = 0;
            }else{
                statebflashup = 1;
            }
            megaaother.midibflashup = map(statebflashup, 0, 1, 0, 127);
            lastbflashup = valbflashup;
        }
        if(valbflashdown != lastbflashdown){
            if(statebflashdown != 0){
                statebflashdown = 0;
            }else{
                statebflashdown = 1;
            }
            megaaother.midibflashdown = map(statebflashdown, 0, 1, 0, 127);
            lastbflashdown = valbflashdown;
        }

        
    /*Read Faders*/

        valf1 = analogRead(fader1);
        if(valf1 != lastf1){
            megaafader.midif1 = map(valf1, 1023, 0, 0, 127);
            analogWrite(ledfader1, megaafader.midif1 / 4);
            lastf1 = valf1;
        }
        valf2 = analogRead(fader2);
        if(valf2 != lastf2){
            megaafader.midif2 = map(valf2, 1023, 0, 0, 127);
            analogWrite(ledfader2, megaafader.midif2 / 4);
            lastf2 = valf2;
        }
        valf3 = analogRead(fader3);
        if(valf3 != lastf3){
            megaafader.midif3 = map(valf3, 1023, 0, 0, 127);
            analogWrite(ledfader3, megaafader.midif3 / 4);
            lastf3 = valf3;
        }
        valf4 = analogRead(fader4);
        if(valf4 != lastf4){
            megaafader.midif4 = map(valf4, 1023, 0, 0, 127);
            analogWrite(ledfader4, megaafader.midif4 / 4);
            lastf4 = valf4;
        }
        valf5 = analogRead(fader5);
        if(valf5 != lastf5){
            megaafader.midif5 = map(valf5, 1023, 0, 0, 127);
            analogWrite(ledfader5, megaafader.midif5 / 4);
            lastf5 = valf5;
        }
        valf6 = analogRead(fader6);
        if(valf6 != lastf6){
            megaafader.midif6 = map(valf6, 1023, 0, 0, 127);
            analogWrite(ledfader6, megaafader.midif6 / 4);
            lastf6 = valf6;
        }

        valf13 = analogRead(fader13);
        if(valf13 != lastf13){
            megaafader.midif13 = map(valf13, 1023, 0, 0, 127);
            analogWrite(ledfader13, megaafader.midif13 / 4);
            lastf13 = valf13;
        }
        valf14 = analogRead(fader14);
        if(valf14 != lastf14){
            megaafader.midif14 = map(valf14, 1023, 0, 0, 127);
            analogWrite(ledfader14, megaafader.midif14 / 4);
            lastf14 = valf14;
        }
        valf15 = analogRead(fader15);
        if(valf15 != lastf15){
            megaafader.midif15 = map(valf15, 1023, 0, 0, 127);
            analogWrite(ledfader15, megaafader.midif15 / 4);
            lastf15 = valf15;
        }
        valf16 = analogRead(fader16);
        if(valf16 != lastf16){
            megaafader.midif16 = map(valf16, 1023, 0, 0, 127);
            analogWrite(ledfader16, megaafader.midif16 / 4);
            lastf16 = valf16;
        }
        valf17 = analogRead(fader17);
        if(valf17 != lastf17){
            megaafader.midif17 = map(valf17, 1023, 0, 0, 127);
            analogWrite(ledfader17, megaafader.midif17 / 4);
            lastf17 = valf17;
        }
        valf18 = analogRead(fader18);
        if(valf18 != lastf18){
            megaafader.midif18 = map(valf18, 1023, 0, 0, 127);
            analogWrite(ledfader18, megaafader.midif18 / 4);
            lastf18 = valf18;
        }
        valffade = analogRead(faderfade);
        if(valffade != lastffade){
            megaafader.midiffade = map(valffade, 1023, 0, 0, 127);
            lastffade = valffade;
        }
        valfspeed = analogRead(faderspeed);
        if(valfspeed != lastfspeed){
            megaafader.midifspeed = map(valfspeed, 1023, 0, 0, 127);
            lastfspeed = valfspeed;
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