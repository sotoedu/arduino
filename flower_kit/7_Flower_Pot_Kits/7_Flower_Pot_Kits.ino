#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);         // LCD모듈 초기 주소 값, 영역 설정

int Relaypin1 = 7;                          // 릴레이모듈 핀을 D7로 설정
int Soil_moisture = A1;                     // 토양수분센서 핀을 A1으로 설정
int Red = 9;                                // 신호등 모듈 Red핀 설정
int Yellow = 10;                             // 신호등 모듈 Yellow핀 설정
int Green = 11;                             // 신호등 모듈 Green핀 설정


void setup() {
  lcd.init();
  Serial.begin(9600);
  lcd.backlight();                          // 백라이트 ON
  pinMode(Relaypin1, OUTPUT);               // 릴레이 제어 1번핀을 출력으로 설정
  pinMode(Red, OUTPUT);                     // Red 출력핀 설정
  pinMode(Yellow, OUTPUT);                  // Yellow 출력핀 설정
  pinMode(Green, OUTPUT);                   // Green 출력핀 설정
}

void loop() {
  Flower_kit_on();
}
void Flower_kit_on() {
  int Soil_moisture = analogRead(A1);  
  Serial.println(Soil_moisture);            //토양수분감지모듈의 아날로그 값 출력
        
  if (Soil_moisture > 800 )                 //수분 값이 900 초과의 조건
  {
    digitalWrite(Red, HIGH);                //신호등 모듈 빨간색 점등
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);
    lcd.setCursor(0, 0);                    // 0번째, 0라인
    lcd.print("Water please");              // Water please 출력
    digitalWrite(Relaypin1, HIGH);          //릴레이모듈(워터펌프)동작
  }
  if (Soil_moisture > 600 && Soil_moisture < 800)        //수분 값이 700 초과 900 미만의 조건
  {
    digitalWrite(Red, LOW);                              //신호등 모듈 노란색 점등
    digitalWrite(Yellow, HIGH);
    digitalWrite(Green, LOW);
  }
  else if (Soil_moisture < 600)                          //수분 값이 700 미만의 조건
  {
    digitalWrite(Red, LOW);                              //신호등 모듈 초록색 점등
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, HIGH);
    lcd.setCursor(0, 0);                                 // 0번째, 0라인
    lcd.print("Water enough");
    digitalWrite(Relaypin1, LOW);                        //릴레이모듈(워터펌프)동작 정지
    delay(1000);
    Flower_kit_off();                                    //동작정지 함수 호출
  }
}
void Flower_kit_off() {
    digitalWrite(Red, LOW);                               //신호등 모듈 빨간색 점등
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);
    lcd.clear();
    digitalWrite(Relaypin1, LOW);                         //릴레이모듈(워터펌프)동작
    delay(10000);                                         //동작정지 시간 설정
}
