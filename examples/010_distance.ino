//초음파센서 trig, echo핀 설정
const int distTrigPin = 2;
const int distEchoPin = 3;
 
//3색 LED 핀 설정
const int ledRedPin = 11;
const int ledGreenPin = 10;
const int ledBluePin = 9;
 
void setup() {
  pinMode(distTrigPin, OUTPUT);
  pinMode(distEchoPin, INPUT);
  Serial.begin(9600); //Serial Port at 9600 baud
}
 
void loop() {
  analogWrite(ledRedPin, 0);
  analogWrite(ledGreenPin, 0);
  analogWrite(ledBluePin, 0);
 
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
 
  if(distance < 10) {
    analogWrite(ledRedPin, 255);
  }
  else if(distance < 20) {
    analogWrite(ledGreenPin , 255);
  }
  else if(distance < 30) {
    analogWrite(ledBluePin , 255);
  }

  Serial.print("distance: ");  
  Serial.println(distance);
 
  delay(100);
}
