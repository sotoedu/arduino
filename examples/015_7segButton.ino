//#define CATHODE
int segPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int digit = 0;
const int BUTTON1=11;   //The Button is connected to pin 11
const int BUTTON2=12;   //The Button is connected to pin 12

byte digits[10][7] = {
#ifdef CATHODE
  // Cathode
  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 1, 0, 1, 1 } // 9

#else
  // Anode
  { 0, 0, 0, 0, 0, 0, 1 }, // 0
  { 1, 0, 0, 1, 1, 1, 1 }, // 1
  { 0, 0, 1, 0, 0, 1, 0 }, // 2
  { 0, 0, 0, 0, 1, 1, 0 }, // 3
  { 1, 0, 0, 1, 1, 0, 0 }, // 4
  { 0, 1, 0, 0, 1, 0, 0 }, // 5
  { 0, 1, 0, 0, 0, 0, 0 }, // 6
  { 0, 0, 0, 1, 1, 1, 1 }, // 7
  { 0, 0, 0, 0, 0, 0, 0 }, // 8
  { 0, 0, 0, 0, 1, 0, 0 } // 9

#endif
};


void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  
  for (int i = 0; i < 8; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  digitalWrite(segPins[7], HIGH);
}

void loop() {
  if (digitalRead(BUTTON1) == HIGH)
  {
    ++digit;
    if (digit > 9)
    {
      digit = 0;
    }
  }

  if (digitalRead(BUTTON2) == HIGH)
  {
    --digit;
    if (digit < 0)
    {
      digit = 9;
    }
  }

  displayDigit(digit);
  delay(200);
 
}

void displayDigit(int idx)
{
  int pin = 2;
  for (int j = 0; j < 7; j++) {
    digitalWrite(pin + j, digits[idx][j]);
  }
}
