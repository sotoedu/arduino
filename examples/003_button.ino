/*
Exploring Arduino - Code Listing 3: Button-LED
Copyright 2020 SotoLAB ( https://github.com/sotoedu/arduino )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

const int LED = 13;      //The LED is connected to pin 13
const int BUTTON = 8;      //The Button is connected to pin 8

void setup()
{
  pinMode (LED, OUTPUT);     //Set the LED pin as an output
  pinMode (BUTTON, INPUT);   //Set button as input (not required)
}

void loop()
{
  if (digitalRead(BUTTON) == LOW)
  {
    digitalWrite(LED, LOW);
  }
  else
  {
    digitalWrite(LED, HIGH);
  }
}
