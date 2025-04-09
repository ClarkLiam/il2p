/*Project: IL2P-I"C Testing*/
/*Device: Elegoo_Mega1*/
/*Author: Liam Clark */
/*Version: 1.1*/

/*Libraries*/  
    #include <Wire.h>
    const int SLAVE_Mega1 = 2;


/*Union*/
union data_A
    {
    struct
    {
        int val1;

    };
    byte bytes[2];
    };
    data_A megaa; 


void setup()
{
    /*Serial*/
        Serial.begin(115200);
    /*Wire*/
        Wire.begin(2);
        Wire.onRequest(requestEvent);
}

void loop()
{
  megaa.val1 = 1;
  delay(1000);
  megaa.val1 = 0;
  delay(1000);
}

void requestEvent()
{
 Wire.write(megaa.bytes, sizeof(megaa));
}
