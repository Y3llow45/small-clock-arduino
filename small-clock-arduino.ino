#include <SevSegShift.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire myWire(3, 7, 2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

#define SHIFT_PIN_SHCP 6
#define SHIFT_PIN_STCP 5
#define SHIFT_PIN_DS 4
int timeValue = 9999;
SevSegShift sevseg(SHIFT_PIN_DS, SHIFT_PIN_SHCP, SHIFT_PIN_STCP, 1, true);

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {12, 11, 10, 9}; // These are the PINS of the ** Arduino **
  byte segmentPins[] = {0, 1, 2, 3, 4, 5, 6, 7}; // These are the PINs of the ** Shift register **
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(100);
  Serial.begin(9600);

  Rtc.Begin(); // Initialize the DS1302 RTC module

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__); // Get the current compile time

  if (!Rtc.IsDateTimeValid() || Rtc.GetDateTime() < compiled) {
    Rtc.SetDateTime(compiled); // Set the current time if invalid or older than compiled time
  }
}

void loop() {
  sevseg.setNumber(timeValue); // Display the current time on the 7-segment display
  sevseg.refreshDisplay(); // Must run repeatedly; don't use blocking code (ex: delay()) in the loop() function or this won't work right
  RtcDateTime now = Rtc.GetDateTime(); // Retrieve the current time from the RTC
  int hour = now.Hour(); // Extract the hour component
  int minute = now.Minute(); // Extract the minute component

  int timeValue = hour * 60 + minute; // Combine the hour and minute into a single value
  //Serial.print("Current Time: ");
  //Serial.print(hour);
  //Serial.print(":");
  //Serial.print(minute);
  //Serial.println();

  //delay(10); // Delay for one second (adjust if needed)
}
