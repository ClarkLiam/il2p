/*Project: IL2P*/
/*Device: UNO (display)*/
/*Author: Liam Clark */
/*Version: 2.0.1 pre-alpha*/

#include <Wire.h>
const int SLAVE_UNO = 1;
const int SLAVE_Mega1 = 2;
const int SLAVE_Mega2 = 3;
const int SLAVE_Display = 4;

#include <PCF8574.h>
PCF8574 pcf8574(0x20);

#include <LiquidCrystal.h>
LiquidCrystal lcdA(2,3,4,5,6,7);
LiquidCrystal lcdB(8,9,10,11,12,13);

/*Definitions*/
    #define btnAup P0       //up (lcdA)
    #define btnAdown P1     //down (lcdA)

    #define btnBup P4       //up (lcdB)
    #define btnBdown P5     //down (lcdB)

    #define btnMenu P7       //menu
    #define btnSelect P6     //select

/*Custom Characters*/
    byte nine[] = {
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111
    };
    byte zero[] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
    };
    byte stepone[] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111
    };
    byte steptwo[] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111
    };
    byte stepthree[] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111,
        B11111
    };
    byte stepfour[] = {
        B00000,
        B00000,
        B00000,
        B00000, 
        B11111,
        B11111,
        B11111,
        B11111
    };
    byte stepfive[] = {
        B00000,
        B00000,
        B00000,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111
    };
    byte stepsix[] = {
        B00000,
        B00000,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111
    };
    byte stepseven[] = {
        B00000,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111
    };
    byte stepeight[] = {
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111
    };

/*Variables*/
    /*Button States*/
    int valbtnAup = 0;
    int valbtnAdown = 0;
    int valbtnBup = 0;
    int valbtnBdown = 0;
    int valbtnMenu = 0;
    int valbtnSelect = 0;

    int lastbtnAup = 0;
    int lastbtnAdown = 0;
    int lastbtnBup = 0;
    int lastbtnBdown = 0;
    int lastbtnMenu = 0;
    int lastbtnSelect = 0;

    /*Menu States*/
    int menustate = 0;

    int menu = 0;       //register current menu
    int submenu = 0;    //register current submenu

    /*Status States*/
    char *MidiStatusText[] = {"N/A", "OK"};
    char *ConsoleStatusText[] = {"Error", "running"};

/*Unions*/
    union data_unodataA
    {
    struct
    {
        int Fader1;
        int Fader2;
        int Fader3;
        int Fader4;
        int Fader5;
        int Fader6;

        int Fader13;
        int Fader14;
        int Fader15;
        int Fader16;
        int Fader17;
        int Fader18;

        int MidiStatus;
        int ConsoleStatus;
        int Master;
    };
    byte bytes[30];
    };
    data_unodataA unodataA;

    union data_unodataB
    {
    struct
    {
        int Fader7;
        int Fader8;
        int Fader9;
        int Fader10;
        int Fader11;
        int Fader12;

        int Fader19;
        int Fader20;
        int Fader21;
        int Fader22;
        int Fader23;
        int Fader24;
    };
    byte bytes[24];
    };
    data_unodataB unodataB;

    union data_unodataC
    {
    struct
    {
        int BtnFlashMode;
        int BtnFlashUp;
        int BtnFlashDown;

        int BtnAudioMode;
        int BtnAMUp;
        int BtnAMDown;

        int BtnChaserMode;
        int BtnChaserModeUp;
        int BtnChaserModeDown;
        int BtnChaserModeStop;
        int BtnChaserModeStart;
    };
    byte bytes[22];
    };
    data_unodataC unodataC;


void setup(){
    /*Wire*/
        Wire.begin(SLAVE_UNO); // Join I2C bus with address #1
        Wire.setClock(400000); // Set I2C clock speed to 400kHz
    
    /*Serial*/
        Serial.begin(115200);
    
    /*PCF8574*/
        pcf8574.begin();

    /*pinMode*/
        pcf8574.pinMode(btnAup, INPUT_PULLUP);
        pcf8574.pinMode(btnAdown, INPUT_PULLUP);
        pcf8574.pinMode(btnBup, INPUT_PULLUP);
        pcf8574.pinMode(btnBdown, INPUT_PULLUP);
        pcf8574.pinMode(btnMenu, INPUT_PULLUP);
        pcf8574.pinMode(btnSelect, INPUT_PULLUP);

    /*LCDs*/
        lcdA.begin(16, 2);
        lcdA.createChar(0, zero);
        lcdA.createChar(1, stepone);
        lcdA.createChar(2, steptwo);
        lcdA.createChar(3, stepthree);
        lcdA.createChar(4, stepfour);
        lcdA.createChar(5, stepfive);
        lcdA.createChar(6, stepsix);
        lcdA.createChar(7, stepseven);
        lcdA.createChar(8, stepeight);
        lcdA.createChar(9, nine);

        lcdB.begin(16, 2);
        lcdB.createChar(0, zero);
        lcdB.createChar(1, stepone);
        lcdB.createChar(2, steptwo);
        lcdB.createChar(3, stepthree);
        lcdB.createChar(4, stepfour);
        lcdB.createChar(5, stepfive);
        lcdB.createChar(6, stepsix);
        lcdB.createChar(7, stepseven);
        lcdB.createChar(8, stepeight);
        lcdB.createChar(9, nine);
}

void loop(){
    getData();
}


void getData(){
    Wire.requestFrom(SLAVE_UNO, sizeof(unodataA));
    if (Wire.available() == sizeof(unodataA)) {
        Wire.readBytes(unodataA.bytes, sizeof(unodataA));
    }
    Wire.requestFrom(SLAVE_UNO, sizeof(unodataB));
    if (Wire.available() == sizeof(unodataB)) {
        Wire.readBytes(unodataB.bytes, sizeof(unodataB));
    }
    Wire.requestFrom(SLAVE_UNO, sizeof(unodataC));
    if (Wire.available() == sizeof(unodataC)) {
        Wire.readBytes(unodataC.bytes, sizeof(unodataC));
    }

    Serial.println("UNODataA Received:");
    for (int i = 0; i < sizeof(unodataA.bytes); i++)
    {
        Serial.print(unodataA.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
    Serial.println("UNODataB Received:");
    for (int i = 0; i < sizeof(unodataB.bytes); i++)
    {
        Serial.print(unodataB.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
    Serial.println("UNODataC Received:");
    for (int i = 0; i < sizeof(unodataC.bytes); i++)
    {
        Serial.print(unodataC.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
    delay(500);
}












void ismenuopen(){
    if (menustate != 0) {
        return 1;
    } else {
        return 0;
    }
}