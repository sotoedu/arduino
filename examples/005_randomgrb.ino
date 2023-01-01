/*
Exploring Arduino - Code Listing 5: RGB LED Random

Copyright 2020 SotoLAB ( https://github.com/sotoedu/arduino )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/


const int GLED=8;    //Green LED on Pin 8
const int BLED=9;    //Blue LED on Pin 9
const int RLED=10;   //Red LED on Pin 10
const int BUTTON=2;    //The Button is connected to pin 2

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(A0));
  Serial.begin(9600); //Serial Port at 9600 baud

}

void RGB_color(int r_value, int g_value, int b_value)
{// RGB_color라는 함수를 만들어서 3가지 숫자를 조합하게 만드는 함수를 제작합니다.
 // 이 함수가 없다면 예를들어 빨간색을 추출하고 싶다면 analogWrite를 3번하여야합니다.
 // 하지만 이 함수를 제작하여 바로 숫자만 바꾸어 실행 할 수 있습니다!
  analogWrite(RLED, r_value);
  analogWrite(GLED, g_value);
  analogWrite(BLED, b_value);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(RLED, random(256));
  analogWrite(GLED, random(256));
  analogWrite(BLED, random(256));
  delay(1000);  
  Serial.print("random: ");  
  Serial.println(random(256));
  RGB_color(0, 0, 255); // Blue
  delay(1000);  
}
