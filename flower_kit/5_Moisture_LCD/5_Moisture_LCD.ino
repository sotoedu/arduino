#include <Wire.h>                  // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>     // LCD 1602 I2C용 라이브러리
LiquidCrystal_I2C lcd(0x27, 16, 2); // 접근주소: 0x3F or 0x27

void setup() {
  Serial.begin(9600);
  lcd.init();  // LCD 초기화
}

void loop() {
  int Soil_moisture = analogRead(A1);     //Soil_Moisture에 아날로그값 저장
  lcd.backlight();                        // 백라이트 켜기
  lcd.setCursor(1, 0);                    // 1번째, 1라인
  lcd.print("Soil_moisture");
  lcd.setCursor(4, 1);                    // 1번째, 1라인
  lcd.print(Soil_moisture);
  delay(500);
  lcd.clear();
  delay(500);
}
