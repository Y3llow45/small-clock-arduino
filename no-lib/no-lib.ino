const int latchPin = 5;   // Shift register latch pin
const int clockPin = 6;   // Shift register clock pin
const int dataPin = 4;    // Shift register data pin
byte data;

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
  displayDigits(5812);
}

void displayDigits(int number) {
  int digits[4];
  
  digits[0] = number / 1000;
  digits[1] = (number / 100) % 10;
  digits[2] = (number / 10) % 10;
  digits[3] = number % 10;
  
  for (int i = 1; i < 5; i++) {
    switch(i){
      case 1:
        digitalWrite(12, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(9, HIGH);
        // get byte data from digitPatterns[] for the current number digits[0]
        // if number is 4, data should be set to B01100110
        // call updateShiftRegister and pass data
        break;
      case 2:
        digitalWrite(12, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(9, HIGH);
        // same think from before just use digits[1] and call updateShiftRegister with propper data
        break;
      case 3:
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(9, HIGH);
        // same think from before just use digits[2] and call updateShiftRegister with propper data
        break;
      case 4:
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(9, LOW);
        // same think from before just use digits[3] and call updateShiftRegister with propper data
        break;
    }
    //for (int j = 0; j < 8; j++) { //Don't need that
    //  bitSet(currentSegment, j);
    //  updateShiftRegister();
    //  delay(200);
    //}   
    delay(1);
  }
}

void updateShiftRegister(data)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, data);
   digitalWrite(latchPin, HIGH);
}
