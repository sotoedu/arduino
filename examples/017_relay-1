/*
Exploring Arduino - Code Listing 17: Relay-1
Copyright 2020 SotoLAB ( https://github.com/sotoedu/arduino )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

#define Relay 8    
#define LED 13   

void setup() {
  // put your setup code here, to run once:
  pinMode(Relay , OUTPUT);       
  pinMode(LED , OUTPUT); 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Relay , HIGH);  // COM(공통단자)와 NC(Nomal Close)단자 접점형성
  delay(1000);
  digitalWrite(Relay , LOW);   // COM(공통단자)와 NO(Nomal OPEN)단자 접점형성
  delay(1000); 
}
