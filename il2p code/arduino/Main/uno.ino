/*Project: IL2P*/
/*Device: UNO (main)*/
/*Author: Liam Clark */
/*Version: 1.8.3 pre-alpha*/

#include <Wire.h>    
const int SLAVE_UNO = 1;
const int SLAVE_Mega1 = 2;
const int SLAVE_Mega2 = 3;
const int SLAVE_Display = 4;

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

/*Definitions*/
#define GrandMaster A0

#define DBO 2

#define ButtonAudioMode 3
#define ButtonAMUp 4
#define ButtonAMDown 5

#define Display_DMX1 6
#define Display_DMX2 7
#define Display_DMX3 8
#define Display_DMX4 9

/*Variables*/
    /*Buttons*/
        int lastbutton1 = 0;
        int lastbutton2 = 0;
        int lastbutton3 = 0;
        int lastbutton4 = 0;
        int lastbutton5 = 0;
        int lastbutton6 = 0;

        int lastbutton7 = 0;
        int lastbutton8 = 0;
        int lastbutton9 = 0;
        int lastbutton10 = 0;
        int lastbutton11 = 0;
        int lastbutton12 = 0;

        int lastbuttonA = 0;
        int lastbuttonB = 0;
        int lastbuttonSequencer = 0;
        int lastbuttonAux = 0;
        int lastbuttonDelete = 0;
        int lastbuttonStore = 0;
        int lastbuttonModify = 0;
        int lastbuttonSoundUp = 0;
        int lastbuttonSoundDown = 0;
        int lastbuttonDBO = 0;

        int lastbuttonChaserMode = 0;
        int lastbuttonChaserModeUp = 0;
        int lastbuttonChaserModeDown = 0;
        int lastbuttonChaserModeStop = 0;
        int lastbuttonChaserModeStart = 0;
        int lastbuttonFlashMode = 0;
        int lastbuttonFlashUp = 0;
        int lastbuttonFlashDown = 0;
        int lastbuttonAudioMode = 0;
        int lastbuttonAMUp = 0;
        int lastbuttonAMDown = 0;

        int valbDBO = 0;
        int valbAudioMode = 0;
        int valbAMUp = 0;
        int valbAMDown = 0;

        int lastbDBO = 0;
        int lastbAudioMode = 0;
        int lastbAMUp = 0;
        int lastbAMDown = 0;

        int statebDBO = 0;
        int statebAudioMode = 0;
        int statebAMUp = 0;
        int statebAMDown = 0;

        int midibDBO = 0;
        int midibAudioMode = 0;
        int midibAMUp = 0;
        int midibAMDown = 0;

    

    /*Faders*/
        int lastfader1 = 0;
        int lastfader2 = 0;
        int lastfader3 = 0;
        int lastfader4 = 0;
        int lastfader5 = 0;
        int lastfader6 = 0;
        
        int lastfader7 = 0;
        int lastfader8 = 0;
        int lastfader9 = 0;
        int lastfader10 = 0;
        int lastfader11 = 0;
        int lastfader12 = 0;

        int lastfader13 = 0;
        int lastfader14 = 0;
        int lastfader15 = 0;
        int lastfader16 = 0;
        int lastfader17 = 0;
        int lastfader18 = 0;

        int lastfader19 = 0;
        int lastfader20 = 0;
        int lastfader21 = 0;
        int lastfader22 = 0;
        int lastfader23 = 0;
        int lastfader24 = 0;

        int lastfaderA = 0;
        int lastfaderB = 0;
        int lastGrandMaster = 0;

        int lastfaderSequencer = 0;
        int lastfaderAux = 0;
        int lastfaderFade = 0;
        int lastfaderSpeed = 0;

        int valfGM = 0;
        int lastfGM = 0;
        int midifGM = 0;

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
        int midiflashup;
        int midiflashdown;

        int waste;

    };
    byte bytes[32];
    };
    data_OtherA megaaother;

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


void setup() {
    /*Wire*/
        Wire.begin(); // Join I2C bus with address #1
        Wire.setClock(400000); // Set I2C clock speed to 400kHz

    /*MIDI*/
        MIDI.begin();

    /*Serial*/
        Serial.begin(115200);

    /*pinMode*/
        pinMode(DBO, INPUT_PULLUP);

        pinMode(ButtonAudioMode, INPUT_PULLUP);
        pinMode(ButtonAMUp, INPUT_PULLUP);
        pinMode(ButtonAMDown, INPUT_PULLUP);

        pinMode(Display_DMX1, OUTPUT);
        pinMode(Display_DMX2, OUTPUT);
        pinMode(Display_DMX3, OUTPUT);
        pinMode(Display_DMX4, OUTPUT);
}

void loop() {
    getData1();
    Serial.println("Fader Data Received:");
    for (int i = 0; i < sizeof(megaafader.bytes); i++) {
        Serial.print(megaafader.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
    Serial.println("Other Data Received:");
    for (int i = 0; i < sizeof(megaaother.bytes); i++) {
        Serial.print(megaaother.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
    
    getData2();
    Serial.println("Fader Data Received:");
    for (int i = 0; i < sizeof(megabfader.bytes); i++) {
        Serial.print(megabfader.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
    Serial.println("Other Data Received:");
    for (int i = 0; i < sizeof(megabother.bytes); i++) {
        Serial.print(megabother.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
    Serial.println("Submaster Data Received:");
    for (int i = 0; i < sizeof(megabsubmaster.bytes); i++) {
        Serial.print(megabsubmaster.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();

    /*Midi*/
        /*MegaA*/
        if(megaaother.midib1 != lastbutton1)
        {
            MIDI.sendNoteOn(0, megaaother.midib1, 1);
            lastbutton1 = megaaother.midib1;
        }
        if(megaaother.midib2 != lastbutton2)
        {
            MIDI.sendNoteOn(1, megaaother.midib2, 1);
            lastbutton2 = megaaother.midib2;
        }
        if(megaaother.midib3 != lastbutton3)
        {
            MIDI.sendNoteOn(2, megaaother.midib3, 1);
            lastbutton3 = megaaother.midib3;
        }
        if(megaaother.midib4 != lastbutton4)
        {
            MIDI.sendNoteOn(3, megaaother.midib4, 1);
            lastbutton4 = megaaother.midib4;
        }
        if(megaaother.midib5 != lastbutton5)
        {
            MIDI.sendNoteOn(4, megaaother.midib5, 1);
            lastbutton5 = megaaother.midib5;
        }
        if(megaaother.midib6 != lastbutton6)
        {
            MIDI.sendNoteOn(5, megaaother.midib6, 1);
            lastbutton6 = megaaother.midib6;
        }
        if(megaafader.midif1 != lastfader1)
        {
            MIDI.sendNoteOn(0, megaafader.midif1, 2);
            lastfader1 = megaafader.midif1;
        }
        if(megaafader.midif2 != lastfader2)
        {
            MIDI.sendNoteOn(1, megaafader.midif2, 2);
            lastfader2 = megaafader.midif2;
        }
        if(megaafader.midif3 != lastfader3)
        {
            MIDI.sendNoteOn(2, megaafader.midif3, 2);
            lastfader3 = megaafader.midif3;
        }
        if(megaafader.midif4 != lastfader4)
        {
            MIDI.sendNoteOn(3, megaafader.midif4, 2);
            lastfader4 = megaafader.midif4;
        }
        if(megaafader.midif5 != lastfader5)
        {
            MIDI.sendNoteOn(4, megaafader.midif5, 2);
            lastfader5 = megaafader.midif5;
        }
        if(megaafader.midif6 != lastfader6)
        {
            MIDI.sendNoteOn(5, megaafader.midif6, 2);
            lastfader6 = megaafader.midif6;
        }
        if(megaafader.midif13 != lastfader13)
        {
            MIDI.sendNoteOn(12, megaafader.midif13, 2);
            lastfader13 = megaafader.midif13;
        }
        if(megaafader.midif14 != lastfader14)
        {
            MIDI.sendNoteOn(13, megaafader.midif14, 2);
            lastfader14 = megaafader.midif14;
        }
        if(megaafader.midif15 != lastfader15)
        {
            MIDI.sendNoteOn(14, megaafader.midif15, 2);
            lastfader15 = megaafader.midif15;
        }
        if(megaafader.midif16 != lastfader16)
        {
            MIDI.sendNoteOn(15, megaafader.midif16, 2);
            lastfader16 = megaafader.midif16;
        }
        if(megaafader.midif17 != lastfader17)
        {
            MIDI.sendNoteOn(16, megaafader.midif17, 2);
            lastfader17 = megaafader.midif17;
        }
        if(megaafader.midif18 != lastfader18)
        {
            MIDI.sendNoteOn(17, megaafader.midif18, 2);
            lastfader18 = megaafader.midif18;
        }

        /*MegaB*/
        if(megabother.midib7 != lastbutton7)
        {
            MIDI.sendNoteOn(6, megabother.midib7, 1);
            lastbutton7 = megabother.midib7;
        }
        if(megabother.midib8 != lastbutton8)
        {
            MIDI.sendNoteOn(7, megabother.midib8, 1);
            lastbutton8 = megabother.midib8;
        }
        if(megabother.midib9 != lastbutton9)
        {
            MIDI.sendNoteOn(8, megabother.midib9, 1);
            lastbutton9 = megabother.midib9;
        }
        if(megabother.midib10 != lastbutton10)
        {
            MIDI.sendNoteOn(9, megabother.midib10, 1);
            lastbutton10 = megabother.midib10;
        }
        if(megabother.midib11 != lastbutton11)
        {
            MIDI.sendNoteOn(10, megabother.midib11, 1);
            lastbutton11 = megabother.midib11;
        }
        if(megabother.midib12 != lastbutton12)
        {
            MIDI.sendNoteOn(11, megabother.midib12, 1);
            lastbutton12 = megabother.midib12;
        }
        if(megabfader.midif7 != lastfader7)
        {
            MIDI.sendNoteOn(6, megabfader.midif7, 2);
            lastfader7 = megabfader.midif7;
        }
        if(megabfader.midif8 != lastfader8)
        {
            MIDI.sendNoteOn(7, megabfader.midif8, 2);
            lastfader8 = megabfader.midif8;
        }
        if(megabfader.midif9 != lastfader9)
        {
            MIDI.sendNoteOn(8, megabfader.midif9, 2);
            lastfader9 = megabfader.midif9;
        }
        if(megabfader.midif10 != lastfader10)
        {
            MIDI.sendNoteOn(9, megabfader.midif10, 2);
            lastfader10 = megabfader.midif10;
        }
        if(megabfader.midif11 != lastfader11)
        {
            MIDI.sendNoteOn(10, megabfader.midif11, 2);
            lastfader11 = megabfader.midif11;
        }
        if(megabfader.midif12 != lastfader12)
        {
            MIDI.sendNoteOn(11, megabfader.midif12, 2);
            lastfader12 = megabfader.midif12;
        }
        if(megabfader.midif19 != lastfader19)
        {
            MIDI.sendNoteOn(18, megabfader.midif19, 2);
            lastfader19 = megabfader.midif19;
        }
        if(megabfader.midif20 != lastfader20)
        {
            MIDI.sendNoteOn(19, megabfader.midif20, 2);
            lastfader20 = megabfader.midif20;
        }
        if(megabfader.midif21 != lastfader21)
        {
            MIDI.sendNoteOn(20, megabfader.midif21, 2);
            lastfader21 = megabfader.midif21;
        }
        if(megabfader.midif22 != lastfader22)
        {
            MIDI.sendNoteOn(21, megabfader.midif22, 2);
            lastfader22 = megabfader.midif22;
        }
        if(megabfader.midif23 != lastfader23)
        {
            MIDI.sendNoteOn(22, megabfader.midif23, 2);
            lastfader23 = megabfader.midif23;
        }
        if(megabfader.midif24 != lastfader24)
        {
            MIDI.sendNoteOn(23, megabfader.midif24, 2);
            lastfader24 = megabfader.midif24;
        }

        /*Non Faderwing*/
        if(megabsubmaster.midifA != lastfaderA)
        {
            MIDI.sendNoteOn(1, megabsubmaster.midifA, 3);
            lastfaderA = megabsubmaster.midifA;
        }
        if(megabsubmaster.midifB != lastfaderB)
        {
            MIDI.sendNoteOn(2, megabsubmaster.midifB, 3);
            lastfaderB = megabsubmaster.midifB;
        }
        if(megabfader.midifSequencer != lastfaderSequencer)
        {
            MIDI.sendNoteOn(3, megabfader.midifSequencer, 3);
            lastfaderSequencer = megabfader.midifSequencer;
        }
        if(megabfader.midifAux != lastfaderAux)
        {
            MIDI.sendNoteOn(4, megabfader.midifAux, 3);
            lastfaderAux = megabfader.midifAux;
        }
        if(megaafader.midiffade != lastfaderFade)
        {
            MIDI.sendNoteOn(5, megaafader.midiffade, 3);
            lastfaderFade = megaafader.midiffade;
        }
        if(megaafader.midifspeed != lastfaderSpeed)
        {
            MIDI.sendNoteOn(6, megaafader.midifspeed, 3);
            lastfaderSpeed = megaafader.midifspeed;
        }
        if(megaaother.midibdelete != lastbuttonDelete)
        {
            MIDI.sendNoteOn(7, megaaother.midibdelete, 3);
            lastbuttonDelete = megaaother.midibdelete;
        }
        if(megaaother.midibstore != lastbuttonStore)
        {
            MIDI.sendNoteOn(8, megaaother.midibstore, 3);
            lastbuttonStore = megaaother.midibstore;
        }
        if(megaaother.midibmodify != lastbuttonModify)
        {
            MIDI.sendNoteOn(9, megaaother.midibmodify, 3);
            lastbuttonModify = megaaother.midibmodify;
        }
        if(megaaother.midibsoundup != lastbuttonSoundUp)
        {
            MIDI.sendNoteOn(10, megaaother.midibsoundup, 3);
            lastbuttonSoundUp = megaaother.midibsoundup;
        }
        if(megaaother.midibsounddown != lastbuttonSoundDown)
        {
            MIDI.sendNoteOn(11, megaaother.midibsounddown, 3);
            lastbuttonSoundDown = megaaother.midibsounddown;
        }
        if(megaaother.midibflashmode != lastbuttonFlashMode)
        {
            MIDI.sendNoteOn(12, megaaother.midibflashmode, 3);
            lastbuttonFlashMode = megaaother.midibflashmode;
        }
        if(megaaother.midiflashup != lastbuttonFlashUp)
        {
            MIDI.sendNoteOn(13, megaaother.midiflashup, 3);
            lastbuttonFlashUp = megaaother.midiflashup;
        }
        if(megaaother.midiflashdown != lastbuttonFlashDown)
        {
            MIDI.sendNoteOn(14, megaaother.midiflashdown, 3);
            lastbuttonFlashDown = megaaother.midiflashdown;
        }
        if(megabother.midibChaserMode != lastbuttonChaserMode)
        {
            MIDI.sendNoteOn(15, megabother.midibChaserMode, 3);
            lastbuttonChaserMode = megabother.midibChaserMode;
        }
        if(megabother.midibChaserModeUp != lastbuttonChaserModeUp)
        {
            MIDI.sendNoteOn(16, megabother.midibChaserModeUp, 3);
            lastbuttonChaserModeUp = megabother.midibChaserModeUp;
        }
        if(megabother.midibChaserModeDown != lastbuttonChaserModeDown)
        {
            MIDI.sendNoteOn(17, megabother.midibChaserModeDown, 3);
            lastbuttonChaserModeDown = megabother.midibChaserModeDown;
        }
        if(megabother.midibChaserModeStop != lastbuttonChaserModeStop)
        {
            MIDI.sendNoteOn(18, megabother.midibChaserModeStop, 3);
            lastbuttonChaserModeStop = megabother.midibChaserModeStop;
        }
        if(megabother.midibChaserModeStart != lastbuttonChaserModeStart)
        {
            MIDI.sendNoteOn(19, megabother.midibChaserModeStart, 3);
            lastbuttonChaserModeStart = megabother.midibChaserModeStart;
        }
        if(megabother.midibA != lastbuttonA)
        {
            MIDI.sendNoteOn(23, megabother.midibA, 3);
            lastbuttonA = megabother.midibA;
        }
        if(megabother.midibB != lastbuttonB)
        {
            MIDI.sendNoteOn(24, megabother.midibB, 3);
            lastbuttonB = megabother.midibB;
        }
        if(megabother.midibSequencer != lastbuttonSequencer)
        {
            MIDI.sendNoteOn(25, megabother.midibSequencer, 3);
            lastbuttonSequencer = megabother.midibSequencer;
        }
        if(megabother.midibAux != lastbuttonAux)
        {
            MIDI.sendNoteOn(26, megabother.midibAux, 3);
            lastbuttonAux = megabother.midibAux;
        }

    /*Local Ports Uno*/
        /*Read Buttons*/
            if(valbDBO != lastbDBO){
                if(statebDBO != 0){
                    statebDBO = 0;
                }else{
                    statebDBO = 1;
                }
                midibDBO = map(statebDBO, 0, 1, 0, 127);
                lastbDBO = valbDBO;
            }
            if(valbAudioMode != lastbAudioMode){
                if(statebAudioMode != 0){
                    statebAudioMode = 0;
                }else{
                    statebAudioMode = 1;
                }
                midibAudioMode = map(statebAudioMode, 0, 1, 0, 127);
                lastbAudioMode = valbAudioMode;
            }
            if(valbAMUp != lastbAMUp){
                if(statebAMUp != 0){
                    statebAMUp = 0;
                }else{
                    statebAMUp = 1;
                }
                midibAMUp = map(statebAMUp, 0, 1, 0, 127);
                lastbAMUp = valbAMUp;
            }
            if(valbAMDown != lastbAMDown){
                if(statebAMDown != 0){
                    statebAMDown = 0;
                }else{
                    statebAMDown = 1;
                }
                midibAMDown = map(statebAMDown, 0, 1, 0, 127);
                lastbAMDown = valbAMDown;
            }

        /*Read Faders*/
            valfGM = analogRead(GrandMaster);
            if(valfGM != lastfGM){
                midifGM = map(valfGM, 1023, 0, 0, 127);
                lastfGM = valfGM;
            }

        /*Write Midi*/
        if(midibDBO != lastbDBO){
            MIDI.sendNoteOn(3, midibDBO, 27);
            lastbDBO = midibDBO;
        }
        if(midibAudioMode != lastbAudioMode){
            MIDI.sendNoteOn(3, midibAudioMode, 20);
            lastbAudioMode = midibAudioMode;
        }
        if(midibAMUp != lastbAMUp){
            MIDI.sendNoteOn(3, midibAMUp, 21);
            lastbAMUp = midibAMUp;
        }
        if(midibAMDown != lastbAMDown){
            MIDI.sendNoteOn(3, midibAMDown, 22);
            lastbAMDown = midibAMDown;
        }
        if(midifGM != lastfGM){
            MIDI.sendNoteOn(3, midifGM, 0);
            lastfGM = midifGM;
        }
}



void getData1()
{
    Wire.requestFrom(SLAVE_Mega1, sizeof(megaafader));
    if (Wire.available() == sizeof(megaafader)) {
        Wire.readBytes(megaafader.bytes, sizeof(megaafader));
    }else{
        if (Wire.available() == sizeof(megaaother)) {
        Wire.readBytes(megaaother.bytes, sizeof(megaaother));
        }else{
            Serial.println("Failed to receive data from Mega1");
    }}
    delay(100);
    Wire.requestFrom(SLAVE_Mega1, sizeof(megaaother));
    if (Wire.available() == sizeof(megaaother)) {
        Wire.readBytes(megaaother.bytes, sizeof(megaaother));
    }else{
        if (Wire.available() == sizeof(megaafader)) {
        Wire.readBytes(megaafader.bytes, sizeof(megaafader));
        }else{
        Serial.println("Failed to receive data from Mega1");
    }}
}

void getData2()
{
    Wire.requestFrom(SLAVE_Mega2, sizeof(megabfader));
    if (Wire.available() == sizeof(megabfader)) {
        Wire.readBytes(megabfader.bytes, sizeof(megabfader));
    }else{
        if (Wire.available() == sizeof(megabother)) {
        Wire.readBytes(megabother.bytes, sizeof(megabother));
        }else{
            if(Wire.available() == sizeof(megabsubmaster)) {
                Wire.readBytes(megabsubmaster.bytes, sizeof(megabsubmaster));
            }else{
                Serial.println("Failed to receive data from Mega2");
    }}}
    delay(100);
    Wire.requestFrom(SLAVE_Mega2, sizeof(megabother));
    if (Wire.available() == sizeof(megabother)) {
        Wire.readBytes(megabother.bytes, sizeof(megabother));
    }else{
        if (Wire.available() == sizeof(megabfader)) {
        Wire.readBytes(megabfader.bytes, sizeof(megabfader));
        }else{
            if(Wire.available() == sizeof(megabsubmaster)) {
                Wire.readBytes(megabsubmaster.bytes, sizeof(megabsubmaster));
            }else{
                Serial.println("Failed to receive data from Mega2");
    }}}
    delay(100);
    Wire.requestFrom(SLAVE_Mega2, sizeof(megabsubmaster));
    if (Wire.available() == sizeof(megabsubmaster)) {
        Wire.readBytes(megabsubmaster.bytes, sizeof(megabsubmaster));
    }else{
        if (Wire.available() == sizeof(megabfader)) {
        Wire.readBytes(megabfader.bytes, sizeof(megabfader));
        }else{
            if(Wire.available() == sizeof(megabother)) {
                Wire.readBytes(megabother.bytes, sizeof(megabother));
            }else{
                Serial.println("Failed to receive data from Mega2");
    }}}
}