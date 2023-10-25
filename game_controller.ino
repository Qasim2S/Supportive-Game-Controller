// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//--------------------------------------------------------------------

#include <Joystick.h>

int xPin = A2; //x pin of the joy stick is connected to Analog pin 2
int yPin = A3; //y pin of the joy stick is connected to analog pin 3

int xPosition = 0; //starting value is 0 for the x value
int yPosition = 0; //starting value is 0 for the y value


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  12, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

int lBut1 = 0;
int lBut2 = 0;
int lBut3 = 0;
int lBut4 = 0;
int lBut5 = 0;
int lBut6 = 0;
int lBut7 = 0;
int lBut8 = 0;
int lBut9 = 0;
int lBut10 = 0;
int lBut11 = 0;
int lBut12 = 0;

void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
 pinMode(16, INPUT_PULLUP);

pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(0, 1023);
}

// Last state of the buttons
int lastButtonState[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {
xPosition = analogRead(xPin);
yPosition = analogRead(yPin);

// when connecting into the board the pins were reversed. Hence I managed to correct it in software below for the x and y pins. Also, the directions were reverse, so subtracting from 1023 to get
// the inverse values
Joystick.setYAxis(1023-xPosition);
  Joystick.setXAxis(1023-yPosition);

//But1 is the current value of button1. lBut1 is the last value of Button1
// The if statement compares the current value and last value and will update the joystick values
// only if the values don't match
// before exiting the if statement set the lBut1 to the now Button value.
// Also Buttons in Joystick are labelled 1 to 12. But in Arduino the digital pins are 2 to 10 and then 14, 15, 16. So note the digital read values.
// And the setButton is a 12 member array from (0 to 11).
int But1 = digitalRead(2);
if (But1 != lBut1) {
  Joystick.setButton(0, !But1);
  lBut1 = But1;
}
int But2 = digitalRead(3);
if (But2 != lBut2) {
  Joystick.setButton(1, !But2);
  lBut2 = But2;
}
int But3 = digitalRead(4);
if (But3 != lBut3) {
  Joystick.setButton(2, !But3);
  lBut3 = But3;
}
int But4 = digitalRead(5);
if (But4 != lBut4) {
  Joystick.setButton(3, But4);
  lBut4 = But4;
}
int But5 = digitalRead(6);
if (But5 != lBut5) {
  Joystick.setButton(4, !But5);
  lBut5 = But5;
}
int But6 = digitalRead(7);
if (But6 != lBut6) {
  Joystick.setButton(5, But6);
  lBut6 = But6;
}
int But7 = digitalRead(8);
if (But7 != lBut7) {
  Joystick.setButton(6, !But7);
  lBut7 = But7;
}
int But8 = digitalRead(9);
if (But8 != lBut8) {
  Joystick.setButton(7, But8);
  lBut8 = But8;
}
int But9 = digitalRead(10);
if (But9 != lBut9) {
  Joystick.setButton(8, !But9);
  lBut9 = But9;
}
int But10 = digitalRead(14);
if (But10 != lBut10) {
  Joystick.setButton(9, !But10);
  lBut10 = But10;
}
int But11 = digitalRead(15);
if (But11 != lBut11) {
  Joystick.setButton(10, But11);
  lBut11 = But11;
}
int But12 = digitalRead(16);
if (But12 != lBut12) {
  Joystick.setButton(11, !But12);
  lBut12 = But12;
}
 delay(10);
}
