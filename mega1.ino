/*Project: IL2P*/
/*Device: Elegoo_Mega1*/
/*Author: Liam Clark */
/*Version: 1.1*/

/*Libraries*/
    #include <Wire.h>
    #define NODE_ADDRESS 2
    #define PAYLOAD_SIZE 2
    byte nodePayload[PAYLOAD_SIZE]; 

    #include <SoftPWM.h>


/*Variables*/
    int vf1 = 0;            //ValueFaderNum
    int vf1last = 0;
    int vf1send = 0;
    int vf2 = 0;
    int vf2last = 0;
    int vf2send = 0;
    int vf3 = 0;
    int vf3last = 0;
    int vf3send = 0;
    int vf4 = 0;
    int vf4last = 0;
    int vf4send = 0;
    int vf5 = 0;
    int vf5last = 0;
    int vf5send = 0;
    int vf6 = 0;
    int vf6last = 0;
    int vf6send = 0;
    int vf13 = 0;
    int vf13last = 0;
    int vf13send = 0;
    int vf14 = 0;
    int vf14last = 0;
    int vf14send = 0;
    int vf15 = 0;
    int vf15last = 0;
    int vf15send = 0;
    int vf16 = 0;
    int vf16last = 0;
    int vf16send = 0;
    int vf17 = 0;
    int vf17last = 0;
    int vf17send = 0;
    int vf18 = 0;
    int vf18last = 0;
    int vf18send = 0;


    int sb1 = 0;            //StateButtonNum
    int b1 = 14;
    int sb2 = 0;
    int b2 = 15;
    int sb3 = 0;
    int b3 = 16;
    int sb4 = 0;
    int b4 = 17;
    int sb5 = 0;
    int b5 = 18;
    int sb6 = 0;
    int b6 = 19;

    





void setup()
{
    SoftPWMBegin();
    Serial.begin(9600);

    Wire.begin(NODE_ADDRESS);
//    Wire.onReceive(receiveEvent); // erstelle ein Empfangen-Ereignis
//    Wire.onRequest(requestEvent); // erstelle ein Anfrage-Ereignis


    SoftPWMSet(0, 0);       //FaderLED1
    SoftPWMSet(1, 0);       //FaderLED2
    SoftPWMSet(2, 0);       //FaderLED3
    SoftPWMSet(3, 0);       //FaderLED4
    SoftPWMSet(4, 0);       //FaderLED5
    SoftPWMSet(5, 0);       //FaderLED6
    SoftPWMSet(6, 0);       //FaderLED7
    SoftPWMSet(7, 0);       //FaderLED8
    SoftPWMSet(8, 0);       //FaderLED9
    SoftPWMSet(9, 0);       //FaderLED10
    SoftPWMSet(10, 0);      //FaderLED11
    SoftPWMSet(11, 0);      //FaderLED12

    
  


  //Interrupts
    attachInterrupt(digitalPinToInterrupt(14), bA, LOW);
    //attachInterrupt(digitalPinToInterrupt(15), bB, CHANGE);
    //attachInterrupt(digitalPinToInterrupt(16), bC, RISING);
    //attachInterrupt(digitalPinToInterrupt(17), bD, CHANGE);
    //attachInterrupt(digitalPinToInterrupt(18), bE, CHANGE);
    //attachInterrupt(digitalPinToInterrupt(19), bF, CHANGE);
    
pinMode(14, INPUT_PULLUP);
pinMode(15, INPUT_PULLUP);
pinMode(16, INPUT_PULLUP);
pinMode(17, INPUT_PULLUP);
pinMode(18, INPUT_PULLUP);
pinMode(19, INPUT_PULLUP);

}

void loop()
{
  
  //Read Faders
        vf1 = analogRead(A0);
        vf2 = analogRead(A1);
        vf3 = analogRead(A2);
        vf4 = analogRead(A3);
        vf5 = analogRead(A4);
        vf6 = analogRead(A5);
        vf13 = analogRead(A6);
        vf14 = analogRead(A7);
        vf15 = analogRead(A8);
        vf16 = analogRead(A9);
        vf17 = analogRead(A10);
        vf18 = analogRead(A11);

    //Check Fader with last value
        if (vf1 != vf1last)
        {
            vf1last = vf1;
            vf1send = map(vf1, 0, 1023, 0, 127);
        }
        if (vf2 != vf2last)
        {
            vf2last = vf2;
            vf2send = map(vf2, 0, 1023, 0, 127);
        }
        if (vf3 != vf3last)
        {
            vf3last = vf3;
            vf3send = map(vf3, 0, 1023, 0, 127);
        }
        if (vf4 != vf4last)
        {
            vf4last = vf4;
            vf4send = map(vf4, 0, 1023, 0, 127);
        }
        if (vf5 != vf5last)
        {
            vf5last = vf5;
            vf5send = map(vf5, 0, 1023, 0, 127);
        }
        if (vf6 != vf6last)
        {
            vf6last = vf6;
            vf6send = map(vf6, 0, 1023, 0, 127);
        }
        if (vf13 != vf13last)
        {
            vf13last = vf13;
            vf13send = map(vf13, 0, 1023, 0, 127);
        }
        if (vf14 != vf14last)
        {
            vf14last = vf14;
            vf14send = map(vf14, 0, 1023, 0, 127);
        }
        if (vf15 != vf15last)
        {
            vf15last = vf15;
            vf15send = map(vf15, 0, 1023, 0, 127);
        }
        if (vf16 != vf16last)
        {
            vf16last = vf16;
            vf16send = map(vf16, 0, 1023, 0, 127);
        }
        if (vf17 != vf17last)
        {
            vf17last = vf17;
            vf17send = map(vf17, 0, 1023, 0, 127);
        }
        if (vf18 != vf18last)
        {
            vf18last = vf18;
            vf18send = map(vf18, 0, 1023, 0, 127);
        }

        Serial.print("B1");
        Serial.println(sb1);

        delay(500);
}



        

void bA ()
{
    if (sb1 == 0)
    {
        sb1 = 1;
    }
    else
    {
        sb1 = 0;
    }
    Serial.print("B1");
        Serial.println(sb1);
}


void bB ()
{
    if (sb2 == 0)
    {
        sb2 = 1;
    }
    else
    {
        sb2 = 0;
    }
    Serial.print("B2");
        Serial.println(sb2);
}
void bC ()
{
    if (sb3 == 0)
    {
        sb3 = 1;
    }
    else
    {
        sb3 = 0;
    }
    Serial.print("B3");
        Serial.println(sb3);
}
void bD ()
{
    if (sb4 == 0)
    {
        sb4 = 1;
    }
    else
    {
        sb4 = 0;
    }
    Serial.print("B4");
        Serial.println(sb4);
}
void bE ()
{
    if (sb5 == 0)
    {
        sb5 = 1;
    }
    else
    {
        sb5 = 0;
    }
    Serial.print("B5");
        Serial.println(sb5);
}
void bF ()
{
    if (sb6 == 0)
    {
        sb6 = 1;
    }
    else
    {
        sb6 = 0;
    }
    Serial.print("B6");
        Serial.println(sb6);
}
