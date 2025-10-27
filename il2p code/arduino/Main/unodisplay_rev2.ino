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
    byte stepone[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
    };
    byte steptwo[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111,
    };
    byte stepthree[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111,
        B11111,
    };
    byte stepfour[8] = {
        B00000,
        B00000,
        B00000,
        B00000, 
        B11111,
        B11111,
        B11111,
        B11111,
    };
    byte stepfive[8] = {
        B00000,
        B00000,
        B00000,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
    };
    byte stepsix[8] = {
        B00000,
        B00000,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
    };
    byte stepseven[8] = {
        B00000,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
    };
    byte stepeight[8] = {
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
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

    int posBtnA = 0;
    int posBtnB = 0;

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
        lcdA.createChar(0, stepone);
        lcdA.createChar(1, steptwo);
        lcdA.createChar(2, stepthree);
        lcdA.createChar(3, stepfour);
        lcdA.createChar(4, stepfive);
        lcdA.createChar(5, stepsix);
        lcdA.createChar(6, stepseven);
        lcdA.createChar(7, stepeight);

        lcdB.begin(16, 2);
        lcdB.createChar(0, stepone);
        lcdB.createChar(1, steptwo);
        lcdB.createChar(2, stepthree);
        lcdB.createChar(3, stepfour);
        lcdB.createChar(4, stepfive);
        lcdB.createChar(5, stepsix);
        lcdB.createChar(6, stepseven);
        lcdB.createChar(7, stepeight);
}

void loop(){
    getData();
    
    //Check Menu Button
    valbtnMenu = pcf8574.digitalRead(btnMenu);
    if(valbtnMenu != lastbtnMenu){
        lastbtnMenu = valbtnMenu;
        if(valbtnMenu == LOW){
            menustate = 1;
            displayMenu(posBtnA, posBtnB);
        }
    }

    //Open Menu
    while(menustate == 1){
        checkButtons();
        checkSelect();
    }

    //Update new values
    if(menustate == 0){
        selectMenu(posBtnA, posBtnB);
        delay(100);
    }

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
    delay(50);
}

void checkButtons(){
    valbtnAdown = pcf8574.digitalRead(btnAdown);
    valbtnAup = pcf8574.digitalRead(btnAup);
    valbtnBdown = pcf8574.digitalRead(btnBdown);
    valbtnBup = pcf8574.digitalRead(btnBup);
    valbtnSelect = pcf8574.digitalRead(btnSelect);

    if(valbtnAup != lastbtnAup){
        lastbtnAup = valbtnAup;
        if(valbtnAup == LOW){
            posBtnA++;
            if(posBtnA > 3){
                posBtnA = 0;
            }
            displayMenu(posBtnA, posBtnB);
        }
    }
    if(valbtnAdown != lastbtnAdown){
        lastbtnAdown = valbtnAdown;
        if(valbtnAdown == LOW){
            posBtnA--;
            if(posBtnA < 0){
                posBtnA = 3;
            }
            displayMenu(posBtnA, posBtnB);
        }
    }
    if(valbtnBup != lastbtnBup){
        lastbtnBup = valbtnBup;
        if(valbtnBup == LOW){
            posBtnB++;
            if(posBtnB > 3){
                posBtnB = 0;
            }
            displayMenu(posBtnA, posBtnB);
        }
    }
    if(valbtnBdown != lastbtnBdown){
        lastbtnBdown = valbtnBdown;
        if(valbtnBdown == LOW){
            posBtnB--;
            if(posBtnB < 0){
                posBtnB = 3;
            }
            displayMenu(posBtnA, posBtnB);
        }
    }
}

void checkSelect(){
    valbtnSelect = pcf8574.digitalRead(btnSelect);
    if(valbtnSelect != lastbtnSelect){
        lastbtnSelect = valbtnSelect;
        if(valbtnSelect == LOW){
            selectMenu(posBtnA, posBtnB);
        }
    }
}

void displayMenu(int menu, int submenu){
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

void selectMenu(int menu, int submenu){
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


/* Menu Options
Menu -> Run         ->Overview
                    ->Wing
                    ->Fader         -> Faders 1-24
                    ->Programs      -> Programs
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

/*Pages*/
    /*Menu Run*/
    void run_overview(){
        lcdA.print("Welcome to");
        lcdB.print("illumination2PRO");
    }
    void run_wing(){
        lcdA.print("Wing  1-6 ");
        lcdA.setCursor(0,1);
        lcdA.print("A   13-18 ");
        printFader(10,0,unodataA.Fader1);
        printFader(10,1,unodataB.Fader7);
        printFader(11,0,unodataA.Fader2);
        printFader(11,1,unodataB.Fader8);
        printFader(12,0,unodataA.Fader3);
        printFader(12,1,unodataB.Fader9);
        printFader(13,0,unodataA.Fader4);
        printFader(13,1,unodataB.Fader10);
        printFader(14,0,unodataA.Fader5);
        printFader(14,1,unodataB.Fader11);
        printFader(15,0,unodataA.Fader6);
        printFader(15,1,unodataB.Fader12);

        lcdB.print("Wing 7-12 ");
        lcdB.setCursor(0,1);
        lcdB.print("B   19-24 ");
        printFader(26,0,unodataB.Fader7);
        printFader(26,1,unodataB.Fader19);
        printFader(27,0,unodataB.Fader8);
        printFader(27,1,unodataB.Fader20);
        printFader(28,0,unodataB.Fader9);
        printFader(28,1,unodataB.Fader21);
        printFader(29,0,unodataB.Fader10);
        printFader(29,1,unodataB.Fader22);
        printFader(30,0,unodataB.Fader11);
        printFader(30,1,unodataB.Fader23);
        printFader(31,0,unodataB.Fader12);
        printFader(31,1,unodataB.Fader24);
    }
    void run_fader(){
        lcdA.print("Run Fader");
    }
    void run_programs(){
        lcdA.print("Error");
        lcdA.setCursor(0,1);
        lcdA.print("no programs");
    }

    /*Menu Settings*/
    void settings_display(){
        lcdA.print("il2p - Screen 1 ");
        lcdB.print("il2p - Screen 2 ");
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
        lcdA.print("System Overview ");
        lcdA.setCursor(0,1);
        lcdA.print("iP: 127.0.0.1   ");
        lcdB.print("Status: ");
        lcdB.setCursor(8,0);
        lcdB.print(ConsoleStatusText[unodataA.ConsoleStatus]);
        lcdB.setCursor(0,1);
        lcdB.print("Systems: running");
    }
    void system_dmx(){
        lcdA.print("DMX Settings");
        lcdB.print("Node1: N/A");
        lcdB.setCursor(0,1);
        lcdB.print("Node2: N/A");
    }
    void system_midi(){
        lcdA.print("MIDI Settings");
        lcdB.print("Host: pc-il2p");
        lcdB.setCursor(0,1);
        lcdB.print("Connection:");
        lcdB.setCursor(11,1);
        lcdB.print(MidiStatusText[unodataA.MidiStatus]);
    }
    void boardtest(){
        lcdA.print("Board Test");
        lcdB.print("self-test not");
        lcdB.setCursor(0,1);
        lcdB.print("available");
    }

    /*Menu Info*/
    void screen_info(){
        lcdA.print("illumination2PRO");
        lcdA.setCursor(0,1);
        lcdA.print("S/N: LS01859643");
        lcdB.print("Version: 1.2.3");
        lcdB.setCursor(0,1);
        lcdB.print("Release: pre");
    }

/*Pages Systems*/
void printFader(int posx, int posy, int value){
    int bar = map(value, 0, 127, 0, 8);
    if(bar == 0){
      if(posx < 16){
        lcdA.setCursor(posx, posy);
        lcdA.print(" ");
      }else{
        lcdB.setCursor(posx - 16, posy);
        lcdB.print(" ");
      }
    }else{
      if(posx < 16){
        lcdA.setCursor(posx, posy);
        lcdA.write(byte(bar - 1));
      }else{
        lcdB.setCursor(posx - 16, posy);
        lcdB.write(byte(bar - 1));
      }
    }
  
}
