/*Project: IL2P*/
/*Device: Mega (2)*/
/*Author: Liam Clark */
/*Version: 1.8.1 pre-alpha*/

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

    #define button7 14
    #define button8 15
    #define button9 16
    #define button10 17
    #define button11 18
    #define button12 19

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

    int lastb7 = 0;
    int lastb8 = 0;
    int lastb9 = 0;
    int lastb10 = 0;
    int lastb11 = 0;
    int lastb12 = 0;

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

/*Unions*/
    union data_B
    {
    struct
    {
        int midib7;
        int midib8;
        int midib9;
        int midib10;
        int midib11;
        int midib12;

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

    };
    byte bytes[36];
    };
    data_B megab;

void setup()
{
    /*Serial*/
        Serial.begin(115200);
    /*Wire*/
        Wire.begin(SLAVE_Mega2);    // Join I2C bus with address #3
        Wire.setClock(400000); // Set I2C clock speed to 400kHz
        Wire.onRequest(sendData);
    /*pinMode*/
        pinMode(button7, INPUT_PULLUP);
        pinMode(button8, INPUT_PULLUP);
        pinMode(button9, INPUT_PULLUP);
        pinMode(button10, INPUT_PULLUP);
        pinMode(button11, INPUT_PULLUP);
        pinMode(button12, INPUT_PULLUP);

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

        if(valb7 != lastb7){
            if(stateb7 != 0){
                stateb7 = 0;
            }else{
                stateb7 = 1;
            }
            megab.midib7 = map(stateb7, 0, 1, 0, 127);
            lastb7 = valb7;
        }
        if(valb8 != lastb8){
            if(stateb8 != 0){
                stateb8 = 0;
            }else{
                stateb8 = 1;
            }
            megab.midib8 = map(stateb8, 0, 1, 0, 127);
            lastb8 = valb8;
        }
        if(valb9 != lastb9){
            if(stateb9 != 0){
                stateb9 = 0;
            }else{
                stateb9 = 1;
            }
            megab.midib9 = map(stateb9, 0, 1, 0, 127);
            lastb9 = valb9;
        }
        if(valb10 != lastb10){
            if(stateb10 != 0){
                stateb10 = 0;
            }else{
                stateb10 = 1;
            }
            megab.midib10 = map(stateb10, 0, 1, 0, 127);
            lastb10 = valb10;
        }
        if(valb11 != lastb11){
            if(stateb11 != 0){
                stateb11 = 0;
            }else{
                stateb11 = 1;
            }
            megab.midib11 = map(stateb11, 0, 1, 0, 127);
            lastb11 = valb11;
        }
        if(valb12 != lastb12){
            if(stateb12 != 0){
                stateb12 = 0;
            }else{
                stateb12 = 1;
            }
            megab.midib12 = map(stateb12, 0, 1, 0, 127);
            lastb12 = valb12;
        }

        
    /*Read Faders*/

        valf7 = analogRead(fader7);
        if(valf7 != lastf7){
            megab.midif7 = map(valf7, 1023, 0, 0, 127);
            analogWrite(ledfader7, megab.midif7 / 4);
            lastf7 = valf7;
        }
        valf8 = analogRead(fader8);
        if(valf8 != lastf8){
            megab.midif8 = map(valf8, 1023, 0, 0, 127);
            analogWrite(ledfader8, megab.midif8 / 4);
            lastf8 = valf8;
        }
        valf9 = analogRead(fader9);
        if(valf9 != lastf9){
            megab.midif9 = map(valf9, 1023, 0, 0, 127);
            analogWrite(ledfader9, megab.midif9 / 4);
            lastf9 = valf9;
        }
        valf10 = analogRead(fader10);
        if(valf10 != lastf10){
            megab.midif10 = map(valf10, 1023, 0, 0, 127);
            analogWrite(ledfader10, megab.midif10 / 4);
            lastf10 = valf10;
        }
        valf11 = analogRead(fader11);
        if(valf11 != lastf11){
            megab.midif11 = map(valf11, 1023, 0, 0, 127);
            analogWrite(ledfader11, megab.midif11 / 4);
            lastf11 = valf11;
        }
        valf12 = analogRead(fader12);
        if(valf12 != lastf12){
            megab.midif12 = map(valf12, 1023, 0, 0, 127);
            analogWrite(ledfader12, megab.midif12 / 4);
            lastf12 = valf12;
        }

        valf19 = analogRead(fader19);
        if(valf19 != lastf19){
            megab.midif19 = map(valf19, 1023, 0, 0, 127);
            analogWrite(ledfader19, megab.midif19 / 4);
            lastf19 = valf19;
        }
        valf20 = analogRead(fader20);
        if(valf20 != lastf20){
            megab.midif20 = map(valf20, 1023, 0, 0, 127);
            analogWrite(ledfader20, megab.midif20 / 4);
            lastf20 = valf20;
        }
        valf21 = analogRead(fader21);
        if(valf21 != lastf21){
            megab.midif21 = map(valf21, 1023, 0, 0, 127);
            analogWrite(ledfader21, megab.midif21 / 4);
            lastf21 = valf21;
        }
        valf22 = analogRead(fader22);
        if(valf22 != lastf22){
            megab.midif22 = map(valf22, 1023, 0, 0, 127);
            analogWrite(ledfader22, megab.midif22 / 4);
            lastf22 = valf22;
        }
        valf23 = analogRead(fader23);
        if(valf23 != lastf23){
            megab.midif23 = map(valf23, 1023, 0, 0, 127);
            analogWrite(ledfader23, megab.midif23 / 4);
            lastf23 = valf23;
        }
        valf24 = analogRead(fader24);
        if(valf24 != lastf24){
            megab.midif24 = map(valf24, 1023, 0, 0, 127);
            analogWrite(ledfader24, megab.midif24 / 4);
            lastf24 = valf24;
        }
}

void sendData()
{
 Wire.write(megab.bytes, sizeof(megab));
}

void getData()
{

}