/* 
위의 코드는 bitelab 블로그의 원작자가 만든 코드입니다. 
필요하신 부분이 있으면 사용하시면 됩니다.
사용하기 전에 댓글을 남겨 주시면 감사하겠습니다. 
https://blog.naver.com/bitelab
*/

#include <Wire.h>                     // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>        // LCD 2004 I2C용 라이브러리
LiquidCrystal_I2C lcd(0x27,16,2);     //  0x3F or 0x27를 선택하여 주세요. 작동이 되지 않는 경우 0x27로 바꾸어주세요. 확인결과 0x3f가 작동하지 않을 수 있습니다.
//고유주소가 LCD마다 다르기 때문입니다.

#define trigPin1 8  // 초음파 발신핀 define은 쉽게말하면, 숫자의 이름을 정의해주는것. 
#define echoPin1 9  // 초음파 수신핀

//변수를 설정합니다. 
long duration1, distance1;

void setup() 
{
  pinMode(trigPin1,OUTPUT);   // trig를 출력 모드로 설정
  pinMode(echoPin1,INPUT);    // echo를 입력모드로 설정

  Serial.begin(9600);        //시리얼 프린트 시작
  lcd.init();                // LCD 초기화
  lcd.backlight();           // 백라이트 켜기

}

void loop() 
{
  //초음파 센서를 한번 초기화 하는 과정입니다. 마치 껏다 켯다를 하면서 거리를 초기화합니다.
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1= duration1*0.034/2;

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Distance Check");
  lcd.setCursor(4,1);
  lcd.print(distance1); lcd.print(" cm");
  delay(1000);
  lcd.setCursor(1,3);
  lcd.print("Warning from crash!");

}
