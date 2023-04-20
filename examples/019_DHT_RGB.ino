/*
Exploring Arduino - Code Listing 19: Temperature TMP RGB
Copyright 2020 SotoLAB ( https://github.com/sotoedu/arduino )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

# define Sensor A1
# define GLED 8
# define BLED 9
# define RLED 10

int celsius = 0;
int fahrenheit = 0;
 
void setup(){
  pinMode(Sensor, INPUT);
  pinMode (BLED, OUTPUT);   //Set Blue LED as Output
  pinMode (GLED, OUTPUT);   //Set Green LED as Output
  pinMode (RLED, OUTPUT);   //Set Red LED as Output
  Serial.begin(9600);
}

void RGB_color(int r_value, int g_value, int b_value)
{// RGB_color라는 함수를 만들어서 3가지 숫자를 조합하게 만드는 함수를 제작합니다.
 // 이 함수가 없다면 예를들어 빨간색을 추출하고 싶다면 analogWrite를 3번하여야합니다.
 // 하지만 이 함수를 제작하여 바로 숫자만 바꾸어 실행 할 수 있습니다!
  analogWrite(RLED, r_value);
  analogWrite(GLED, g_value);
  analogWrite(BLED, b_value);
}
 
void loop(){
    celsius = map(((analogRead(Sensor) - 20) * 3.04), 0, 1023, -40, 125);
    fahrenheit = ((celsius * 9) / 5 + 32);
    Serial.print(celsius);
    Serial.print(" C, ");
    Serial.print(fahrenheit);
    Serial.println(" F");
  
    if ( celsius < 30) {
      RGB_color(0, 0, 255); // Blue
    }
    else if ( celsius < 60) {
      RGB_color(0, 255, 0); // Green
    }
    else if ( celsius < 100) {
      RGB_color(255, 0, 0); // Red
    }
}
