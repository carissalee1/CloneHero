
#include <Keyboard.h>

#define BUTTON_PIN 2   // connect button to pin 2 and GND

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // button active LOW
  Keyboard.begin();
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  // button pressed when pulled LOW
  if (buttonState == LOW) {
    Keyboard.print("A");
    delay(200); // simple debounce + prevents spamming
  }
}


void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  // if a button press is detected
  if (buttonState == LOW) {
    Keyboard.print("A");
    delay(50); // easy debounce
  }
}
