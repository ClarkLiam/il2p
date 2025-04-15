/*Project: IL2P.I2C-Testing*/
/*Device: Mega (1)*/
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
        Wire.begin(SLAVE_Mega1);    // Join I2C bus with address #2
        Wire.setClock(400000); // Set I2C clock speed to 400kHz
        Wire.onRequest(sendData);
}

void loop()
{
    for(int i = 0; i < 100; i++){
            megaa.v1 = i;
            megaa.v2 = i + 1;
            megaa.v3 = i + 2;
            megaa.v4 = i + 3;
            megaa.v5 = i + 4;
            megaa.v6 = i + 5;
            megaa.v7 = i + 6;
            megaa.v8 = i + 7;
            megaa.v9 = i + 8;
            megaa.v10 = i + 9;
            megaa.v11 = i + 10;
            megaa.v12 = i + 11;
            megaa.v13 = i + 12;
            megaa.v14 = i + 13;
            megaa.v15 = i + 14;
            megaa.v16 = i + 15;

            delay(100);
    }
}

void sendData()
{
    Wire.write(megaa.bytes, sizeof(megaa));
    Serial.println("Data Sent:");
    for (int i = 0; i < sizeof(megaa.bytes); i++) {
        Serial.print(megaa.bytes[i]);
        Serial.print(" ");
    }
    Serial.println();
}
