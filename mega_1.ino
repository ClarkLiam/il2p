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
    int vf7 = 0;
    int vf7last = 0;
    int vf7send = 0;
    int vf8 = 0;
    int vf8last = 0;
    int vf8send = 0;
    int vf9 = 0;
    int vf9last = 0;
    int vf9send = 0;
    int vf10 = 0;
    int vf10last = 0;
    int vf10send = 0;
    int vf11 = 0;
    int vf11last = 0;
    int vf11send = 0;
    int vf12 = 0;
    int vf12last = 0;
    int vf12send = 0;


    int sb1 = 0;            //StateButtonNum
    int b1 = 12;
    int sb2 = 0;
    int b2 = 13;
    int sb3 = 0;
    int b3 = 14;
    int sb4 = 0;
    int b4 = 15;
    int sb5 = 0;
    int b5 = 16;
    int sb6 = 0;
    int b6 = 17;

    





void setup()
{
    SoftPWMBegin();
    Serial.begin(9600);

    Wire.begin(NODE_ADDRESS);
    Wire.onReceive(receiveEvent); // erstelle ein Empfangen-Ereignis
    Wire.onRequest(requestEvent); // erstelle ein Anfrage-Ereignis


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

    pinMode
  


  //Interrupts
    attachInterrupt(digitalPinToInterrupt(b1), b1, RISING);
    attachInterrupt(digitalPinToInterrupt(b2), b2, RISING);
    attachInterrupt(digitalPinToInterrupt(b3), b3, RISING);
    attachInterrupt(digitalPinToInterrupt(b4), b4, RISING);
    attachInterrupt(digitalPinToInterrupt(b5), b5, RISING);
    attachInterrupt(digitalPinToInterrupt(b6), b6, RISING);
    
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
        vf7 = analogRead(A6);
        vf8 = analogRead(A7);
        vf9 = analogRead(A8);
        vf10 = analogRead(A9);
        vf11 = analogRead(A10);
        vf12 = analogRead(A11);

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
        if (vf7 != vf7last)
        {
            vf7last = vf7;
            vf7send = map(vf7, 0, 1023, 0, 127);
        }
        if (vf8 != vf8last)
        {
            vf8last = vf8;
            vf8send = map(vf8, 0, 1023, 0, 127);
        }
        if (vf9 != vf9last)
        {
            vf9last = vf9;
            vf9send = map(vf9, 0, 1023, 0, 127);
        }
        if (vf10 != vf10last)
        {
            vf10last = vf10;
            vf10send = map(vf10, 0, 1023, 0, 127);
        }
        if (vf11 != vf11last)
        {
            vf11last = vf11;
            vf11send = map(vf11, 0, 1023, 0, 127);
        }
        if (vf12 != vf12last)
        {
            vf12last = vf12;
            vf12send = map(vf12, 0, 1023, 0, 127);
        }
  

}

void b1
{
    if (sb1 == 0)
    {
        sb1 = 1;
    }
    else
    {
        sb1 = 0;
    }
}
void b2
{
    if (sb2 == 0)
    {
        sb2 = 1;
    }
    else
    {
        sb2 = 0;
    }
}
void b3
{
    if (sb3 == 0)
    {
        sb3 = 1;
    }
    else
    {
        sb3 = 0;
    }
}
void b4
{
    if (sb4 == 0)
    {
        sb4 = 1;
    }
    else
    {
        sb4 = 0;
    }
}
void b5
{
    if (sb5 == 0)
    {
        sb5 = 1;
    }
    else
    {
        sb5 = 0;
    }
}
void b6
{
    if (sb6 == 0)
    {
        sb6 = 1;
    }
    else
    {
        sb6 = 0;
    }
}
