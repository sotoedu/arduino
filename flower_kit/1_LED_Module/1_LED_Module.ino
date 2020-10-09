//LED신호등에 사용되는 LED 변수 지정
int Red = 9;
int Yellow = 10;
int Green = 11;


void setup() {
  //LED신호등 초기화
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
}

void loop() {
  
  digitalWrite(Red, HIGH); //빨간색 LED ON!
  digitalWrite(Yellow, LOW); //노란색 LED OFF!
  digitalWrite(Green, LOW); //초록색 LED OFF!
  delay(1000);
  digitalWrite(Red, LOW); //빨간색 LED OFF!
  digitalWrite(Yellow, HIGH); //노란색 LED ON!
  digitalWrite(Green, LOW); //초록색 LED OFF!
  delay(1000);
  digitalWrite(Red, LOW); //빨간색 LED OFF!
  digitalWrite(Yellow, LOW); //노란색 LED OFF!
  digitalWrite(Green, HIGH); //초록색 LED ON!
  delay(1000);
  
}
