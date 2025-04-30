/*Project: IL2P*/
/*Device: Mega (2)*/
/*Author: Liam Clark */
/*Version: 1.8.3 pre-alpha*/

#include <Wire.h>    
const int SLAVE_UNO = 1;
const int SLAVE_Mega1 = 2;
const int SLAVE_Mega2 = 3;

/*Definations*/
    /*Pins*/
    #define fader7 A0
    #define fader8 A1
    #define fader9 A2
    #define fader10 A3
    #define fader11 A4
    #define fader12 A5

    #define fader19 A6
    #define fader20 A7
    #define fader21 A8
    #define fader22 A9
    #define fader23 A10
    #define fader24 A11

    #define faderA A12
    #define faderB A13
    #define faderSequencer A14
    #define faderAux A15

    #define button7 14
    #define button8 15
    #define button9 16
    #define button10 17
    #define button11 18
    #define button12 19

    #define buttonA 22
    #define buttonB 23
    #define buttonSequencer 24
    #define buttonAux 25

    #define buttonChaserMode 26
    #define buttonChaserModeUp 27
    #define buttonChaserModeDown 28
    #define buttonChaserModeStop 29
    #define buttonChaserModeStart 30

    #define SDALink 20
    #define SCLLink 21

    #define ledfader7 2
    #define ledfader8 3
    #define ledfader9 4
    #define ledfader10 5
    #define ledfader11 6
    #define ledfader12 7

    #define ledfader19 8
    #define ledfader20 9
    #define ledfader21 10
    #define ledfader22 11
    #define ledfader23 12
    #define ledfader24 13

/*Variables*/
    /*Button States*/
    int stateb7 = 0;
    int stateb8 = 0;
    int stateb9 = 0;
    int stateb10 = 0;
    int stateb11 = 0;
    int stateb12 = 0;

    int statebA = 0;
    int statebB = 0;
    int statebSequencer = 0;
    int statebAux = 0;

    int statebChaserMode = 0;
    int statebChaserModeUp = 0;
    int statebChaserModeDown = 0;
    int statebChaserModeStop = 0;
    int statebChaserModeGo = 0;


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

    /*Fader Values*/
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

    /*LEDs*/
    int ledstate7 = 0;
    int ledstate8 = 0;
    int ledstate9 = 0;
    int ledstate10 = 0;
    int ledstate11 = 0;
    int ledstate12 = 0;

    int ledstate19 = 0;
    int ledstate20 = 0;
    int ledstate21 = 0;
    int ledstate22 = 0;
    int ledstate23 = 0;
    int ledstate24 = 0;

    /*SendCount*/
    int sendcount = 0;

/*Unions*/
    union data_FaderB
    {
    struct
    {
        int typeFader;

        int midif7;
        int midif8;
        int midif9;
        int midif10;
        int midif11;
        int midif12;

        int midif19;
        int midif20;
        int midif21;
        int midif22;
        int midif23;
        int midif24;

        int midifSequencer;
        int midifAux;
    };
    byte bytes[32];
    };
    data_FaderB megabfader;

    union data_OtherB
    {
    struct
    {
        int typeOther;

        int midib7;
        int midib8;
        int midib9;
        int midib10;
        int midib11;
        int midib12;

        int midibA;
        int midibB;
        int midibSequencer;
        int midibAux;

        int midibChaserMode;
        int midibChaserModeUp;
        int midibChaserModeDown;
        int midibChaserModeStop;
        int midibChaserModeStart;

    };
    byte bytes[30];
    };
    data_OtherB megabother;

    union data_SubmasterB
    {
    struct
    {
        int typeSubmaster;

        int midifA;
        int midifB;
    };
    byte bytes[6];
    };
    data_SubmasterB megabsubmaster;

    union data_Display
    {
    struct
    {
        int display_channel;
        int display_flash;
        int display_solo;
        int display_preview;
        int display_DMX;
        int display_segment1;
        int display_segment2;
        int display_segment3;
        int display_segment4;
        int display_segment5;
        int display_segment6;
        int display_chaser;
        int display_prog;
        int display_next;
        int display_groupon;
    };
    byte bytes[30];
    };
    data_Display display;


void setup()
{
    /*Serial*/
        Serial.begin(115200);
    /*Wire*/
        Wire.begin(SLAVE_Mega2);    // Join I2C bus with address #2
        Wire.setClock(400000); // Set I2C clock speed to 400kHz
        Wire.onRequest(sendData);

    /*pinMode*/
        pinMode(button7, INPUT_PULLUP);
        pinMode(button8, INPUT_PULLUP);
        pinMode(button9, INPUT_PULLUP);
        pinMode(button10, INPUT_PULLUP);
        pinMode(button11, INPUT_PULLUP);
        pinMode(button12, INPUT_PULLUP);

        pinMode(buttonA, INPUT_PULLUP);
        pinMode(buttonB, INPUT_PULLUP);
        pinMode(buttonSequencer, INPUT_PULLUP);
        pinMode(buttonAux, INPUT_PULLUP);

        pinMode(buttonChaserMode, INPUT_PULLUP);
        pinMode(buttonChaserModeUp, INPUT_PULLUP);
        pinMode(buttonChaserModeDown, INPUT_PULLUP);
        pinMode(buttonChaserModeStop, INPUT_PULLUP);
        pinMode(buttonChaserModeStart, INPUT_PULLUP);

        pinMode(ledfader7, OUTPUT);
        pinMode(ledfader8, OUTPUT);
        pinMode(ledfader9, OUTPUT);
        pinMode(ledfader10, OUTPUT);
        pinMode(ledfader11, OUTPUT);
        pinMode(ledfader12, OUTPUT);

        pinMode(ledfader19, OUTPUT);
        pinMode(ledfader20, OUTPUT);
        pinMode(ledfader21, OUTPUT);
        pinMode(ledfader22, OUTPUT);
        pinMode(ledfader23, OUTPUT);
        pinMode(ledfader24, OUTPUT);

        /*Union Management*/
            megabfader.typeFader = 1;
            megabother.typeOther = 2;
            megaabsubmaster.typeSubmaster = 3;
}

void loop()
{
    /*Read Buttons*/
        valb7 = digitalRead(button7);
        valb8 = digitalRead(button8);
        valb9 = digitalRead(button9);
        valb10 = digitalRead(button10);
        valb11 = digitalRead(button11);
        valb12 = digitalRead(button12);
        valbA = digitalRead(buttonA);
        valbB = digitalRead(buttonB);
        valbSequencer = digitalRead(buttonSequencer);
        valbAux = digitalRead(buttonAux);
        valbChaserMode = digitalRead(buttonChaserMode);
        valbChaserModeUp = digitalRead(buttonChaserModeUp);
        valbChaserModeDown = digitalRead(buttonChaserModeDown);
        valbChaserModeStop = digitalRead(buttonChaserModeStop);
        valbChaserModeGo = digitalRead(buttonChaserModeStart);

        if(valb7 != lastb7){
            if(stateb7 != 0){
                stateb7 = 0;
            }else{
                stateb7 = 1;
            }
            megabother.midib7 = map(stateb7, 0, 1, 0, 127);
            lastb7 = valb7;
        }
        if(valb8 != lastb8){
            if(stateb8 != 0){
                stateb8 = 0;
            }else{
                stateb8 = 1;
            }
            megabother.midib8 = map(stateb8, 0, 1, 0, 127);
            lastb8 = valb8;
        }
        if(valb9 != lastb9){
            if(stateb9 != 0){
                stateb9 = 0;
            }else{
                stateb9 = 1;
            }
            megabother.midib9 = map(stateb9, 0, 1, 0, 127);
            lastb9 = valb9;
        }
        if(valb10 != lastb10){
            if(stateb10 != 0){
                stateb10 = 0;
            }else{
                stateb10 = 1;
            }
            megabother.midib10 = map(stateb10, 0, 1, 0, 127);
            lastb10 = valb10;
        }
        if(valb11 != lastb11){
            if(stateb11 != 0){
                stateb11 = 0;
            }else{
                stateb11 = 1;
            }
            megabother.midib11 = map(stateb11, 0, 1, 0, 127);
            lastb11 = valb11;
        }
        if(valb12 != lastb12){
            if(stateb12 != 0){
                stateb12 = 0;
            }else{
                stateb12 = 1;
            }
            megabother.midib12 = map(stateb12, 0, 1, 0, 127);
            lastb12 = valb12;
        }

        if(valbA != lastbA){
            if(statebA != 0){
                statebA = 0;
            }else{
                statebA = 1;
            }
            megabother.midibA = map(statebA, 0, 1, 0, 127);
            lastbA = valbA;
        }
        if(valbB != lastbB){
            if(statebB != 0){
                statebB = 0;
            }else{
                statebB = 1;
            }
            megabother.midibB = map(statebB, 0, 1, 0, 127);
            lastbB = valbB;
        }
        if(valbSequencer != lastbSequencer){
            if(statebSequencer != 0){
                statebSequencer = 0;
            }else{
                statebSequencer = 1;
            }
            megabother.midibSequencer = map(statebSequencer, 0, 1, 0, 127);
            lastbSequencer = valbSequencer;
        }
        if(valbAux != lastbAux){
            if(statebAux != 0){
                statebAux = 0;
            }else{
                statebAux = 1;
            }
            megabother.midibAux = map(statebAux, 0, 1, 0, 127);
            lastbAux = valbAux;
        }
        if(valbChaserMode != lastbChaserMode){
            if(statebChaserMode != 0){
                statebChaserMode = 0;
            }else{
                statebChaserMode = 1;
            }
            megabother.midibChaserMode = map(statebChaserMode, 0, 1, 0, 127);
            lastbChaserMode = valbChaserMode;
        }
        if(valbChaserModeUp != lastbChaserModeUp){
            if(statebChaserModeUp != 0){
                statebChaserModeUp = 0;
            }else{
                statebChaserModeUp = 1;
            }
            megabother.midibChaserModeUp = map(statebChaserModeUp, 0, 1, 0, 127);
            lastbChaserModeUp = valbChaserModeUp;
        }
        if(valbChaserModeDown != lastbChaserModeDown){
            if(statebChaserModeDown != 0){
                statebChaserModeDown = 0;
            }else{
                statebChaserModeDown = 1;
            }
            megabother.midibChaserModeDown = map(statebChaserModeDown, 0, 1, 0, 127);
            lastbChaserModeDown = valbChaserModeDown;
        }
        if(valbChaserModeStop != lastbChaserModeStop){
            if(statebChaserModeStop != 0){
                statebChaserModeStop = 0;
            }else{
                statebChaserModeStop = 1;
            }
            megabother.midibChaserModeStop = map(statebChaserModeStop, 0, 1, 0, 127);
            lastbChaserModeStop = valbChaserModeStop;
        }
        if(valbChaserModeGo != lastbChaserModeGo){
            if(statebChaserModeGo != 0){
                statebChaserModeGo = 0;
            }else{
                statebChaserModeGo = 1;
            }
            megabother.midibChaserModeStart = map(statebChaserModeGo, 0, 1, 0, 127);
            lastbChaserModeGo = valbChaserModeGo;
        }
   
    /*Read Faders*/

        valf7 = analogRead(fader7);
        if(valf7 != lastf7){
            megabfader.midif7 = map(valf7, 1023, 0, 0, 127);
            analogWrite(ledfader7, megabfader.midif7 / 4);
            lastf7 = valf7;
        }
        valf8 = analogRead(fader8);
        if(valf8 != lastf8){
            megabfader.midif8 = map(valf8, 1023, 0, 0, 127);
            analogWrite(ledfader8, megabfader.midif8 / 4);
            lastf8 = valf8;
        }
        valf9 = analogRead(fader9);
        if(valf9 != lastf9){
            megabfader.midif9 = map(valf9, 1023, 0, 0, 127);
            analogWrite(ledfader9, megabfader.midif9 / 4);
            lastf9 = valf9;
        }
        valf10 = analogRead(fader10);
        if(valf10 != lastf10){
            megabfader.midif10 = map(valf10, 1023, 0, 0, 127);
            analogWrite(ledfader10, megabfader.midif10 / 4);
            lastf10 = valf10;
        }
        valf11 = analogRead(fader11);
        if(valf11 != lastf11){
            megabfader.midif11 = map(valf11, 1023, 0, 0, 127);
            analogWrite(ledfader11, megabfader.midif11 / 4);
            lastf11 = valf11;
        }
        valf12 = analogRead(fader12);
        if(valf12 != lastf12){
            megabfader.midif12 = map(valf12, 1023, 0, 0, 127);
            analogWrite(ledfader12, megabfader.midif12 / 4);
            lastf12 = valf12;
        }

        valf19 = analogRead(fader19);
        if(valf19 != lastf19){
            megabfader.midif19 = map(valf19, 1023, 0, 0, 127);
            analogWrite(ledfader19, megabfader.midif19 / 4);
            lastf19 = valf19;
        }
        valf20 = analogRead(fader20);
        if(valf20 != lastf20){
            megabfader.midif20 = map(valf20, 1023, 0, 0, 127);
            analogWrite(ledfader20, megabfader.midif20 / 4);
            lastf20 = valf20;
        }
        valf21 = analogRead(fader21);
        if(valf21 != lastf21){
            megabfader.midif21 = map(valf21, 1023, 0, 0, 127);
            analogWrite(ledfader21, megabfader.midif21 / 4);
            lastf21 = valf21;
        }
        valf22 = analogRead(fader22);
        if(valf22 != lastf22){
            megabfader.midif22 = map(valf22, 1023, 0, 0, 127);
            analogWrite(ledfader22, megabfader.midif22 / 4);
            lastf22 = valf22;
        }
        valf23 = analogRead(fader23);
        if(valf23 != lastf23){
            megabfader.midif23 = map(valf23, 1023, 0, 0, 127);
            analogWrite(ledfader23, megabfader.midif23 / 4);
            lastf23 = valf23;
        }
        valf24 = analogRead(fader24);
        if(valf24 != lastf24){
            megabfader.midif24 = map(valf24, 1023, 0, 0, 127);
            analogWrite(ledfader24, megabfader.midif24 / 4);
            lastf24 = valf24;
        }
        valfA = analogRead(faderA);
        if(valfA != lastfA){
            megabsubmaster.midifA = map(valfA, 1023, 0, 0, 127);
            lastfA = valfA;
        }
        valfB = analogRead(faderB);
        if(valfB != lastfB){
            megabsubmaster.midifB = map(valfB, 1023, 0, 0, 127);
            lastfB = valfB;
        }
        valfSequencer = analogRead(faderSequencer);
        if(valfSequencer != lastfSequencer){
            megabsubmaster.midifSequencer = map(valfSequencer, 1023, 0, 0, 127);
            lastfSequencer = valfSequencer;
        }
        valfAux = analogRead(faderAux);
        if(valfAux != lastfAux){
            megabsubmaster.midifAux = map(valfAux, 1023, 0, 0, 127);
            lastfAux = valfAux;
        }

}

void sendData()
{
    if(sendcount == 0)
    {
        Wire.write(megabfader.bytes, sizeof(megabfader));
        sendcount = 1;
    }else{
        if(sendcount == 1)
        {
            Wire.write(megabother.bytes, sizeof(megabother));
            sendcount = 2;
        }else{
            if(sendcount == 2)
            {
                Wire.write(megabsubmaster.bytes, sizeof(megabsubmaster));
                sendcount = 0;
            }
        }
    }
}

void getData()
{

}