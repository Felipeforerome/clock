#include "Time.h"
#include "DS3231.h"


//Pin connected to ST_CP of 74HC595
int latchPin = 53;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 12;

//Pin for potentionmeter regulation brightnes
int potPin = 2;

//Values for de delay between high and low
float val = 0;
float valDelay = 3;

//Variables that will hold the time and date
int seconds;
int minutes;
int hours;
int months;
int days;
byte data;
byte dataArray[10];


// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

// Init a Time-data structure
Time  t;

void setup()
{
  // Set functions for pins
  pinMode(latchPin, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  for (int b = 22; b < 52; b++) {
    pinMode(b, OUTPUT);
  }
  for (int a = 0; a < 6; a++) {
    pinMode(a, OUTPUT);
  }
  for (int c = 14; c < 20; c++) {
    pinMode(c, OUTPUT);
  }
  for (int d = 22; d < 52; d++) {
    pinMode(d, OUTPUT);
  }
  //Serial.begin(9600);

  //Turn on the RTC
  rtc.begin();

  //Fill the dataArray with the corresponding values for hours 1-3
  dataArray[1] = 0xFF; //0b00000001
  dataArray[8] = 0xFE; //0b00000010
  dataArray[7] = 0xFC; //0b00000100
  dataArray[6] = 0xF8; //0b00001000
  dataArray[5] = 0xF0; //0b00010000
  dataArray[4] = 0xE0; //0b00100000
  dataArray[3] = 0xC0; //0b01000000
  dataArray[2] = 0x80; //0b10000000
  dataArray[0] = 0x00; //0b00000000

  //Delay to let the RTC begin
  delay(1000);
}

void loop() {
  //Turn Potentionmeter value to delay time
  val = analogRead(potPin) * 0.01667;
  valDelay = val;

  //Get seconds, minutes, and hours from the RTC
  t = rtc.getTime();
  seconds = t.sec;
  minutes = t.min;
  hours = t.hour;

  //Get the hour value indifferent of AM and PM
  int  hoursap = hours % 12;

  //Hold all hour leds of in data
  data = dataArray[0];

  //Shift out the all LEDS off data
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, data);
  digitalWrite(latchPin, 1);

  Turn off all LEDs conected to pins: 0-11,14-19,22-53
  for (int p = 0; p < 12; p++) {
    digitalWrite(p, LOW);
  }
  for (int w = 14; w < 20; w++) {
    digitalWrite(w, LOW);
  }
  for (int q = 22; q < 52; q++) {
    digitalWrite(q, LOW);
  }

  //Stay off this time
  delay(valDelay);
//  Serial.print(val);
//  Serial.print(":");
//  Serial.println(valDelay);

  //Turn off hour LEDS of hours 0-4
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  
  //Ignore extreme values of the Potentiometer
  if (valDelay > 17.04) {
    return;
  }
  else {
    //Turn each hour LED increasingly withour turning off the previous one
    if (hoursap == 0) {
      digitalWrite(7, HIGH);
      data = dataArray[0];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }

    if (hoursap == 1) {
      digitalWrite(8, HIGH);
      data = dataArray[0];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 2) {
      digitalWrite(9, HIGH);
      data = dataArray[0];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 3) {
      digitalWrite(10, HIGH);
      data = dataArray[0];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 4) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      data = dataArray[2];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 5) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      data = dataArray[3];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 6) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      data = dataArray[4];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 7) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      data = dataArray[5];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 8) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      data = dataArray[6];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 9) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      data = dataArray[7];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 10) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      data = dataArray[8];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 11) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      data = dataArray[1];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }
    if (hoursap == 12) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);
      data = dataArray[0];
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, data);
      digitalWrite(latchPin, 1);
    }

    //Call the functions to turn on or off the sets of LED that compose
    //a segment of a 7-sement display to displays the tens of the minute value
    if (minutes / 10 == 0) {
      onA2();
      onB2();
      onC2();
      onD2();
      onE2();
      onF2();
      offG2();
    }
    if (minutes / 10 == 1) {
      offA2();
      onB2();
      onC2();
      offD2();
      offE2();
      offF2();
      offG2();
    }
    if (minutes / 10 == 2) {
      onA2();
      onB2();
      offC2();
      onD2();
      onE2();
      offF2();
      onG2();
    }
    if (minutes / 10 == 3) {
      onA2();
      onB2();
      onC2();
      onD2();
      offE2();
      offF2();
      onG2();
    }
    if (minutes / 10 == 4) {
      offA2();
      onB2();
      onC2();
      offD2();
      offE2();
      onF2();
      onG2();
    }
    if (minutes / 10 == 5) {
      onA2();
      offB2();
      onC2();
      onD2();
      offE2();
      onF2();
      onG2();
    }
    if (minutes / 10 == 6) {
      onA2();
      offB2();
      onC2();
      onD2();
      onE2();
      onF2();
      onG2();
    }
    //Call the functions to turn on or off the sets of LED that compose
    //a segment of a 7-sement display to displays the ones of the minute value
    if (minutes % 10 == 1) {
      offA1();
      onB1();
      onC1();
      offD1();
      offE1();
      offF1();
      offG1();
    }
    if (minutes % 10 == 2) {
      onA1();
      onB1();
      offC1();
      onD1();
      onE1();
      offF1();
      onG1();
    }
    if (minutes % 10 == 3) {
      onA1();
      onB1();
      onC1();
      onD1();
      offE1();
      offF1();
      onG1();
    }
    if (minutes % 10 == 4) {
      offA1();
      onB1();
      onC1();
      offD1();
      offE1();
      onF1();
      onG1();
    }
    if (minutes % 10 == 5) {
      onA1();
      offB1();
      onC1();
      onD1();
      offE1();
      onF1();
      onG1();
    }
    if (minutes % 10 == 6) {
      onA1();
      offB1();
      onC1();
      onD1();
      onE1();
      onF1();
      onG1();
    }
    if (minutes % 10 == 7) {
      onA1();
      onB1();
      onC1();
      offD1();
      offE1();
      offF1();
      offG1();
    }
    if (minutes % 10 == 8) {
      onA1();
      onB1();
      onC1();
      onD1();
      onE1();
      onF1();
      onG1();
    }
    if (minutes % 10 == 9) {
      onA1();
      onB1();
      onC1();
      onD1();
      offE1();
      onF1();
      onG1();
    }
    if (minutes % 10 == 0) {
      onA1();
      onB1();
      onC1();
      onD1();
      onE1();
      onF1();
      offG1();
    }
  }
  //Time spent off
  delay(1023 * 0.01667 - valDelay);
}

//Function to shiftOut the hour LEDs state (On/Off)
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i = 0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights.
  for (i = 7; i >= 0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1 << i) ) {
      pinState = 1;
    }
    else {
      pinState = 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }
  //stop shifting
  digitalWrite(myClockPin, 0);
}

//Functions that group leds in a 7-segment fashion, as a on or off segment
void onA1 () {
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
}

void onB1 () {
  digitalWrite(2, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(6, HIGH);
}

void onC1 () {
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
}

void onD1 () {
  digitalWrite(17, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
}

void onE1 () {
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
}

void onF1 () {
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
}

void onG1 () {
  digitalWrite(28, HIGH);
  digitalWrite(29, HIGH);
  digitalWrite(30, HIGH);
}

void onA2 () {
  digitalWrite(31, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
}

void onB2 () {
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
}

void onC2 () {
  digitalWrite(37, HIGH);
  digitalWrite(38, HIGH);
  digitalWrite(39, HIGH);
}

void onD2 () {
  digitalWrite(40, HIGH);
  digitalWrite(41, HIGH);
  digitalWrite(42, HIGH);
}

void onE2 () {
  digitalWrite(43, HIGH);
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
}

void onF2 () {
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  digitalWrite(48, HIGH);
}

void onG2 () {
  digitalWrite(49, HIGH);
  digitalWrite(50, HIGH);
  digitalWrite(51, HIGH);
}
void offA1 () {
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
}

void offB1 () {
  digitalWrite(2, LOW);
  digitalWrite(1, LOW);
  digitalWrite(0, LOW);
}

void offC1 () {
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
}

void offD1 () {
  digitalWrite(17, LOW);
  digitalWrite(18, LOW);
  digitalWrite(19, LOW);
}

void offE1 () {
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);
  digitalWrite(24, LOW);
}

void offF1 () {
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
}

void offG1 () {
  digitalWrite(28, LOW);
  digitalWrite(29, LOW);
  digitalWrite(30, LOW);
}

void offA2 () {
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
}

void offB2 () {
  digitalWrite(34, LOW);
  digitalWrite(35, LOW);
  digitalWrite(36, LOW);
}

void offC2 () {
  digitalWrite(37, LOW);
  digitalWrite(38, LOW);
  digitalWrite(39, LOW);
}

void offD2 () {
  digitalWrite(40, LOW);
  digitalWrite(41, LOW);
  digitalWrite(42, LOW);
}

void offE2 () {
  digitalWrite(43, LOW);
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
}

void offF2 () {
  digitalWrite(46, LOW);
  digitalWrite(47, LOW);
  digitalWrite(48, LOW);
}

void offG2 () {
  digitalWrite(49, LOW);
  digitalWrite(50, LOW);
  digitalWrite(51, LOW);
}
