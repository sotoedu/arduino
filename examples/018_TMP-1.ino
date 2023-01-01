/*
Exploring Arduino - Code Listing 18-1: Temperature TMP RGB
Copyright 2020 SotoLAB ( https://github.com/sotoedu/arduino )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

# define Sensor A1

int celsius = 0;
int fahrenheit = 0;
 
void setup(){
  pinMode(Sensor, INPUT);
  Serial.begin(9600);
}

void loop(){
    celsius = map(((analogRead(Sensor) - 20) * 3.04), 0, 1023, -40, 125);
    fahrenheit = ((celsius * 9) / 5 + 32);
    Serial.print(celsius);
    Serial.print(" C, ");
    Serial.print(fahrenheit);
    Serial.println(" F");

}
