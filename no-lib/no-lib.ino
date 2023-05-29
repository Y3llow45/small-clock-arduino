const int latchPin = 5;   // Shift register latch pin
const int clockPin = 6;   // Shift register clock pin
const int dataPin = 4;    // Shift register data pin

const byte digitPatterns[] = {
  B00111111,  // Digit 0
  B00000110,  // Digit 1
  B01011011,  // Digit 2
  B01001111,  // Digit 3
  B01100110,  // Digit 4
  B01101101,  // Digit 5
  B01111101,  // Digit 6
  B00000111,  // Digit 7
  B01111111,  // Digit 8
  B01101111   // Digit 9
};

const int digitPins[] = {
  12,  // Digit 1
  11,  // Digit 2
  10,  // Digit 3
  9    // Digit 4
};

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
}

void loop() {
  displayDigits(1203);
}

void displayDigits(int number) {
  int digits[4];
  
  digits[3] = number / 1000;
  digits[0] = (number / 100) % 10;
  digits[1] = (number / 10) % 10;
  digits[2] = number % 10;
  
  digitalWrite(digitPins[0], LOW);
  digitalWrite(digitPins[1], HIGH);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], HIGH);
  updateShiftRegister(digitPatterns[digits[0]]);
  //delay(2);
  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], LOW);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], HIGH);
  updateShiftRegister(digitPatterns[digits[1]]);
  //delay(2);
  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], HIGH);
  digitalWrite(digitPins[2], LOW);
  digitalWrite(digitPins[3], HIGH);
  updateShiftRegister(digitPatterns[digits[2]]);
  //delay(2);
  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], HIGH);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], LOW);
  updateShiftRegister(digitPatterns[digits[3]]);
  //delay(2);
}

void updateShiftRegister(byte data) {
  delay(5);
  digitalWrite(latchPin, LOW);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, (data >> i) & 1);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(latchPin, HIGH);
}
