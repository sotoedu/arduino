/*
Exploring Arduino - Code Listing 10-2: LCD Updating Progress Bar Code
http://www.exploringarduino.com/content/ch10

Copyright 2013 Jeremy Blum ( http://www.jeremyblum.com )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

//LCD with Progress Bar

//Include the library code:
#include <LiquidCrystal.h>

//Initialize the library with the numbers of the interface pins
const int Rs = 12;
const int E = 11;
const int D4 = 2;
const int D5 = 3;
const int D6 = 4;
const int D7 = 5;

// output control pins
#define LCD_CONTRAST_PIN 6

LiquidCrystal lcd(Rs, E, D4, D5, D6, D7);

byte smile[8] = {                          // 스마일 패턴

    B00000, B10001, B00000, B00000, B10001, B01110, B00000, B00000

};

byte robot[8] = {                         // 로봇 패턴

    B01110, B01110, B01110, B10100, B11111, B00101, B11100, B10111

};

//초음파센서 trig, echo핀 설정
const int distTrigPin = 8;
const int distEchoPin = 9;

void setup()
{
  analogWrite(LCD_CONTRAST_PIN, 50); //set some contrast
  //Set up the LCDs number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Smart Farm");
  lcd.createChar(0, smile); // 사용자정의 문자 생성(스마일)
  lcd.createChar(1, robot); // 사용자정의 문자 생성(로봇)

  pinMode(distTrigPin, OUTPUT);
  pinMode(distEchoPin, INPUT);

  delay(3000);          //wait
 
}

void loop()
{
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
  
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.write(byte(0)); // LCD에 스마일 출력
  lcd.write(byte(1)); // LCD에 로봇 출력
  lcd.print(" Dist: ");
  lcd.print(distance); 
  lcd.print(" CM");
  //Move cursor to second line
  lcd.setCursor(0,1);
  //Clear the line each time it reaches the end
  //with 16 " " (spaces)
  lcd.print("                ");  
  
  //Iterate through each character on the second line
  for (int i = 0; i<8; i++)
  {
    //Iterate through each progress value for each character
    for (int j=0; j<5; j++)
    {
      lcd.setCursor(i, 1); //Move the cursor to this location
      lcd.write(j);        //update progress bar
      delay(100);          //wait
    }  
  }
}

