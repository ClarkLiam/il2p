/*Project: IL2P*/
/*Device: Uno*/
/*Author: Liam Clark */
/*Version: 1.0.3 pre-alpha*/

#include <PCF8574.h>
PCF8574 pcf8574(0x20);

#include <LiquidCrystal.h>
LiquidCrystal lcdA(6, 7, 8, 9, 10,11);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdB(0x27, 16, 2);

/*Definitions*/
    #define lcdABtn1 P0
    #define lcdABtn2 P1
    #define lcdABtn3 P2
    #define lcdABtn4 P3
    #define lcdBBtn1 P4
    #define lcdBBtn2 P5
    #define lcdBBtn3 P6
    #define lcdBBtn4 P7

/*Variables*/
    /*Button States*/
    int vallcdABtn1 = 0;
    int vallcdABtn2 = 0;
    int vallcdABtn3 = 0;
    int vallcdABtn4 = 0;
    int vallcdBBtn1 = 0;
    int vallcdBBtn2 = 0;
    int vallcdBBtn3 = 0;
    int vallcdBBtn4 = 0;

    int lastlcdABtn1 = 0;
    int lastlcdABtn2 = 0;
    int lastlcdABtn3 = 0;
    int lastlcdABtn4 = 0;
    int lastlcdBBtn1 = 0;
    int lastlcdBBtn2 = 0;
    int lastlcdBBtn3 = 0;
    int lastlcdBBtn4 = 0;

/*Menu States*/
    int menustate = 0;
    int menu = 0;
    int submenu = 0;

/*Menu Definitions*/
    

void setup(){
    Serial.begin(115200);
    pcf8574.begin();
    pcf8574.pinMode(P0, INPUT_PULLUP);
    pcf8574.pinMode(P1, INPUT_PULLUP);
    pcf8574.pinMode(P2, INPUT_PULLUP);
    pcf8574.pinMode(P3, INPUT_PULLUP);
    pcf8574.pinMode(P4, INPUT_PULLUP);
    pcf8574.pinMode(P5, INPUT_PULLUP);
    pcf8574.pinMode(P6, INPUT_PULLUP);
    pcf8574.pinMode(P7, INPUT_PULLUP);
    lcdA.begin(16, 2);
    lcdB.init();
    lcdB.backlight();

    lcdA.print("IL2P - Screen 1");
    lcdB.print("IL2P - Screen 2");
    delay(2000);
    lcdA.clear();
    lcdB.clear();
}

void loop(){
    vallcdABtn1 = pcf8574.digitalRead(lcdABtn1);    //up
    vallcdABtn2 = pcf8574.digitalRead(lcdABtn2);    //down
    vallcdABtn3 = pcf8574.digitalRead(lcdABtn3);    //
    vallcdABtn4 = pcf8574.digitalRead(lcdABtn4);    //
    vallcdBBtn1 = pcf8574.digitalRead(lcdBBtn1);    //up
    vallcdBBtn2 = pcf8574.digitalRead(lcdBBtn2);    //down
    vallcdBBtn3 = pcf8574.digitalRead(lcdBBtn3);    //select
    vallcdBBtn4 = pcf8574.digitalRead(lcdBBtn4);    //menu

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
    vallcdABtn3 = pcf8574.digitalRead(lcdABtn3);    //
    vallcdABtn4 = pcf8574.digitalRead(lcdABtn4);    //
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

void run_overview(){
    lcdA.print("Run Overview");
}
void run_wing(){
    lcdA.print("Run Wing");

}
void run_fader(){
    lcdA.print("Run Fader");
}
void run_programs(){
    lcdA.print("Run Programs");
}

void settings_display(){
    lcdA.print("il2p - Screen 1");
    lcdB.print("il2p - Screen 2");
    delay(50);
    lcdA.clear();
    lcdB.clear();
    lcdA.print("Settings Display");
    lcdB.print(">Brightness");
    lcdB.setCursor(0,1);
    lcdB.print(" Contrast");
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

void system_overview(){
    lcdA.print("System Overview");
    lcdA.setCursor(0,1);
    lcdA.print("iP: 127.0.0.1");
    lcdB.print("Status: OK");
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
    lcdB.print("Connection: N/A");
}
void boardtest(){
    lcdA.print("Board Test");
}
void screen_info(){
    lcdA.print("illumination2PRO");
    lcdA.setCursor(0,1);
    lcdA.print("S/N: LS01859643");
    lcdB.print("Version: 1.0.3");
    lcdB.setCursor(0,1);
    lcdB.print("Release: pre");
}