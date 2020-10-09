
void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int Soil_moisture = analogRead(A1);   //Soil_Moisture에 아날로그값 저장
  Serial.println(Soil_moisture);        //토양수분감지모듈의 아날로그 값 출력
  delay(100);
  
}
