/*
Exploring Arduino - Code Listing 7: Melody Button
Copyright 2020 SotoLAB ( https://github.com/sotoedu/arduino )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

#include "pitches.h" //Header file with pitch definitions

const int SPEAKER = 8;  //Speaker Pin
const int BUTTON = 4;      //The Button is connected to pin 2

//Note Array
int notes[] = {
 NOTE_A4, NOTE_E3, NOTE_A4, 0, 
 NOTE_A4, NOTE_E3, NOTE_A4, 0,
 NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4,
 NOTE_E4, NOTE_E3, NOTE_A4, 0
};

//The Duration of each note (in ms)
int times[] = {
 250, 250, 250, 250, 
 250, 250, 250, 250,
 125, 125, 125, 125, 125, 125, 125, 125,
 250, 250, 250, 250 
};


void setup()
{
  pinMode (BUTTON, INPUT);   //Set button as input (not required)
 //Play each note for the right duration
 
}

void loop()
{
 //Press the reset button to play again.
 if (digitalRead(BUTTON) == HIGH)
 {
  for (int i = 0; i < 20; i++)
  {
    tone(SPEAKER, notes[i], times[i]);
    delay(times[i]);
  }
 }
 
}
