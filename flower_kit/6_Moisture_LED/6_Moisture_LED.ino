int Sensor_pin = A1;  // 토양수분센서 핀을 A1으로 설정
int Red = 9;
int Yellow = 10;
int Green = 11;


void setup() {
  Serial.begin(9600);
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
}

void loop() {
  int Soil_moisture = analogRead(A1); //Soil_Moisture에 아날로그값 저장
  Serial.println(Soil_moisture); //토양수분감지모듈의 아날로그 값 출력
  delay(100);

  if (Soil_moisture < 750)
  {
    digitalWrite(Red, LOW); //빨간색 LED OFF!
    digitalWrite(Yellow, LOW); //노란색 LED OFF!
    digitalWrite(Green, HIGH); //초록색 LED ON!
  }
  else
  {
    digitalWrite(Red, HIGH); //빨간색 LED ON!
    digitalWrite(Yellow, LOW); //노란색 LED OFF!
    digitalWrite(Green, LOW); //초록색 LED OFF!
  }

}
