
const int BLED=9;    //Blue LED on Pin 9
const int GLED=10;   //Green LED on Pin 10
const int RLED=11;   //Red LED on Pin 11
const int BUTTON=2;    //The Button is connected to pin 2

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(A0));

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(RLED, random(256));
  analogWrite(GLED, random(256));
  analogWrite(BLED, random(256));
  delay(1000);  
}
