/*
Exploring Arduino - Code Listing 3-3: Automatic Night Light Sketch
http://www.exploringarduino.com/content/ch3

Copyright 2013 Jeremy Blum ( http://www.jeremyblum.com )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

//Automatic Night Light Melody

const int SPEAKER=8;     //Speaker Pin       
const int LIGHT=0;       //Lght Sensor on Analog Pin 0

void setup()
{
  Serial.begin(9600);    //Serial Port at 9600 baud
  
  
}

void loop()
{
  for (int i = 0; i < 10; i++)
  {
    int light = analogRead(LIGHT);                  //read the light sensor
    int hertz = map(light, 0, 1023, 31, 4978);      //map the light reading
    tone(SPEAKER, hertz, 100);                      //constrain light value
    delay(100);
    noTone(8);
    delay(200);
    Serial.print("light: ");  
    Serial.println(light);
  }
  
}

