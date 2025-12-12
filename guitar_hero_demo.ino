#include <Keyboard.h>

// Button pins
const int green = A2;
const int red = 6;
const int yellow = A3;
const int blue = 15;
const int orange = A1;

const int strumBar = A0;
const int joySwitch = 4;

// Last states for edge detection (HIGH = not pressed with INPUT_PULLUP)
bool lastGreen = HIGH;
bool lastRed = HIGH;
bool lastYellow = HIGH;
bool lastBlue = HIGH;
bool lastOrange = HIGH;
bool lastJoy = HIGH;

// Strum bar tracking
const int STRUM_CENTER = 512;  // analog midpoint (0–1023)
const int STRUM_TOLERANCE = 150;  // how far from center counts as up/down

bool strumUpHeld = false;
bool strumDownHeld = false;

void setup() {
  pinMode(green, INPUT_PULLUP);
  pinMode(red, INPUT_PULLUP);
  pinMode(yellow, INPUT_PULLUP);
  pinMode(blue, INPUT_PULLUP);
  pinMode(orange, INPUT_PULLUP);

  pinMode(joySwitch, INPUT_PULLUP);

  Keyboard.begin();
}

// Function to type a key when a button is pressed
void handleButtonPress(int pin, bool isPressed) {
  switch (pin) {
    case green:
      if (isPressed) Keyboard.press('A');
      else Keyboard.release('A');
      break;

    case red:
      if (isPressed) Keyboard.press('S');
      else Keyboard.release('S');
      break;

    case yellow:
      if (isPressed) Keyboard.press('J');
      else Keyboard.release('J');
      break;

    case blue:
      if (isPressed) Keyboard.press('K');
      else Keyboard.release('K');
      break;

    case orange:
      if (isPressed) Keyboard.press('L');
      else Keyboard.release('L');
      break;
  }
}

// Create function that maps analog regions to up/down arrow and hold while in region
void updateStrum() {
  int val = analogRead(strumBar);

  bool shouldUp = (val > STRUM_CENTER + STRUM_TOLERANCE);
  bool shouldDown = (val < STRUM_CENTER - STRUM_TOLERANCE);

  // Up arrow
  if (shouldUp && !strumUpHeld) {
    Keyboard.press(KEY_UP_ARROW);
    strumUpHeld = true;
  } else if (!shouldUp && strumUpHeld) {
    Keyboard.release(KEY_UP_ARROW);
    strumUpHeld = false;
  }

  // Down arrow
  if (shouldDown && !strumDownHeld) {
    Keyboard.press(KEY_DOWN_ARROW);
    strumDownHeld = true;
  } else if (!shouldDown && strumDownHeld) {
    Keyboard.release(KEY_DOWN_ARROW);
    strumDownHeld = false;
  }
}

void loop() {
  // Read current button states
  bool greenState = digitalRead(green);
  bool redState = digitalRead(red);
  bool yellowState = digitalRead(yellow);
  bool blueState = digitalRead(blue);
  bool orangeState = digitalRead(orange);
  bool joyState = digitalRead(joySwitch);

  // Fret buttons: press while held, release when let go
  if (greenState != lastGreen) {
    handleButtonPress(green, (greenState == LOW));
    lastGreen = greenState;
  }

  if (redState != lastRed) {
    handleButtonPress(red, (redState == LOW));
    lastRed = redState;
  }

  if (yellowState != lastYellow) {
    handleButtonPress(yellow, (yellowState == LOW));
    lastYellow = yellowState;
  }

  if (blueState != lastBlue) {
    handleButtonPress(blue, (blueState == LOW));
    lastBlue = blueState;
  }

  if (orangeState != lastOrange) {
    handleButtonPress(orange, (orangeState == LOW));
    lastOrange = orangeState;
  }

  // Joystick switch: type Return on press (edge)
  if (lastJoy == HIGH && joyState == LOW) {
    Keyboard.write(KEY_RETURN);
  }
  lastJoy = joyState;

  // Strum bar up/down handling
  updateStrum();

  delay(5);  // small debounce / smoothing
}
