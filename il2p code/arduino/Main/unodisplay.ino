/*Project: IL2P*/
/*Device: UNO (display)*/
/*Author: Liam Clark */
/*Version: 1.1.2 pre-alpha*/ //2 versions in the code please update both

#include <Wire.h>    
const int SLAVE_UNO = 1;
const int SLAVE_Mega1 = 2;
const int SLAVE_Mega2 = 3;
const int SLAVE_Display = 4;

#include <PCF8574.h>
PCF8574 pcf8574(0x20);

#include <LiquidCrystal.h>
LiquidCrystal lcdA(6, 7, 8, 9, 10,11);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdB(0x27, 16, 2);

/*Definitions*/
    #define lcdABtn1 P0     //up (lcdA)
    #define lcdABtn2 P1     //down (lcdA)
    #define lcdABtn3 P2     //not used
    #define lcdABtn4 P3     //not used
    #define lcdBBtn1 P4     //up (lcdB)
    #define lcdBBtn2 P5     //down (lcdB)
    #define lcdBBtn3 P6     //select
    #define lcdBBtn4 P7     //menu 

    #define lcdBacklight 5  //dimmable backlight

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
    int vallcdABtn1 = 0;
    int vallcdABtn2 = 0;
    int vallcdBBtn1 = 0;
    int vallcdBBtn2 = 0;
    int vallcdBBtn3 = 0;
    int vallcdBBtn4 = 0;

    int lastlcdABtn1 = 0;
    int lastlcdABtn2 = 0;
    int lastlcdBBtn1 = 0;
    int lastlcdBBtn2 = 0;
    int lastlcdBBtn3 = 0;
    int lastlcdBBtn4 = 0;

    /*Backlight State*/
    int valBacklight = 175;

    /*Menu States*/
    int menustate = 0;
    int menu = 0;
    int submenu = 0;

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

/*Startup*/
void bootscreen(){
    lcdA.clear();
    lcdB.clear();
    lcdA.print("illumination2PRO");
    lcdB.print("start-up");
    delay(650);
    progressbar();
    lcdA.print("il2p - Screen 1");
    lcdB.print("il2p - Screen 2");
    delay(1500);
    lcdA.clear();
    lcdB.clear();
    lcdA.print("Welcome to");
    lcdB.print("illumination2PRO");
    lcdA.setCursor(0,1);
    lcdA.print(by LS Visuals);
    delay(500);
    lcdA.setCursor(0,1);
    lcdA.print("version 1.1.2");
    lcdB.setCursor(0,1);
    lcdB.print("S/N: LS01859643");
    delay(2000);
    lcdA.clear();
    lcdB.clear();
    lcdA.print("Boot complete");
    delay(1750);
    lcdA.clear();
    lcdB.print("Enjoy your show!");
    lcdA.print("User: LS_Admin");
    delay(2500);
    lcdA.clear();
    lcdB.clear();
}

void progressbar(){
    for(int i = 0; i < 16; i++){
        lcdA.setCursor(i,1);
        lcdA.write(byte(9)); // Use the 'five' custom character for a filled block
        delay(150);
    }
    for(int i = 0; i < 16; i++){
        lcdB.setCursor(i,1);
        lcdB.write(byte(9)); // Use the 'five' custom character for a filled block
        delay(90);
    }
    delay(250);
    lcdA.clear();
    lcdB.clear();
}

void setup(){
    /*Wire*/
        Wire.begin(4); // Join I2C bus with address #4
        Wire.setClock(400000); // Set I2C clock speed to 400kHz

    /*Serial*/
    Serial.begin(115200);

    /*PCF8574*/
    pcf8574.begin();

    /*pinMode*/
    pcf8574.pinMode(P0, INPUT_PULLUP);
    pcf8574.pinMode(P1, INPUT_PULLUP);
    pcf8574.pinMode(P2, INPUT_PULLUP);
    pcf8574.pinMode(P3, INPUT_PULLUP);
    pcf8574.pinMode(P4, INPUT_PULLUP);
    pcf8574.pinMode(P5, INPUT_PULLUP);
    pcf8574.pinMode(P6, INPUT_PULLUP);
    pcf8574.pinMode(P7, INPUT_PULLUP);

    pinMode(5, OUTPUT);

    /*LCDs*/
    lcdA.begin(16, 2);
    analogWrite(5, valBacklight);

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

    lcdB.init();
    lcdB.backlight();

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

    delay(250);
    bootscreen();
}

void loop(){
    getData1();
    Serial.println("UNODataA Received:");
    for (int i = 0; i < sizeof(unodataA.bytes); i++) {
        Serial.print(unodataA.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
    Serial.println("UNODataB Received:");
    for (int i = 0; i < sizeof(unodataB.bytes); i++) {
        Serial.print(unodataB.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
    Serial.println("UNODataC Received:");
    for (int i = 0; i < sizeof(unodataC.bytes); i++) {
        Serial.print(unodataC.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();

    /*Read Expander Buttons*/
    vallcdABtn1 = pcf8574.digitalRead(lcdABtn1);    //up
    vallcdABtn2 = pcf8574.digitalRead(lcdABtn2);    //down
    vallcdBBtn1 = pcf8574.digitalRead(lcdBBtn1);    //up
    vallcdBBtn2 = pcf8574.digitalRead(lcdBBtn2);    //down
    vallcdBBtn3 = pcf8574.digitalRead(lcdBBtn3);    //select
    vallcdBBtn4 = pcf8574.digitalRead(lcdBBtn4);    //menu

    /*Open Menu*/
    if(vallcdBBtn4 != lastlcdBBtn4){
        lastlcdBBtn4 = vallcdBBtn4;
        if(vallcdBBtn4 == LOW){
            menustate = 1;
            lcdA.clear();
            lcdB.clear();
            lcdA.print("Menu:");
            lcdB.print("Submenu:");
            delay(500);
            mainmenu(menu, submenu);
        }
    }
    while(menustate > 0){
        buttons();
        delay(150);
    }
    menuselect(menu, submenu);
    delay(150);
}

/* Menu Options
Menu -> Run         ->Overview
                    ->Wing
                    ->Fader
                    ->Programs
Menu -> Settings    ->Display
                    ->Fader
                    ->Buttons
                    ->Modes
Menu -> System      ->Overview
                    ->DMX
                    ->MIDI
                    ->Board Test
                    ->LED Test
Menu -> Info */

void buttons(){
    vallcdABtn1 = pcf8574.digitalRead(lcdABtn1);    //up
    vallcdABtn2 = pcf8574.digitalRead(lcdABtn2);    //down
    vallcdBBtn1 = pcf8574.digitalRead(lcdBBtn1);    //up
    vallcdBBtn2 = pcf8574.digitalRead(lcdBBtn2);    //down
    vallcdBBtn3 = pcf8574.digitalRead(lcdBBtn3);    //select
    vallcdBBtn4 = pcf8574.digitalRead(lcdBBtn4);    //menu

    if(vallcdABtn1 != lastlcdABtn1){
        lastlcdABtn1 = vallcdABtn1;
        if(vallcdABtn1 == LOW){
            menu++;
            if(menu > 3){
                menu = 0;
        }
            mainmenu(menu, submenu);
        }
    }
    if(vallcdABtn2 != lastlcdABtn2){
        lastlcdABtn2 = vallcdABtn2;
        if(vallcdABtn2 == LOW){
            menu--;
            if(menu < 0){
                menu = 3;
            }
            mainmenu(menu, submenu);
        }
    }
    if(vallcdBBtn1 != lastlcdBBtn1){
        lastlcdBBtn1 = vallcdBBtn1;
        if(vallcdBBtn1 == LOW){
            submenu++;
            if(submenu > 3){
                submenu = 0;
            }
            mainmenu(menu, submenu);
        }
    }
    if(vallcdBBtn2 != lastlcdBBtn2){
        lastlcdBBtn2 = vallcdBBtn2;
        if(vallcdBBtn2 == LOW){
            submenu--;
            if(submenu < 0){
                submenu = 3;
            }
            mainmenu(menu, submenu);
        }
    }
    if(vallcdBBtn3 != lastlcdBBtn3){
        lastlcdBBtn3 = vallcdBBtn3;
        if(vallcdBBtn3 == LOW){
            menuselect(menu, submenu);
        }
    }
}

void mainmenu(int menu, int submenu){
    switch(menu){
        case 0:
            lcdA.clear();
            lcdA.print(">Run");
            lcdA.setCursor(0,1);
            lcdA.print(" Settings");
            switch(submenu){
                case 0:
                    lcdB.clear();
                    lcdB.print(">Overview");
                    lcdB.setCursor(0,1);
                    lcdB.print(" Wing");
                    break;
                case 1:
                    lcdB.clear();
                    lcdB.print(" Overview");
                    lcdB.setCursor(0,1);
                    lcdB.print(">Wing");
                    break;
                case 2:
                    lcdB.clear();
                    lcdB.print(" Wing");
                    lcdB.setCursor(0,1);
                    lcdB.print(">Fader");
                    break;
                case 3:
                    lcdB.clear();
                    lcdB.print(" Fader");
                    lcdB.setCursor(0,1);
                    lcdB.print(">Programs");
                    break;
            }
            break;
        case 1:
            lcdA.clear();
            lcdA.print(" Run");
            lcdA.setCursor(0,1);
            lcdA.print(">Settings");
            switch(submenu){
                case 0:
                    lcdB.clear();
                    lcdB.print(">Display");
                    lcdB.setCursor(0,1);
                    lcdB.print(" Fader");
                    break;
                case 1:
                    lcdB.clear();
                    lcdB.print(" Display");
                    lcdB.setCursor(0,1);
                    lcdB.print(">Fader");
                    break;
                case 2:
                    lcdB.clear();
                    lcdB.print(" Fader");
                    lcdB.setCursor(0,1);
                    lcdB.print(">Buttons");
                    break;
                case 3:
                    lcdB.clear();
                    lcdB.print(" Buttons");
                    lcdB.setCursor(0,1);
                    lcdB.print(">Modes");
                    break;
            }
            break;
        case 2:
            lcdA.clear();
            lcdA.print(" Settings");
            lcdA.setCursor(0,1);
            lcdA.print(">System");
            switch(submenu){
                case 0:
                    lcdB.clear();
                    lcdB.print(">Overview");
                    lcdB.setCursor(0,1);
                    lcdB.print(" DMX");
                    break;
                case 1:
                    lcdB.clear();
                    lcdB.print(" Overview");
                    lcdB.setCursor(0,1);
                    lcdB.print(">DMX");
                    break;
                case 2:
                    lcdB.clear();
                    lcdB.print(" DMX");
                    lcdB.setCursor(0,1);
                    lcdB.print(">MIDI");
                    break;
                case 3:
                    lcdB.clear();
                    lcdB.print(" MIDI");
                    lcdB.setCursor(0,1);
                    lcdB.print(">Board Test");
                    break;
            }
            break;
        case 3:
            lcdA.clear();
            lcdB.clear();
            lcdA.print(" System");
            lcdA.setCursor(0,1);
            lcdA.print(">Info");
            break;
    }
}

void menuselect(int menu, int submenu){
    menustate = 0;
    lcdA.clear();
    lcdB.clear();
    switch(menu){
        case 0:
            switch(submenu){
                case 0:
                    run_overview();
                    break;
                case 1:
                    run_wing();
                    break;
                case 2:
                    run_fader();
                    break;
                case 3:
                    run_programs();
                    break;
            }
            break;
        case 1:
            switch(submenu){
                case 0:
                    settings_display();
                    break;
                case 1:
                    settings_fader();
                    break;
                case 2:
                    settings_buttons();
                    break;
                case 3:
                    settings_modes();
                    break;
            }
            break;
        case 2:
            switch(submenu){
                case 0:
                    system_overview();
                    break;
                case 1:
                    system_dmx();
                    break;
                case 2:
                    system_midi();
                    break;
                case 3:
                    boardtest();
                    break;
            }
            break;
        case 3:
            switch(submenu){
                case 0:
                    screen_info();
                    break;
            }
            break;
    }

}

/*Pages*/
    /*Menu Run*/
    void run_overview(){
        getData1();
        lcdA.print("Run Overview");
    }
    void run_wing(){
        lcdA.print("Wing  1-6");
        lcdA.setCursor(0,1);
        lcdA.print("A   13-18");
        printFader(10,0,1,unodataA.Fader1);
        printFader(10,1,13,unodataB.Fader7);
        printFader(11,0,2,unodataA.Fader2);
        printFader(11,1,14,unodataB.Fader8);
        printFader(12,0,3,unodataA.Fader3);
        printFader(12,1,15,unodataB.Fader9);
        printFader(13,0,4,unodataA.Fader4);
        printFader(13,1,16,unodataB.Fader10);
        printFader(14,0,5,unodataA.Fader5);
        printFader(14,1,17,unodataB.Fader11);
        printFader(15,0,6,unodataA.Fader6);
        printFader(15,1,18,unodataB.Fader12);

        lcdB.print("Wing 7-12");
        lcdB.setCursor(0,1);
        lcdB.print("B   19-24");
        printFader(10,0,7,unodataB.Fader7);
        printFader(10,1,19,unodataB.Fader19);
        printFader(11,0,8,unodataB.Fader8);
        printFader(11,1,20,unodataB.Fader20);
        printFader(12,0,9,unodataB.Fader9);
        printFader(12,1,21,unodataB.Fader21);
        printFader(13,0,10,unodataB.Fader10);
        printFader(13,1,22,unodataB.Fader22);
        printFader(14,0,11,unodataB.Fader11);
        printFader(14,1,23,unodataB.Fader23);
        printFader(15,0,12,unodataB.Fader12);
        printFader(15,1,24,unodataB.Fader24);
        
    }
    void run_fader(){
        getData1();
        lcdA.print("Run Fader");
    }
    void run_programs(){
        getData1();
        lcdA.print("Error");
        lcdA.setCursor(0,1);
        lcdA.print("no programs");
    }

    /*Menu Settings*/
    void settings_display(){
        lcdA.print("il2p - Screen 1");
        lcdB.print("il2p - Screen 2");
        delay(50);
        lcdA.clear();
        lcdB.clear();
        lcdA.print("Settings Display");
        lcdB.print("Brightness: 80%");
        lcdB.setCursor(0,1);
        lcdB.print("Contrast: Auto");
    }
    void settings_fader(){
        lcdA.print("Fader Settings");
        lcdB.print(">Standard");
        lcdB.setCursor(0,1);
        lcdB.print(" Precise");
    }
    void settings_buttons(){
        lcdA.print("Buttons Settings");
        lcdB.print(">Standard");
        lcdB.setCursor(0,1);
        lcdB.print(" Precise");
    }
    void settings_modes(){
        lcdA.print("Modes:");
        lcdB.print(">Standard");
        lcdB.setCursor(0,1);
        lcdB.print(" Programmer");
    }

    /*Menu System*/
    void system_overview(){
        getData1();
        lcdA.print("System Overview");
        lcdA.setCursor(0,1);
        lcdA.print("iP: 127.0.0.1");
        lcdB.print("Status:" );
        lcdB.setCursor(8,0);
        lcdB.print(ConsoleStatusText[unodataA.ConsoleStatus]);
        lcdB.setCursor(0,1);
        lcdB.print("Systems: running");
    }
    void system_dmx(){
        getData1();
        lcdA.print("DMX Settings");
        lcdB.print("Node1: N/A");
        lcdB.setCursor(0,1);
        lcdB.print("Node2: N/A");
    }
    void system_midi(){
        getData1();
        lcdA.print("MIDI Settings");
        lcdB.print("Host: pc-il2p");
        lcdB.setCursor(0,1);
        lcdB.print("Connection:");
        lcdB.setCursor(11,1);
        lcdB.print(MidiStatusText[unodataA.MidiStatus]);
    }
    void boardtest(){
        getData1();
        lcdA.print("Board Test");
    }

    /*Menu Info*/
    void screen_info(){
        lcdA.print("illumination2PRO");
        lcdA.setCursor(0,1);
        lcdA.print("S/N: LS01859643");
        lcdB.print("Version: 1.1.2");
        lcdB.setCursor(0,1);
        lcdB.print("Release: pre");
    }

/*Pages Systems*/
void printFader(int posx, int posy, int fader, int value){
    int bar = map(value, 0, 127, 0, 8);
    if(posx < 16){
        lcdA.setCursor(posx, posy);
        lcdA.write(byte(bar));
    }else{
        posx = posx - 16;
        lcdB.setCursor(posx, posy);
        lcdB.write(byte(bar));
    }
}

/*Communication*/
void getData1()
{
    Wire.requestFrom(SLAVE_UNO, sizeof(unodataA));
    if (Wire.available() == sizeof(unodataA)) {
        Wire.readBytes(unodataA.bytes, sizeof(unodataA));
    }else{
        if(Wire.available() == sizeof(unodataB)) {
        Wire.readBytes(unodataB.bytes, sizeof(unodataB));
        }else{
        if (Wire.available() == sizeof(unodataC)) {
        Wire.readBytes(unodataC.bytes, sizeof(unodataC));
        }else{
            Serial.println("Failed to receive data from UNO");
    }}
    delay(100);
    Wire.requestFrom(SLAVE_UNO, sizeof(unodataB));
    if (Wire.available() == sizeof(unodataB)) {
        Wire.readBytes(unodataB.bytes, sizeof(unodataB));
    }else{
        if (Wire.available() == sizeof(unodataA)) {
        Wire.readBytes(unodataA.bytes, sizeof(unodataA));
        }else{
        if (Wire.available() == sizeof(unodataC)) {
        Wire.readBytes(unodataC.bytes, sizeof(unodataC));
        }else{
            Serial.println("Failed to receive data from UNO");
    }}
    delay(100);
    Wire.requestFrom(SLAVE_UNO, sizeof(unodataC));
    if (Wire.available() == sizeof(unodataC)) {
        Wire.readBytes(unodataC.bytes, sizeof(unodataC));
    }else{
        if (Wire.available() == sizeof(unodataA)) {
        Wire.readBytes(unodataA.bytes, sizeof(unodataA));
        }else{
        if (Wire.available() == sizeof(unodataB)) {
        Wire.readBytes(unodataB.bytes, sizeof(unodataB));
        }else{
            Serial.println("Failed to receive data from UNO");
    }}
}
    }
    }
}