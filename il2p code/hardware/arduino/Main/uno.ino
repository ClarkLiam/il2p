/*Project: IL2P*/
/*Device: UNO (main)*/
/*Author: Liam Clark */
/*Version: 1.8.1 pre-alpha*/

#include <Wire.h>    
const int SLAVE_UNO = 1;
const int SLAVE_Mega1 = 2;
const int SLAVE_Mega2 = 3;

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

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

void setup() {
  Wire.begin(1); // Join I2C bus with address #1

  MIDI.begin();
  Serial.begin(115200);

}

void loop() {
    getData1();
    delay(50);
    getData2();
    delay(50);

    /*Midi*/
        /*MegaA*/
            if(megaa.midib1 != lastbutton1)
        {
            MIDI.sendNoteOn(0, megaa.midib1, 1);
            lastbutton1 = megaa.midib1;
        }
        if(megaa.midib2 != lastbutton2)
        {
            MIDI.sendNoteOn(1, megaa.midib2, 1);
            lastbutton2 = megaa.midib2;
        }
        if(megaa.midib3 != lastbutton3)
        {
            MIDI.sendNoteOn(2, megaa.midib3, 1);
            lastbutton3 = megaa.midib3;
        }
        if(megaa.midib4 != lastbutton4)
        {
            MIDI.sendNoteOn(3, megaa.midib4, 1);
            lastbutton4 = megaa.midib4;
        }
        if(megaa.midib5 != lastbutton5)
        {
            MIDI.sendNoteOn(4, megaa.midib5, 1);
            lastbutton5 = megaa.midib5;
        }
        if(megaa.midib6 != lastbutton6)
        {
            MIDI.sendNoteOn(5, megaa.midib6, 1);
            lastbutton6 = megaa.midib6;
        }
        if(megaa.midif1 != lastfader1)
        {
            MIDI.sendNoteOn(0, megaa.midif1, 2);
            lastfader1 = megaa.midif1;
        }
        if(megaa.midif2 != lastfader2)
        {
            MIDI.sendNoteOn(1, megaa.midif2, 2);
            lastfader2 = megaa.midif2;
        }
        if(megaa.midif3 != lastfader3)
        {
            MIDI.sendNoteOn(2, megaa.midif3, 2);
            lastfader3 = megaa.midif3;
        }
        if(megaa.midif4 != lastfader4)
        {
            MIDI.sendNoteOn(3, megaa.midif4, 2);
            lastfader4 = megaa.midif4;
        }
        if(megaa.midif5 != lastfader5)
        {
            MIDI.sendNoteOn(4, megaa.midif5, 2);
            lastfader5 = megaa.midif5;
        }
        if(megaa.midif6 != lastfader6)
        {
            MIDI.sendNoteOn(5, megaa.midif6, 2);
            lastfader6 = megaa.midif6;
        }
        if(megaa.midif13 != lastfader13)
        {
            MIDI.sendNoteOn(12, megaa.midif13, 2);
            lastfader13 = megaa.midif13;
        }
        if(megaa.midif14 != lastfader14)
        {
            MIDI.sendNoteOn(13, megaa.midif14, 2);
            lastfader14 = megaa.midif14;
        }
        if(megaa.midif15 != lastfader15)
        {
            MIDI.sendNoteOn(14, megaa.midif15, 2);
            lastfader15 = megaa.midif15;
        }
        if(megaa.midif16 != lastfader16)
        {
            MIDI.sendNoteOn(15, megaa.midif16, 2);
            lastfader16 = megaa.midif16;
        }
        if(megaa.midif17 != lastfader17)
        {
            MIDI.sendNoteOn(16, megaa.midif17, 2);
            lastfader17 = megaa.midif17;
        }
        if(megaa.midif18 != lastfader18)
        {
            MIDI.sendNoteOn(17, megaa.midif18, 2);
            lastfader18 = megaa.midif18;
        }
        /*MegaB*/
        if(megab.midib7 != lastbutton7)
        {
            MIDI.sendNoteOn(6, megab.midib7, 1);
            lastbutton7 = megab.midib7;
        }
        if(megab.midib8 != lastbutton8)
        {
            MIDI.sendNoteOn(7, megab.midib8, 1);
            lastbutton8 = megab.midib8;
        }
        if(megab.midib9 != lastbutton9)
        {
            MIDI.sendNoteOn(8, megab.midib9, 1);
            lastbutton9 = megab.midib9;
        }
        if(megab.midib10 != lastbutton10)
        {
            MIDI.sendNoteOn(9, megab.midib10, 1);
            lastbutton10 = megab.midib10;
        }
        if(megab.midib11 != lastbutton11)
        {
            MIDI.sendNoteOn(10, megab.midib11, 1);
            lastbutton11 = megab.midib11;
        }
        if(megab.midib12 != lastbutton12)
        {
            MIDI.sendNoteOn(11, megab.midib12, 1);
            lastbutton12 = megab.midib12;
        }
        if(megab.midif7 != lastfader7)
        {
            MIDI.sendNoteOn(6, megab.midif7, 2);
            lastfader7 = megab.midif7;
        }
        if(megab.midif8 != lastfader8)
        {
            MIDI.sendNoteOn(7, megab.midif8, 2);
            lastfader8 = megab.midif8;
        }
        if(megab.midif9 != lastfader9)
        {
            MIDI.sendNoteOn(8, megab.midif9, 2);
            lastfader9 = megab.midif9;
        }
        if(megab.midif10 != lastfader10)
        {
            MIDI.sendNoteOn(9, megab.midif10, 2);
            lastfader10 = megab.midif10;
        }
        if(megab.midif11 != lastfader11)
        {
            MIDI.sendNoteOn(10, megab.midif11, 2);
            lastfader11 = megab.midif11;
        }
        if(megab.midif12 != lastfader12)
        {
            MIDI.sendNoteOn(11, megab.midif12, 2);
            lastfader12 = megab.midif12;
        }
        if(megab.midif19 != lastfader19)
        {
            MIDI.sendNoteOn(18, megab.midif19, 2);
            lastfader19 = megab.midif19;
        }
        if(megab.midif20 != lastfader20)
        {
            MIDI.sendNoteOn(19, megab.midif20, 2);
            lastfader20 = megab.midif20;
        }
        if(megab.midif21 != lastfader21)
        {
            MIDI.sendNoteOn(20, megab.midif21, 2);
            lastfader21 = megab.midif21;
        }
        if(megab.midif22 != lastfader22)
        {
            MIDI.sendNoteOn(21, megab.midif22, 2);
            lastfader22 = megab.midif22;
        }
        if(megab.midif23 != lastfader23)
        {
            MIDI.sendNoteOn(22, megab.midif23, 2);
            lastfader23 = megab.midif23;
        }
        if(megab.midif24 != lastfader24)
        {
            MIDI.sendNoteOn(23, megab.midif24, 2);
            lastfader24 = megab.midif24;
        }
}



void getData1() {
  // Request 36 bytes from Mega1 (Slave Address 2)
  Wire.requestFrom(2, sizeof(megaa.bytes));
  delay(10); // Wait for the data to be available
  if (Wire.available() == sizeof(megaa.bytes)) {
    for (unsigned int i = 0; i < sizeof(megaa.bytes); i++) {
      megaa.bytes[i] = Wire.read(); // Read each byte into the union
    }

    // Debugging: Print the received data
    Serial.println("Data received from Mega1:");
    for (unsigned int i = 0; i < sizeof(megaa.bytes); i++) {
      Serial.print(megaa.bytes[i]);
      Serial.print(" ");
    }
    Serial.println();
  } else {
    Serial.println("Failed to receive data from Mega1");
  }
}

void getData2() {
  // Request 36 bytes from Mega2 (Slave Address 3)
  Wire.requestFrom(3, sizeof(megab.bytes));
  if (Wire.available() == sizeof(megab.bytes)) {
    for (unsigned int i = 0; i < sizeof(megab.bytes); i++) {
      megab.bytes[i] = Wire.read(); // Read each byte into the union
    }

    // Debugging: Print the received data
    Serial.println("Data received from Mega2:");
    for (unsigned int i = 0; i < sizeof(megab.bytes); i++) {
      Serial.print(megab.bytes[i]);
      Serial.print(" ");
    }
    Serial.println();
  } else {
    Serial.println("Failed to receive data from Mega2");
  }
}