/*Project: IL2P*/
/*Device: Uno*/
/*Author: Liam Clark */
/*Version: 1.0.1 pre-alpha*/

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
    int statelcdABtn1 = 0;
    int statelcdABtn2 = 0;
    int statelcdABtn3 = 0;
    int statelcdABtn4 = 0;
    int statelcdBBtn1 = 0;
    int statelcdBBtn2 = 0;
    int statelcdBBtn3 = 0;
    int statelcdBBtn4 = 0;

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
    vallcdABtn1 = pcf8574.digitalRead(lcdABtn1);
    vallcdABtn2 = pcf8574.digitalRead(lcdABtn2);
    vallcdABtn3 = pcf8574.digitalRead(lcdABtn3);
    vallcdABtn4 = pcf8574.digitalRead(lcdABtn4);
    vallcdBBtn1 = pcf8574.digitalRead(lcdBBtn1);
    vallcdBBtn2 = pcf8574.digitalRead(lcdBBtn2);
    vallcdBBtn3 = pcf8574.digitalRead(lcdBBtn3);
    vallcdBBtn4 = pcf8574.digitalRead(lcdBBtn4);

    Serial.print(vallcdABtn1);
    Serial.print(vallcdABtn2);
    Serial.print(vallcdABtn3);
    Serial.print(vallcdABtn4);
    Serial.print(" | ");
    Serial.print(vallcdBBtn1);
    Serial.print(vallcdBBtn2);
    Serial.print(vallcdBBtn3);
    Serial.println(vallcdBBtn4);
    delay(100);
}