/*Project: IL2P*/
/*Device: Elegoo_Mega1*/
/*Author: Liam Clark */
/*Version: 1.5*/

/*Libraries*/  
    #include <Wire.h>
    const int SLAVE_Mega1 = 2;

/*Definations*/
    /*PINS*/
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

    #define button1 14
    #define button2 15
    #define button3 16
    #define button4 17
    #define button5 18
    #define button6 19

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

    int lastb1 = 0;
    int lastb2 = 0;
    int lastb3 = 0;
    int lastb4 = 0;
    int lastb5 = 0;
    int lastb6 = 0;

    int valb1 = 0;
    int valb2 = 0;
    int valb3 = 0;
    int valb4 = 0;
    int valb5 = 0;
    int valb6 = 0;

    /*Faders*/
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


/*MIDI Transfer Variables*/
    union data_A
        {
        struct
        {
            int midib1;
            int midib2;
            int midib3;
            int midib4;
            int midib5;
            int midib6;

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

        };
        byte bytes[36];
        };
        data_A megaa;


void setup()
{
    /*Serial*/
        Serial.begin(9600);
    /*Wire*/
        Wire.begin(SLAVE_Mega1);
        Wire.onRequest(requestEvent);
    /*pinMode*/
        pinMode(button1, INPUT_PULLUP);
        pinMode(button2, INPUT_PULLUP);
        pinMode(button3, INPUT_PULLUP);
        pinMode(button4, INPUT_PULLUP);
        pinMode(button5, INPUT_PULLUP);
        pinMode(button6, INPUT_PULLUP);

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

        if(valb1 != lastb1){
            if(stateb1 != 0){
                stateb1 = 0;
            }else{
                stateb1 = 1;
            }
            megaa.midib1 = map(stateb1, 0, 1, 0, 127);
            lastb1 = valb1;
        }
        if(valb2 != lastb2){
            if(stateb2 != 0){
                stateb2 = 0;
            }else{
                stateb2 = 1;
            }
            megaa.midib2 = map(stateb2, 0, 1, 0, 127);
            lastb2 = valb2;
        }
        if(valb3 != lastb3){
            if(stateb3 != 0){
                stateb3 = 0;
            }else{
                stateb3 = 1;
            }
            megaa.midib3 = map(stateb3, 0, 1, 0, 127);
            lastb3 = valb3;
        }
        if(valb4 != lastb4){
            if(stateb4 != 0){
                stateb4 = 0;
            }else{
                stateb4 = 1;
            }
            megaa.midib4 = map(stateb4, 0, 1, 0, 127);
            lastb4 = valb4;
        }
        if(valb5 != lastb5){
            if(stateb5 != 0){
                stateb5 = 0;
            }else{
                stateb5 = 1;
            }
            megaa.midib5 = map(stateb5, 0, 1, 0, 127);
            lastb5 = valb5;
        }
        if(valb6 != lastb6){
            if(stateb6 != 0){
                stateb6 = 0;
            }else{
                stateb6 = 1;
            }
            megaa.midib6 = map(stateb6, 0, 1, 0, 127);
            lastb6 = valb6;
        }
        


    /*Read Faders*/
        //read faders and map to 0-127
        //send to uno
        //update led
        valf1 = analogRead(fader1);
        valf2 = analogRead(fader2);
        valf3 = analogRead(fader3);
        valf4 = analogRead(fader4);
        valf5 = analogRead(fader5);
        valf6 = analogRead(fader6);

        valf13 = analogRead(fader13);
        valf14 = analogRead(fader14);
        valf15 = analogRead(fader15);
        valf16 = analogRead(fader16);
        valf17 = analogRead(fader17);
        valf18 = analogRead(fader18);

        if(valf1 != lastf1){
            megaa.midif1 = map(valf1, 1023, 0, 0, 127);
            analogWrite(ledfader1, megaa.midif1 / 4);
            lastf1 = valf1;
        }
        if(valf2 != lastf2){
            megaa.midif2 = map(valf2, 1023, 0, 0, 127);
            analogWrite(ledfader2, megaa.midif2 / 4);
            lastf2 = valf2;
        }
        if(valf3 != lastf3){
            megaa.midif3 = map(valf3, 1023, 0, 0, 127);
            analogWrite(ledfader3, megaa.midif3 / 4);
            lastf3 = valf3;
        }
        if(valf4 != lastf4){
            megaa.midif4 = map(valf4, 1023, 0, 0, 127);
            analogWrite(ledfader4, megaa.midif4 / 4);
            lastf4 = valf4;
        }
        if(valf5 != lastf5){
            megaa.midif5 = map(valf5, 1023, 0, 0, 127);
            analogWrite(ledfader5, megaa.midif5 / 4);
            lastf5 = valf5;
        }
        if(valf6 != lastf6){
            megaa.midif6 = map(valf6, 1023, 0, 0, 127);
            analogWrite(ledfader6, megaa.midif6 / 4);
            lastf6 = valf6;
        }

        if(valf13 != lastf13){
            megaa.midif13 = map(valf13, 1023, 0, 0, 127);
            analogWrite(ledfader13, megaa.midif13 / 4);
            lastf13 = valf13;
        }
        if(valf14 != lastf14){
            megaa.midif14 = map(valf14, 1023, 0, 0, 127);
            analogWrite(ledfader14, megaa.midif14 / 4);
            lastf14 = valf14;
        }
        if(valf15 != lastf15){
            megaa.midif15 = map(valf15, 1023, 0, 0, 127);
            analogWrite(ledfader15, megaa.midif15 / 4);
            lastf15 = valf15;
        }
        if(valf16 != lastf16){
            megaa.midif16 = map(valf16, 1023, 0, 0, 127);
            analogWrite(ledfader16, megaa.midif16 / 4);
            lastf16 = valf16;
        }
        if(valf17 != lastf17){
            megaa.midif17 = map(valf17, 1023, 0, 0, 127);
            analogWrite(ledfader17, megaa.midif17 / 4);
            lastf17 = valf17;
        }
        if(valf18 != lastf18){
            megaa.midif18 = map(valf18, 1023, 0, 0, 127);
            analogWrite(ledfader18, megaa.midif18 / 4);
            lastf18 = valf18;
        }

}

void requestEvent()
{
 Wire.write(megaa.bytes, sizeof(megaa));
}
