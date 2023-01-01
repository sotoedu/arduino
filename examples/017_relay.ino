/*
Exploring Arduino - Code Listing 17: RELAY
Copyright 2020 SotoLAB ( https://github.com/sotoedu/arduino )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

#define Relay  2                            //적외선 리모턴 1번 버튼에 제어될 LED를 디지털 포트 2번에 연결시켜주세요.
 
void setup() {
  // put your setup code here, to run once:
  pinMode(Relay , OUTPUT);                 //디지털 포트 2번을 OUT으로 설정
}
 
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Relay , HIGH);               // COM(공통단자)와 NC(Nomal Close)단자 접점형성
  delay(1000);
  digitalWrite(Relay , LOW);              // COM(공통단자)와 NO(Nomal OPEN)단자 접점형성
  delay(1000); 
}
