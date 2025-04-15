/*Project: IL2P.I2C-Testing*/
/*Device: UNO*/
/*Author: Liam Clark */
/*Version: 1.0.1 pre-alpha*/

#include <Wire.h>    
const int SLAVE_UNO = 1;
const int SLAVE_Mega1 = 2;
const int SLAVE_Mega2 = 3;

/*Unions*/
    union data_A
    {
    struct
    {
        int v1;
        int v2;
        int v3;
        int v4;
        int v5;
        int v6;
        int v7;
        int v8;
        int v9;
        int v10;
        int v11;
        int v12;
        int v13;
        int v14;
        int v15;
        int v16;

    };
    byte bytes[32];
    };
    data_A megaa;

void setup()
{
    /*Serial*/
        Serial.begin(115200);
    /*Wire*/
        Wire.begin(SLAVE_UNO);    // Join I2C bus with address #2
        Wire.setClock(400000); // Set I2C clock speed to 400kHz
}

void loop()
{
    getData1();
    delay(100);
    Serial.println("Data Received:");
    for (int i = 0; i < sizeof(megaa.bytes); i++) {
        Serial.print(megaa.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
}

void getData1()
{
    Wire.requestFrom(SLAVE_Mega1, sizeof(megaa));
    if (Wire.available() == sizeof(megaa)) {
        Wire.readBytes(megaa.bytes, sizeof(megaa));
    }
}

