#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire myWire(3, 7, 2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

const int latchPin = 5;   // Shift register latch pin
const int clockPin = 6;   // Shift register clock pin
const int dataPin = 4;    // Shift register data pin
int digits[4];

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
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
  Rtc.Begin(); // Initialize the DS1302 RTC module

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__); // Get the current compile time

  if (!Rtc.IsDateTimeValid() || Rtc.GetDateTime() < compiled) {
    Rtc.SetDateTime(compiled); // Set the current time if invalid or older than compiled time
  }
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime(); // Retrieve the current time from the RTC
  int hour = now.Hour(); // Extract the hour component
  int minute = now.Minute(); // Extract the minute component
  //int timeValue = hour*100 + minute; // Combine the hour and minute into a single value
  int hourDigit1 = hour / 10;
  int hourDigit2 = hour % 10;

  // Extract the individual digits of the minute
  int minuteDigit1 = minute / 10;
  int minuteDigit2 = minute % 10;
  //displayDigits(timeValue);
  displayDigits(hourDigit1, hourDigit2, minuteDigit1, minuteDigit2);
}

//void displayDigits(int number) {
//  digits[3] = number / 1000;
//  digits[0] = (number / 100) % 10;
//  digits[1] = (number / 10) % 10;
//  digits[2] = number % 10;
void displayDigits(int digit1, int digit2, int digit3, int digit4) {
  digits[3] = digit1;
  digits[0] = digit2;
  digits[1] = digit3;
  digits[2] = digit4;
  
  digitalWrite(digitPins[0], LOW);
  digitalWrite(digitPins[1], HIGH);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], HIGH);
  updateShiftRegister(digitPatterns[digits[0]]);
  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], LOW);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], HIGH);
  updateShiftRegister(digitPatterns[digits[1]]);
  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], HIGH);
  digitalWrite(digitPins[2], LOW);
  digitalWrite(digitPins[3], HIGH);
  updateShiftRegister(digitPatterns[digits[2]]);
  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], HIGH);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], LOW);
  updateShiftRegister(digitPatterns[digits[3]]);
  digitalWrite(digitPins[3], HIGH);
}

void updateShiftRegister(byte data) {
  delay(1);
  digitalWrite(latchPin, LOW);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, (data >> i) & 1);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(latchPin, HIGH);
}
