/*Project: IL2P*/
/*Device: Mega (1)*/
/*Author: Liam Clark */
/*Version: 1.8.1 pre-alpha*/

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

    int valb1 = 0;
    int valb2 = 0;
    int valb3 = 0;
    int valb4 = 0;
    int valb5 = 0;
    int valb6 = 0;

    int lastb1 = 0;
    int lastb2 = 0;
    int lastb3 = 0;
    int lastb4 = 0;
    int lastb5 = 0;
    int lastb6 = 0;

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

/*Unions*/
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
        Serial.begin(115200);
    /*Wire*/
        Wire.begin(2);    // Join I2C bus with address #2
        Wire.onRequest(sendData);

}

void loop()
{
    for(int i = 0; i < 100; i++){
            megaa.midib1 = i;
            megaa.midib2 = i+1;
            megaa.midib3 = i+2;
            megaa.midib4 = i+3;
            megaa.midib5 = i+4;
            megaa.midib6 = i+5;
            megaa.midif1 = i+6;
            megaa.midif2 = i+7;
            megaa.midif3 = i+8;
            megaa.midif4 = i+9;
            megaa.midif5 = i+10;
            megaa.midif6 = i+11;
            megaa.midif13 = i+12;
            megaa.midif14 = i+13;
            megaa.midif15 = i+14;
            megaa.midif16 = i+15;
            megaa.midif17 = i+16;
            megaa.midif18 = i+17;
            delay(500);
    }

    

}



void sendData() {
    // Send the data union as bytes when the master requests it
    Wire.write(megaa.bytes, sizeof(megaa)); // Send the entire union as a byte array
    Serial.println("Data Sent:");
    for (int i = 0; i < sizeof(megaa.bytes); i++) {
        Serial.print(megaa.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
}