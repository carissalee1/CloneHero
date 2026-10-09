// Carissa Lee
// CMPE3815 Final Project | Drum Final Code

//
// Balloons / channels / keys:
//   Channel 0 (Yellow) -> 'J'
//   Channel 1 (Green)  -> 'A'
//   Channel 2 (Red)    -> 'S'
//   Channel 3 (Orange) -> 'L'
//   Channel 4 (Blue)   -> 'K'

#include <Wire.h>
#include "Adafruit_MPRLS.h"
#include <Keyboard.h>

// I2C multiplexer settings
#define TCA_ADDR 0x70

void tcaSelect(uint8_t channel) {
  if (channel > 7) return;
  Wire.beginTransmission(TCA_ADDR);
  Wire.write(1 << channel);
  Wire.endTransmission();
}

// pressure sensor settings
#define NUM_SENSORS 5

const uint8_t sensorChannels[NUM_SENSORS] = {0, 1, 2, 3, 4};

#define RESET_PIN -1
#define EOC_PIN   -1
Adafruit_MPRLS mpr = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

// button and hit detection constants
#define BUTTON_PIN A0
#define HIT_DELTA_PSI     0.02f
#define RELEASE_THRESHOLD 0.01f
#define COOLDOWN_MS       150

bool   zeroed[NUM_SENSORS]     = {false};
bool   hitLatched[NUM_SENSORS] = {false};
float  zeroPsi[NUM_SENSORS]    = {0.0f};
unsigned long lastHitMs[NUM_SENSORS] = {0};
bool prevBtnState = HIGH;

// key mapping
const char sensorKeys[NUM_SENSORS] = {'J', 'A', 'S', 'L', 'K'};

// pressure in PSI
static inline float readPsi() {
  float hPa = mpr.readPressure();
  return hPa / 68.947572932f;
}

// setup
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Keyboard.begin();

  // button conventions
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // checks each sensor
  for (int i = 0; i < NUM_SENSORS; i++) {
    tcaSelect(sensorChannels[i]);
    delay(5);
    if (!mpr.begin()) {
      Serial.print("MPRLS NOT found on channel ");
      Serial.println(sensorChannels[i]);
    } else {
      Serial.print("Found MPRLS on channel ");
      Serial.println(sensorChannels[i]);
    }
  }

}

// detect button press to zero sensors
void loop() {
  // create a constant boolean to define button state
  bool btn = digitalRead(BUTTON_PIN);
  // if button is pressed, zero sensors
  if (prevBtnState == HIGH && btn == LOW) {
    // print to serial monitor
    Serial.println("Zeroing all Pressure Sensors!");
    // loops through all sensors and zeros 
    for (int i = 0; i < NUM_SENSORS; i++) {
      tcaSelect(sensorChannels[i]);
      delay(5);
      zeroPsi[i] = readPsi();
      zeroed[i] = true;
      hitLatched[i] = false;
      lastHitMs[i] = 0;

      // print zeroing PSI to serial monitor
      Serial.print("  Sensor ");
      Serial.print(i);
      Serial.print(" zeroed at ");
      Serial.print(zeroPsi[i], 3);
      Serial.println(" psi");
    }
  }
  prevBtnState = btn;

  unsigned long now = millis();

  // loops through each sensor
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (!zeroed[i]) continue;
    // selects the channel currently being indexed
    tcaSelect(sensorChannels[i]);
    delay(2);

    // reads current pressure and establishes hit detection logic
    float psi = readPsi();
    float trigger = zeroPsi[i] + HIT_DELTA_PSI;
    float release = trigger - RELEASE_THRESHOLD;

    // if hit was detected, prints vlaues to the serial monitor and prints letter
    if (!hitLatched[i]) {
      if (psi >= trigger && (now - lastHitMs[i]) >= COOLDOWN_MS) {
        Serial.print("Hit on sensor ");
        Serial.print(i);
        Serial.print(" psi=");
        Serial.println(psi, 3);

        Keyboard.write(sensorKeys[i]);

        hitLatched[i] = true;
        lastHitMs[i] = now;
      }
    } else {
      if (psi <= release) {
        hitLatched[i] = false;
      }
    }
  }

  delay(5);
}
