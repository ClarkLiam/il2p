/*Project: IL2P*/
/*Device: UNO (main)*/
/*Author: Liam Clark */

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
    /*SendCount*/
        int sendcount = 0;

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

    union data_unodataA
    {
    struct
    {
        int fader1;
        int fader2;
        int fader3;
        int fader4;
        int fader5;
        int fader6;
        int fader13;
        int fader14;
        int fader15;
        int fader16;
        int fader17;
        int fader18;

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
        int fader7;
        int fader8;
        int fader9;
        int fader10;
        int fader11;
        int fader12;

        int fader19;
        int fader20;
        int fader21;
        int fader22;
        int fader23;
        int fader24;
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

void setup() {
    /*Wire*/
        Wire.begin(1); // Join I2C bus with address #1
        Wire.setClock(400000); // Set I2C clock speed to 400kHz
        Wire.onRequest(sendData);

    /*Serial*/
        Serial.begin(115200);
}

void loop() {
    /*Sample Values for Faders 1->24*/
    int i = 0;
    for(i = 0; i < 12; i++){
        unodataA.bytes[i] = 255;
    }
}


void sendData()
{
    if(sendcount == 0)
    {
        Wire.write(unodataA.bytes, sizeof(unodataA));
        sendcount = 1;
    }else{
        if(sendcount == 1)
        {
            Wire.write(unodataB.bytes, sizeof(unodataB));
            sendcount = 2;
        }else{
            if(sendcount == 2)
            {
                Wire.write(unodataC.bytes, sizeof(unodataC));
                sendcount = 0;
            }   
        }
    }
}