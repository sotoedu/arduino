int Relaypin1 = 7;                        //relay 신호핀 설정

void setup() {
  pinMode(Relaypin1, OUTPUT);             // 릴레이 제어 1번핀을 출력으로 설정
}

void loop() {
  digitalWrite(Relaypin1, HIGH);           //릴레이모듈(워터펌프) 동작
  delay(1000);
  digitalWrite(Relaypin1, LOW);          //릴레이모듈(워터펌프) 동작정지
  delay(500);
}
