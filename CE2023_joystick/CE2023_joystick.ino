// Simple example application that shows how to read four Arduino
// digital pins and map them to the USB Joystick library.
//
// Ground digital pins 9, 10, 11, and 12 to press the joystick 
// buttons 0, 1, 2, and 3.
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2015-11-20
//--------------------------------------------------------------------

#include <Joystick.h>

#define XAXIS_PIN A0
#define FIRST_BUTTON 2
#define NUM_BUTTONS 7

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_MULTI_AXIS, NUM_BUTTONS, 0,
  true, false, false, false, false, false, 
  false, false, false, false, false
  );

void setup() {
  // Initialize Button Pins
  for (int index = 0; index < NUM_BUTTONS; index++) 
  {
    pinMode(index + FIRST_BUTTON, INPUT_PULLUP);
  }

  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = FIRST_BUTTON;

// Last state of the button
int lastButtonState[NUM_BUTTONS] = {0,0,0,0,0,0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < NUM_BUTTONS; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
  Joystick.setXAxis(analogRead(XAXIS_PIN));

  

  delay(50);
}
