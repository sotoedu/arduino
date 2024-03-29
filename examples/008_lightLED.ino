/*
Exploring Arduino - Code Listing 8: Light LED
Copyright 2020 SotoLAB ( https://github.com/sotoedu/arduino )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

const int RLED = 9;        //Red LED on pin 9 (PWM)
const int LIGHT = 0;       //Lght Sensor on Analog Pin 0
const int MIN_LIGHT = 200; //Minimum expected light value
const int MAX_LIGHT = 900; //Maximum Expected Light value
int val = 0;             //variable to hold the analog reading

void setup()
{
  pinMode(RLED, OUTPUT); //Set LED pin as output
  Serial.begin(9600); //Serial Port at 9600 baud
}

void loop()
{
  val = analogRead(LIGHT);                      //read the light sensor
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0); //map the light reading - map(value, fromLow, fromHigh, toLow, toHigh);
  val = constrain(val, 0, 255);                 //constrain light value
  analogWrite(RLED, val);                       //control the LED
  Serial.print("val: ");  
  Serial.println(val);
}
