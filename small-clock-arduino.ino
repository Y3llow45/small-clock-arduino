#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire myWire(3, 7, 2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  Serial.begin(9600);
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
  int timeValue = hour*100 + minute; // Combine the hour and minute into a single value
  delay(200); // Delay for one second (adjust if needed)
}
