/*
Exploring Arduino - Code Listing 11: Distance Melody
Copyright 2020 SotoLAB ( https://github.com/sotoedu/arduino )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

//초음파센서 trig, echo핀 설정
const int distEchoPin = 2;
const int distTrigPin = 3;

const int SPEAKER=8;  //Speaker Pin

void setup() {
  pinMode(distTrigPin, OUTPUT);
  pinMode(distEchoPin, INPUT);
  Serial.begin(9600); //Serial Port at 9600 baud
}
 
void loop() {
 
  //거리 측정
  digitalWrite(distTrigPin, HIGH); //스위치 온
  // 1sec = 1000 ms, 1ms = 1000 microSec
  delayMicroseconds(10);
  digitalWrite(distTrigPin, LOW); //잠깐 쉬고 바로 꺼줌
 
  //pulseIn: pin이 HIGH가 될 때까지의 시간을 구함
  //최대 1초까지 대기, 대기 중 HIGH가 안된다면 0으로 반환
  long duration = pulseIn(distEchoPin, HIGH);
  if(duration == 0) {
    return;
  }
 
  // 29.1를 나누면 cm단위, 왕복이기 때문에 58.2
  long distance = duration / 58.2;

  Serial.print("distance: ");  
  Serial.println(distance);
 
  tone(SPEAKER, 1000, 20);
  delay(20);
  noTone(8);
  delay(2 * distance);
}
