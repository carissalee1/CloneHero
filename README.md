
# Microcontroller-Based Clone Hero Guitar and Drum Controllers

Embedded Systems | Hardware Design | PCB Design | CAD | Microcontroller Programming

## Project Overview

This project involved the design and development of custom guitar and drum controllers for _Clone Hero_, a music-based rhythm video game. The objective was to integrate physical inputs with a microcontroller-based system capable of translating user interactions into digital commands recognized by the game. The completed project was showcased at the 2026 Women Can Do tabling event, where it served as an interactive demonstration to engage high school students and encourage their interest in electrical engineering.

## Project Objectives

- Design and assemble functional guitar and drum controllers compatible with _Clone Hero_
- Interface physical buttons, switches, joysticks, and pressure sensors with a microcontroller
- Develop firmware to detect and process various user inputs
- Design a PCB to house electronic components
- 3D print a housing unit for the guitar controller
- Test controller functionality and reliability

## Hardware

| Component | Function |
|---|---|
| Arduino Pro Micro (ATmega32U4) | Processes inputs and communicates with the computer through native USB HID |
| LED Push Buttons | Detect guitar fret inputs and provide visual indication |
| Two-Axis Joystick Module | Detects upward and downward strumming and provides a navigation button |
| Adafruit MPRLS I2C Pressure Sensors (5) | Measure pressure changes within the balloons to detect drum strikes |
| TCA9548A I2C Multiplexer | Allows communication with five pressure sensors sharing the same I2C address |
| Zeroing Push Button | Calibrates all five pressure sensors to their current baseline pressure |
| Flexible Tubing and Balloons | Transfer mechanical drum strikes into measurable air pressure changes |
| Wiring and Connectors | Provide electrical connections between components |
| PLA Guitar Housing | Provides mechanical support for guitar components |
| Cardboard Drum Housing | Secures individual balloons and allows access to electrical components |
| Computer | Runs Clone Hero and receives controller inputs |

## System Architecture

1. _Input Detection_: Physical interaction with the user through fret buttons, joystick movement, and pressure-sensitive balloons.
2. _Signal Processing_: The microcontroller reads digital button states, analog joystick values, and I2C pressure sensor measurements.
3. _Input Mapping_: Detected actions are mapped to predefined keyboard commands recognized by Clone Hero.
4. _Communication_: The ATmega32U4 uses native USB Human Interface Device (HID) functionality to transmit keyboard inputs directly to the computer.
5. _Game Response_: Clone Hero interprets the commands as guitar or drum controller inputs.

## Software Implementation

The embedded firmware is responsible for monitoring live input signals and converting them into meaningful in-game commands. Separate firmware was developed for the guitar and drum controllers.

Primary programming considerations:
- Selecting a microcontroller with native USB HID keyboard emulation capabilities
- Input mapping and controller logic
- Digital button detection and analog joystick thresholding
- I2C communication and multiplexer channel selection
- Pressure sensor calibration and threshold-based drum hit detection
- Debouncing, input state tracking, and timing responsiveness
- Communication between hardware and software

_Programming Language_: C/C++  
_Microcontroller_: Arduino Pro Micro with ATmega32U4 chip  
_Development Environment_: Arduino IDE  
_Libraries_: Keyboard.h, Wire.h, Adafruit_MPRLS.h

## Design and Implementation

_Guitar Controller_: The guitar controller utilized five LED-illuminated fret buttons and a joystick serving as the strumming mechanism. Each fret button functioned as a digital input using the microcontroller's internal pull-up resistors, registering a button press and transmitting the corresponding command to the game. The joystick's vertical axis was monitored through an analog input, with upper and lower thresholds used to detect upward and downward strumming. The joystick's integrated push button also provided a navigation input. A large external housing was 3D printed using a hollow guitar model obtained from an online repository. The PLA housing was modified using drilling and assembly techniques to accommodate the buttons, joystick, and electrical components.

_Drum Controller_: The drum controller consisted of five balloons connected via flexible tubing to individual Adafruit MPRLS I2C pressure sensors. When a balloon was struck, the resulting increase in internal air pressure was detected by its corresponding sensor. Because all five pressure sensors shared the same I2C address, a TCA9548A I2C multiplexer was implemented to allow the microcontroller to communicate with each sensor individually. A zeroing button was implemented to calibrate the pressure sensors by setting their current readings as the baseline when pressed. This established a consistent reference across all five balloons, accounting for differences in their initial internal pressures and improving the consistency of drum hit detection. The microcontroller continuously monitored pressure changes and registered a drum hit when the measured pressure exceeded a predefined threshold of 0.02 PSI above the calibrated baseline. Additional release thresholds and cooldown timing were implemented to prevent repeated or unintended hit detection. This design enabled the conversion of physical drum strikes into digital game inputs. The external housing was constructed using interconnected cardboard boxes, each designed to securely hold an individual balloon in place during operation.

## Testing and Troubleshooting

A primary consideration in the hardware selection process was identifying a cost-effective microcontroller capable of supporting keyboard input emulation. The project initially utilized an Arduino Mega; however, further research identified the ATmega32U4 microcontroller as a more suitable option due to its native USB Human Interface Device (HID) capabilities. Consequently, an Arduino Pro Micro was selected to enable direct keyboard input emulation and key mapping for compatibility with Clone Hero.

Initial keyboard mapping was verified by connecting a single push button to the microcontroller and confirming that a button press generated the corresponding keyboard character. This established proof of concept for USB HID communication before expanding the system to five fret buttons and joystick-based strumming.

For the drum controller, initial testing was performed using a single pressure sensor and balloon to determine appropriate hit detection parameters. A pressure change threshold of 0.02 PSI was selected to register intentional drum strikes. A release threshold of 0.01 PSI below the trigger level and a 150 ms cooldown were incorporated to reduce repeated triggering. The system was subsequently expanded to five pressure sensors using the TCA9548A multiplexer, with serial monitor outputs used to verify sensor calibration and hit detection.

Both controllers were successfully tested with Clone Hero, demonstrating functional keyboard mapping and responsive gameplay inputs.

## Project Media

_Guitar Controller_

### Guitar Controller Design

<p align="center">
  <img src="images/GuitarController_Physical_Design_Iteration1" width="48%">
  <img src="images/GuitarController_Key_Binding_Map" width="48%">
</p>

<p align="center">
  <em>Figure 1. Guitar controller physical design (left) and key binding map (right).</em>
</p>

### Guitar Controller CAD Design

<p align="center">
  <img src="images/GuitarController_CAD_files" width="90%">
</p>

<p align="center">
  <em>Figure 2. CAD models and design files for the guitar controller.</em>
</p>

### Guitar Controller Assembly and Final Design

<p align="center">
  <img src="images/GuitarController_Soldered_Buttons" width="32%">
  <img src="images/GuitarController_Final_Front" width="32%">
  <img src="images/GuitarController_Final_Back" width="32%">
</p>

<p align="center">
  <em>Figure 3. Soldered fret button assembly (left), completed guitar controller front view (middle), and back view (right).</em>
</p>

### Community Outreach — Women Can Do 2026

<p align="center">
  <img src="images/GuitarController_WomanCanDo" width="75%">
</p>

<p align="center">
  <em>Figure 4. Guitar controller showcased at the 2026 Women Can Do event, providing an interactive demonstration to engage high school students and encourage interest in electrical engineering.</em>
</p>

_Drum Controller_

### Drum Controller Design

<p align="center">
  <img src="images/DrumController_Design_Iteration1" width="48%">
  <img src="images/DrumController_Key_Mapping" width="48%">
</p>

<p align="center">
  <em>Figure 5. Initial drum controller design (left) and key mapping configuration (right).</em>
</p>

### Final Drum Controller Design

<p align="center">
  <img src="images/DrumController_Final_Top" width="48%">
  <img src="images/DrumController_Final_Side" width="48%">
</p>

<p align="center">
  <em>Figure 6. Completed drum controller showing the top view (left) and side view (right).</em>
</p>

_Circuit Design_

### Guitar Controller Circuit Schematic

<p align="center">
  <img src="images/GuitarController_CircuitSchematic" width="85%">
</p>

<p align="center">
  <em>Figure 7. Circuit schematic illustrating the electrical connections between the microcontroller, fret buttons, LEDs, and joystick strumming mechanism.</em>
</p>

**Note:** Photographic documentation of the initial breadboard prototype was not captured. The circuit schematic above illustrates the electrical design and connections used during prototyping. The Arduino Pro Micro was used in the final implementation.

### Drum Controller Circuit Schematic and Breadboard Prototype

<p align="center">
  <img src="images/DrumController_CircuitSchematic" width="48%">
  <img src="images/DrumController_Breadboard_Prototype.png" width="48%">
</p>

<p align="center">
  <em>Figure 8. Drum controller circuit schematic (left) and physical breadboard prototype (right), illustrating the integration of the microcontroller, TCA9548A I2C multiplexer, and pressure sensors for drum hit detection.</em>
</p>

## Future Improvements

Although a custom PCB was planned for the project, it was never integrated due to budget constraints. Future development would involve implementing the PCB to replace the existing wiring configuration, improving the overall organization, reliability, and compactness of the electrical system.

Additional improvements could include:
- Replacing the joystick strumming mechanism with a spring-loaded strum bar to better replicate a traditional guitar controller
- Implementing velocity-sensitive drum detection to distinguish between light and forceful strikes
- Developing more durable drum surfaces to replace the balloons
- Improving wire routing and electrical component mounting within the housings

## Project Information

**Course:** Microcontrollers (CMPE3815)

**Institution:** University of Vermont

**Project Type:** Initially an independent project, later expanded as part of a team project in the Microcontrollers course.

**Contributions:** Independently initiated the project, including initial hardware selection, controller design, and development. Further developed and refined the guitar and drum controllers through microcontroller programming, sensor integration, circuit assembly, and troubleshooting in collaboration with team members.
