/*Project: IL2P - Feature Files*/
/*Device: Arduino UNO*/
/*Author: Liam Clark */
/*Version: 1.0.1*/

// Tests the midi output

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();



void loop() {
    /*Midi*/
    for(int i = 0; i < 255; i++=>){         
        MIDI.sendNoteOn(2, i, 0);       //Fader 1
        MIDI.sendNoteOn(2, i+5, 1);     //Fader 2
        MIDI.sendNoteOn(2, i+10, 2);    //Fader 3
        MIDI.sendNoteOn(2, i+15, 3);    //Fader 4
        MIDI.sendNoteOn(2, i+20, 4);    //Fader 5
        MIDI.sendNoteOn(2, i+25, 5);    //Fader 6
        MIDI.sendNoteOn(2, i+30, 6);    //Fader 7
        MIDI.sendNoteOn(2, i+35, 7);    //Fader 8
        MIDI.sendNoteOn(2, i+40, 8);    //Fader 9
        MIDI.sendNoteOn(2, i+45, 9);    //Fader 10
        MIDI.sendNoteOn(2, i+50, 10);   //Fader 11
        MIDI.sendNoteOn(2, i+55, 11);   //Fader 12
        MIDI.sendNoteOn(2, i+60, 12);   //Fader 13
        MIDI.sendNoteOn(2, i+65, 13);   //Fader 14
        MIDI.sendNoteOn(2, i+70, 14);   //Fader 15
        MIDI.sendNoteOn(2, i+75, 15);   //Fader 16
        MIDI.sendNoteOn(2, i+80, 16);   //Fader 17
        MIDI.sendNoteOn(2, i+85, 17);   //Fader 18
        MIDI.sendNoteOn(2, i+90, 18);   //Fader 19
        MIDI.sendNoteOn(2, i+95, 19);   //Fader 20
        MIDI.sendNoteOn(2, i+100, 20);  //Fader 21
        MIDI.sendNoteOn(2, i+105, 21);  //Fader 22
        MIDI.sendNoteOn(2, i+110, 22);  //Fader 23
        MIDI.sendNoteOn(2, i+115, 23);  //Fader 24

        MIDI.sendNoteOn(3, i+120, 0);   //Fader GrandMaster
        MIDI.sendNoteOn(3, i+125, 1);   //Fader SubMasterA
        MIDI.sendNoteOn(3, i+130, 2);   //Fader SubMasterB
        MIDI.sendNoteOn(3, i+135, 3);   //Fader Sequencer
        MIDI.sendNoteOn(3, i+140, 4);   //Fader Aux
        MIDI.sendNoteOn(3, i+145, 5);   //Fader FadeTime
        MIDI.sendNoteOn(3, i+150, 6);   //Fader speed

        if(i < 50){
            MIDI.sendNoteOn(1, 255, 0); //Button 1
            MIDI.sendNoteOn(1, 255, 1); //Button 2
            MIDI.sendNoteOn(1, 255, 2); //Button 3
            MIDI.sendNoteOn(1, 255, 3); //Button 4
            MIDI.sendNoteOn(1, 255, 4); //Button 5
            MIDI.sendNoteOn(1, 255, 5); //Button 6
            MIDI.sendNoteOn(1, 255, 6); //Button 7
            MIDI.sendNoteOn(1, 255, 7); //Button 8
            MIDI.sendNoteOn(1, 255, 8); //Button 9
            MIDI.sendNoteOn(1, 255, 9); //Button 10
            MIDI.sendNoteOn(1, 255, 10); //Button 11
            MIDI.sendNoteOn(1, 255, 11); //Button 12
        }else{
            MIDI.sendNoteOn(1, 0, 0); //Button 1
            MIDI.sendNoteOn(1, 0, 1); //Button 2
            MIDI.sendNoteOn(1, 0, 2); //Button 3
            MIDI.sendNoteOn(1, 0, 3); //Button 4
            MIDI.sendNoteOn(1, 0, 4); //Button 5
            MIDI.sendNoteOn(1, 0, 5); //Button 6
            MIDI.sendNoteOn(1, 0, 6); //Button 7
            MIDI.sendNoteOn(1, 0, 7); //Button 8
            MIDI.sendNoteOn(1, 0, 8); //Button 9
            MIDI.sendNoteOn(1, 0, 9); //Button 10
            MIDI.sendNoteOn(1, 0, 10); //Button 11
            MIDI.sendNoteOn(1, 0, 11); //Button 12

            if(i < 100){
                MIDI.sendNoteOn(3, 255, 7); //Button Delete 
                MIDI.sendNoteOn(3, 255, 8); //Button Store
                MIDI.sendNoteOn(3, 255, 9); //Button Modify
                MIDI.sendNoteOn(3, 255, 10); //Button Sound Up
                MIDI.sendNoteOn(3, 255, 11); //Button Sound Down
                MIDI.sendNoteOn(3, 255, 12); //Button Flash Mode
                MIDI.sendNoteOn(3, 255, 13); //Button Flash Up
                MIDI.sendNoteOn(3, 255, 14); //Button Flash Down
                MIDI.sendNoteOn(3, 255, 15); //Button Chaser Mode
                MIDI.sendNoteOn(3, 255, 16); //Button Chaser Mode Up
                MIDI.sendNoteOn(3, 255, 17); //Button Chaser Mode Down
                MIDI.sendNoteOn(3, 255, 18); //Button Chaser Mode Stop
                MIDI.sendNoteOn(3, 255, 19); //Button Chaser Mode Start
                MIDI.sendNoteOn(3, 255, 20); //Button Audio Mode
                MIDI.sendNoteOn(3, 255, 21); //Button AM Up
                MIDI.sendNoteOn(3, 255, 22); //Button AM Down
                MIDI.sendNoteOn(3, 255, 23); //ButtonA
                MIDI.sendNoteOn(3, 255, 24); //ButtonB
                MIDI.sendNoteOn(3, 255, 25); //Button Sequencer
                MIDI.sendNoteOn(3, 255, 26); //Button Aux
                MIDI.sendNoteOn(3, 255, 27); //Button DBO
        }else{
            MIDI.sendNoteOn(3, 0, 7); //Button Delete 
            MIDI.sendNoteOn(3, 0, 8); //Button Store
            MIDI.sendNoteOn(3, 0, 9); //Button Modify
            MIDI.sendNoteOn(3, 0, 10); //Button Sound Up
            MIDI.sendNoteOn(3, 0, 11); //Button Sound Down
            MIDI.sendNoteOn(3, 0, 12); //Button Flash Mode
            MIDI.sendNoteOn(3, 0, 13); //Button Flash Up
            MIDI.sendNoteOn(3, 0, 14); //Button Flash Down
            MIDI.sendNoteOn(3, 0, 15); //Button Chaser Mode
            MIDI.sendNoteOn(3, 0, 16); //Button Chaser Mode Up
            MIDI.sendNoteOn(3, 0, 17); //Button Chaser Mode Down
            MIDI.sendNoteOn(3, 0, 18); //Button Chaser Mode Stop
            MIDI.sendNoteOn(3, 0, 19); //Button Chaser Mode Start
            MIDI.sendNoteOn(3, 0, 20); //Button Audio Mode
            MIDI.sendNoteOn(3, 0, 21); //Button AM Up
            MIDI.sendNoteOn(3, 0, 22); //Button AM Down
            MIDI.sendNoteOn(3, 0, 23); //ButtonA
            MIDI.sendNoteOn(3, 0, 24); //ButtonB
            MIDI.sendNoteOn(3, 0, 25); //Button Sequencer
            MIDI.sendNoteOn(3, 0, 26); //Button Aux
            MIDI.sendNoteOn(3, 0, 27); //Button DBO
        }
    }
}