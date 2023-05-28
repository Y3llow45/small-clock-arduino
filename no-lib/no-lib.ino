const int SHIFT_PIN_SHCP = 6;  // Shift register clock pin (SHCP)
const int SHIFT_PIN_STCP = 5;  // Shift register latch pin (STCP)
const int SHIFT_PIN_DS = 4;    // Shift register data pin (DS)

// Define the segment patterns for each digit (common cathode)
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

void shiftOutPattern(byte pattern) {
  // Shift out a byte pattern to the shift register
  digitalWrite(SHIFT_PIN_SHCP, LOW);
  shiftOut(SHIFT_PIN_DS, SHIFT_PIN_SHCP, LSBFIRST, pattern);
  digitalWrite(SHIFT_PIN_SHCP, HIGH);
}

void displayDigit(int digit, int value) {
  // Display a single digit on the 7-segment display
  shiftOutPattern(digitPatterns[value]);
  digitalWrite(SHIFT_PIN_STCP, LOW);
  digitalWrite(digit, LOW);
  digitalWrite(SHIFT_PIN_STCP, HIGH);
  digitalWrite(digit, HIGH);
}

void setup() {
  pinMode(SHIFT_PIN_SHCP, OUTPUT);
  pinMode(SHIFT_PIN_STCP, OUTPUT);
  pinMode(SHIFT_PIN_DS, OUTPUT);

  // Set digit pins as outputs
  pinMode(12, OUTPUT);  // Digit 0
  pinMode(11, OUTPUT);  // Digit 1
  pinMode(10, OUTPUT);  // Digit 2
  pinMode(9, OUTPUT);   // Digit 3
}

void loop() {
  // Example: Display the number 1234 on the 4-digit 7-segment display
  int number = 1234;

  // Convert the number to individual digits
  int digit1 = 1;
  int digit2 = 2;
  int digit3 = 3;
  int digit4 = 4;

  // Display each digit sequentially
  displayDigit(12, digit1);  // Digit 0
  delay(5);  // Adjust the delay as needed for brightness
  displayDigit(11, digit2);  // Digit 1
  delay(5);  // Adjust the delay as needed for brightness
  displayDigit(10, digit3);  // Digit 2
  delay(5);  // Adjust the delay as needed for brightness
  displayDigit(9, digit4);   // Digit 3
  delay(5);  // Adjust the delay as needed for brightness

  // Delay before refreshing the display
  //delay(1000);  // Delay for one second (adjust if needed)
}
