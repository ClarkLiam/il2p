/*Project: IL2P - Feature Files*/
/*Device: Arduino UNO*/
/*Author: Liam Clark */
/*Version: 1.0.5*/

// Tests a tow DigitDisplay connected to the ports 0, 1, 2, 3, 4, 5, 6, and 7, 8, 9, 10, 11, 12, 13 as specified in the library

#include <digitdisplay.h>




// Declare digitDisplay as a global variable
DigitDisplay digitDisplay1(0, 1, 2, 3, 4, 5, 6);
DigitDisplay digitDisplay2(7, 8, 9, 10, 11, 12, 13);


void setup() {
    digitDisplay1.begin();
    digitDisplay2.begin();
}
void loop(){

    digitDisplay1.displayNumber(0);
    digitDisplay2.displayNumber(9);
    delay(1000);
    digitDisplay1.displayNumber(1);
    digitDisplay2.displayNumber(8);
    delay(1000);
    digitDisplay1.displayNumber(2);
    digitDisplay2.displayNumber(7);
    delay(1000);
    digitDisplay1.displayNumber(3);
    digitDisplay2.displayNumber(6);
    delay(1000);
    digitDisplay1.displayNumber(4);
    digitDisplay2.displayNumber(5);
    delay(1000);
    digitDisplay1.displayNumber(5);
    digitDisplay2.displayNumber(4);
    delay(1000);
    digitDisplay1.displayNumber(6);
    digitDisplay2.displayNumber(3);
    delay(1000);
    digitDisplay1.displayNumber(7);
    digitDisplay2.displayNumber(2);
    delay(1000);
    digitDisplay1.displayNumber(8);
    digitDisplay2.displayNumber(1);
    delay(1000);
    digitDisplay1.displayNumber(9);
    digitDisplay2.displayNumber(0);
    delay(1000);
}
