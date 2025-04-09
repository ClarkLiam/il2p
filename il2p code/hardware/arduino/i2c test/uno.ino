/*Project: IL2P-I2C Testing*/
/*Device: Arduino_UNO*/
/*Author: Liam Clark */
/*Version: 1.1*/

/*Libraries*/  
    #include <MIDI.h>
    MIDI_CREATE_DEFAULT_INSTANCE();

    #include <Wire.h>    
    const int SLAVE_Mega1 = 2;
    const int SLAVE_Mega2 = 3; 

/*Definations*/int lastval1 = 0;
/*Unions*/
    union data_A
    {
    struct
    {
        int val1;

    };
    byte bytes[2];
    };
    data_A megaa; 

    union data_B
    {
    struct
    {
        int val1;

    };
    byte bytes[2];
    };
    data_B megab;  

void setup ()
{
    /*Serial*/
        Serial.begin(115200);
    /*I2C*/
        Wire.begin();       // Initialize As A Master I2C Device
        //Wire.setClock(clockFrequency)
}

void loop ()
{
    /*Get Data from Mega1 and Mega2*/
        getData1();
        getData2();
        if(megaa.val1 != lastval1)
        {
            MIDI.sendNoteOn(0, megaa.val1, 1);
            lastval1 = megaa.val1;
        }
        Serial.println(megaa.val1);
        delay(100);
}

void getData1()
{
  Wire.requestFrom(SLAVE_Mega1, sizeof(megaa));
  for (unsigned int i = 0; i < sizeof(megaa); i++)
    megaa.bytes[i] = Wire.read();
}
void getData2()
{
  Wire.requestFrom(SLAVE_Mega2, sizeof(megab));
  for (unsigned int i = 0; i < sizeof(megab); i++)
    megab.bytes[i] = Wire.read();
}