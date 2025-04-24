/*Project: IL2P - Feature Files*/
/*Device: Arduino UNO*/
/*Author: Liam Clark */
/*Version: 1.0.4*/

//Tests a singe DigitDisplay connected to the ports 2, 3, 4, 5, 6, 7, 8, like specified in the library

#include <digitdisplay.h>

DigitDisplay digitdisplay1;


void setup() {
    digitdisplay1 = DigitDisplay(2, 3, 4, 5, 6, 7, 8);
    digitdisplay1.begin();
}
void.loop(){
    digitdisplay1.displayNumber(0);
    delay(1000);
    digitdisplay1.displayNumber(1);
    delay(1000);
    digitdisplay1.displayNumber(2);
    delay(1000);
    digitdisplay1.displayNumber(3);
    delay(1000);
    digitdisplay1.displayNumber(4);
    delay(1000);
    digitdisplay1.displayNumber(5);
    delay(1000);
    digitdisplay1.displayNumber(6);
    delay(1000);
    digitdisplay1.displayNumber(7);
    delay(1000);
    digitdisplay1.displayNumber(8);
    delay(1000);
    digitdisplay1.displayNumber(9);
    delay(1000);
    digitdisplay1.clearDisplay();
    delay(1000);
}
